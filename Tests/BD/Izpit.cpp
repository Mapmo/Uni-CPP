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
	std::cout << "Izpit po BD\nIzgotven ot Mapmo, vyprosite sa dareni ot lyubolp\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question r1("Koe ne e svoystvo na SUBD?");
	r1.AddOption("Efektiven dostyp do golemi obemi ot danni", -1);
	r1.AddOption("Poddrryjka na ustoychivi danni", -1);
	r1.AddOption("Moshten ezik za zaqvki", 1);
	r1.AddOption("Atomarnost i nezavisimost na zaqvkite", -1);
	exam.push_back(r1);

	Question r2("Koe ne e preimushtestvo na SUBD pred konvencionalnata faylova sistema");
	r2.AddOption("Efektivno tyrsene i modifikaciq na malki parcheta ot danni", -1);
	r2.AddOption("Izpylnenie na slojni zaqvki", -1);
	r2.AddOption("Upravlenie na buferizaciqta v osnovnata pamet", -1);
	r2.AddOption("Upravlenie na tranzakcii", -1);
	r2.AddOption("Nito edno ot izbroenite", 1);
	exam.push_back(r2);

	Question r3("Koe ot slednite tvyrdeniq ne e vqrno?");
	r3.AddOption("Relacionnite SUBD sa bazirani na relacionniq model", -1);
	r3.AddOption("Informaciqta v relacionnite SUBD e organizirana v tablici", -1);
	r3.AddOption("SQL e nay-chesto izpolzvaniq ezik za zaqvki v relacionnite SUBD", -1);
	r3.AddOption("Vsichki sa verni", 1);
	exam.push_back(r3);

	Question r4("Bazite ot danni ne se syhranqvat v");
	r4.AddOption("Operativnata pamet", 1);
	r4.AddOption("Vtorichnata pamet", -1);
	r4.AddOption("Tretichnata pamet", -1);
	r4.AddOption("Syhranqvat se i w trite vida pamet", -1);
	exam.push_back(r4);

	Question r5("Koe ot slednite tvyrdeniq ne e vqrno?");
	r5.AddOption("SUBD poddyrjat client-server arhitektura", -1);
	r5.AddOption("Tendenciqta e SUBD da poddyrjat multimedijni obekti", -1);
	r5.AddOption("Integraciqta ot mnojestvo nezavisimi iztochnici v edna baza danni se oformq kato zadacha na bydeshtite SUBD", -1);
	r5.AddOption("Vsichki sa verni", 1);
	exam.push_back(r5);

	Question r6("Koy ot slednite ezici e podezik");
	r6.AddOption("Ezik za definiciqta na dannite", -1);
	r6.AddOption("Ezik za zaqvki", 1);
	r6.AddOption("Ezik na manipulaciqta na dannite", -1);
	r6.AddOption("Nqma takyv", -1);
	exam.push_back(r6);

	Question r7("Koe ne e komponent na bazata ot danni");
	r7.AddOption("Manager na pametta", -1);
	r7.AddOption("Processor na zaqvkite", -1);
	r7.AddOption("Manager na tranzakciite", -1);
	r7.AddOption("Vsichki sa komponenti", 1);
	exam.push_back(r7);

	Question r8("Za kakvo ne e otgovoren managera na pametta");
	r8.AddOption("Syhranqvane na danni i metadanni", -1);
	r8.AddOption("Syhranqvane na jurnalnite zapisi(logovete)", -1);
	r8.AddOption("Optimizaciqta na zaqvkite i izpylnenieto na zaqvkite", 1);
	r8.AddOption("Upravlenie buferizaciqta v operativnata pamet", -1);
	exam.push_back(r8);

	Question r9("Za kakvo ne e otgovoren managerat na tranzakciite");
	r9.AddOption("Izbor na plan na zaqvkata", 1);
	r9.AddOption("Jurnalnite zapisi", -1);
	r9.AddOption("Konkurentnoto izpylnenie na zaqvkite", -1);
	r9.AddOption("Atomarnost i izolaciq na tranzakciite", -1);
	r9.AddOption("Otgovoren e za vsichko izbroeno", -1);
	exam.push_back(r9);

	Question r10("Chlenovete na mnojestvo syshnosti mogat da sa");
	r10.AddOption("Atributi na mnojestvata syshnosti", -1);
	r10.AddOption("Enti", 1);
	r10.AddOption("Drugi mnojestva syshnosti", -1);
	r10.AddOption("Vsichki izbroeni", -1);
	r10.AddOption("Nito edno ot izbroenite", -1);
	exam.push_back(r10);

	Question r11("Koi geometrichni figuri se izpolzvat za predstavqne na mnojestvo syshnosti");
	r11.AddOption("Mnojestva syshnosti - pravoygylnik", 0.33);
	r11.AddOption("Vryzki - romb", 0.34);
	r11.AddOption("Atributi - elipsi", 0.33);
	r11.AddOption("Nasledqvane - strelka", -1);
	exam.push_back(r11);

	Question r12("Pri koy vid vryzka ima svyrzvane na syshnost ot ednoto mnojestvo syshnosti s tochno edna syshnost ot drugoto mnojestvo syshnosti");
	r12.AddOption("Mnogo kym mnogo", -1);
	r12.AddOption("Mnogo kym edin", -1);
	r12.AddOption("Nito edno ot izbroenite", 1);
	r12.AddOption("Edin kym mnogo", -1);
	r12.AddOption("Vryzka s ogranichenie tip referentna cqlost", -1);
	exam.push_back(r12);

	Question r13("Koe ot slednite tvyrdeniq ne e vqrno za key pri modela na syshnost-vryzki");
	r13.AddOption("Key e mnojestvo ot atributi, koeto unikalno identificira syshnostite v mnojestvata syshnosti", -1);
	r13.AddOption("Key e minimalen", 1);
	r13.AddOption("Moje da ima poveche ot edin key v dadeno mnojestvo", -1);
	r13.AddOption("Vsichki tvyrdeniq sa verni", -1);
	exam.push_back(r13);

	Question r14("Koe ne e svoystveno na dobriq proekt na bazite danni?");
	r14.AddOption("Adekvatno predstavqne na realniq svqt", -1);
	r14.AddOption("Podhodqshto izbrani elementi", -1);
	r14.AddOption("Izbqgvane na izlishestva", -1);
	r14.AddOption("Izbroenite sa svoystva na dobriq proekt na bazi danni", 1);
	exam.push_back(r14);

	Question r15("Podklasovete sa");
	r15.AddOption("Mnojestva syshnosti organizirani v yerarhiq", -1);
	r15.AddOption("Mnojestvo syshnosti svyrzani s vryzki tip isa", -1);
	r15.AddOption("Mnojestvo syshnosti, chiito syshnosti mogat da imat komponenti prinadlejashti na poddyrvo ot yerarhiqta stiga poddyrvoto da sydyrja korena", -1);
	r15.AddOption("I trite izbroeni", 1);
	exam.push_back(r15);

	Question r16("Koe ot slednite tvyrdeniq ne e vqrno");
	r16.AddOption("Vsqko mnojestvo ot syshnosti ima key", -1);
	r16.AddOption("Slabite mnojestva syshnosti nqmat key", 1);
	r16.AddOption("Key na slabite mnojestva syshnosti se formira chrez atributite na svyrzano s nego mnojestvo syshnosti", -1);
	r16.AddOption("Slabite mnojestva syshnosti se izobrazqvat s pravoygylnik s dvoyni strani, a poddyrjashtite gi vryzki s dvoyni strani", -1);
	exam.push_back(r16);

	Question r17("Koe ot slednite tvyrdeniq za relacionniq model ne e vqrno");
	r17.AddOption("Informaciqta se predstavq s tablici", -1);
	r17.AddOption("Kolonkite sa ozaglaveni s atributi", -1);
	r17.AddOption("Atributite sa asociirani s domains", -1);
	r17.AddOption("Atributite sa asociirani s tipove danni", -1);
	r17.AddOption("Redovete se narichat korteji", -1);
	r17.AddOption("Vseki kortej ima po edin komponent za vseki atribut na relaciqta", -1);
	r17.AddOption("Vsichki sa verni", 1);
	exam.push_back(r17);

	Question r18("Koe ot slednite tvyrdeniq za shemite ne e vqrno");
	r18.AddOption("Shemata na relaciqta se systoi ot imeto na relaciqta i imenata na atributite", -1);
	r18.AddOption("Tipyt na atributite e chast ot shemata na relaciqta", -1);
	r18.AddOption("Shemata na bazata danni e nabora ot relacionni shemi na relaciite i", -1);
	r18.AddOption("Konkretnite danni za dadena relaciq se naricha ekzemplqr na relaciqta", 1);
	r18.AddOption("Konkretnite danni na mnojestvoto relacii ot bazata danni se naricha ekzemplqr na bazata ot danni", -1);
	exam.push_back(r18);

	Question r19("Koe ot slednite tvyrdeniq pri preobrazuvaneto na diagramite syshnost vryzki v relacionnata shema e vqrno");
	r19.AddOption("Relaciqta na mnojestvoto syshnosti ima po edin atribut za vseki atribut na slaboto mnojestsvo syshnosti, a syshto i atributi za key atributi ot drugi mnojestva syshnosti, koito spomagat za identifikaciq na syshnostite ot slaboto mnojestvo syshnosti\n", -1);
	r19.AddOption("Relaciqta za slaboto mnojestvo syshnosti ima po edin atribut za vseki atribut na slaboto mnojestvo syshnosti, a syshto i atributi za key atributi ot drugi mnojestva syshnosti, koito spomagat za identifikaciq na syshnostite ot slaboto mnojestvo syshnosti\n", -1);
	r19.AddOption("Relaciqta za vryzka ima za atributi atributite syotvetstvashti na key atributi za vsqko mnojestvo syshnosti uchastvashti vyv vryzkata\n", -1);
	r19.AddOption("Relaciqta na poddyrjashtata vryzka za slaboto mnojestvo syshnosti se systoi samo ot atributi syotvetstvashti na key atributi na mnojestvoto syshnosti, v koeto sochi strelkata na vryzkata\n", 1);
	exam.push_back(r19);

	Question r20("Koy podhod pri preobrazuvaneto na ISA yerarhiq ot izbroenite e OOP");
	r20.AddOption("Da se razpredelqt syshnostite po razlichnite mnojestva syshnosti v yerarhiqta i da se syzdade relaciq za vsqko takova mnojestvo syshnosti", -1);
	r20.AddOption("Da se syzdade relaciq za vsqko vyzmojno podmnojestvo ot mnojestvata syshnosti v yerarhiqta kato za vsqka syshnost se syzdade kortej, koyto popada v relaciqta, syotvetstvashta na tochniq nabor mnojestva", 1);
	r20.AddOption("Da se syzdade samo edna relaciq i da se izpolzvat nulevi stojnosti na tezi atributi, koito ne sa prilojimi za syshnostta predstavlqvashta daden kortej", -1);
	r20.AddOption("Ne e sred izbroenite", -1);
	exam.push_back(r20);

	Question r21("Koe ot slednite tvyrdeniq ne e vqrno");
	r21.AddOption("Funkcionalnata zavisimost utvyrjdava, che ako dva korteja v relaciqta se syglasuvat po opredeleno mnojestvo atributi, to te se syglasuvat i po nqkoy drug opredelen atribut", -1);
	r21.AddOption("Mnogoznachnata zavisimost utvyrjdava, che dve mnojestva ot atributi v relaciqta imat mnojestva ot stoynosti, koito se poqvqvat vyv vsichki vyzmojni kombinacii", -1);
	r21.AddOption("Super key za dadena relaciq e mnojestvo ot atributi, koeto funkcionalno opredelq vsichki atributi v relaciqta", -1);
	r21.AddOption("Key e super key, koyto nqma sobstveno podmnojestvo funkcionalno opredelqshto vsichki atributi", -1);
	r21.AddOption("Nito edno tvyrdenie ne e vqrno", -1);
	r21.AddOption("Vsichki tvyrdeniq sa verni", 1);
	exam.push_back(r21);

	Question r22("Aksiomite na Armstrong sa");
	r22.AddOption("Aksiomatichna osnova na teoriqta na funckionalnite zavisimosti", -1);
	r22.AddOption("Pylen nabor ot pravila za novi funkcionalni zavisimosti", 1);
	r22.AddOption("Algoritmichni pravila za presmqtane pokritieto ot atributi za dadeno mnojestvo funkcionalni zavisimosti", -1);
	r22.AddOption("Pravila za dekompoziciq na relacii bez zaguba na informaciq", -1);
	exam.push_back(r22);

	Question r23("Koe ot slednite tvyrdeniq ne e vqrno");
	r23.AddOption("Edna relaciq se namira v normalna forma na Boyce-Codd ako netrivialite i funkcionalni zavisimosti sa sys super key ot lqvata strana", -1);
	r23.AddOption("Edna relaciq se namira v treta normalna forma ako netrivialnite i funkcionalni zavisimosti sa sys super key ot lqvata strana ili dqsnata im strana e pyrvichen atribut", -1);
	r23.AddOption("Normalna forma na Boyce-Codd premahva izlishestvata predizvikani ot funkcionalnite zavisimosti", -1);
	r23.AddOption("Pri dekompoziciq v normalna forma na Boyce-Codd se zapazvat funckonalnite zavisimosti i ne se gubi informaciq", 1);
	r23.AddOption("Edna relaciq se namira v chetvyrta normalna forma ako v neq nqma netrivialni mnogoznachni zavisimosti", -1);
	r23.AddOption("Pri dekompoziciqta v chetvyrta normalna forma ne se gubi informaciq", -1);
	exam.push_back(r23);

	Question r24("Koe ot slednite tvyrdeniq ne e vqrno");
	r24.AddOption("ODL e notaciq za formalno opisanie na shemi na bazi ot danni v OOP style", -1);
	r24.AddOption("Klasovete imat tri svoystva: atributi, metodi i vryzki", -1);
	r24.AddOption("Vryzkite v ODL sa inversni i binarni", 1);
	r24.AddOption("Tipovete v ODL se izgravdat ot atomarnite tipove i imenata na klasovete s prilaganeto na konstruktorite za struktura", -1);
	exam.push_back(r24);

	Question r25("Koe ot slednite tvyrdeniq ne e vqrno");
	r25.AddOption("Razshirenieto v ODL syotvetstva na ekzemplqr na relaciq", -1);
	r25.AddOption("Deklaraciq na klas v ODL syotvetstva na shemata na relaciq", -1);
	r25.AddOption("Key v ODL sa opcionalni i se opredelqt chrez atributite na klasa", -1);
	r25.AddOption("ODL klasovete preobrazuvame v relacionni shemi kato za atributi na klasa syzdavame i druga relaciq za vsqka inversna vryzka", 1);
	exam.push_back(r25);

	Question r26("Koe ne e ponqtie v OOP relacionniq model");
	r26.AddOption("Razshireniqta", 1);
	r26.AddOption("Vgnezdenite relacii", -1);
	r26.AddOption("Referentnite tipove", -1);
	r26.AddOption("Relaciite", -1);
	r26.AddOption("Vsichki ot izbroenite", -1);
	exam.push_back(r26);

	Question r27("Koe ot slednite tvyrdeniq ne e vqrno");
	r27.AddOption("V modela na polustrukturiranite danni, dannite sa predstaveni chrez graf", -1);
	r27.AddOption("XML e realizaciq na polustrukturiranite danni v dokumenti, kydeto vyzlite sa chasti ot teksta otgradeni s otvarqsht i zatvarqsht marker", -1);
	r27.AddOption("Predstavqneto na vryzkite v XML stava chrez vgnezdqvane i chrez spisyci atributi", -1);
	r27.AddOption("Vsichki tvyrdeniq sa verni", 1);
	r27.AddOption("Nito edno ot tvyrdeniqta ne e vqrno", -1);
	exam.push_back(r27);

	//28 i 29 sa snimki 

	Question r30("Koq ot slednite operacii v relacionnata algebra e nezavisima");
	r30.AddOption("Sortirovka", -1);
	r30.AddOption("Razshirena proekciq", -1);
	r30.AddOption("Syedinenie", -1);
	r30.AddOption("Grupirane", -1);
	r30.AddOption("Vynshno syedinenie", -1);
	r30.AddOption("Dekartovo proizvedenie", 1);
	r30.AddOption("Sechenie", -1);
	exam.push_back(r30);

	Question r31("Koe ot slednite tvyrdeniq ne e vqrno");
	r31.AddOption("Relacionnata algebra moje da se razshiri za multimnojestva kato se zapzvat algebrichnite zakoni", 1);
	r31.AddOption("Grupirane moje da se prilaga bez agregirane", -1);
	r31.AddOption("Agregirane moje da se prilaga bez grupirane", -1);
	r31.AddOption("Vynshnite syedineniq se prilagat, za da ne se gubi informaciq", -1);
	exam.push_back(r31);

	Question r32("Koe ot slednite tvyrdeniq ne e vqrno");
	r32.AddOption("Ogranicheniqta na cqlostnost v relacionnata algebra se izrazqvat s lineyna versiq na ezika", 1);
	r32.AddOption("Funckionalnite zavisimosti mogat da bydat izrazeni s relacionnata algebra", -1);
	r32.AddOption("Ogranicheniqta na cqlostnost mogat da bydat izrazeni s relacionnata algebra", -1);
	r32.AddOption("Ogranicheniqta po domen mogat da bydat izrazeni s relacionnata algebra", -1);
	exam.push_back(r32);

	Question r33("IDB predikatite v Datalog");
	r33.AddOption("Syotvetstvat na relacii po bazata danni", -1);
	r33.AddOption("Sa definirani chrez Datalog pravila", 1);
	r33.AddOption("Nito edno ot izbroenite", -1);
	r33.AddOption("I dvete izbroeni", -1);
	exam.push_back(r33);

	Question r34("Uslovieto za bezopasnost na pravilata v Datalog iziskva");
	r34.AddOption("Relaciite syotvetstvashti na EDB predikatite sa krayni", -1);
	r34.AddOption("Ako pravilata sa nerekursivni da ima v syotvetstvie izraz ot relacionnata algebra", -1);
	r34.AddOption("Vsqka promenliva v praviloto da se poqvqva v neotrechena relacionna podcel na tqloto", 1);
	r34.AddOption("Nito edno ot izbroenite", -1);
	exam.push_back(r34);

	Question r35("Nerekursivnata Datalog programa moje da ima");
	r35.AddOption("Edno nay-malko reshenie", 1);
	r35.AddOption("Nqkolko nay-malki resheniq", -1);
	r35.AddOption("Edno razsloeno reshenie", -1);
	r35.AddOption("Nqkolko razsloenie resheniq", -1);
	exam.push_back(r35);

	Question r36("Rekursivnata programa s otrecheni podceli v Datalog moje da ima");
	r36.AddOption("1 minimalno reshenie", -1);
	r36.AddOption("nqkolko minimalni reshenie", 1);
	r36.AddOption("1 razsloeno reshenie", -1);
	r36.AddOption("nito edno ot izbroenite", -1);
	exam.push_back(r36);

	Question r37("V SQL: (vqrnoto tvyrdenie)");
	r37.AddOption("rekursiqta se predstavq chrez FOR", -1);
	r37.AddOption("rekursiqta se predstavq chrez WITH", 1);
	r37.AddOption("rekursiqta se predstavq chrez psevdonimi", -1);
	r37.AddOption("rekursiqta se predstavq chrez bazoviq ezik", -1);
	r37.AddOption("nqma rekursiq", -1);
	exam.push_back(r37);

	Question r38("V SQL za razsloeniq trqbva da se izsledvat");
	r38.AddOption("rekursiq, v koqto ima razlika na relacii", -1);
	r38.AddOption("rekursiq, v koqto ima avoagregaciq", -1);
	r38.AddOption("rekursiq, v koqto ima NOT IN", 1);
	r38.AddOption("rekursiq s s otrecheni podceli", -1);
	exam.push_back(r38);

	Question r39("Rekursivnata programa bez otrecheni podceli v Datalog moje da ima");
	r39.AddOption("1 minimalno reshenie", 1);
	r39.AddOption("nqkolko minimalni reshenie", -1);
	r39.AddOption("1 razsloeno reshenie", -1);
	r39.AddOption("nqkolko razsloeni resheniq", -1);
	exam.push_back(r39);

	/*
	Question r3("");
	r3.AddOption("", -1);
	r3.AddOption("", -1);
	r3.AddOption("", -1);
	r3.AddOption("", -1);
	exam.push_back(r3);
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
