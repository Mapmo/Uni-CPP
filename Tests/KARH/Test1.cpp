#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
unsigned counter = 0;
struct Option
{
	Option(const std::string&, const double);
	double val = 0;
	std::string text;
};
Option::Option(const std::string& txt, const double val) : text(txt), val(val)
{
}
class Question
{
public:
	Question(const std::string&);
	void AddOption(const std::string&, const double);
	void AskQuestion();
	int AnswerQuestion();
private:
	std::string m_Question;
	std::vector<Option>m_Answers;
	double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
	Option opt(rhs, val);
	m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
	return std::rand() % i;
}
void Question::AskQuestion()
{
	std::cout << m_Question << "\n\n";
	std::srand(unsigned(std::time(0)));
	for (unsigned i = 0; i<m_Answers.size(); ++i)
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	for (unsigned i = 0; i<m_Answers.size(); ++i)
	{
		char ind = i + 65;
		std::cout << ind << ' ' << m_Answers[i].text << '\n';
	}
}

int Question::AnswerQuestion()
{
	char tmp = 'v';
	unsigned tmpToInt;
	std::cin >> tmp;
	tmpToInt = tmp;
	do
	{
		if (tmpToInt<97)
			tmpToInt -= 65;
		else
			tmpToInt -= 97;
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');
	std::cout << "Rezultat: " << m_Score << "\nVeren otgovor(i): ";
	for (unsigned i = 0; i<m_Answers.size(); ++i)
		if (m_Answers[i].val>0)
			std::cout << char(i + 65) << ' ';
	std::cout << "\nVavedi nqkoi simvol";
	if (m_Score>0)
		counter++;
	return m_Score;
}
int main()
{
	std::cout << "Test 1 po KARH\nIzgotven ot Mapmo, Dakata, Ikbal i M.\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	//cache memory
	Question d0("Koi ot trite metoda na razpolagane na blokove ot operativnata pamet se implementira nai-lesno(izberete edno)?");
	d0.AddOption("Direktno supostavqne", 1);
	d0.AddOption("Pulna asociativnost", -1);
	d0.AddOption("Mnojestvena asociativnost", -1);
	exam.push_back(d0);

	Question d1("Otbelejete nevqrnoto tvurdenie(izberete edno).");
	d1.AddOption("Glavnata (DRAM) pamet e po-bavna ot SRAM pametta", -1);
	d1.AddOption("DRAM konsumira poveche energiq ot SRAM", -1);//tuka rusalchoto go smeni,moje i da e greshno
	d1.AddOption("Cache pametta e malka,burza i SRAM bazirana", -1);
	d1.AddOption("SRAM e po-evtina ot DRAM", 1);
	exam.push_back(d1);

	Question d2("Kakva e korelaciqta kapacitet i burzodeistvie pri kompiyturnite pameti(izberete edno)?");
	d2.AddOption("Proporcionalna", -1);
	d2.AddOption("Obratnoproporcionalna", 1);//verniqt
	d2.AddOption("Nqma korelaciq", -1);
	exam.push_back(d2);

	Question d3("Kakuv e formata na liniqta pri Cache pametta s mnojestvena acociativnost(izberete edno)?");
	d3.AddOption("tag,duma", -1);
	d3.AddOption("tag,liniq,duma", -1);
	d3.AddOption("tag,mnojestwo,duma", 1);//verniqt
	exam.push_back(d3);

	Question d4("Koy vid pameti sa po-burzi ot Cache pametite(izberete edno)?");
	d4.AddOption("Registrite", 1);//tova e verniqt otgovor
	d4.AddOption("Flash pametite", -1);
	d4.AddOption("Glavnata pamet", -1);
	exam.push_back(d4);

	Question d5("Metodut pri koito obnovqvane na glavnata pamet nastupva asinhronno sled premahvane na duma ot Cache se naricha(izberete edno)?");
	d5.AddOption("Zashtiten zapis", -1);
	d5.AddOption("Write-back", 1);//verniqt
	d5.AddOption("Cache-write", -1);
	d5.AddOption("Write-trough", -1);
	exam.push_back(d5);

	Question q31("Metodut pri koito obnovqvane na glavnata pamet nastupva sinhronno sled premahvane na duma ot Cache se naricha(izberete edno)?");
	q31.AddOption("Zashtiten zapis", -1);
	q31.AddOption("Write-back", -1);//verniqt
	q31.AddOption("Cache-write", -1);
	q31.AddOption("Write-trough", 1);
	exam.push_back(q31);

	Question d6("Kakav e formatat na liniqta pri Cache pamet s pulna asociativnost?");
	d6.AddOption("tag,liniq,duma", -1);
	d6.AddOption("tag,duma", 1);
	d6.AddOption("tag,mnojestvo,duma", -1);
	exam.push_back(d6);

	Question d7("Dadena e mashina s pobaitovo adresiruema osnovna pamet s razemr 2^16 baita,i razmer na bloka 8 baita.Cache pametta e s \ndirektna organizaciai se sustoi ot 32 linii.Kakuv e maksimalniqt broi baitove, koito mogat da budat razpolojeni w Cache pametta?(izberete edno)?");
	d7.AddOption("256B", 1);//verniqt
	d7.AddOption("1024B", -1);
	d7.AddOption("512B", -1);
	d7.AddOption("128B", -1);
	d7.AddOption("64B", -1);
	exam.push_back(d7);

	Question d8("LFU e algoritumut za?");
	d8.AddOption("zamestvane na nai-chesto izpolzvanata stranica ot Cache pametta ", -1);
	d8.AddOption("zamestvane na nai-neizpolzvanata stranica v Cache pametta", 1);//veren
	d8.AddOption("zamestvane na nqkoi ot izpolzvanite stranici v Cache pametta", -1);
	d8.AddOption("periodichno izchistvane priznacite za obrushtenie kum nai-rqdko izpolzvanite stranici v Cache pametta.", -1);
	exam.push_back(d8);

	Question d9("Dadena e mashina s pobaitovo adresiruema osnovna pamet i 2-kraten mnojestveno asociativen Cache. Cache-logikata interpretira adresa ot pametta\nkakto sledva :14 bita za tag, 8 nita za mnojestvo,2 bita za adresirane na duma\n.Kolko e maksimalniq broi na blokovete v glavnata pamet?(izberete edno)?");
	d9.AddOption("Ne moje da bude opredelen", -1);
	d9.AddOption("2^2", -1);
	d9.AddOption("2^8", -1);
	d9.AddOption("2^22", 1);//veren
	d9.AddOption("2^14", -1);
	d9.AddOption("2^24", -1);
	exam.push_back(d9);

	Question d10("Cache pamet s asociativna organizaciq e s kapacitet 64 linii,pazdeleni na mnojestva s po 16 linii vsqko.Osnovnata pamet sudurja 4K bloka s po128 dumi vseka.\nPosochete adresniqt format ,koito i suotvetstva:(Formata e : tag,set,word)?");
	d10.AddOption("8 2 7", 1);//towa bi trqbwalo da e vqrno , but who knows, definitely not Cvetanov
	d10.AddOption("14 8 4", -1);
	d10.AddOption("14 8 7", -1);
	d10.AddOption("4 8 7", -1);
	exam.push_back(d10);

	Question d11("Metodut,pri koito zapis na dannite se izvurshva samo v Cache pametta,a sustoqnieto na Cache-bloka se otbelqzva \nkato obiknoveno v ypravlqvashtoto pole s priznak,narechen \"update\" ili \"dirty\" se naricha :?");
	d11.AddOption("Obraten zapis(Write back)", 1);
	d11.AddOption("Ednovremenen zapis(Write trough)", -1);
	exam.push_back(d11);

	Question q36("Kakav e formatat na liniqta pri Cache pamet s asociativna organizaciq?");
	q36.AddOption("tag,liniq,duma", -1);
	q36.AddOption("tag,duma", 1);
	q36.AddOption("tag,mnojestvo,duma", -1);
	exam.push_back(q36);

	Question q37("Pri koy ot trite metoda na razpolagane blokove ot operacionnata pamet v kesha e nay-malko veroqtno dva bloka da budat zapisani na edna i sushta liniq?");
	q37.AddOption("Pulna asociativnost", 1);
	q37.AddOption("Direktno supostavqne", -1);
	q37.AddOption("Mnojestvena asociativnost", -1);
	exam.push_back(q37);

	Question q0("Dadena e mashina s pobaytovo adresiruema osnovna pamet 2^24 bayta i s kesh za danni s direktna organizaciq i s kapacitet 64k i 32 bajtovi blokove. Kolko bita sa neobhodimi za tag, blok i otmestvane?");
	q0.AddOption("8 bita za tag, 5 bita za blok, 11 bita za unikalna duma", -1);
	q0.AddOption("8 bita za tag, 11 bita za blok, 5 bita za unikalna duma", 1);
	q0.AddOption("11 bita za tag, 8 bita za blok, 5 bita za unikalna duma", -1);
	exam.push_back(q0);

	Question q1("Koi ot izbroenite podhodi sposobstvat za namalqvane na latentnostta pri zarejdane na danni v kesha?");
	q1.AddOption("Otlojen zapis na danni", 0.34);
	q1.AddOption("Zarejdane pri poiskvane", 0.33);
	q1.AddOption("Obraten zapis", -1);
	q1.AddOption("Ednovremenen zapis", -1);
	q1.AddOption("Spekulativno zrejdane", 0.33);
	exam.push_back(q1);

	Question q25("Koe ot izbroenite ne e vqrno za kesh pametta?");
	q25.AddOption("Namira se v adresnoto prostranstvo na procesora i moje da se adresira s pomoshta na mashinnite instrukcii", 1);
	q25.AddOption("Osigurqva burz dostup do intenzivno izpolzvanite danni chrez tqhnoto predvaritelno zarejdane", -1);
	q25.AddOption("Suglasuva interfeisa na procesora i kontrolera na pametta", -1);
	exam.push_back(q25);

	Question q33("Koi ot izbroenite algoritmi za upravlenie na zamestvaneto na blokove pri kesh pametite se osnovavat na ocenka na veroqtnostta za obryshtenie kum bloka v budeshte vreme?");
	q33.AddOption("Algoritam za sluchayniq izbor RC(random choice)", -1);
	q33.AddOption("Algoritam FIFO", -1);
	q33.AddOption("Algoritam LFU(Least Frequently Used)", -1);
	q33.AddOption("Algoritam LRU(Least Recently Used)", -1);
	q33.AddOption("Nito edin ot posochenite", 1);//Algoritmite za upravlenie na zamestvaneto, koito se osnovavat na ocenka na veroqtnostta za obryshtenie na bloka v budeshte vreme se narichat fizicheski nerealiziruemi
	exam.push_back(q33);						//src http://www.tyanev.com/resources/books/ComputerOrganization/OK_632.HTM?fbclid=IwAR1HMqF44Y7Y8QsChrI4_m4pZPm4yy4BZJmsDMuHMyWh2jLShvHi7oc6mcw

	//virtual memory
	Question q11("Koy ot posochenite metodi ne e metod za preobrazuvane na virtualni adresi?");
	q11.AddOption("Metod na stranichna organizaciq", -1);
	q11.AddOption("Metod na segmentno-stranichna organizaciq", -1);
	q11.AddOption("Metod na lokalnostta", 1);
	q11.AddOption("Metod na segmentna organizaciq", -1);
	exam.push_back(q11);

	Question q3("Kolko e maksimalniqt broy stranici s razmer na stranicite 4k pri 32 bitov adres?");
	q3.AddOption("1M", 1);
	q3.AddOption("64k", -1);
	q3.AddOption("5k", -1);
	q3.AddOption("20k", -1);
	exam.push_back(q3);

	Question q4("Kakvo sudurja TLB pri stranichna organizaciq na pametta?");
	q4.AddOption("Momentna karta na sustoqnieto na stranicite na operativnata pamet", 1);
	q4.AddOption("Tablica s nomera na fizicheski stranici, prinadlejashti na daden proces", -1);
	q4.AddOption("Tablica s nomera na virtualni stranici, prinadlejashti na daden proces", -1);
	q4.AddOption("Tablica na stranicite na diska", -1);
	exam.push_back(q4);

	Question q5("Koq ot izbroenite harakteristiki ne opisva tablicata na stranicite?");
	q5.AddOption("Tablicata na stranicite se sustoi ot redove, vseki red ot tablicata suotvetstva na nomer na virtualna stranica", -1);
	q5.AddOption("Tablicata na stranicite sudurja informaciq za aktivnite procesi", 1);
	q5.AddOption("Tablicata na stranicite e dopulnena s bit za prisustvie, pokazvasht dali suotvetnata stranica se namira v svobodnata pamet", -1);
	q5.AddOption("Tablicata na stranicite se pazi nqkude v operativnata pamet", -1);
	exam.push_back(q5);

	Question q6("Kakvo e prednaznachenieto na TLB?");
	q6.AddOption("Da minimizira zagubata na burzodeystvie pri tarsene na fizicheskoto razpolojenie na dannite", 1);
	q6.AddOption("Da preobrazuva virtualnite stranichni adresi vuv fizicheski", -1);
	q6.AddOption("Da namali proizvoditelnostta na harduerna implementaciq", -1);
	exam.push_back(q6);

	Question q7("Kakvi tipove pamet se izpolzvat za sahranenie i poddurjane na tablicite na stranicite pri statichna organizaciq na pametta?");
	q7.AddOption("Keshova s direktna organizaciq", -1);
	q7.AddOption("Asociativni keshove", 0.5);
	q7.AddOption("Mnojestveno asociativni keshove", 0.5);
	q7.AddOption("Vunshna diskova pamet", -1);
	q7.AddOption("Glavna pamet", -1);
	exam.push_back(q7);

	//addressing modes
	Question q8("Posochete za koy ot izbroenite rejimi na adresaciq se otnasq pokazanata figura\n|  kod |  operand |");
	q8.AddOption("Indeksna", -1);
	q8.AddOption("Kosvena", -1);
	q8.AddOption("Vlojena", -1);
	q8.AddOption("Neposredstvena", 1);
	exam.push_back(q8);

	Question q9("Kak se ukazva stoynostta na operanda pri registrov rejim na adresaciq?");
	q9.AddOption("Zadava se v koda na instrukciqta", -1);
	q9.AddOption("Zadava se chrez konstantno otmestvane sprqmo nachaloto na programniq segent", -1);
	q9.AddOption("Zadava se s nomera na registara", 1);
	exam.push_back(q9);

	Question q10("Pri koy ot izbroenite metodi na adresaciq v adresnata chast na instrukciqta e zapisan adresen ukazatel?");
	q10.AddOption("Indeksna adresaciq", -1);
	q10.AddOption("Direktna adresaciq", -1);
	q10.AddOption("Indeksna adresaciq s registri", -1);
	q10.AddOption("Neposredstvena adresaciq", -1);
	q10.AddOption("Indirektna adresaciq", 1);
	exam.push_back(q10);

	Question q12("Kude e mestopolojenieto na operanda pri registrovo kosvena adresaciq?");
	q12.AddOption("V registar", -1);
	q12.AddOption("V osnovnata pamet", 1);
	q12.AddOption("Vav vtorichnata pamet", -1);
	q12.AddOption("V koda na instrukciqta", -1);
	exam.push_back(q12);

	Question q13("Kak se ukazva efektivniq adres na operanda v pametta pri neposredstven rejim na adresaciq?");
	q13.AddOption("Chrez adres na registar na mikroprocesora", -1);
	q13.AddOption("Chrez stekoviq ukazatel", -1);
	q13.AddOption("Chrez adresnoto pole na operanda v koda na instrukciqta", 1);
	exam.push_back(q13);

	Question q28("Kolko e maksimalniqt broi stranici s razmer 8 pri 8 bitov adres?");
	q28.AddOption("16", -1);
	q28.AddOption("32", 1);
	q28.AddOption("64", -1);
	q28.AddOption("512", -1);
	q28.AddOption("4k", -1);
	exam.push_back(q28);

	Question q29("Pri razmer na stranicite 8 i 8-bitov adres, koy red na tablicata sudurja adresa na stranicata?");
	q29.AddOption("3", 1);
	q29.AddOption("5", -1);
	q29.AddOption("7", -1);
	q29.AddOption("10", -1);
	q29.AddOption("12", -1);
	exam.push_back(q29);

	//pipelining
	Question u7("Poso4ete pri konveyernata obrabotka na koq ot dadenite instrukcii posledovatelnostti vuznikvat hazart ot tipa write-after-read");
	u7.AddOption("ADD R3, R2, R1; R3 = R2 + R1", -1);
	u7.AddOption("ADD R3, R2, R1; R3=R2+R1  SUB R2, R3, 1; R2=R3-1  ADD R3, R2, R5; R3 = R2+R5", 1);
	u7.AddOption("ADD R3, R4, R5 SUB R2, R2, 1 BEQ R2, R0, L1", -1);
	exam.push_back(u7);

	Question u8("Znaeiki, che uskorenieto e pravoproporcionalno na broq fazi na konveyera, zashto realno poluchenoto uskorenie e po-malko v sravnenie s teoreti4no dostijimoto?");
	u8.AddOption("Zaradi hazartite", 0.5);
	u8.AddOption("Zaradi po-visokata patentnost za individualnite instrukcii", -1);
	u8.AddOption("Zaradi vremeto neobhodimo za zapulvane na konveyera", 0.5);
	exam.push_back(u8);

	Question u9("Razdelqneto na instrukciite na otdelni fazi na obrabotka e harakterno za:(izberete edno ili poveche)");
	u9.AddOption("razpredelenata obrabotka", -1);
	u9.AddOption("paralelnata obrabotka", -1);
	u9.AddOption("sistemnata obrabotka", -1);
	u9.AddOption("konveyernata obrabotka", 0.5);
	u9.AddOption("poddurjaneto na paralelizum na nivo instrukcii", 0.5);
	exam.push_back(u9);

	Question u10("Kolko mashinni cikula shte sa neobhodimi za konveyerna obrabotka na 1500 instrukcii v 5-fazen lineen instrukcionen konveyer?");
	u10.AddOption("1505", -1);
	u10.AddOption("7500", -1);
	u10.AddOption("18", -1);
	u10.AddOption("1504", 1);
	exam.push_back(u10);

	Question u11("Kak se preodolqvat hazartite v konveyera pri dostup do obshti resursu v instrukcionniq potok?(ibereze edno ili pove4e)");
	u11.AddOption("chrez prenarejdane na instrukcionniq potok ot kompilatora", -1);
	u11.AddOption("chrez predskazvane na prehodite v instrukcionniq potok", -1);
	u11.AddOption("chrez dublirane na kritichnite fazi", -1);
	u11.AddOption("chrez blokirasti tehniki na konveyera za opredeleno vreme i posledovatelna obrabotka", 0.5);
	u11.AddOption("chrez preskachane na kritichnite fazi", -1);
	u11.AddOption("chrez vuvejdane na zakusneniq i modificirane glavnata tablica na zaetost na konveyera", 0.5);
	exam.push_back(u11);

	Question u12("V instrukcionniq konveyer se izpulnqvat ednovremenno(izberete edno)");
	u12.AddOption("Prazni instrukcii", -1);
	u12.AddOption("Instrukcii za usloven i bezusloven prehod", -1);
	u12.AddOption("Instrukcii v realni fazi", 1);
	u12.AddOption("Zapisi na danni ot registrite kum procesora", -1);
	exam.push_back(u12);

	Question u13("Koi ot izbroenite tehniki se izpolzvat pri razreshavaneto na problemi pri konveyernoto izpulnenie na instrukcii s prehod? (izberete edno ili pove4e)");
	u13.AddOption("Dublirane na konveyernite resursi", -1);
	u13.AddOption("Mnojestveno predvaritelno izpulvane na instrukcii", 1);
	u13.AddOption("Prediction Look-up Table", -1);
	u13.AddOption("Izpolzvane na specializirani funkcionalni ustroistva za chetene na operaciite ili zapis na rezultatite v pametta", -1);
	u13.AddOption("BTB bufer", -1);
	exam.push_back(u13);

	Question u14("Kak se preodolqvat konfliktite za pamet pri konveyeriziranoto izpulnenie na instrukcionniq potok?");
	u14.AddOption("chrez vuvejdane na zakusneniq i modificirane izhodnata tablica na zaetost na konveyera ", -1);
	u14.AddOption("chrez predskazvane na prehodite v instrukcionniq potok", 1);
	u14.AddOption("chrez prenarejdane na instrukcionniq potok ot kompilatora", -1);
	u14.AddOption("chrez izpolzvane na specializirano funkcionalno ustroistvo za chetene na operaciite ili zapis na rezultati v pametta", -1);
	exam.push_back(u14);

	Question u15("Posochete koi ot izbroenite faktori sa prichina za ponijavane na potokovata skorost pri konveyernata obrabotka (izberete edno ili pove4e)");
	u15.AddOption("Zavisimosti po danni", 0.25);
	u15.AddOption("Predskazvane na prehoda v informacionniq potok", -1);
	u15.AddOption("Temp na inicializaciq na konveyera", -1);
	u15.AddOption("Konflikti pri dostup na obshti resursi", 0.25);
	u15.AddOption("Patentnost na konveyernata obrabotka", -1);
	u15.AddOption("Izpolzvaemost na funkcionalnite ustroistva po konveyera", -1);
	u15.AddOption("Anti-zavisimosti po danni", 0.25);
	u15.AddOption("Prehodi v informacionniq potok, zasqgashi modificiraneto na programniq broqch", 0.25);
	exam.push_back(u15);

	Question u16("Na kakvo se duljat precedurnite zavisimosti");
	u16.AddOption("Edinstveno na instrukcii za bezusloven prehod", -1);
	u16.AddOption("Edinstveno na instrukcii za usloven prehod ", -1);
	u16.AddOption("Instrukcii za bezusloven prehod i instrukcii s osushtestven usloven prehod v instrukcionniq potok na programata", 1);
	u16.AddOption("Ednovremenni zaqvki za edin i susht resurs", -1);
	exam.push_back(u16);

	Question u17("Ot kakvo se predizvikvat resursnite konflikti?");
	u17.AddOption("Ne dobro planirane na resursite na instrukcionniq konveyer", -1);
	u17.AddOption("Ednovremenni zaqvki za edni i susti resursi", 1);
	u17.AddOption("Ot vuzniknali mehuri v konveyera", -1);
	exam.push_back(u17);

	Question u18("Koi ot izbroenite metodi se izpolzva za reshavane na problema s instrukcionnite hazarti ? (izberete edno ili pove4e)");
	u18.AddOption("Prezarejdane na konveyera ", -1);
	u18.AddOption("Uveli4avane razmera na bufernata pamet v otdelnite funkcionalni ustroistva", -1);
	u18.AddOption("Oprostqvane formata na instrukciite izpolzvani ot programata", -1);
	u18.AddOption("Razdelqne na instrukcionniq cikul na dopulnitelni fazi na obrabotka", -1);
	u18.AddOption("Prenarejdane na instrukcii ot kompilatora", 1);
	exam.push_back(u18);

	//random
	Question q14("Superskalaren procesor obrabotva dva instrukcionni potoka(ot prosti i slojni instrukcii)Koq ot izbroenite fazi na razrabotka e obshta i za dvata potoka?");
	q14.AddOption("Izvlichane", 1);
	q14.AddOption("Izpalnenie", -1);
	q14.AddOption("Zapis na rezultata", -1);
	q14.AddOption("Dekodirane", -1);
	exam.push_back(q14);

	Question q15("Kakvo e prednaznachenieto na mehanizmite za zashtita na pametta?");
	q15.AddOption("Da ne dopuskat modificirane na sistemniq softuer ot prilojeniq", -1);
	q15.AddOption("Da ogranichavat dostupa do suhranqvanata v sistemata informaciq", -1);
	q15.AddOption("Da otkrivat greshki pri adresiraneto predi izvurshvaneto na nerazreshen dostup", -1);
	q15.AddOption("Da ogranichavat dostupa do opredeleni segmenti ili stranici", 1);
	exam.push_back(q15);

	Question q16("Shinata PCI v procesornata arhitektura se qvqva most mejdu:");
	q16.AddOption("shina EISA i periferiqta", 1);
	q16.AddOption("sistemnata shina na mikroprocesora i shinata EISA", -1);
	q16.AddOption("sistemnata shina na mikroprocesora i osnovnata pamet", -1);
	q16.AddOption("mikroprocesora i kesh pametta L2", -1);
	exam.push_back(q16);

	Question q17("Koq/koi ot izbroenite shini ne sa chast ot sistemnata shina?");
	q17.AddOption("Shina za danni", -1);
	q17.AddOption("Shina za logicheski signali", 1);
	q17.AddOption("Kontrolna shina", -1);
	q17.AddOption("Adresna shina", -1);
	exam.push_back(q17);

	Question q18("V rejim na direkten dostap do pametta, upravlenieto na obmena se poema ot:");
	q18.AddOption("Ustroystvoto za vhod/izhod", 1);
	q18.AddOption("Procesora", -1);
	q18.AddOption("Glavnata pamet", -1);
	exam.push_back(q18);

	Question q26("Kolko provodna moje da bude USB platinata?");
	q26.AddOption("4", 0.5);
	q26.AddOption("9", 0.5);
	q26.AddOption("6", -1);
	exam.push_back(q26);

	Question q27("Koq e pravilnata definiciq za termina CISC");
	q27.AddOption("Complex Instruction Set Computing", 1);
	q27.AddOption("Corect Index System Call", -1);
	q27.AddOption("Chip Ignore Call", -1);
	q27.AddOption("Central Integer Stack Index", -1);
	exam.push_back(q27);

	Question q39("Koq e pravilnata definiciq za termina RISC");
	q39.AddOption("Reduced Instruction Set Computing", 1);
	q39.AddOption("Random Index System Call", -1);
	q39.AddOption("Risk Instruction Stack Call", -1);
	q39.AddOption("Real Invested Space Capacity ", -1);
	exam.push_back(q39);

	//ISA
	Question q19("V zavisimost ot rejima na adresaciq vremeto za izpalnenie na edna procesorna instrukciq moje da varira v znachitelna stepen. Pri koq ot izbroenite podredbi na adresni rejimi vremeto shte se izmenq ot mnogo kratko do mnogo dulgo?");
	q19.AddOption("direktna, kosvena, neposredstvena", -1);
	q19.AddOption("neposredstvena, kosvena, direktna", -1);
	q19.AddOption("neposredstvena, direktna, kosvena", 1);
	q19.AddOption("kosvena, neposredstvena, direktna", -1);
	exam.push_back(q19);

	Question q20("Koy ot izbroenite etapi ne e chast ot instrukcionniq cikal?");
	q20.AddOption("Prenarejdane", 1);
	q20.AddOption("Izvlichane", -1);
	q20.AddOption("Izpalnenie", -1);
	q20.AddOption("Dekodirane", -1);
	exam.push_back(q20);

	Question q21("Koi procesori ot izbroenite procesorni familii se harakterizirat s RISC-arhitektura?");
	q21.AddOption("SPARC", 0.33);
	q21.AddOption("CYRIX", -1);
	q21.AddOption("ALPHA", -1);
	q21.AddOption("INTEL", -1);
	q21.AddOption("AMD", -1);
	q21.AddOption("MIPS-R4000", 0.34);
	q21.AddOption("ARM", 0.33);
	exam.push_back(q21);

	Question q22("Kakva sistema instrukcii imat razlichnite familii multiprocesorni arhitekturi?");
	q22.AddOption("Ednakva", -1);
	q22.AddOption("Suvpadashta otchasti", 0.5);
	q22.AddOption("Izcqlo razlichna", 0.5);
	exam.push_back(q22);

	Question q23("Koy/Koi ot izbroenite etapi e chast ot instrukcionniq cikal?");
	q23.AddOption("Prenarejdane", -1);
	q23.AddOption("Izvlichane", 0.34);
	q23.AddOption("Izpalnenie", 0.33);
	q23.AddOption("Dekodirane", 0.33);
	exam.push_back(q23);

	Question q24("Koe ot tvardeniqta otnosno razmera na stranicite e nevqrno");
	q24.AddOption("Po-golemiqt razmer na stranicite uvelichava vremeto za vhodno-izhodni operacii(chetene, zapis na stranici) po vreme na izpulnenie na programite", 1);
	q24.AddOption("Po-golemiqt razmer vodi do vavejdane na izlishna informaciq, koqto moje da e izlishna", -1);
	q24.AddOption("Po-malkiqt razmer na stranicata vodi do namalqvane na vatreshnata fragmentaciq, koqto e 1/2 ot poslednata stranica", -1);
	exam.push_back(q24);

	//komp arch
	Question u1("Ot koi faktori zavisi proizvoditelnostta na komputurnite sistemi?");
	u1.AddOption("Ot vremeto za dostup do registrirane", -1);
	u1.AddOption("Arhitekturata i tehnologiqta", 1);
	u1.AddOption("Ot taktovata 4estota", -1);
	exam.push_back(u1);

	Question u2("Edinicata za izmervane na proizvoditelnostta MIPS za supostavqne na ednotipni procesorni arhitekturi se osnovava na:");
	u2.AddOption("Broi operacii s operandi ot virtualnata pamet", -1);
	u2.AddOption("Broi operacii s operandi ot kesh pametta", -1);
	u2.AddOption("Broi operacii s operandi ot glavnata pamet", 1);
	u2.AddOption("Broi operacii s operandi ot flash-pametta", -1);
	exam.push_back(u2);

	Question u3("Osnovni proizvoditeli na x86 arhitekturata sa:(Izberete edno ili poveche)");
	u3.AddOption("IBM", 0.34);
	u3.AddOption("Hewlett-Packard", 0.33);
	u3.AddOption("Intel", 0.33);
	u3.AddOption("Sun Microsystems", -1);
	u3.AddOption("Advanced Micro Device", -1);
	exam.push_back(u3);

	Question u4("Za kakvo sluji programniqt broqch (Izberete edno)");
	u4.AddOption("Za ukazvane adresa na sledvashtata instrukciq za izpylnenie", 1);
	u4.AddOption("Za suhranqvane na rezultata ot aritmetichnite operacii izpulnqvani v ALU-to", -1);
	u4.AddOption("Za otchitane broq na izpulneniqta na dadena instrukciq ", -1);
	u4.AddOption("Za otchitane na procenta pamet zaeman ot izpulnqvashtata se programa", -1);
	exam.push_back(u4);

	Question u5("Koq e pravilnata definiciq za termina SIMD? (Izberete edno)");
	u5.AddOption("Single Instruction, Multiple Data", 1);
	u5.AddOption("Single Interrupt, Multiple Distribution", -1);
	u5.AddOption("Single Input, Multiple Distributions", -1);
	u5.AddOption("Single Integration, Multiple Dynamics", -1);
	exam.push_back(u5);

	Question u6("Koi ot izbroenite tehniki slujat za uveli4avane stepenta na paralelizum po vreme na izpulnenie na programata (izberete edno ili pove4e)");
	u6.AddOption("nito edno ot poso4enite ", -1);
	u6.AddOption("Prognozirane posokata na prehodite", 0.25);
	u6.AddOption("Ednovremenno zarejdane za izpulnenie na nqkolko instrukcii i dinami4no planirane", 0.25);
	u6.AddOption("Otkrivane i premahvane na zavisimosti po danni pri kompilirane", 0.25);
	u6.AddOption("Reorganizaciq na ciklite po takuv na4in, 4e wsqka iteraciq w polu4eniq kod da se sustoi ot instrukcii, koito sa izbrani ot razli4ni iteracii na purvona4alniq cikul(loop unrolling)", 0.25);
	exam.push_back(u6);

	Question q30("Koe ot izbroenite harakterizira arhitekturnata koncepciq EPIC?");
	q30.AddOption("Opolzotvorqvane paralelizam na nivo instrukciq chrez izprashtane na nqkolko instrukcii na obiknoveniq instrukcionen potok v razlichni funkcionalni ustroystva na konveyeara", -1);
	q30.AddOption("Opolzotvorqvane na qven paralelizam na nivo instrukciq", 0.34);
	q30.AddOption("Opolzotvorqvane na skritiq v programniq kod na nivo kompilator i aparatna poddrujka", 0.33);
	q30.AddOption("Ednovremenno zarekdane za izpalnenie na nqkolko instrukcii i dinamichno planirane", -1);
	q30.AddOption("Izpolzvane na shiroka shina za zarejdane na instrukciq i dulgi konveyeri s golqma zadrujka", 0.33);
	exam.push_back(q30);
	
	Question q32("Za koq ot izbroenite komputarni arhitekturi se otnasqt slednite osobeonsoti:\n-Daljinata na instrukciite e stotici bitove\n-V ramkite na procesora funkcionirat paralelno mnojestvo funkcionalni ustroystva\n-Vsichki funckionalni ustroystva spodelqt ogromen obsht registrov fail");
	q32.AddOption("Potokova", -1);
	q32.AddOption("Superskalarna", -1);
	q32.AddOption("VLIW", 1);
	q32.AddOption("EPIC", -1);
	exam.push_back(q32);

	Question q34("Po kakvo se razlichavat CISC ot RISC?");
	q34.AddOption("Vsichki instrukcii se harakterizirat s oprosten format", 1);
	q34.AddOption("Instrukciite preobladavashto sa ot tip pamet-pamet", -1);
	q34.AddOption("Vsichki instrukcii se harakterizirat s enda is sushta duljina", -1);
	q34.AddOption("Slojnite instrukcii se sintezirat ot po-prostite", -1);
	q34.AddOption("Operaciite s pametta sa samo ot tipa \"Load\" i \"store\"", -1);
	exam.push_back(q34);

	Question q35("Ot kakvo se opredelq vremeto za izpalnenie na programata v procesora:\n1)algoritama 2)programniq ezik 3)kompilatora 4)sistamata procesorni instrukcii");
	q35.AddOption("1) i 3)", 1);//in Kosyo we trust
	q35.AddOption("3) i 4)", -1);
	q35.AddOption("1), 2), 3 i 4))", -1);
	q35.AddOption("1) i 2)", -1);
	q35.AddOption("2) i 3)", -1);
	q35.AddOption("2), 3) i 4)", -1);
	exam.push_back(q35);

	Question q38("Ot kakav tip e slednata istrukciq?\nADD 5,15,20");
	q38.AddOption("RISC", -1);
	q38.AddOption("CISC", 1);
	q38.AddOption("VLIW", -1);
	exam.push_back(q38);

	Question q40("Pri kesh s direktno adresirane s 4 linii i razmer na blok 8, na koq liniq popada adres 22?");
	q40.AddOption("0", -1);
	q40.AddOption("1", -1);
	q40.AddOption("2", 1);
	q40.AddOption("8", -1);
	exam.push_back(q40);

	Question q41("poso4ete na koy ot izbroenite rejimi na adresaciq se otnasq dadenata figura\n kod|adres na registyra|adres w pametta:");
	q41.AddOption("adresaciq s izmestvane", -1);
	q41.AddOption("vlojena adresaciq", -1);
	q41.AddOption("indirektna adresaciq s registri", 1);
	q41.AddOption("adresirane na registri", -1);
	exam.push_back(q41);

	Question q42("Poso4ete pri konveierna obrabotka na koq ot dadenite instrykcionni posledowatelnosti vyznikva hazart ot tipa write-after-write?");
	q42.AddOption("ADD R3,R2,R1/nSUB R2,R3,1\nADD R3,R2,R5", 1);
	q42.AddOption("ADD R3,R4,R5\nSUB R2,R2,1\nBEQ R2,R0,L1", -1);
	q42.AddOption("ADD R3,R2,R1\nSUB R2,R3,1", -1);
	exam.push_back(q42);

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i<questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i<exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "Sekciq sus sgresheni vuprosi\nnatisnete nqkoy buton\n";
			std::cin >> useless;
			system("CLS");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("CLS");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	return 0;
}
