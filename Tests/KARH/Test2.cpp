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
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	for (unsigned i = 0; i < m_Answers.size(); ++i)
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
		if (tmpToInt < 97)
			tmpToInt -= 65;
		else
			tmpToInt -= 97;
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');
	std::cout << "Rezultat: " << m_Score << "\nVeren otgovor(i): ";
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		if (m_Answers[i].val > 0)
			std::cout << char(i + 65) << ' ';
	std::cout << "\nVavedi nqkoi simvol";
	if (m_Score > 0)
		counter++;
	return m_Score;
}
int main()
{
	std::cout << "Test 2 po KARH\nIzgotven ot Mapmo, Dakata, Ikbal i M.\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Kakva e celta na izpolzvaneto na CMOVZ?");
	q1.AddOption("Reducirane na uuslovnite prehodi", 1);
	q1.AddOption("Spestqvane na pamet", -1);
	q1.AddOption("Izbqgvane na logicheska greshka", -1);
	q1.AddOption("Predotvratqvane na mehuri v konveyera", -1);
	exam.push_back(q1);

	Question q2("Koi ot izbroenite abreviaturi sa imena na shini?");
	q2.AddOption("USB, CAN, I2C", 1);
	q2.AddOption("LPT, PWM, I2C", -1);
	q2.AddOption("Com-port, PCA, PWM", -1);
	q2.AddOption("PCA, ISA, RJ11", -1);
	exam.push_back(q2);

	Question q3("Koi ot posochenite komponenti osushtestvqva vruzka s vutreshna shina?");
	q3.AddOption("USB", -1);
	q3.AddOption("LPT", -1);
	q3.AddOption("Com-port", -1);
	q3.AddOption("PCI", 0.5);
	q3.AddOption("ISA", 0.5);
	q3.AddOption("Ethernet", -1);
	exam.push_back(q3);

	Question q4("Koi ot posochenite komponenti osushtestvqva vruzka s vunshna shina?");
	q4.AddOption("USB", 0.25);
	q4.AddOption("LPT", 0.25);
	q4.AddOption("Com-port", 0.25);
	q4.AddOption("PCI", -1);
	q4.AddOption("ISA", -1);
	q4.AddOption("Ethernet", 0.25);
	exam.push_back(q4);

	Question q5("Kak se sluchvat vav vremeto REQ i GNT?");
	q5.AddOption("Poluchava se GNT, a sled tova REQ", -5);
	q5.AddOption("Poluchava se REQ, sled koeto GNT", 1);
	q5.AddOption("Sled poluchavane na REQ, vednaga se generiran GNT", -1);
	q5.AddOption("Sled poluchavane na GNT, vednaga se generira REQ", -5);
	exam.push_back(q5);

	Question q6("Mejdu T3 i T4 koy ustanovqva signalite za danni na shinata za purvata chast na kartinkata?\nIMG not found");
	q6.AddOption("Master", -1);
	q6.AddOption("Slave", 1);
	exam.push_back(q6);
	
	Question q7("Mejdu T3 i T4 koy ustanovqva signalite za danni na shinata za vtorata chast na kartinkata?\nIMG not found");
	q7.AddOption("Master", 1);
	q7.AddOption("Slave", -1);
	exam.push_back(q7);

	Question q8("Zashto ima po edna strelka vuv vsqka posoka?");
	q8.AddOption("Zashtoto sa diferencialni dvoyki", -1);
	q8.AddOption("Zashtoto ne stiga chestotnata liniq", -1);
	q8.AddOption("Za postigane na po-visoki skorosti", -1);
	q8.AddOption("Vsichki sa verni", 1);
	exam.push_back(q8);

	Question q9("Kakvo oznachava CRC?");
	q9.AddOption("Cyclic Redundancy Check", 1);
	q9.AddOption("Complete Register Content", -1);
	q9.AddOption("Connection Regulating Chip", -1);
	q9.AddOption("Create Read Clear", -1);
	exam.push_back(q9);

	Question q10("Koq shina ima posoka ot uC HOST kum Ethernet?\nImg not found");
	q10.AddOption("TXD", 1);
	q10.AddOption("RXD", -1);
	exam.push_back(q10);

	Question q11("Koq shina ima posoka ot Ethernet kum ucHost?\nImg not found");
	q11.AddOption("TXD", -1);
	q11.AddOption("RXD", 1);
	exam.push_back(q11);

	Question q12("Kakvo e DMA?");
	q12.AddOption("Direct Memory Access", 1);
	q12.AddOption("Digital Machine Accumulator", -1);
	q12.AddOption("Digital Memory Access", -1);
	q12.AddOption("Detector of Masked Attacks", -1);
	exam.push_back(q12);

	Question q13("Kolko provodna e USB3 shinata?");
	q13.AddOption("9", 1);
	q13.AddOption("3", -1);
	q13.AddOption("6", -1);
	q13.AddOption("1", -1);
	exam.push_back(q13);

	Question q14("Kolko provodna e USB2 shinata?");
	q14.AddOption("4", 1);
	q14.AddOption("2", -1);
	q14.AddOption("8", -1);
	q14.AddOption("1", -1);
	exam.push_back(q14);

	Question q15("Zashto D+ i D- sa usukani?");
	q15.AddOption("Za povishavane na skorostta", -1);
	q15.AddOption("Za po-golqma zdravina", -1);
	q15.AddOption("Za po-dobra guvkavost na kabela", -1);
	q15.AddOption("Za shumoustoychivost", 1);
	exam.push_back(q15);

	Question q16("Kakvo e SOF?");
	q16.AddOption("Start of Frame", 1);
	q16.AddOption("Superior orbital fissure", -100);
	q16.AddOption("Sequence of Files", -1);
	q16.AddOption("Single Offset Flag", -1);
	exam.push_back(q16);

	Question q17("Koy freim e za chetene?");
	q17.AddOption("Purvi", 1);
	q17.AddOption("Vtori", -1);
	q17.AddOption("Treti", -1);
	q17.AddOption("Chetvrti", -1);
	exam.push_back(q17);

	Question q18("Koy freim e za pisane?");
	q18.AddOption("Purvi", -1);
	q18.AddOption("Vtori", -1);
	q18.AddOption("Treti", 1);
	q18.AddOption("Chetvrti", -1);
	exam.push_back(q18);

	Question q19("Za kakvo slujat rezistorite?");
	q19.AddOption("Za suzdavane na elektrichesko suprotivlenie", 1);
	q19.AddOption("Za po-burza vruzka s pametta", -1);
	q19.AddOption("Za zashtita ot udari", -1);
	q19.AddOption("Za uskorqvane na vruzkata mejdu shinite i procesora", -1);
	exam.push_back(q19);

	Question q20("Kakvo e prednaznachenieto na predicate?");
	q20.AddOption("Da opishe daden proces", 1);
	q20.AddOption("Da optimizira operaciq", -1);
	q20.AddOption("Da namali latentnostta", -1);
	q20.AddOption("Da uskori rabotata s procesora", -1);
	exam.push_back(q20);

	Question q21("Ima srqzana kartinka i Rusalcho pita koe e pyrvo");
	q21.AddOption("Read", 1);
	q21.AddOption("Write", -1);
	q21.AddOption("Idle", -1);
	exam.push_back(q21);

	Question q22("Ima srqzana kartinka i Rusalcho pita koe e po sredata");
	q22.AddOption("Read", -1);
	q22.AddOption("Write", -1);
	q22.AddOption("Idle", 1);
	exam.push_back(q22);

	Question q23("Ima srqzana kartinka i Rusalcho pita koe e nakraq");
	q23.AddOption("Read", -1);
	q23.AddOption("Write", 1);
	q23.AddOption("Idle", -1);
	exam.push_back(q23);
	
	Question q24("S kakwa cel se izpolzwa CMOWZ?");
	q24.AddOption("Reducirane na obryshteniqta do pamtta", -1);
	q24.AddOption("Namalqwaneto na zakysneniq pre chetene ili zapis", -1);
	q24.AddOption("Predotwatqwane na hazartite", -1);
	q24.AddOption("Reducirane na uslownite prehodi", 1);
	exam.push_back(q24);

	Question q25("Zashto ima po edna strelka wyw wsqka posoka");
	q25.AddOption("Zashtoto sa diferencialni dvoiki", -1);
	q25.AddOption("Zashtoto ne dostiga chestotnata lenta", -1);
	q25.AddOption("Za da se postigne po visoka skorost", -1);
	q25.AddOption("Wsichki sa verni", 1);
	exam.push_back(q25);
	
	Question q26("Zashto se nalaga izpolzwaneto na poweche linii");
	q26.AddOption("Zashtoto sa diferencialni dvoiki", -1);
	q26.AddOption("Zashtoto ne dostiga chestotnata lenta", -1);
	q26.AddOption("Za da se postigne po visoka skorost", -1);
	q26.AddOption("Wsichki sa verni", 1);
	exam.push_back(q26);

	Question q27("Koe e oznacheniqt s B sloq v CI protokolniq stek");
	q27.AddOption("Communication", -1);
	q27.AddOption("Software", -1);
	q27.AddOption("Tranzaction", 1);
	q27.AddOption("Physical", -1);
	q27.AddOption("Data Link", -1);
	exam.push_back(q27);

	Question q28("Koe e oznacheniqt s C sloq v CI protokolniq stek");
	q28.AddOption("Communication", -1);
	q28.AddOption("Software", -1);
	q28.AddOption("Tranzaction", -1);
	q28.AddOption("Physical", -1);
	q28.AddOption("Data Link", 1);
	exam.push_back(q28);

	Question q29("Koi e elementyt oboznachen s bukwata B(img 29_30)");
	q29.AddOption("Level 1 Cache", -1);
	q29.AddOption("Level 2 Cache", -1);
	q29.AddOption("USB Controller", -1);
	q29.AddOption("Main Memory", 1);
	exam.push_back(q29);

	Question q30("Koi e elementyt oboznachen s bukwata A(img 29_30)");
	q30.AddOption("Level 1 Cache", -1);
	q30.AddOption("Level 2 Cache", -1);
	q30.AddOption("USB Controller", 1);
	q30.AddOption("Main Memory", -1);
	exam.push_back(q30);

	Question q31("Koi e elementa oznachen s A(img 31_32_33_34_35)");
	q31.AddOption("CPU", 1);
	q31.AddOption("PCI Bridge", -1);
	q31.AddOption("USB", -1);
	q31.AddOption("Main memory", -1);
	q31.AddOption("Isa Bridge", -1);
	exam.push_back(q31);

	Question q32("Koi e elementa oznachen s B(img 31_32_33_34_35)");
	q32.AddOption("CPU", -1);
	q32.AddOption("PCI Bridge", 1);
	q32.AddOption("USB", -1);
	q32.AddOption("Main memory", -1);
	q32.AddOption("Isa Bridge", -1);
	exam.push_back(q32);

	Question q33("Koi e elementa oznachen s C(img 31_32_33_34_35)");
	q33.AddOption("CPU", -1);
	q33.AddOption("PCI Bridge", -1);
	q33.AddOption("USB", -1);
	q33.AddOption("Main memory", 1);
	q33.AddOption("Isa Bridge", -1);
	exam.push_back(q33);

	Question q34("Koi e elementa oznachen s D(img 31_32_33_34_35)");
	q34.AddOption("CPU", -1);
	q34.AddOption("PCI Bridge", -1);
	q34.AddOption("USB", 1);
	q34.AddOption("Main memory", -1);
	q34.AddOption("Isa Bridge", 1);
	exam.push_back(q34);

	Question q35("Koi e elementa oznachen s E(img 31_32_33_34_35)");
	q35.AddOption("CPU", -1);
	q35.AddOption("PCI Bridge", -1);
	q35.AddOption("USB", -1);
	q35.AddOption("Main memory", -1);
	q35.AddOption("Isa Bridge", 1);
	exam.push_back(q35);

	Question q36("Koi ustanowqwa signalite za danni w shinata");
	q36.AddOption("Master", 1);
	q36.AddOption("Slave", -1);
	q36.AddOption("Arbiter", -1);
	exam.push_back(q36);

	Question q37("Koi freim e za zapis");
	q37.AddOption("Frame 1", -1);
	q37.AddOption("Frame 2", -1);
	q37.AddOption("Frame 3", 1);
	q37.AddOption("Nito edin", -1);
	exam.push_back(q37);

	Question q38("Pri USB komunikaciqta, za kakwo slujat resiztorite predstaveni na shemata");
	q38.AddOption("Za powishawane na obhwata", -1);
	q38.AddOption("Za powishawane na skorostta", -1);
	q38.AddOption("Za po dobra shumoustichivost", -1);
	q38.AddOption("Za opredelqne na skorostta", 1);
	exam.push_back(q38);

	Question q39("Sored predstawenata na figurata wremediagrama na PCI signalite se osushtestwqwa");
	q39.AddOption("Zapis", -1);
	q39.AddOption("Prazen zapis", -1);
	q39.AddOption("Obraten zapis", -1);
	q39.AddOption("Izprewarwashto chetene", -1);
	q39.AddOption("Chetene", 1);
	exam.push_back(q39);

	Question q40("Posochete za koj ot izbroenite rejimi na adresaciq se otnasq sledniq ");
	q40.AddOption("Wlojen", -1);
	q40.AddOption("Koswen", -1);
	q40.AddOption("Indeksen", -1);
	q40.AddOption("Neposredstwen", 1);
	exam.push_back(q40);

	Question q41("Kak se ukazwa stojnostta na oeranda pri registrow rejim na indeksaciq");
	q41.AddOption("Zadawa se w koda na instrukciqta", -1);
	q41.AddOption("Zadawa se cherez konstantno otmestwane sprqmo nachaloto na programniq segment", -1);
	q41.AddOption("S nomera na registyra", 1);
	exam.push_back(q41);

	Question q42("Koi ot pokazanite shemi pokazwa direktn rejim na adresaciq");
	q42.AddOption("A)", 1);
	q42.AddOption("B)", -1);
	q42.AddOption("C)", -1);
	exam.push_back(q42);

	Question q43("Koi ot izborenite sa fazi na instrukcionniq konveier");
	q43.AddOption("Prenarejdane", 0.3);
	q43.AddOption("Izpylnenie", 0.3);
	q43.AddOption("Izwlichane", 0.4);
	q43.AddOption("dekodirane", 1);
	exam.push_back(q43);

	Question q44("Kak se ukaza efektiwniq adres na operanda w ppametta pri neposredstwen rejim na adresaciq");
	q44.AddOption("Chrez stekoviq ukazatel", -1);
	q44.AddOption("Chrez adresnoto pole na operanda w koda na instrukciqta", 1);
	q44.AddOption("chrez adres na registyr na mikroprocesora", -1);
	exam.push_back(q44);

	Question q45("W zawisimost ot rejima na adresaciq wremeto za edna pprocesorna instrukciq moje da warira w znachitelna stepen. Pri koq ot izbroenite podredbi na adresni rejimi wremeto shte se izmenq ot mnogo kratko do mnogo dylgo?");
	q45.AddOption("neposredstwena, koswena, direktna", -1);
	q45.AddOption("neposredstwena, direktna, koswena", 1);
	q45.AddOption("direktna, koswena, neposredstwena", -1);
	q45.AddOption("koswena, neposredstwena, direktna", -1);
	exam.push_back(q45);

	Question q46("Pri koi ot izbroenite metodi za adresaciq w adresnata chast na instrukciqta e zapisan adresniq ukazatel");
	q46.AddOption("Indeksna adresaciq ", -1);
	q46.AddOption("Indirenktna adresaciq", -1);
	q46.AddOption("direktna adresaciq", -1);
	q46.AddOption("indirektna adresaciq", -1);
	q46.AddOption("Neposredstwena adresaciq", 1);
	exam.push_back(q46);

	Question q47("Kolko instrukcii za GDT(Global Descriptor Table) sushtestwuwat w IA-32 arhitekturata");
	q47.AddOption("Edna ili nqkolko za wseki proces", -1);
	q47.AddOption("Edna za wsichki procesi", 1);
	q47.AddOption("Po edna z awseki proces", -1);
	exam.push_back(q47);

	Question q48("Ot kakyw tip e slednata instrukciq Add,5,15,20");
	q48.AddOption("VWIL", -1);
	q48.AddOption("EPIC", -1);
	q48.AddOption("CISC", 1);
	q48.AddOption("RISC", -1);
	exam.push_back(q48);

	Question q49("Pri Signed - 2's complement kodirane, kakyw e reqzultatyt ot operaciqta 0-1");
	q49.AddOption("1001", -1);
	q49.AddOption("1111", 1);
	q49.AddOption("0001", -1);
	q49.AddOption("1000", -1);
	exam.push_back(q49);
	
	Question q50("Pri Signed - 2's complement kodirane, kakyw e reqzultatyt ot operaciqta 3-5");
	q50.AddOption("1001", -1);
	q50.AddOption("1111", -1);
	q50.AddOption("0001", -1);
	q50.AddOption("1110", 1);
	exam.push_back(q50);
	
	Question q51("Pri sybiraneto na floating point chisla, kakwo deistwie se izwyrshwa eksponentite");
	q51.AddOption("Nulirat se", -1);
	q51.AddOption("Umnojawat se", -1);
	q51.AddOption("Izwajdat se ", -1);
	q51.AddOption("Izmestwat se nalqwo ", -1);
	q51.AddOption("Izmestwat se nadqsno ", -1);
	q51.AddOption("Izmestwat se wzaimno ", -1);
	q51.AddOption(" Sybirat se", 1);
	exam.push_back(q51);

	Question q52("Kakyw e prioritetyt na prekyswaniqta predstaweeni na figurate ot nai wisok kym nai nisyk");
	q52.AddOption("RS232 > Disc > Printer", 1);
	q52.AddOption("Disc > RS232 > Printer", -1);
	q52.AddOption("Printer > Disc > RS232", -1);
	q52.AddOption("RS232 > Printer > Disc", -1);
	q52.AddOption("Printer > RS232 > Disc", -1);
	exam.push_back(q52);

	Question q53("Kakyw e prioritetyt na prekyswaniqta predstaweeni na figurate ot nai nisyk kym nai wisok");
	q53.AddOption("RS232 < Disc < Printer", -1);
	q53.AddOption("Disc < RS232 < Printer", -1);
	q53.AddOption("Printer < Disc < RS232", 1);
	q53.AddOption("RS232 < Printer < Disc", -1);
	q53.AddOption("Printer < RS232 < Disc", -1);
	exam.push_back(q53);

	Question q54("Koi e eleneta oznachen s A na shemata(img 54_55)");
	q54.AddOption("Airbiter", -1);
	q54.AddOption("Processor", -1);
	q54.AddOption("Bridge", 1);
	q54.AddOption("Cashe", -1);
	exam.push_back(q54);

	Question q55("Koi e eleneta oznachen s B na shemata(img 54_55)");
	q55.AddOption("Airbiter", 1);
	q55.AddOption("Processor", -1);
	q55.AddOption("Bridge", -1);
	q55.AddOption("Cashe", -1);
	exam.push_back(q55);

	Question q56("Dadena e multiprocessorna komputyrna sistema s podelena shina i bez kesh. Edna ot wseki chetiri instrukcii prawi obrushtenie kym pametta,\n kato po wreme na swoeto izpulnenie tazi instrukciq zaema shina. Ako shinata e zaeta, to zaqviliqt q processor se postawq w opashka za ichakwane.\n Kolko po-byrza bi bila takawa komputyrna sistema s 64 procesora w srawnenie s 1?");
	q56.AddOption("1.4", -1);
	q56.AddOption("2.2", -1);
	q56.AddOption("3.8", -1);
	q56.AddOption("5.32", -1);
	q56.AddOption("4.16", 1);
	exam.push_back(q56);

	Question q57("Dadena e multiprocessorna komputyrna sistema s n procesora izpolzwashti obshta shina. Weroqtnostta wseki edin ot procesorite da izpolzwa shinata w daden cikyl e p. Kolko e shansut da e swobodna(da ima 0 zaqwki za polzwane)");
	q57.AddOption("(1-p)^n", 1);
	q57.AddOption("(p*n)^2", -1);
	q57.AddOption("p/n", -1);
	q57.AddOption("(1-p)*n", -1);
	q57.AddOption("1/(p*n)", -1);
	exam.push_back(q57);

	Question q58("Za pokazanata topologiq opredelete niwoto na otkazoustojchivost(Fault tolerance) opredelena kato broq vryzki, koito mogat da bydat izgubeni, bez towa da dowede do razpadane na mrejata na 2(img 58_59(a))");
	q58.AddOption("0", 1);
	q58.AddOption("1", -1);
	q58.AddOption("2", -1);
	q58.AddOption("3", -1);
	q58.AddOption("4", -1);
	q58.AddOption("5", -1);
	q58.AddOption("6", -1);
	exam.push_back(q58);

	Question q59("Za pokazanata topologiq opredelete niwoto na otkazoustojchivost(Fault tolerance) opredelena kato broq vryzki, koito mogat da bydat izgubeni, bez towa da dowede do razpadane na mrejata na 2(img 58_59(b))");
	q59.AddOption("0", -1);
	q59.AddOption("1", -1);
	q59.AddOption("2", -1);
	q59.AddOption("3", -1);
	q59.AddOption("4", -1);
	q59.AddOption("5", -1);
	q59.AddOption("6", 1);
	exam.push_back(q59);

	Question q60("Za koq ot izbroenite procesorni arhitekturi se otnasqt slednite osobenosti:\n-Dyljinata na instrukciite e stotici bitowe\n-W ramkite na procesora funkcionirat aralelno mnojestwo funkcionalni ustroistwa\n-Wsichki funkcionalni ustroistwa spodelqt obsht registrow fail");
	q60.AddOption("VWIL", 1);
	q60.AddOption("EPIC", -1);
	q60.AddOption("Potokowa", -1);
	q60.AddOption("Superskalarna", -1);
	exam.push_back(q60);

	Question q61("Koi ot izbroenite osobenosti harakterizirat predimstwata na VWIL arhitekturata pred ostanalite");
	q61.AddOption("Nito edna ot posochenite", -1);
	q61.AddOption("Implementaciite sa mashinno zawisimi ", 0.25);
	q61.AddOption("Zaemaneto na funkcionalnite ustroistwa se planira ot kompilatora spored poziciqta w instrukcionnite paketi", 0.25);
	q61.AddOption("Kompilatorut generira izcqlo planirat izpulnim kod, w koito lippswat hazarti", 0.25);
	q61.AddOption("Zawisimostite mejdu instrukciite se opredelqt ot kompilaora i se izpolzwat pri planiraneto w syotwetstwie s latentnostite na funkcionalnite ustroistwa", 0.25);
	exam.push_back(q61);

	Question q62("Ako daden proces izpolzwa 8 stranici, kolko reda ima w tablica na stranicite");
	q62.AddOption("16", -1);
	q62.AddOption("2", -1);
	q62.AddOption("23", -1);
	q62.AddOption("8", 1);
	exam.push_back(q62);

	Question q63("Kakwo e prednaznachenito na TLB");
	q63.AddOption("Da minimizira zagubata na burzodeystvie pri tarsene na fizicheskoto razpolojenie na dannite", 1);
	q63.AddOption("Da preobrazuva virtualnite stranichni adresi vuv fizicheski", -1);
	q63.AddOption("Da namali proizvoditelnostta na harduerna implementaciq", -1);
	exam.push_back(q63);

	Question q64("Kakvo sudurja TLB pri stranichna organizaciq na pametta?");
	q64.AddOption("Momentna karta na sustoqnieto na stranicite na operativnata pamet", 1);
	q64.AddOption("Tablica s nomera na fizicheski stranici, prinadlejashti na daden proces", -1);
	q64.AddOption("Tablica s nomera na virtualni stranici, prinadlejashti na daden proces", -1);
	q64.AddOption("Tablica na stranicite na diska", -1);
	exam.push_back(q64);

	Question q65("Koi ot posochenite metodi ne e metod za preobrazuwane na wirtualni adresi");
	q65.AddOption("Metod na stranichna organizaciq", -1);
	q65.AddOption("Metod na segmentno-stranichna organizaciq", -1);
	q65.AddOption("Metod na segmentna organizaciq", -1);
	q65.AddOption("Metod na lokalnostta(po wreme i pprostranstwo)", 1);
	exam.push_back(q65);

	Question q66("Kolko e maksimalniq broi stranici s razmer 4K ppri 32 bitow adres");
	q66.AddOption("5K", -1);
	q66.AddOption("20K", -1);
	q66.AddOption("64K", -1);
	q66.AddOption("1M", 1);
	exam.push_back(q66);

	Question q67("Pri razmer na stranicite 8 baita i 8 bitow adres, kolko e maksimalniq broi stranici");
	q67.AddOption("512", -1);
	q67.AddOption("32", 1);
	q67.AddOption("16", -1);
	q67.AddOption("64", -1);
	q67.AddOption("4K", -1);
	exam.push_back(q67);

	Question q68("Koq ot izbroenite harakteristiki ne opisva tablicata na stranicite?");
	q68.AddOption("Tablicata na stranicite se sustoi ot redove, vseki red ot tablicata suotvetstva na nomer na virtualna stranica", -1);
	q68.AddOption("Tablicata na stranicite sudurja informaciq za aktivnite procesi", 1);
	q68.AddOption("Tablicata na stranicite e dopulnena s bit za prisustvie, pokazvasht dali suotvetnata stranica se namira v svobodnata pamet", -1);
	q68.AddOption("Tablicata na stranicite se pazi nqkude v operativnata pamet", -1);
	exam.push_back(q68);

	Question q69("Pri razmer na stranicite 8 baita, na koi red w tablicata na stranicite se sydyrja adresyt na stranicata, koqto sydyrja adres 18 ot pametta(redowete se broqt ot 1)");
	q69.AddOption("5", -1);
	q69.AddOption("7", -1);
	q69.AddOption("1", -1);
	q69.AddOption("2", -1);
	q69.AddOption("3", 1);
	exam.push_back(q69);

	Question q70("Pri razmer na stranicite 8 baita, na koi red w tablicata na stranicite se sydyrja adresyt na stranicata, koqto sydyrja adres 12 ot pametta(redowete se broqt ot 1)");
	q70.AddOption("5", -1);
	q70.AddOption("7", -1);
	q70.AddOption("1", -1);
	q70.AddOption("2", 1);
	q70.AddOption("3", -1);
	exam.push_back(q70);

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
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
