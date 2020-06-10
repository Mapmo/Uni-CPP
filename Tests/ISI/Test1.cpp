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
	std::cout << "Test 1 po ISI\nIzgotven ot Mapmo\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Ocenkata e osnoven proces v softuernata ikonomika, koito vodi do:");
	q1.AddOption("Postigane na po-dobra proizvoditelnost na baza osnovni faktori za uspeh", 1);
	q1.AddOption("Identifikaciq na harakteristiki i funkcionalni elementi na produkta", -1);
	q1.AddOption("Opredelqne na jizneniq cikul i kriteriite za priemane na produkta", -1);
	q1.AddOption("Definiciq na goleminata na produkta i faktorite za uspeh na produkta", -1);
	exam.push_back(q1);

	Question q2("Pri koq tehnika za ocenka elementite imat svoy unikalen identifikacionen nomer");
	q2.AddOption("WBS", 1);
	q2.AddOption("Parkinson", -1);
	q2.AddOption("Time boxing", -1);
	q2.AddOption("COCOMO", -1);
	exam.push_back(q2);

	Question q3("Web dizainer tvurdi che tvorcheskata mu rabota ne moje da byde ocenena. Reshavate da izpolzvate kato baza opit ot drug proekt. Kak se naricha tova?");
	q3.AddOption("Ocenka na analogiqta", 1);
	q3.AddOption("Ocenka na razhodite", -1);
	q3.AddOption("Ocenka na budjeta", -1);
	q3.AddOption("Finansova ocenka", -1);
	exam.push_back(q3);

	Question q4("Razmerut na purvonachalnata investiciq se vkluchva v koy finansov model");
	q4.AddOption("NPV", 1);
	q4.AddOption("PV", -1);
	q4.AddOption("BCR", -1);
	q4.AddOption("IRR", -1);
	exam.push_back(q4);

	Question q5("Kato chast ot inicializaciqta na proekta trqbva da se napravi:");
	q5.AddOption("Ocenka na alternativite chrez izpolzvane na finansovi i nefinansovi metodi", 1);
	q5.AddOption("Izbor na standartni resheniq na bazata na ikonomicheski metodi", -1);
	q5.AddOption("Ocenka na mnojestvo finansovi	i nefinansovi kriterii za planirane na prdukta", -1);
	q5.AddOption("Ocenka na neobhodimoto dopulnitelno finansirane za startirane na proekta", -1);
	exam.push_back(q5);

	Question q6("Softuernata ikonomika e tazi oblast, koqto");
	q6.AddOption("Tursi seriozni podobreniq v SW dizayn i SW injenerstvo chrez prilagane na ikonomicheska logika", 1);
	q6.AddOption("Identificira osnovnite finansovi parametri na proekta", -1);
	q6.AddOption("Opredelq i organizira izpulnenieto na finansoviq  resurs po proekta", -1);
	q6.AddOption("Ocenqva budjeta na proekta i razhodite po zadachite", -1);
	exam.push_back(q6);

	Question q7("Parichniqt potok se izrazqva chrez");
	q7.AddOption("Prihodite ot rezultatite na proekta i razhodite na proekta", 1);
	q7.AddOption("Prihodite i razhodite na softuerniq produkt sravneni s tqhnata segashna parichna stoynost", -1);
	q7.AddOption("Razhodite za suzdavane na softuera", -1);
	q7.AddOption("Prihodite ot softuerniq proekt", -1);
	exam.push_back(q7);

	Question q8("Proektat e vyv faza inicializaciq. Trqbva da se napravi optimalno predlojenie na sponsora. Koy finansov metod shte se izpolzva?");
	q8.AddOption("PV", 1);
	q8.AddOption("EV", -1);
	q8.AddOption("PERT", -1);
	q8.AddOption("Gantt", -1);
	exam.push_back(q8);

	Question q9("Osnovnite ogranichiteli na proekta sa:");
	q9.AddOption("Obhvat, vreme, razhodi", 1);
	q9.AddOption("Vreme, resurisi, pari", -1);
	q9.AddOption("Kachestvo, budjet, obhvat", -1);
	q9.AddOption("Kkachestvo, cena, resursi", -1);
	exam.push_back(q9);

	Question q10("Proektat e");
	q10.AddOption("Vremenno nachinanie s cel da se syzdade unikalen produkt ili usluga", 1);
	q10.AddOption("Proces s golqm obhvat i detaylen plan", -1);
	q10.AddOption("Grupa ot fazi, koordinirani i upravlqvani za postigane na opredelena cel", -1);
	q10.AddOption("Grupa ot planirani zadachi s opredeleno nachalo i kray", -1);
	exam.push_back(q10);

	Question q11("Harakteristika na fazite na proekta e");
	q11.AddOption("Kontrolni tochki (milestones)", 1);
	q11.AddOption("Dostavki", -1);
	q11.AddOption("Kachestveno izpulnenie na fazata", -1);
	q11.AddOption("Plan na fazata", -1);
	exam.push_back(q11);

	Question q12("Obshto rabotata na proekta e ocenena na 90 ch/dni na bazata na sumirane na zadachite po kodirane i testvane. Te sled tova sa oceneni na po 30 choveka/dni Kakav podhod e realiziran?");
	q12.AddOption("Otgore nadolu (Top down)", 1);
	q12.AddOption("Otdolu nagore (Bottom up)", -1);
	q12.AddOption("Parametrichen", -1);
	q12.AddOption("Eksperten", -1);
	exam.push_back(q12);

	Question q13("WBS se realizira chrez");
	q13.AddOption("Obhvat na proekta", -1);
	q13.AddOption("Dekompoziciq na rabotata", 1);
	q13.AddOption("Obhvat na zadachite", -1);
	q13.AddOption("Grafika na proekta", -1);
	exam.push_back(q13);

	Question q14("Primer za proekt e");
	q14.AddOption("Dizain na nov softueren produkt", 1);
	q14.AddOption("Upravlenie na softuerna firma", -1);
	q14.AddOption("Tehnichesko poddurjane na sistemite", -1);
	q14.AddOption("Finansirane na softuerni produkti", -1);
	exam.push_back(q1);

	Question q15("Koeficient prihod/razhod e metod za ocenka za");
	q15.AddOption("Vuzvrashtaemost na proekta", 1);
	q15.AddOption("NPV na prihodite/razhodite na proekta", -1);
	q15.AddOption("Period za vuzvrashtaemost na investiciqta", -1);
	q15.AddOption("Vutreshna norma za vuzvrashtaemost", -1);
	exam.push_back(q15);

	Question q16("Metrikata za ocenka na goleminata na produkta ocenqva");
	q16.AddOption("Razhodite za trud na chovek/den", -1);
	q16.AddOption("Broq na interface i tqhnata slovnost", 1); //idiotat kaza che tova e vqrnoto prez 2019
	q16.AddOption("Neobhodimiq trud na chovek/den", -1);
	q16.AddOption("Proizvoditelnostta za chovek/den", -1);
	exam.push_back(q16);

	Question q17("Grupa eksperti ocenqvat suzdavaneto na daden produkt bez da se konsultirat pomejdu si, kogato se izpolzva koy metod za ocenka");
	q17.AddOption("Delfi", 1);
	q17.AddOption("Po analogiq", -1);
	q17.AddOption("Funkcionalni tochki", -1);
	q17.AddOption("Parametrichen", -1);
	exam.push_back(q17);

	Question q18("Vsichki definirani razhodi po proekta opredelqt");
	q18.AddOption("Budjeta na proekta", 1);
	q18.AddOption("Budjeta na produkta", -1);
	q18.AddOption("Investiciqta za suzdavane na reshenieto", -1);
	q18.AddOption("Cenata na proekta", -1);
	exam.push_back(q18);

	Question q19("Celta na proekta e");
	q19.AddOption("Da se suzdade unikalen produkt ili usluga", 1);
	q19.AddOption("Da se postigne opredeleno kachestvo za potrebitelq", -1);
	q19.AddOption("Da se izpulni v srok i v grafik", -1);
	q19.AddOption("Da se napravqt po-malko razhodi za po-visoka efektivnost", -1);
	exam.push_back(q19);

	Question q20("Proektite trqbva da sa izcqlo podchineni na realizaciqta na");
	q20.AddOption("Biznes celi", 1);
	q20.AddOption("Tehnologichni celi", -1);
	q20.AddOption("Moralni celi", -1);
	q20.AddOption("Izsledovatelski celi", -1);
	exam.push_back(q20);

	Question q21("Ekipat za razrabotka na softuer ima samo 2 sedmici i se sustoi ot 2 programista za syzdavane na prototip na sistema. Te shte sprat rabota sled 2 sedmici bez znachenie ot rezultata. Tova e");
	q21.AddOption("Ocenka chrez interval ot vreme", 1);
	q21.AddOption("Algoritmichna ocenka", -1);
	q21.AddOption("Parametrichna ocenka", -1);
	q21.AddOption("Ocenka chrez analogiq", -1);
	exam.push_back(q21);

	Question q22("Osnovna vhodna informaciq za ocenka i planirane na resursite na edin proekt e");
	q22.AddOption("Struktura na rabota na proekta", 1);
	q22.AddOption("Budjeta na proekta", -1);
	q22.AddOption("Obhvata na softuerniq produkt", -1);
	q22.AddOption("Tehnologichnata baza za razrabotka", -1);
	exam.push_back(q22);

	Question q23("PV izchislqva");
	q23.AddOption("Segashna stoynost na parite", 1);
	q23.AddOption("Netna segashna stoynost na parite", -1);
	q23.AddOption("Segashna norma na pechalbata", -1);
	q23.AddOption("Segashen dohod za otkupuvane", -1);
	exam.push_back(q23);

	Question q24("Broqt na funkciite i interface e metrika");
	q24.AddOption("Funkcionalno orientirana kum softuerniq produkt", 1);
	q24.AddOption("Orientirana kum ocenka na razhodite za suzdavane na softuer", -1);
	q24.AddOption("Orientirana kym goleminata na softuerniq produkt", -1);
	q24.AddOption("Orientirana kum proizvoditelnostta na softuera", -1);
	exam.push_back(q24);

	Question q25("Osnovna cel na softuernoto injenerstvo ot gledna tocha na SW ikonomika e");
	q25.AddOption("Da syzdade maksimalna stojnost za dadena investiciq", 1);
	q25.AddOption("Da oceni optimalno reshenie za izbor na SW", -1);
	q25.AddOption("Da oceni neobhodimiq trud po syzdavane na produkta", -1);
	q25.AddOption("Da oceni razhodite za razrabotka na SW", -1);
	exam.push_back(q25);

	Question w1("Koy metod vodi do preuvelichena ocenka");
	w1.AddOption("Parkinson", 1);
	w1.AddOption("Parametrichen metod", -1);
	w1.AddOption("Po analogiq", -1);
	w1.AddOption("Ekspertno mnenie", -1);
	exam.push_back(w1);

	Question w2("Web dizaner zaqvqva, che negovata rabota e tvorcheska i ne moje da byde fiksirana cena v nachaloto. Reshavate da izpolzvate kato baza dvoyno po-golqma zadacha na podoben proekt. Kak se naricha tova");
	w2.AddOption("Parametrichna ocenka", 1);
	w2.AddOption("Ekspertna ocenka", -1);
	w2.AddOption("Algoritmichna ocenka", -1);
	w2.AddOption("Delfi ocenka", -1);
	exam.push_back(w2);

	Question w3("Koga obiknoveno se inicalizira edin proekt?");
	w3.AddOption("Kogato e identificirana opredelena nujda", 1);
	w3.AddOption("Kogato e identificiran budjet na proekta", -1);
	w3.AddOption("Kogato e realizirana opredelena nujda", -1);
	w3.AddOption("Kogato vuzlojitelqt e predlojil softuerno reshenie", -1);
	exam.push_back(w3);

	Question w6("Strutura za rabota po proekta WBS e");
	w6.AddOption("Grafichno sredstvo, koeto organizira rabotata po proekta v jerarhichna logicheska struktura", 1);
	w6.AddOption("Identifikaciq na osnovnite zadachi i rezultati ot proekta, vkluchitelno upravlenieto", -1);
	w6.AddOption("Reshenie dali syotvetni ocenki za razhodi i vremetraene na zadachite mogat da se napravqt", -1);
	w6.AddOption("Nabor ot logicheski svyrzani zadachi", -1);
	exam.push_back(w6);

	Question w7("Otricatelniqt parichen potok otrazqva");
	w7.AddOption("Razhodite za syzdavane na softuerniq produkt", 1);
	w7.AddOption("Prihodite ot rezultatite na proekta i razhodite na proekta", -1);
	w7.AddOption("Prihodite i razhodite na softuerniq produkt sravneni s tqhnata segash parichna stoynost", -1);
	w7.AddOption("Prihodite ot softuerniq proekt", -1);
	exam.push_back(w7);

	Question w13("Neobhodimata rabota po proekta se opisva v");
	w13.AddOption("Obhvata na proekta", 1);
	w13.AddOption("Obhvata na produkta", -1);
	w13.AddOption("Obhvata na zadachite", -1);
	w13.AddOption("Grafika na proekta", -1);
	exam.push_back(w13);

	Question w14("Primer za proekt e");
	w14.AddOption("Izgrajdane na jileshten blok", 1);
	w14.AddOption("Fakturirane na dostavkite", -1);
	w14.AddOption("Upravlenie na finansov otdel", -1);
	w14.AddOption("Osigurqvane na tehnichesko poddurjane", -1);
	exam.push_back(w14);

	Question w15("Koeficient vytreshna norma na pechalbata (IRR) izrazqva");
	w15.AddOption("Norma na vyzvrashtaemost na proekta", 1);
	w15.AddOption("PV na prihodite/PV na razhodite na proekta", -1);
	w15.AddOption("NPV na prihodite/razhodite na proekta", -1);
	w15.AddOption("Period na vyzvryshtane na investiciqta", -1);
	exam.push_back(w15);

	Question w16("Metrika za ocenqvane na goleminata na softuera moje da e za");
	w16.AddOption("Ocenka na liniite kod", 1);
	w16.AddOption("Ocenka na razhodite", -1);
	w16.AddOption("Ocenka na prihodite", -1);
	w16.AddOption("Ocenka na investiciqta", -1);
	exam.push_back(w16);

	Question w17("Matrica za ocenka na reshenie se izpolzva za:");
	w17.AddOption("Ocenka na alternativite i na optimalnoto reshenie", 1);
	w17.AddOption("Ocenka na razhodite za syzdavane na softuer", -1);
	w17.AddOption("Ocenka na goleminata na softuera", -1);
	w17.AddOption("Ocenka na proizvoditelnostta na softuera", -1);
	exam.push_back(w17);

	Question w25("Modelite \"Analiz na funkcionalnite tochki\" i COCOMO sa osnovno prednaznacheni za");
	w25.AddOption("Ocenka na goleminata na softuerniq produkt", 1);
	w25.AddOption("Ocenka na optimalnoto reshenie za izbor na softuera", -1);
	w25.AddOption("Ocenka na neobhodimiq trud i razhodite po syzdavane na produkta", -1);
	w25.AddOption("Ocenka na funkcionalnostta na softuera", -1);
	exam.push_back(w25);

	Question e1("Algoritmite za ocenka na goleminata na softuera izpolzvat");
	e1.AddOption("Razlichni harakteristiki i funkcionalni elementi na produkta za ocenka na goleminata na produkta", 1);
	e1.AddOption("Harakteristiki i funkcionalni elementi na produkta, koito se opredelqt chrez metoda Delfi", -1);
	e1.AddOption("Ocenka na bazata na matematicheska ekspertiza i parametrizirane na produkta", -1);
	e1.AddOption("Identifikaciq i ocenka na osnovni i vajni za razhodite komponenti, funkcii i procesi", -1);
	exam.push_back(e1);

	Question e2("Koi sa nay-chesto sreshtanite metodi za ocenka");
	e2.AddOption("Parametrichni metodi", -1);
	e2.AddOption("Parkinson", -1);
	e2.AddOption("Po analogiq", 1);
	e2.AddOption("Ekspertno mnenie", -1);
	exam.push_back(e2);

	Question e23("NPV izchislqva");
	e23.AddOption("Segashna stoynost na parite", -1);
	e23.AddOption("Netna segashna stoynost na parite", 1);
	e23.AddOption("Segashna norma na pechalbata", -1);
	e23.AddOption("Segashen dohod za otkupuvane", -1);
	exam.push_back(e23);

	Question e24("Broqt na liniite kod, chrez koito e realiziran programniqt produkt e metrika:");
	e24.AddOption("Orientirana kym goleminata na softuera", 1);
	e24.AddOption("Orientirana kym ocenka na razhodite za syzdavane na softuera", -1);
	e24.AddOption("Funkcionalno orientirana kym softuerniq produkt", -1);
	e24.AddOption("Orientirana kym proizvodstvoto na softuera", -1);
	exam.push_back(e24);

	Question r15("Koeficientat BCR e metod za:");
	r15.AddOption("Ocenka na razhodite na proekta", -1);
	r15.AddOption("Ocenka na prihodite na proekta", -1);
	r15.AddOption("Ocenka na vutreshnata norma za pechalba na proekta", -1);
	r15.AddOption("Ocenka na vuzvrashtaemost na proekta", 1);
	exam.push_back(r15);

	Question r16("IRR izchislqva:");
	r16.AddOption("Netna segashna stoynost na parite", -1);
	r16.AddOption("Golemina na parichniq potok", -1);
	r16.AddOption("Segashe dohod za otkupuvane", -1);
	r16.AddOption("Vutreshna norma na pechalbata", 1);
	exam.push_back(r16);

	Question r17("Koe ne e osnovna informaciq za planirane na proekt:");
	r17.AddOption("Zaetite choveshki resursi", -1);
	r17.AddOption("Znaniq na choveshkite resursi", -1);
	r17.AddOption("Umeniq na choveshkite resursi", -1);
	r17.AddOption("Predpochitaniq na choveshkite resursi", 1);
	exam.push_back(r17);

	Question n1("Obshto rabotata na proekta e ocenena na 100ch/dni i e razppredelena po zadachite po dizajn, kodirane i testvane. Kakyv podhod za ocenka na zadachite e reali?");
	n1.AddOption("Horizontalen", -1);
	n1.AddOption("Vertikalen", -1);
	n1.AddOption("Otdolu nagore Bottom up)", -1);
	n1.AddOption("Otgore nadolu Top down)", 1);
	exam.push_back(n1);
	
	Question n2("Primer za proekt ne e");
	n2.AddOption("Izgrajdaneto na softueren ofis", -1);
	n2.AddOption("Razrabotka na softuer za bankirane", -1);
	n2.AddOption("Syzdavaneto na nova softuerna tehnologiq", -1);
	n2.AddOption("Upravlenie na softueren ofis", 1);
	exam.push_back(n2);
	
	Question n3("Osnowna vhodna informaciq za ocenka i planirane na resursite na edin proekt e");
	n3.AddOption("Budeshtiqt obhvat na softuerniq produkt", -1);
	n3.AddOption("Vremeto za razrabotka", -1);
	n3.AddOption("Tehnologiqta", -1);
	n3.AddOption("WBS", 1);
	exam.push_back(n3);
	
	Question n4("Rezultata ot proekta e");
	n4.AddOption("Nova tehnologiq", -1);
	n4.AddOption("Inovativen produkt", -1);
	n4.AddOption("Vsichko izbroeno po-gore", -1);
	n4.AddOption("Polza ili pechalba", 1);
	exam.push_back(n4);
	
	Question n5("Metrikata za ocenka na goleminata na produkta");
	n5.AddOption("Razhodite za trud na chovek/den", -1);
	n5.AddOption("Proizvoditelnostta na linii kod na den", -1);
	n5.AddOption("Goleminata na razrabotkata v dni", -1);
	n5.AddOption("Broq na podprogramite v softuera", 1);
	exam.push_back(n5);
	
	Question n6("Koeficient IRR e motod za");
	n6.AddOption("Koeficient prihodi - razhodi", -1);
	n6.AddOption("Godishna norma na vyzvrashtaemost", -1);
	n6.AddOption("Mesechna norma na vyzvrashtaemost", -1);
	n6.AddOption("Vytreshna norma na vyzvrashtaemost", 1);
	exam.push_back(n6);
	
	Question n7("Koy finansov model e baziran na koncepciqta, che stajnostta na parite sega e po-golqma ot tqhnata stojnost v bydeshte");
	n7.AddOption("IRR", -1);
	n7.AddOption("CBA", -1);
	n7.AddOption("EVA", -1);
	n7.AddOption("PV", 1);
	exam.push_back(n7);
	
	Question n8("Izpolzvaneto na WBS za ocenka na softuerni resheniq");
	n8.AddOption("vodi do netochna ocenka pri razrabotkata na softuer", -1);
	n8.AddOption("s dobra praktika  pri modelite za ocenka na softuer", 1);
	n8.AddOption("e trudno postijimo za ocenka w realna sreda", -1);
	n8.AddOption("mnogo skupo reshenie za cenka", -1);
	exam.push_back(n8);
	
	Question n9("Koy parametur ot razhodniq model na sofftuera ne trqbwa da se podobri spored softuernata ikonomika");
	n9.AddOption("ekipyt za razrabotka/prilojenie (Team)", -1);
	n9.AddOption("Tehnicheskite sredstva (Tools)", -1);
	n9.AddOption("Kompleksnost (Complexity)", -1);
	n9.AddOption("Metodyt na ocenka", 1);
	exam.push_back(n9);
	
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
