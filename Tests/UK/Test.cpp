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
	{
		if (m_Answers[i].val > 0)
		{
			std::cout << char(i + 65) << ' ';
		}
	}
	std::cout << "\nVavedi nqkoi simvol";
	if (m_Score > 0)
	{
		counter++;
	}
	return m_Score;
}
int main()
{
	std::cout << "Test 1 po UK\nIzgotven ot Mapmo i Dakata\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simulaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q0("Koe ot izbroenite e definiciq na Error?");
	q0.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", -1);
	q0.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", -1);
	q0.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", 1);
	exam.push_back(q0);

	Question q1("Koe ot izbroenite e definiciq na Fault?");
	q1.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", 1);
	q1.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", -1);
	q1.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", -1);
	exam.push_back(q1);

	Question q2("Koe ot izbroenite e definiciq na Failure?");
	q2.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", -1);
	q2.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", 1);
	q2.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", -1);
	exam.push_back(q2);
	
	Question q3("Каква е връзката между понятията повреда, грешка и отказ?");
	q3.AddOption("Повреда → Грешка → Отказ ", -1);
	q3.AddOption("Грешка → Повреда → Отказ ", 1);
	q3.AddOption("Отказ → Повреда → Грешка ", -1);
	exam.push_back(q3);
	
	Question q4("При коя фаза от тестовия процес се избират метрики и модели?");
	q4.AddOption("Тестово планиране", 1);
	q4.AddOption("Изпълнение на тестове и наблюдения", -1);
	q4.AddOption("Анализ и проследяване ", -1);
	exam.push_back(q4);
	
	Question q6("?При коя фаза от тестовия процес се дефинират тестовите сценарии?");
	q6.AddOption("Изпълнение на тестовете и наблюдение" , -1);
	q6.AddOption("Тестово планиране и подготовка" , 1);
	q6.AddOption("Анализ и проследяване" , -1);
	exam.push_back(q6);
	
	Question q7("Коя от следните дейности НЕ се изпълнява при подготовка на тестовите сценарии??");
	q7.AddOption("Конструиране на нови тестови сценарии", -1);
	q7.AddOption("Автоматично генериране на тестови сценарии", -1);
	q7.AddOption("Избор на тестови сценарии от съществуващи такива", -1);
	q7.AddOption("Дефиниране на тестова цел", 1);
	exam.push_back(q7);
	
	Question q8("Коя от следните дейности НЕ се извършва при функционалното тестване?");
	q8.AddOption("Наблюдение на външното поведение на софтуерната система", -1);
	q8.AddOption("Дебъгване на софтуерната система", 1);
	q8.AddOption("Създаване на формални тестови модели", -1);
	exam.push_back(q8);
	
	
	/*
	Question q0("?");
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	exam.push_back(q0);
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
