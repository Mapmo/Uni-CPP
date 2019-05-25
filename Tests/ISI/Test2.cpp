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
	std::cout << "Test 2 po ISI\nIzgotven ot Mapmo\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	
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

	Question q3("Koga e umestno da se izpolzva modela na ranniq dizajn pri COMOCOMO II");
	q3.AddOption("Predi da se opredeli arhitekturata na softuernoto prilojenie", 1);
	q3.AddOption("Sled kato se opredeli arhitekturata na softuernoto prilojenie", -1);
	q3.AddOption("Predi da se opredelqt iziskvaniqta na klienta", -1);
	q3.AddOption("Sled izgotvqne na detajlen tehnicheski dizajn", -1);
	exam.push_back(q3);

	Question q4("Kakvo otrazqva fakktora B v osnovnoto uravnenie na COCOMO II PM .... A * S");
	q4.AddOption("Razmera na proekta", -1);
	q4.AddOption("Usiliq za proekta izmereni v choveko-meseci", -1);
	q4.AddOption("Stepenta na ikonomiq ili razshirenie na usiliq v proekti s razlichen razmeri", 1);
	q4.AddOption("Stepenta na namalqvane na usiliqta", -1);
	exam.push_back(q4);

	Question q5("Kakvi merni edinici za razmer na proekt izpolzva modelyt na ranniq dizajn na COCOMO II");
	q5.AddOption("Use-case points", -1);
	q5.AddOption("Korigirani funkcionalni tochki (adjusted function points)", 1);
	q5.AddOption("Obektni tochki (object points)", -1);
	q5.AddOption("Nekorigirani funkcionalni tochki (unadjusted function points)", -1);
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
	q7.AddOption("Stepen na zrqlost (MATD)", -1);
	exam.push_back(q7);

	Question q8("Po kakvo se razlichavat modela na ranniq dizajn dizajn i post-arhitekturniq model na COCOMO II");
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
	q11.AddOption("Granicite na prilojenieto trqbwa da se definirat maksimalno detajlno", -1);
	q11.AddOption("Granicite na prilojenieto se menqt po vreme na ocenkata", 1);
	q11.AddOption("Opredelenqneto na granicite na prilojenieto e zadyljitelno ori tozi model", -1);
	exam.push_back(q11);

	Question q12("Koq ot izbroenite definicii ne se otnasq za tranzakciqta za izvlichane na danni EQ");
	q12.AddOption("Elementaren proces, koyto izprashta danni ili upravlenska informaciq izvyn prilojenieto", -1);
	q12.AddOption("Elementaren proces, koyto predostavq informaciq na potrebiteli", -1);
	q12.AddOption("Elementaren proces, kojto izvyrshva dopylnitelna obrabotka vyrhu predostavenata informaciq", 1);
	q12.AddOption("Opredelqneto na granicata na prilojenieto e zadyljitelna pri ocenkata s funkcionalni tochki", -1);
	exam.push_back(q12);

	Question q13("Koq ot izbroenite definicii ne se otnasq za vytrshni logicheski fajlove (ILF)");
	q13.AddOption("Grupa ot logicheski svyrzani danni, koito sa identificirani ot potrebitelite i se upravlqvat izvyn granicite na prilojenieto", 1);
	q13.AddOption("Grupa ot logicheski svyrzani danni, koito se identificirat ot potrebitelite", -1);
	q13.AddOption("Osnovna cel na ILF e da syhranqva dannite na prolojenieto", -1);
	q13.AddOption("Dannite syhranqvani ot ILF se upravlqvat ot elementarni procesi v ramkite na prilojenieto", -1);
	exam.push_back(q13);

	Question q14("Koi elementarni procesi sa elementi na analiza s funkcionalni tochki");
	q14.AddOption("Slojni tranzakcii TR i vytreshni logicheski fajlove", -1);
	q14.AddOption("Vytreshni vhodove EI i vynshni izhodi EO", 1);
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

	/*
	Question q1("");
	q1.AddOption("", -1);
	q1.AddOption("", -1);
	q1.AddOption("", -1);
	q1.AddOption("", -1);
	exam.push_back(q1);
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