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
	std::cout << "Izpit po SARS\nIzgotven ot Mapmo, M. i Dakata, redakciq ot tantanita\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question r34("Koe ot slednite ne e primer za arhitekturen pohvat za postigane na nadejdnost v softuernite\nsistemi?\nIzberete edno");
	r34.AddOption("Shared Bus", 1);
	r34.AddOption("Izlishyk (redundancy)", -1);
	r34.AddOption("N-Version programming", -1);
	r34.AddOption("Heartbeat (Keepaive)", -1);
	exam.push_back(r34);

	Question r33("Arhitektirniqt stil Circuit Breaker\nIzberete Edno");
	r33.AddOption("Znachitelno podobrqva izmenqemostta na sistemata", -1);
	r33.AddOption("Podobrqva samo nadejdnostta na sistemata", 1);
	r33.AddOption("Podobrqva nadejdnostta i proizvoditelnostta na sistemata", -1);
	r33.AddOption("Namalqva znachitelno izmenqemostta na sistemata", -1);
	exam.push_back(r33);

	Question r32("Shablonyt fasada se izpolzva pri neobhodimost ot uvelichavane na byrzodeystvieto na programata");
	r32.AddOption("True", -1);
	r32.AddOption("False", 1);
	exam.push_back(r32);

	Question r31("Koe ot izbroenite ne vliqe vurhu izbora na arhitekturni taktiki\nIzberete edno");
	r31.AddOption("Bydeshti planove za razvitie na organizaciqta", 1);
	r31.AddOption("Broqt i kvalifikaciqta na nalichnite razrabotchici", -1);
	r31.AddOption("Kvalifikaciqta na manager-a na proekta", -1);
	r31.AddOption("Nalichie na legacy software", -1);
	exam.push_back(r31);

	Question r30("V stilyt neqvno izvikvane (implicit invocation) komponentite vzaimodejstvat pomejdu si chrez:\nIzberete edno");
	r30.AddOption("Izprashtane na t.nar sybitiq, pri koito izprashtashtiq komponent ne znae nishto za poluchatelq", 1);
	r30.AddOption("Izvikvane na metod, pri koeto izprashtashtiq komponent izchakva za otgovor, predi da prodylji sys svoeto izpylnenie", -1);
	r30.AddOption("Izprashtane na t.nar sybitiq, pri koito izprashtashtiq komponent ima informaciq za poluchatelq", -1);
	exam.push_back(r30);

	Question r29("Koe ot slednite tvyrdeniq e vqrno za stila kanal-filter (pipe and fileter)\nIzberete edno");
	r29.AddOption("V tozi arhitekturen stil nqma syedinitelni moduli", -1);
	r29.AddOption("Tozi stil ne se preporychva pri razrabotka na sistemi, koito obrabotvat razlichni po format danni", 1);
	r29.AddOption("Komponentite v stila kanal-filter se realizirat samo na ezika Java", -1);
	r29.AddOption("Vseki modul (komponent) v sistemata predava dannite v proizvolen red na sledvashtiq komponent", -1);
	exam.push_back(r29);

	Question r28("Kakvo predstavlqvat arhitekturnite drivers ot gledna tochka na procesa na proektirane \nIzberete edno");
	r28.AddOption("Vryzka mejdu arhitekturata na sistemata i realizaciqta i", -1);
	r28.AddOption("Sredstvo za ulesnqvane na proektiraneto na softuerna arhitektura", -1);
	r28.AddOption("Iziskvaniqta kym sistemata, koito imat nay-visok prioritet", 1);
	r28.AddOption("Nay-vajnite tehnologii, koito shte bydat izpolzvani", -1);
	exam.push_back(r28);

	Question r27("Broqt na strukturite, koito shte bydat vklucheni v dokumentaciqta na softuernata arhitektura\nzavisi ot\nIzberete edno ili poveche");
	r27.AddOption("Vidyt na zainteresovanite lica", 0.5);
	r27.AddOption("Softuertnata sistema", -1);
	r27.AddOption("Prilojnata oblast, kydeto shte se vnedrqva softuernata sistema", 0.5);
	r27.AddOption("Kodyt na sistemata", -1);
	exam.push_back(r27);

	Question r26("Koi ot slednite moje da harakterizirat nadejdnost na sistemata\nIzberete edno ili poveche");
	r26.AddOption("Procent uspeshni izvikvaniq", 0.5);
	r26.AddOption("Veroqtnost za otkaz", 0.5);
	r26.AddOption("Latentnost", -1);
	r26.AddOption("Vreme za izpylnenie", -1);
	exam.push_back(r26);

	Question r25("Koe ot slednite tvyrdeniq ne e vqrno po otnoshenie na nefunkcionalnite iziskvaniq (NFI)\nIzberete edno");
	r25.AddOption("NFI sa chesto protivorechivi i se nalaga da se pravqt kompromisi mejdu tqh", -1);
	r25.AddOption("NFI si vliqqt s iziskvaniqta po funkcionalnostta na sistemata", -1);
	r25.AddOption("NFI trqbva da se balansirat sprqmo interesite na zainteresovanite lica", -1);
	r25.AddOption("NFI ne sa opredelqshti za dekompoziciqta na modulite na sistemata", 1);
	exam.push_back(r25);

	Question r24("Spored vas primer za dobre napravena dekompoziciq na modulite li e pokazanata diagrama\n(3 modula computation, communication, processing)\nIzberete edno");
	r24.AddOption("True", -1);
	r24.AddOption("False", 1);
	exam.push_back(r24);

	Question r23("Sigurnost i otkazoustoichivost (fault tolerance) sa dve nefunkcionalni harakteristiki,\nkoito chesto si protivorechat\nIzberete edno");
	r23.AddOption("True", 1);
	r23.AddOption("False", -1);
	exam.push_back(r23);

	Question r22("Sofuernata arhitektura ne e\nIzberete edno");
	r22.AddOption("Abstraktno opisanie na sistemata ot razlichnite gledni tochki, koeto zasqga minimalen broy ot zainteresovanite lica", 1);
	r22.AddOption("Dokument, v koyto lipsvat podrobnosti za koda na sistemata", -1);
	r22.AddOption("Model na upravlenieto na procesite v sistemata", -1);
	r22.AddOption("Syvkupnost ot predstavqne na sistemata ot razlichni gledni tochki", -1);
	exam.push_back(r22);

	Question r21("V stila client-server komponentite vzaimodeystvat pomejdu si chrez izprashtane na\nsyobshteniq(ili izvikvane na metod) pri koeto izprashtashtiq komponent ne znae nishto za poluchatelq?\nIzberete edno");
	r21.AddOption("True", 1);
	r21.AddOption("False", -1);
	exam.push_back(r21);

	Question r20("Koe ot slednite tvyrdeniq e nevqrno\nIzberete edno");
	r20.AddOption("Pri mnogosloyniq arhitekturen stil interface opredelqt protokol za vzaimodeystvie mejdu nivata", -1);
	r20.AddOption("Za da se priloji mnogosloyniq arhitekturen stil se iziskva specializiran hardware", 1);
	r20.AddOption("Mrejoviqt model na OSI e proektiran spored principite na mnogosloyniq arhitekturen stil", -1);
	r20.AddOption("Pri mnogosloyniq arhitekturen stil, vsqko nivo predostavq interface na nivoto pod nego\ni izpolzva interface na nivoto tochno nad nego", -1);
	exam.push_back(r20);

	Question r19("V arhitekturniq stil shared-data:\nIzberete edno");
	r19.AddOption("Nito edin ot posochenite otgovori ne e veren", -1);
	r19.AddOption("Lesno se realizira paraleno izlyplenie na procesite, koito obrabotvat dannite", -1);
	r19.AddOption("Vsichki uchastvashti komponenti imat vyzmojnost za dostyp do spodeleni danni", 1);
	r19.AddOption("Dannite se izprashtat ednovremenno do vsichki uchastvashti komponenti", -1);
	exam.push_back(r19);

	Question r18("Moje li da se tvyrdi sys sigurnost, che izpolzvaneto na replikaciq na sistemata\nili chasti ot neq, s cel osigurqvane na nadejdnost, vliqe otricatelno na sigurnostta\nIzberete edno");
	r18.AddOption("Da", -1);
	r18.AddOption("Ne", -1);
	r18.AddOption("Zavisi", 1);
	exam.push_back(r18);

	Question r17("Spored definiciqta softuernata arhitektura predstavlqva nabor ot strukturi.\nV tazi vryzka moje li da se kaje, che dekompoziciqta na moduli e arhitektura na sistemata\nIzberete edno");
	r17.AddOption("True", -1);
	r17.AddOption("False", 1);
	exam.push_back(r17);

	Question r16("Dokumentaciqta na softuernata arhitektura:\nIzberete edno ili poveche");
	r16.AddOption("Vkluchva kolkoto e vyzmojno poveche strukturi", -1);
	r16.AddOption("Vkluchva kolkoto e vyzmojno po-malko strukturi", -1);
	r16.AddOption("Vkluchva opredeleni strukturi, v zavisimost ot samata sistema i tova koy shte chete dokumentaciqta", 0.5);
	r16.AddOption("Vkluchva opisanie na strukturite na arhitekturata plus pridrujavashti dokumenti", 0.5);
	exam.push_back(r16);

	Question q1("Koi ot slednite sa primer za dobre formuliran scenarii za kachestvo?\nIzberete edno 1 ili poveche");
	q1.AddOption("Dopustimo e sistemata da e v rejim na poddrujka za ne poveche ot 3 chasa sedmichno", 0.5);
	q1.AddOption("Potrebitelqt vliza v sistemata, izbira opciqta za tursene I vuvejda operedelen simvolen niz", -1);
	q1.AddOption("Promeni v sistemata da se pravqt vyzmojno nai-byrzo", -1);
	q1.AddOption("Otgovoryt na potrebitelskite zaqvki trqbva da stane do 30 sec", 0.5);
	exam.push_back(q1);

	Question q2("Smisulut na nefukcionalnite iziskvaniq kum sistemata e\nIzberete edno");
	q2.AddOption("Da se ulesni razrabotkata na sistemata", -1);
	q2.AddOption("Da se izpolzvat nai-suvremennite tehnologii I programni ezici", -1);
	q2.AddOption("Da se namali cenata na razrabotka na softuerna sistema", -1);
	q2.AddOption("Da se ytochni po kakuv nachin I pri kakvi ysloviq shte raboti sistemata", 1);
	exam.push_back(q2);

	Question q3("V 4+1 modela na softuerna arhitektura izgledut na procesi pokazva kak sistemata se dokompozira na\nsustavni softuerni elementi(modyli)");
	q3.AddOption("Istina", -1);
	q3.AddOption("Luja", 1);
	exam.push_back(q3);

	Question q4("Pod proizvoditelnost v softuernite sistemi se razbira\nIzberete edno");
	q4.AddOption("Vuzmojnost na sistemata da osiguri rabota bez otkaz", -1);
	q4.AddOption("Vremeto, za koeto sistemata reagira na vuznikvashti subitiq", 1);
	q4.AddOption("Mqrka za sebestoinostta na promenite v sistemata", -1);
	q4.AddOption("Vuzmojnost na potrebitql burzo da ovladee sistemata", -1);
	exam.push_back(q4);

	Question q5("V koi ot slednite redove e dopusnata greshka?\nIzberete edno");
	q5.AddOption("Vuzdeistvie, algorithm, iztochnik sa elementi na scenarii na kachestvo", 1);
	q5.AddOption("Vuzdeistvie, kolichestveni parametri, kontekst sa elementi na scenarii na kachestvo", -1);
	q5.AddOption("Vuzdeistvie, rezultat, iztochnik sa elementi na scenarii na kachestvo", -1);
	q5.AddOption("Vuzdeistvie, obekt, iztochnik sa elementi na scenarii na kachestvo", -1);
	exam.push_back(q5);

	Question q6("Proektiraneto na softuerna arhitektura e iterativen proces");
	q6.AddOption("True", 1);
	q6.AddOption("False", -1);
	exam.push_back(q6);

	Question q7("Cost Benefit Analysis Method(CBAM) e proces pri koito:\nIzberete edno");
	q7.AddOption("se opredelqt nai-vajnite iziskvaniq kum dokymentaciqta na arhitekturata", -1);
	q7.AddOption("nito edno ot izbroenite ne e vqrno", 1);
	q7.AddOption("se ocenqva proizvoditelnostta na sistemata", -1);
	q7.AddOption("se proverqva dali proektiranta veche architektura udovletvorqva postavenite iziskvaniq", -1);
	exam.push_back(q7);

	Question q8("Pri kakuv tip sistemi e nai-podhodqshto da se izpolzva stryktyrata na vnedrqvaneto\nIzberete edno");
	q8.AddOption("Koito se izpylnqvat na edna mashina", -1);
	q8.AddOption("Sistemi s mnogo potrebiteli", -1);
	q8.AddOption("Nito edin ot posochenite", -1);
	q8.AddOption("Koito se izpulnqvat v cloud", 1);
	exam.push_back(q8);

	Question q9("Architektyrniq stil predstavlqva\nIzberete edno");
	q9.AddOption("Obektno oprientiran model na softuernata sistema", -1);
	q9.AddOption("Opisanie na softuernata arhitektura", -1);
	q9.AddOption("Tipovo arhitekturno reshenie, koeto se dokazalo pri upotreba v konkretni sityacii", 1);
	q9.AddOption("Model za prehod ot softuerna arhitektura kym kod", -1);
	exam.push_back(q9);

	Question q10("Pri proektiraneto na arhitekturata moje da se ogranichi broq na modyli, s koito daden komponent\nkomunikira, za da se:\nIzberete edno");
	q10.AddOption("ogranichi neobhodimostta ot promeni s drugi moduli, s koito dadeniqt komunikira", 1);
	q10.AddOption("namali slovnostta na sistemata I da se yskori procesa na razrabotka", -1);
	q10.AddOption("napravi arhitekturata po-qsna i da se razbira ot vsichki zainteresovani lica", -1);
	q10.AddOption("ne se prilaga takava taktika", -1);
	exam.push_back(q10);

	Question q11("Stuktura na procesite:");
	q11.AddOption("Posochva zadyljeniqta na otdelnite zainteresovani lica", -1);
	q11.AddOption("Pokazwa posledovatelnostta na izpulnenie na otdelnite komponenti v sistemata", 1);
	q11.AddOption("E izgotven ot manager-a na proekta dokument, koito naznachava zadachite\nna ostanlite uchastnici v razrabotkata na proekta", -1);
	q11.AddOption("Pokazva abstraktni grupi ot hora, koito realizirat modulite na sistemata", -1);
	exam.push_back(q11);

	Question q12("Koe ot slednite ne e vqrno za arhitektyren stil Pipe-Filter:\nIzberete edno");
	q12.AddOption("Ima trudnosti pri realizaciqta na interaktivni prilojeniq", -1);
	q12.AddOption("Vodi do prosti za proektirane I realizaciq arhitekturi", -1);
	q12.AddOption("Nqma vyzmojnost za paralelna obrabotka na informaciqta", 1);
	q12.AddOption("Strukturata mu e identichna sys strukturata na povecheto standartni biznes procesi w organizaciite", -1);
	exam.push_back(q12);

	Question q13("V softuernata arhitektura e redno da se opisvat swoistva I metodi na klasovete,\nkoito izgrajdat obektite v sistemata");
	q13.AddOption("True", -1);
	q13.AddOption("False", 1);
	exam.push_back(q13);

	Question q14("V koi ot slednite deynosti e redno da vzimat uchastie softuernite arhitekti?\nIzberete edno ili poveche");
	q14.AddOption("Opredelqne na algoritmite za razabotka na sistemata", -1);
	q14.AddOption("Razrabotka na sistemata", 0.25);
	q14.AddOption("Utochnqvane na iziskvaniqta kym softuernata sistema", 0.25);
	q14.AddOption("Proektirane na arhitekturata", 0.25);
	q14.AddOption("Izgotvqne na biznes plan na proekta", 0.25);
	exam.push_back(q14);

	Question b1("Koi ot slednite sa primer za dobre formuliran scenarii za kachestvoto");
	b1.AddOption("Sistemata za avtomatichna blokirovka trqbwa da prekysne zahranvaneto kym manipulatora\n naj-mnogo za 20ms sled registriraneto na temperatura, po-golqma ot 50 gradusa", 0.5);
	b1.AddOption("Avtimatichnata wtara trqbwa da spe dwivenieto si ne po-kysno ot 0.3 sek sled otkriwane na prepqdstwie", 0.5);
	b1.AddOption("Pri otvarqne na file, antivirusnata programa trqbva da go proveri vyzmozhno nai-byrzo.", -1);
	b1.AddOption("Sistemata trqbva da e sigurna", -1);
	exam.push_back(b1);
	
	Question b2("Sofuernata arhitektura ne e\nIzberete edno");
	b2.AddOption("Model na strukturata za upravlenie na softuernata kompaniq", 1);
	b2.AddOption("Abstrakciq, koqto skriva detailite po realizaciqta na programite", -1);
	b2.AddOption("Dokument, koito mozhe da podobri organizatsiqta na rabota v softuernata kompaniq", -1);
	b2.AddOption("Syvkupnost ot predstavqne na sistemata ot razlichni gledni tochki", -1);
	exam.push_back(b2);
		
	Question b3("Koe ot slednite tvyrdeniq ne e vqrno po otnoshenie na NeFunkcionalnite iziskvaniq (NFI)?\nIzberete edno:");
	b3.AddOption("NFI sa chesto protivorechivi i se nalaga da se pravqt kompromisi mezhdu tqh.", -1);
	b3.AddOption("NFI si vliqqt s iziskvaniqta po funkcionalnostta na sistemata.", -1);
	b3.AddOption("NFI trqbva da se balansirat sprqmo interesite na zainteresovanite lica.", -1);
	b3.AddOption("NFI ne sa opredelqshti za dekompoziciqta na sistemata na moduli.", 1);
	exam.push_back(b3);

	Question b4("Koi ot slednite mozhe da harakterizirat proizvoditelnost na sistemata?\nIzberete edno ili poveche:");
	b4.AddOption("Vreme za izpylnenie", 0.5);
	b4.AddOption("Veroqtnost za otkaz", -1);
	b4.AddOption("Sredno vreme za vyzstanovqvane", -1);
	b4.AddOption("Latentnost", 0.5);
	exam.push_back(b4);

	Question b5("Izboryt na strukturi, koito shte bydat vkliucheni v dokumentaciqta na softuernata arhitektura zavisi ot:\nIzberete edno ili poveche:");
	b5.AddOption("Prilozhnata oblast, kydeto shte se vnedrqva softuernata sistema", 0.5);
	b5.AddOption("Nefunkcionalnite iziskvaniq (kachestvenite harakteristiki)", -1);
	b5.AddOption("Broqt na zainteresovanite litsa", -1);
	b5.AddOption("Konkretnite zainteresovani litsa, koito shte chetat dokumentaciqta", 0.5);
	exam.push_back(b5);

	Question b6("Kakvo predstavlqvat arhitekturnite driveri ot gledna tochka na procesa na proektirane?");
	b6.AddOption("Nai-vazhnite tehnologii, koito shte bydat izpolzvani.", -1);
	b6.AddOption("Vryzka mezhdu arhitekturata na sistemata i neinata realizaciq.", -1);
	b6.AddOption("Sredstvo za ulesnqvane na proektiraneto na softuernata arhitektura.", 1);
	exam.push_back(b6);

	Question b7("Spored teoriqta v strukturata na konkurentnoto izpylnenie sa komponenti i nishki (logical threads) sinhronizacionniteni\nkomunikacionni vryzki mezhdu tqh. Za kakvo mozhe da se izpolzva tazi struktura?");
	b7.AddOption("Za opredelqne na harduernite iziskvaniq na sistemata", -1);
	b7.AddOption("Za razpredelqne na rabotata po implementaciqta na sistemata mezhdu razlichnite ekipi", -1);
	b7.AddOption("Za otsenqvane na nefunkcionalnite harakteristiki na sistemata", -1);
	b7.AddOption("Za analiz na vzaimodeistvieto mezhdu procesite i predotvratqvane na blokirovki (deadlocks)", 1);
	exam.push_back(b7);

	Question b8("Softuerniqt arhitekt raboti nezavisimo ot ostanalite zainteresovani lica");
	b8.AddOption("True", -1);
	b8.AddOption("False", 1);
	exam.push_back(b8);

	Question b9("Pod izpitaemost (testability) w softuernata sistema se razbira:");
	b9.AddOption("Vremeto, za koeto sistemata reagira na vyznikvashtite sybitiq", -1);
	b9.AddOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz", -1);
	b9.AddOption("Lekota pri otkrivane na greshki v softuera", 1);
	b9.AddOption("Mqrka za sebestoinostta na promenite v sistemata", -1);
	exam.push_back(b9);

	Question b10("Arhitekturniqt rechnik i obosnovkata na arhitekturnite resheniq sa nerazdelna chast ot dokumentatsiqta na softuernata arhitektura.");
	b10.AddOption("da", 1);
	b10.AddOption("ne", -1);
	exam.push_back(b10);

	Question b11("Pod sigurnost (security) v softuernite sistemi se razbira:");
	b11.AddOption("Vyzmozhnost na sistemata da osiguri rabota bez otkaz", -1);
	b11.AddOption("Mqrka za sposobnostta na sistemata da ustoqva na opiti za nerazreshena upotreba bez tova da prechi na registriranite potrebiteli", 1);
	b11.AddOption("Mqrka za sebestoinostta na promenite v sistemata", -1);
	b11.AddOption("Uverenost v uspeshnoto izpylnenie na proekta", -1);
	exam.push_back(b11);

	Question b12("Izlishykyt (redundancy) kato taktika za postigane na izmenqemost predstavlqva:");
	b12.AddOption("Osigurqvane na dopylnitelni resursi s cel uspeshen zavyrshek na proekta.", -1);
	b12.AddOption("Osigurqvane na dopylnitelni kopiq na otdelni moduli na sistemata.", -1);
	b12.AddOption("Nqma takava taktika za postigane na izmenqemost.", 1);
	exam.push_back(b12);

	Question b13("Kontrolnite tochki (checkpoint) kato taktika za postigane na gotovnost (availability)\npredstavlqvat celenasocheno izprashtane na signal mezhdu dva modula s cel ediniqt da se uveri, che drugiqt e aktiven.");
	b13.AddOption("True", -1);
	b13.AddOption("False", 1);
	exam.push_back(b13);

	Question b14("Chrez izpolzvaneto na obvivki (posrednik/mediator/wrapper) pri proektirane na softuerna arhitektura ne se podobrqva izmenqemostta na sistemata,\nno ima vyzmozhnost za povishavane na sigurnostta.");
	b14.AddOption("True", -1);//ghub
	b14.AddOption("False", 1);//ili tova ot docs
	exam.push_back(b14);

	Question b15("Koi ot slednite metodi mozhe da se prilozhat za povishavane na proizvoditelnostta na sistemata?\nIzberete edin ili poveche");
	b15.AddOption("Podobrqvane na algoritmite", 0.34);
	b15.AddOption("Vyvezhdane na obvivni moduli", -1);//spored docss e greshno
	b15.AddOption("Promqna na perioda (pri sinhronni sistemi)", -1);
	b15.AddOption("Vyvezhdane na opashka s kraen razmer", 0.33);
	b15.AddOption("Uvelichavane na broq na modulite v sistemata", -1);
	b15.AddOption("Vkliuchvane na dopylnitelni resursi", 0.33);
	exam.push_back(b15);

	Question b16("Osnovnoto predimstvo pri t.nar. otlagane na svyrzvaneto (finalnata integratsiq na sistemata se pravi pri potrebitelq) e:");
	b16.AddOption("povishava se izmenqemostta na sistemata.", -1);//ili tova ot docs
	b16.AddOption("povishava se sigurnostta na sistemata.", -1);
	b16.AddOption("ulesnqva se rabotata na krainite potrebiteli.", -1);
	b16.AddOption("namalqva se tsenata na razrabotka.", 1);//ghub
	exam.push_back(b16);

	Question b17("Nai-podhodqshtiqt podhod za proektirane na softuerna arhitektura e\nda se zapochne ot iziskvaniqta kym kachestvoto na sistemata (nefunkcionalnite iziskvaniq).");
	b17.AddOption("False", -1);
	b17.AddOption("True", 1);
	exam.push_back(b17);

	Question b18("S kakvo zapochva realizatsiqta na softuernata sistema?\n(2 verni otgovora)");
	b18.AddOption("Osnovnite komponenti, koito realizirat protokolite na vzaimodeistvie (middleware).", 0.5);
	b18.AddOption("Sys specifichnite nai-chesto izpolzvani metodi za obrabotka na informaciqta.", 0.5);
	b18.AddOption("Realizirat se pyrvo interfeisite na komponentite.", -1);
	exam.push_back(b18);

	Question b19("Analizyt na softuerni arhitekturi e proces, pri koito:");
	b19.AddOption("se proverqva dali proektiranata veche arhitektura udovletvorqva postavenite iziskvaniq.", 1);
	b19.AddOption("se ocenqva proizvoditelnostta na sistemata.", -1);
	b19.AddOption("se opredelqt nai-vazhnite iziskvaniq kym arhitekturata.", -1);
	exam.push_back(b19);

	Question b20("Analizyt na softuerni arhitekturi vkliuchva razlichni fazi, sreshti i razgovori mezhdu zainteresovanite lica i ocenqvasht ekip.");
	b20.AddOption("True", 1);
	b20.AddOption("False", -1);
	exam.push_back(b20);

	Question b21("Koe ot slednite ne e vqrno:");
	b21.AddOption("V ATAM vzimat uchastie vsichki zainteresovani lica.", -1);
	b21.AddOption("ATAM ocenqva dokolko kodyt na sistemata otgovarq na arhitekturata.", 1);
	b21.AddOption("Razkriva do kakva stepen arhitekturata udovletvorqva kachestvenite iziskvaniq.", -1);
	b21.AddOption("Ne dava ocenka na biznes polzata ot sistemata.", -1);
	exam.push_back(b21);

	Question b23("Proektiraneto na softuernata arhitektura zapochva sled analiza na softuernite iziskvaniq.");
	b23.AddOption("True", 1);
	b23.AddOption("False", -1);
	exam.push_back(b23);
	/*
	Question r1("\nIzberete edno");
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	exam.push_back(r1);
	*/

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
