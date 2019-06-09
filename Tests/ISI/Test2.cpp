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
	std::cout << "Test 2 po ISI\nIzgotven ot Mapmo, redaktiran ot Alexa\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	//q is for 2017, w for 2013, e for 2016, r for Mapmo's own questions
	Question q1("Koy model e izpolzvan pri COCOMO II metod za ocenka?");
	q1.AddOption("Biznes model", -1);
	q1.AddOption("Post-arhitekturen model", 1);
	q1.AddOption("Use-case model", -1);
	q1.AddOption("Model na bazite danni", -1);
	exam.push_back(q1);

	Question q2("Koe ot izbroenite tvyrdeniq e vqrno za modela na kompoziciq na prilojenieto pri COCOMO II?");
	q2.AddOption("Ocenkata se osnovava na analiz s obektni tochki", 1);
	q2.AddOption("Ne e podhodqsht za ocenka na prototipi na prilojenie", -1);
	q2.AddOption("Ocenkata e vyzmojna samo sled detailen tehnicheski dizajn", -1);
	q2.AddOption("Faktorite izpolzvani pri ocenkata sa 33", -1);
	exam.push_back(q2);

	Question q3("Koga e umestno da se izpolzva modela na ranniq dizajn pri COCOMO II");
	q3.AddOption("Predi da se opredeli arhitekturata na softuernoto prilojenie", 1);
	q3.AddOption("Sled kato se opredeli arhitekturata na softuernoto prilojenie", -1);
	q3.AddOption("Predi da se opredelqt iziskvaniqta na klienta", -1);
	q3.AddOption("Sled izgotvqne na detajlen tehnicheski dizajn", -1);
	exam.push_back(q3);

	Question q4("Kakvo otrazqva faktora B v osnovnoto uravnenie na COCOMO II PM nominalno = A * S^B");
	q4.AddOption("Razmera na proekta", -1);
	q4.AddOption("Usiliq za proekta izmereni v choveko-meseci", -1);
	q4.AddOption("Stepenta na ikonomiq ili razshirenie na usiliq v proekti s razlichen razmeri", 1);
	q4.AddOption("Stepenta na namalqvane na usiliqta", -1);
	exam.push_back(q4);

	Question q5("Kakvi merni edinici za razmer na proekt izpolzva modelyt na ranniq dizajn na COCOMO II");
	q5.AddOption("Use-case points", -1);
	q5.AddOption("Korigirani funkcionalni tochki (adjusted function points)", -1);
	q5.AddOption("Obektni tochki (object points)", -1);
	q5.AddOption("Nekorigirani funkcionalni tochki (unadjusted function points)", 1);
	exam.push_back(q5);

	Question q6("Kolko sa faktorite za razhod v post-arhitekturniq model na COCOMO II");
	q6.AddOption("3", -1);
	q6.AddOption("17", 1);
	q6.AddOption("7", -1);
	q6.AddOption("5", -1);
	exam.push_back(q6);

	Question q7("Koy ot izbroenite faktori na razhod ne se otnasq za post-arhitekturniq model na COCOMO II");
	q7.AddOption("Nedejdnost na softuera (RELY)", -1);
	q7.AddOption("Stepen na dokumentaciq (DOCU)", -1);
	q7.AddOption("Razmer na dannite (DATA)", -1);
	q7.AddOption("Stepen na zrqlost (MATD)", 1);
	exam.push_back(q7);

	Question q8("Po kakvo se razlichavat modela na ranniq design i post-arhitekturniq model na COCOMO II");
	q8.AddOption("Po vidovete prilojeniq obekt na ocenkata", -1);
	q8.AddOption("Po slojnost na prilojeniqta", -1);
	q8.AddOption("Po izpolzvanite faktori za razjod (multiplikatori na usiliq)", 1);
	q8.AddOption("Nqma razlika", -1);
	exam.push_back(q8);

	Question q9("Kakvo se izmerva s funkcionalni tochki (Function Points)?");
	q9.AddOption("Kolichestvo (obem) funkcionalnost na prilojenie", 1);
	q9.AddOption("Vytreshna slojnost na prilojenie", -1);
	q9.AddOption("Stepen na korektnost na tehnicheska arhitektura", -1);
	q9.AddOption("Ergonomiq na grafichen interface na prilojenieto", -1);
	exam.push_back(q9);

	Question q10("Koy ot izbroenite elementarni procesi e element na analiza s funkcionalni tochki");
	q10.AddOption("Vytreshni izhodi (IO)", -1);
	q10.AddOption("Vynshni fizicheski fajlove (EPF)", -1);
	q10.AddOption("Procesi na obrabotka (PP)", -1);
	q10.AddOption("Vynshni vhodove (EI)", 1);
	exam.push_back(q10);
	
	Question q11("Koe tvyrdenie ne e vqrno za opredelqneto na granici na prilojenieto pri ocenka s metoda na funkcionalnite tochki?");
	q11.AddOption("Granicite na prilojenieto se opredelqt ot potrebitelska gledna tochka", -1);
	q11.AddOption("Granicite na prilojenieto trqbva da se definirat maksimalno detajlno", -1);
	q11.AddOption("Granicite na prilojenieto se menqt po vreme na ocenkata", 1);
	q11.AddOption("Opredelenqneto na granicite na prilojenieto e zadyljitelno pri tozi model", -1);
	exam.push_back(q11);

	Question q12("Koq ot izbroenite definicii ne se otnasq za tranzakciqta za izvlichane na danni EQ");
	q12.AddOption("Elementaren proces, koyto izprashta danni ili upravlenska informaciq izvyn prilojenieto", -1);
	q12.AddOption("Elementaren proces, koyto predostavq informaciq na potrebiteli", -1);
	q12.AddOption("Elementaren proces, koyto izvyrshva dopylnitelna obrabotka vyrhu predostavenata informaciq", 1);
	q12.AddOption("Opredelqneto na granicata na prilojenieto e zadyljitelna pri ocenkata s funkcionalni tochki", -1);
	exam.push_back(q12);

	Question q13("Koq ot izbroenite definicii ne se otnasq za vytreshni logicheski fajlove (ILF)");
	q13.AddOption("Grupa ot logicheski svyrzani danni, koito sa identificirani ot potrebitelite i se upravlqvat izvyn granicite na prilojenieto", 1);
	q13.AddOption("Grupa ot logicheski svyrzani danni, koito se identificirat ot potrebitelite", -1);
	q13.AddOption("Osnovna cel na ILF e da syhranqva dannite na prolojenieto", -1);
	q13.AddOption("Dannite syhranqvani ot ILF se upravlqvat ot elementarni procesi v ramkite na prilojenieto", -1);
	exam.push_back(q13);

	Question q14("Koi elementarni procesi sa elementi na analiza s funkcionalni tochki");
	q14.AddOption("Slojni tranzakcii TR i vytreshni logicheski fajlove", -1);
	q14.AddOption("Vynshni vhodove EI i vynshni izhodi EO", 1);
	q14.AddOption("Vynshni izhodi EO i vytreshni fizicheski fajlove IPF", -1);
	q14.AddOption("Tranzakcii po izvlichane na danni EQ i vytreshni fizicheski fajlove IPF", -1);
	exam.push_back(q14);

	Question q15("Koe ot izbroenite pravila za identifikaciq se otnasq za vynshen vhod (Extrenal input)");
	q15.AddOption("Dannite ili upravlenskata informaciq se vyvejdat v prilojenieto ot vynshnata sreda", 1);
	q15.AddOption("Funkciqta predava informaciq izvyn sistemata", -1);
	q15.AddOption("Nito edin vytreshen fajl ne se promenq", -1);
	q15.AddOption("Ne se uzmenq systoqnieto na prilojenieto", -1);
	exam.push_back(q15);

	Question q16("Tablicata ot baza danni upravlqvana ot prilojenieto se broi za");
	q16.AddOption("Vytreshen logicheski file (ILF)", 1);
	q16.AddOption("Vytreshen vhod (EI)", -1);
	q16.AddOption("Date Element Type", -1);
	q16.AddOption("Record Element Type", -1);
	exam.push_back(q16);

	Question q17("Tablica ot baza danni referirana ot prilojenieto, no upravlqvana ot drugo prilojenie se broi za:");
	q17.AddOption("Vytreshen logicheski file", -1);
	q17.AddOption("Vynshen interfeisen file", 1);
	q17.AddOption("Data Element Type", -1);
	q17.AddOption("Record Element Type", -1);
	exam.push_back(q17);

	Question q18("Koe tvyrdenie za Data Element Type ne e vqrno");
	q18.AddOption("Poleta ot vytreshen logicheski file (ILF) vidimi za potrebitelq", -1);
	q18.AddOption("Poleta ot vynshen interface file (EIF) vidimi za potrebitelq", -1);
	q18.AddOption("Poleta, koito se izchislqvat avtomatichno", 1);
	q18.AddOption("DET syotvestva na kolona v tablica na baza danni", -1);
	exam.push_back(q18);

	Question q19("Ot kakvo se opredelq slojnostta na funkciite za danni (EIF/ILF) pri analiza s funkcionalni tochki");
	q19.AddOption("Ot broq na RET i DET", 1);
	q19.AddOption("Ot kolichestviti informaciq izmerena v bytes", -1);
	q19.AddOption("Poleta, koito se izchislqvat avtomatichno", -1);
	q19.AddOption("DET syotvetstva na kolona v tablica na baza danni", -1);
	exam.push_back(q19);

	Question q20("Ot kakvo se opredelq slojnostta na funkciite za vynshen vhod (EI) pri analiza s funkcionalni tochki");
	q20.AddOption("Ot broq na RET i DET", -1);
	q20.AddOption("Ot broq na FTR", -1);
	q20.AddOption("Ot broq na DET i FTR", 1);
	q20.AddOption("Ot broq na DET", -1);
	exam.push_back(q20);

	Question q21("Kakyv e broqt na globalnite sistemni harakteristiki izpolzvani pri analiza s funckionalni tochki?");
	q21.AddOption("7", -1);
	q21.AddOption("17", -1);
	q21.AddOption("21", -1);
	q21.AddOption("14", 1);
	exam.push_back(q21);

	Question q22("Koe ot tvyrdeniq ne e vqrno za obektnite tochki");
	q22.AddOption("Mqrka za razmer na funkcionalnost na softuer osnovavashta se na OOP", -1);
	q22.AddOption("Obektnite tochki se osnovavat na metodologiite na strukturnoto programirane", 1);
	q22.AddOption("Obektnite tochki sa tehnologichno orientirani", -1);
	q22.AddOption("Pravilata za broene na obektnite tochki sa po-prosti v sravnenie s funckionalnite tochki", -1);
	exam.push_back(q22);

	Question q23("Ot kakvo se opredelq slojnostta na vytreshnite klasove pri analiz s obektni tochki");
	q23.AddOption("Ot broq na RET i DET", 1);
	q23.AddOption("Ot kolichestvoto informaciq syhranqvana v klasovete izmerena v bytes", -1);
	q23.AddOption("Ot broq na metodite i uslugite raboteshti s vytreshnite klasove", -1);
	q23.AddOption("Opredelq se po subektivna ocenka na ocenitelq", -1);
	exam.push_back(q23);

	Question q24("Koy elementaren proces ot analiza s funckionalni tochki syotvetstva na izhodna usluga pri analiza s obektni tochki");
	q24.AddOption("Vytreshen logicheski file (ILF)", -1);
	q24.AddOption("Vynshen interface file (EIF)", -1);
	q24.AddOption("Vynshen vhod (EI)", -1);
	q24.AddOption("Vynshen izhod (EO)", 1);
	exam.push_back(q24);

	Question q25("Koy element na analiza po metodologiqta SEER-SEM nqma analog pri analiza s funkcionalni tochki");
	q25.AddOption("SEER-FBS Vytreshni logicheski files (ILF)", -1);
	q25.AddOption("SEER-FBS Vynshni interface files (EIF)", -1);
	q25.AddOption("SEER-FBS Vytreshni funkcii (IF)", 1);
	q25.AddOption("SEER-FBS Izvlichane na danni (EQ)", -1);
	exam.push_back(q25);
	
	Question w1("Tablica ot baza danni upravlqvana ot prilojenieto se broi za");
	w1.AddOption("Vytreshen vhod (EI)", -1);
	w1.AddOption("Data Element Type", -1);
	w1.AddOption("Record Element Type", -1);
	w1.AddOption("Vytreshen logicheski file (ILF)", 1);
	exam.push_back(w1);

	Question w2("Koe ot izbroenite pravila za identifikaciq ne se otnasq za external interface files (EIF)");
	w2.AddOption("Grupata ot danni ili upravlqvashta informaciq e logicheska i vidima", -1);
	w2.AddOption("Grupata ot danni e upravlqvana kato EIF v drugo prilojenie", 1);
	w2.AddOption("Grupata ot danni e referirana i vynshna za prilojenieto", -1);
	w2.AddOption("Grupata ot danni e upravlqvana izvyn ramkite na prilojenieto", -1);
	exam.push_back(w2);

	Question w3("Koga e umestno da se izpolzva modela na kompoziciq na prilojenieto pri COCOMO II");
	w3.AddOption("Sled kato se opredeli arhitekturata na softuernoto prilojenie", -1);
	w3.AddOption("Predi da se opredelqt iziskvaniqta na klienta", -1);
	w3.AddOption("V nachalen etap na proekta ili pri izgotvqne na prototip", 1);
	w3.AddOption("Sled izgotvqne na detaylen tehnicheski dizain na prilojenieto", -1);
	exam.push_back(w3);

	Question w7("Kolko sa faktorite za razhod v modela na ranniq design na COCOMO II");
	w7.AddOption("14", -1);
	w7.AddOption("17", -1);
	w7.AddOption("7", 1);
	w7.AddOption("5", -1);
	exam.push_back(w7);

	Question w9("Koe tvyrdenie ne e vqrno za opredelqneto na granici na prilojenieto s metoda na funkcionalnite tochki");
	w9.AddOption("Granicite na prilojenieto trqbva da se definirat maksimalno detaylno", -1);
	w9.AddOption("Granicite na prilojenieto ne se menqt po vreme na ocenka", -1);
	w9.AddOption("Granicite na prilojenieto se opredelqt ot gledna tochka na arhitekta na sistemata", 1);
	w9.AddOption("Opredelqneto na granicite na prilojenieto e zadylvitelno pri ocenkata na sistemata", -1);
	exam.push_back(w9);

	Question w14("Koe tvyrdenie za Data Element Types (DET) e vqrno");
	w14.AddOption("Poleta ot vytreshen logicheski file (ILF), vidimi i znachimi za potrebitelq", 1);
	w14.AddOption("Poleta ot vynshen interface file (EIF) nevidimi i neznachimi za potrebitelq", -1);
	w14.AddOption("Poleta ot vytreshen logicheski file (ILF), nevidimi i neznachimi za potrebitelq", -1);
	w14.AddOption("DET syotvetstva na syhranena procedura(stored procedure)", -1);
	exam.push_back(w14);

	Question w15("Ot kakvo se opredelq slojnostta na funkciite za vynshen izhod (EO) pri analiza s funckionalni tochki");
	w15.AddOption("Ot broq DET i FTR", 1);
	w15.AddOption("Ot broq na RET i DET", -1);
	w15.AddOption("Ot broq na FTR", -1);
	w15.AddOption("Ot broq na RET", -1);
	exam.push_back(w15);

	Question w16("Pri opredelena edna i syshta slojnost na funkcionalnosti ot tip EI i EO koq bi poluchila po visoka ocenka");
	w16.AddOption("EO", 1);
	w16.AddOption("EI", -1);
	w16.AddOption("Ravna ocenka", -1);
	w16.AddOption("Subektivno e", -1);
	exam.push_back(w16);

	Question w18("Koe tvyrdenie e vqrno za funkcionalnite tochki?");
	w18.AddOption("Mqrka za razmer na funkcionalnost na softuer osnovavashta se na OOP pogled", -1);
	w18.AddOption("Funckionalnite tochki se osnovavat na metodologiite na strukturnoto programirane", -1);
	w18.AddOption("Merna edinica za funkcionalnost, kato rezultata e predstaven v terminite na krayniq potrebitel", 1);
	w18.AddOption("Ne se ocenqva s funckionalni tochki", -1);
	exam.push_back(w18);

	Question w19("Pri edna i syshta slojnost na funkciite za danni (ILF, EIF) v modela na funkcionalnite tochki");
	w19.AddOption("EIF se ocenqva s poveche funckionalni tochki ot ILF", -1);
	w19.AddOption("Broqt na funkcionalni tochki e ednakyv", -1);
	w19.AddOption("ILF se ocenqva s poveche funckionalni tochki ot EIF", 1);
	w19.AddOption("Ne se ocenqvat s funkcionalni tochki", -1);
	exam.push_back(w19);

	Question w21("Za izchislqvane na razmera na softuer na osnovata na Use-Case Object Point e neobhodimo:");
	w21.AddOption("Da se preborqt liniite kod bez komentari v prilojenieto", -1);
	w21.AddOption("Da se opredelqt broq obektni tochki na prilojenieto", -1);
	w21.AddOption("Da se identificirat faktorite za razhod v prilojenieto", -1);
	w21.AddOption("Da se identificirat aktyorite", 1);
	exam.push_back(w21);

	Question w22("Koy ot izbroenite elementarni procesi ne e element na analiza s funkcionalni tochki");
	w22.AddOption("Vynshni izhodi (EO)", -1);
	w22.AddOption("Vytreshni interface files (IIF)", 1);
	w22.AddOption("Izvlichane na danni (EQ)", -1);
	w22.AddOption("Vynshni vhodove (EI)", -1);
	exam.push_back(w22);

	Question w23("Buton vyv forma ot prilojenieto se broi za");
	w23.AddOption("Vytreshen logicheski file (ILF)", -1);
	w23.AddOption("Data Element Type (DET)", -1);
	w23.AddOption("Record Element Type (RET)", -1);
	w23.AddOption("Vynshen vhod (EI)", 1);
	exam.push_back(w23);

	Question w24("Koy model e chast ot COCOMO II metod za ocenka?");
	w24.AddOption("Model na biznes procesite", -1);
	w24.AddOption("Model na ranniq design", 1);
	w24.AddOption("Use-case model", -1);
	w24.AddOption("Model na bazite danni", -1);
	exam.push_back(w24);

	Question w25("V kakva posledovatelnost sledva da se izvyrshva analiza s funkcionalni tochki?");
	w25.AddOption("opredelqne na faktori na slojnost, identifikaciq na funkcii, opredelqne na niva na slojnost, izchislqvane na nekorigiran funkcionalen obem, opredelqne na faktori za korekciq na funkcionalen obem, opredelqne na funkcionalen obem\n", -1);
	w25.AddOption("opredelqne na niva na slojnost, identifikaciq na funkcii, opredelqne na faktori na slojnost, izchislqvane na nekorigiran funkcionalen obem, opredelqne na faktori za korekciq na funkcionalen obem, opredelqne na funkcionalen obem\n", -1);
	w25.AddOption("identifikaciq na strukturi ot danni, opredelqne na faktori na slojnost, opredelqne na niva na slojnost, izchislqvane na nekorigiran funkcionalen obem, opredelqne na faktori za korekciq na funkcionalen obem, opredelqne na funkcionalen obem\n", -1);
	w25.AddOption("identifikaciq na funkcii, opredelqne na faktori na slojnost, opredelqne na niva na slojnost, izchislqvane na nekorigiran funkcionalen obem, opredelqne na faktori za korekciq na funkcionalen obem, opredelqne na funkcionalen obem\n", 1);
	exam.push_back(w25);

	Question e1("Pri analiz s funkcionalni tochki na prilojenie s baza danni, RET syotvetstva na:");
	e1.AddOption("Tablica v BD", -1);
	e1.AddOption("Stored procedure v BD", -1);
	e1.AddOption("Triger v BD", -1);
	e1.AddOption("View (izgled) v BD", 1);
	exam.push_back(e1);

	Question e14("Tablica ot baza danni, v koqto prilojenieto pravi Insert/Update/Delete/Select se broi za");
	e14.AddOption("Data Element Type (DET)", -1);
	e14.AddOption("Vytreshen vhod (EI)", -1);
	e14.AddOption("Vytreshen logicheski file (ILF)", 1);
	e14.AddOption("Record Element Type (RET)", -1);
	exam.push_back(e14);

	Question e16("Pri analiz s funkcionalni tochki na prilojenie s BD, Login forma sytvetstva na:");
	e16.AddOption("Izvlichane na danni (EQ)", 1);
	e16.AddOption("Vynshen vhod (EI)", -1);
	e16.AddOption("Vytreshen logicheski file (ILF)", -1);
	e16.AddOption("Vynshen interface file (EIF)", -1);
	exam.push_back(e16);

	Question e19("Kakvo otrazqva parametara S v osnovnoto uravnenie na COCOMO II PM nominalno = A * S^B");
	e19.AddOption("Stepenta na ikonomiq ili razhishtenie na usiliq v proekti s razlichen razmer", -1);
	e19.AddOption("Stepenta na namalqvane na usiliqta", -1);
	e19.AddOption("Razmera na proekta", 1);
	e19.AddOption("Usiliq za proekta izmereni v choveko-meseci", -1);
	exam.push_back(e19);

	Question r1("Kakvo otrazqva parametara PM v osnovnoto uravnenie na COCOMO II PM nominalno = A * S^B");
	r1.AddOption("Stepenta na ikonomiq ili razhishtenie na usiliq v proekti s razlichen razmer", -1);
	r1.AddOption("Stepenta na namalqvane na usiliqta", -1);
	r1.AddOption("Razmera na proekta", -1);
	r1.AddOption("Usiliq za proekta izmereni v choveko-meseci", 1);
	exam.push_back(r1);

	Question r2("Kakvo otrazqva parametara A v osnovnoto uravnenie na COCOMO II PM nominalno = A * S^B");
	r2.AddOption("Stepenta na ikonomiq ili razhishtenie na usiliq v proekti s razlichen razmer", -1);
	r2.AddOption("Stepenta na namalqvane na usiliqta", -1);
	r2.AddOption("Konstanta, otrazqvashta efekta ot uvelichavane na neobhodimite usiliq v proekta s negovoto narastvane", 1);
	r2.AddOption("Usiliq za proekta izmereni v choveko-meseci", -1);
	exam.push_back(r2);

	Question r3("Kakvo oznachava stojnostta na parameta B za produktivnostta v  osnovnoto uravnenie na COCOMO II PM nominalno = A * S^B");
	r3.AddOption("Ne znachi nishto", -1);
	r3.AddOption("Zavisi ot proekta", -1);
	r3.AddOption("Kolkoto po-malko e tolkova poveche raste produktivnostta s razmera na proekta", 1);
	r3.AddOption("Kolkoto po-golqmo e tolkova poveche raste produktivnostta s razmera na proekta", -1);

	/*
	Question r("");
	r.AddOption("", -1);
	r.AddOption("", -1);
	r.AddOption("", -1);
	r.AddOption("", -1);
	exam.push_back(r);
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
