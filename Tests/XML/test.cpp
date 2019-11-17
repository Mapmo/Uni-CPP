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
	std::cout << "Test 1 po XML\nIzgotven ot Mapmo, M. i Dakata\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simulaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	std::cout << "Izpolzvaite system(\"CLS\"); ako konzolata vi ne se chisti\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("clear");
	std::vector<Question> exam;
	std::srand(std::time(0));

	Question w0("XSL елементът Apply-Templates се използва вътре в един шаблон (template) заизвикване на други шаблони. Той:");
        w0.AddOption("активира рекурсивно обработката на всички наследници на елемента, за който се отнася", 1);
        w0.AddOption("активира нерекурсивно обработката на всички наследници на елемента, закойто се отнася", -1);  
        exam.push_back(w0);

	Question w2("DocumentType::Node Interface се използва за получаване на информация за документ,описан в DTD.?");
        w2.AddOption("DOM 1.0 не разрешава редактиране на този възел", 1);
        w2.AddOption("DOM 1.0 разрешава редактиране на този възел", -1); 
	exam.push_back(w2);

	Question w3("Кое е името на подразбиращото се (default) пространство от имена в декларацията по-долу:?\n\n <?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n<pers:person xmlns:perfs=\"http://sernaferna.com\"\n\t\txmlns:perfs=\"http://w3.org/1999\"?>");
        w3.AddOption("няма подразбиращото се (default) пространство от имена", 1);
        w3.AddOption("pers", -1);
        w3.AddOption("зависи от XML парсера", -1);
        w3.AddOption("и pers, и html", -1);
        w3.AddOption("html", -1);
	exam.push_back(w3);

	Question w04("В XLink, изходящите връзки (outbound links) могат да имат:");
        w04.AddOption("произволен краен брой участващи в тях ресурси", 1);
        w04.AddOption("точно два участващи в тях ресурса", -1);
        w04.AddOption("не по-малко от два участващи ресурса", -1);
        exam.push_back(w04);

	Question w05("Регулярният израз [1-9]?[0-9] дефинира XSchema стрингови стойности, които са:");
        w05.AddOption("от 1 до 99", -1);
        w05.AddOption("от 1 до 90", -1);
        w05.AddOption("от 0 до 99", 1);
        w05.AddOption("от 1 до 9", -1);
        exam.push_back(w05);

	Question w06("SAX Element обектите:");
        w06.AddOption("зависи от SAX парсера", -1);
        w06.AddOption("могат да разграничават атрибутите, дефинирани изрично, от тези специфицирани в DTD", 1);
        w06.AddOption("не могат да разграничават атрибути, дефинирани изрично, от тези специфицирани в DTD", -1);
        exam.push_back(w06);

	Question w07("Общо текстово Entity:");
        w07.AddOption("Може да бъде използвано рекурсивно, но не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        w07.AddOption("Може да бъде използвано рекурсивно и може да се появи в съдържанието на елемент, но не и в стойност на атрибут", -1);
        w07.AddOption("Не може да бъде използвано рекурсивно, но може да се появи в съдържанието на елемент и/или в стойност на атрибут", 1);
        w07.AddOption("Може да бъде използвано рекурсивно и може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
	w07.AddOption("Не може да бъде използвано рекурсивно и не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        exam.push_back(w07);
	
	Question w08("На показаната фигура на RDF граф, T-shirt e?\n\nT-shirt --color--> White");
        w08.AddOption("дериват", -1);
        w08.AddOption("обект", -1);
        w08.AddOption("предикат", -1);
        w08.AddOption("субект", 1);
        exam.push_back(w08);

	Question w09("Кое от твърденията е истина?");
        w09.AddOption("само DOM Element обектите имат атрибути", 1);
        w09.AddOption("и DOM Element, и DOM Node обектите имат атрибути", -1);
        w09.AddOption("cамо DOM Node обектите имат атрибути", -1);
        exam.push_back(w09);

	Question w10("Един XML документ може да има повече от едно вътрешно DTD.");
	w10.AddOption("невярно", 1);
	w10.AddOption("вярно", -1);
	exam.push_back(w10);
	
	Question w11("Приложения, които имат нужда от сложни структурни манипулации на много от XML елементите, трябва да използват:");
	w11.AddOption("DOM", 1);
	w11.AddOption("SAX", -1);
	w11.AddOption("Stax API", -1);
	w11.AddOption("CSS", -1);
	w11.AddOption("XSLT", -1);
	exam.push_back(w11);
	
	Question w12("В XSchema, глобалните типове:");
	w12.AddOption("могат да не бъдат директни наследници на корена", -1);
	w12.AddOption("не могат да бъдат директни наследници на корена", -1);
	w12.AddOption("могат да бъдат или да не бъдат директни наследници на корена", -1);
	w12.AddOption("винаги са директни наследници на корена", 1);
	exam.push_back(w12);
	
	Question w13("Разгледайте <xsl:value-of> елемента. Ако стойността на неговия select атрибут е select='.', тогава ние избираме:");
	w13.AddOption("текстовия контекст на всички наследници на елемента", -1);
	w13.AddOption("текстовия контекст само на елемента", -1);
	w13.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", 1);
	w13.AddOption("същия текстов контекст, както когато използваме text() функцията", -1);
	exam.push_back(w13);
	
	Question w14("Един XML документ може да има повече от едно DTD.");
	w14.AddOption("вярно", 1);
	w14.AddOption("невярно", -1);
	exam.push_back(w14);
	
	Question w15("В RDF, група от алтернативни стойности се задава чрез:");
	w15.AddOption("<rdf:Switch>", -1);
	w15.AddOption("<rdf:Alt>", 1);
	w15.AddOption("<rdf:Opt>", -1);
	w15.AddOption("<rdf:Choice>", -1);
	w15.AddOption("<rdf:Case>", -1);
	exam.push_back(w15);
	
	Question w16("Квалифицирано XML име (наречено QName) е:");
	w16.AddOption("всяко валидно XML име", -1);
	w16.AddOption("всяко име на XML елемент", -1);
	w16.AddOption("име от вида namespace_prefix:local_name", 1);
	w16.AddOption("всяко XML име на пространство от имена", -1);
	exam.push_back(w16);
	
	Question w17("Описанието в RDF на групa, съдържащa само зададените в описанието членове, става чрез използване на:");
	w17.AddOption("последователност", -1);
	w17.AddOption("колекция", 1);
	w17.AddOption("алтернативa", -1);
	w17.AddOption("множество", -1);
	w17.AddOption("bag", -1);
	exam.push_back(w17);

	Question w18("Целта на валидацията на XML документ от XML парсера е да се провери дали XML документът е добре структуриран (well-formed).");
	w18.AddOption("Вярно", -1);
	w18.AddOption("Невярно", 1);
	exam.push_back(w18);

	Question w19("В OWL, също както и в ООП, не може да съществуват два класа с общи екземпляри.");
	w19.AddOption("Вярно", -1);
	w19.AddOption("Невярно", 1);
	exam.push_back(w19);

	Question w20("Описанието\nex:adrian foaf:knows ex:gerd.\nex:adrian foaf:age "41"^^xs:int.\nпредставя RDF Triples в:");
	w20.AddOption("RDFa формат.", -1);
	w20.AddOption("N3 формат.", 1);
	w20.AddOption("Turtle формат.", -1);
	w20.AddOption("RDF/XML формат.", -1);
	exam.push_back(w20);

	Question w21("Могат ли екземплярите на класовете да бъдат част от онтологията, описваща тези класове?");
	w21.AddOption("да", 1);
	w21.AddOption("Не", -1);
	exam.push_back(w21);

	Question w22("XML Schema разрешава да се прави разлика между уникална стойност (unique) и ключ (key).");
	w22.AddOption("вярно", 1);
	w22.AddOption("невярно", -1);
	exam.push_back(w22);

	Question w23("В XLink, входящите дъги (inbound arcs) могат да имат:");
	w23.AddOption("произволен краен брой участващи в тях ресурси", 1);
	w23.AddOption("точно два участващи в тях ресурса", -1);
	exam.push_back(w23);

	Question w24("Осъществяването на еmbedding (а не inlining) на Style Sheet според CSS правилата е възможно посредством:");
	w24.AddOption("елемента EMBED", -1);
	w24.AddOption("атрибута STYLE", -1);
	w24.AddOption("елемента STYLE", 1);
	w24.AddOption("елемента LINK", -1);
	exam.push_back(w24);

	Question w25("Параметрично Entity:");
	w25.AddOption("се дефинира в маркъп декларациите в DTD, но може да се използва в който и да е XML документ", -1);
	w25.AddOption("се дефинира в маркъп декларациите в DTD и може да се използва само в DTD дефиниции", 1);
	w25.AddOption("се дефинира в XML документа и може да се използва в който и да е XML документ", -1);
	exam.push_back(w25);

	Question w26("В RDFS, Property е подмножество на RDFS Resources и има за домейн (rdfs:domain):");
	w26.AddOption("множество от отделни стойности на това Property", -1);
	w26.AddOption("типa на стойностите на това Property", -1);
	w26.AddOption("класa rdfs:Resource, на който принадлежат всички екземпляри на ресурса", -1);
	w26.AddOption("класa, асоцииран с това Property", 1);
	exam.push_back(w26);

	Question w27("В CSS3, абсолютната (аbsolute) схема за позициониране:");
	w27.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", 1);
	w27.AddOption("задава липса на движение на кутията при движение на документа за continuous media", -1);
	w27.AddOption("предизвиква повторение на кутията на всяка страница при paged media", -1);
	w27.AddOption("предефинира top и left позициите на кутията", -1);
	exam.push_back(w27);

	Question w28("XML пространствата от имена се дефинират чрез атрибути и могат да бъдат специфицирани в кой да е XML елемент.");
	w28.AddOption("вярно", 1);
	w28.AddOption("невярно", -1);
	exam.push_back(w28);

	Question w29("В XSchema, типът на всеки елемент на еквивалентен клас трябва да бъде:");
	w29.AddOption("същият като типа на елемента-екземпляр, или негов дериват", 1);
	w29.AddOption("различен от типа на елемента-екземпляр", -1);
	w29.AddOption("същият като типа на елемента-екземпляр", -1);
	w29.AddOption("дериват на типа на елемента-екземпляр", -1);
	exam.push_back(w29);





	/*
	Question w2("");
	w2.AddOption("", -1);
	w2.AddOption("", -1);
	w2.AddOption("", -1);
	w2.AddOption("", -1);
	exam.push_back(w2);

*/

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[i], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "Sekciq sus sgresheni vuprosi\nnatisnete nqkoy buton\n";
			std::cin >> useless;
			system("clear");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("clear");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	return 0;
}
















