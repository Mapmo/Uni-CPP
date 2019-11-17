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

	Question w20("Описанието\nex:adrian foaf:knows ex:gerd.\nex:adrian foaf:age \"41\"^^xs:int.\nпредставя RDF Triples в:");
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

	Question w30("XSL се използва за:");
	w30.AddOption("трансформиране на XML документ към друг текстов документ", 1);
	w30.AddOption("трансформиране на XML документ към друг документ само в HTML формат", -1);
	w30.AddOption("трансформиране на XML документ към друг документ само в XML или HTML формат", -1);
	w30.AddOption("трансформиране на XML документ към друг документ само в XML формат", -1);
	exam.push_back(w30);
	
	Question w31("XSL кодът, показан на фигурата, ще даде като резултат:\n<xsl:template match=\"name\">\n\txsl:element name=\"{.}\"> My own contents!\n\t</xsl:element>\n</xsl:template>");
	w31.AddOption("изходните XML елементи ще бъдат с имена, еднакви със съдържанието на елементите от сорс дървото, и със съдържание \"My own contents!\"", 1);
	w31.AddOption("същите елементи в изходния XML файл както в сорс XML файла, и с коментар \"My own contents!\" за всеки един елемент", -1);
	w31.AddOption("същите елементи в изходния XML файл както в сорс XML файла, но с добавено в края съдържание \"My own contents!\"", -1);
	exam.push_back(w31);
	
	Question w32("Resource Description Framework (RDF) представя информация за ресурси, които:");
	w32.AddOption("могат да бъдат или да не бъдат достъпни в Уеб", 1);
	w32.AddOption("не могат да бъдат достъпни в Уеб", -1);
	w32.AddOption("трябва да бъдат достъпни в Уеб", -1);
	exam.push_back(w32);
	
	Question w33("Binary entity може да се използва само като атрибут от тип ENTITY.");
	w33.AddOption("вярно", 1);
	w33.AddOption("невярно", -1);
	exam.push_back(w33);
	
	Question w34("Уникална идентификация на пространство от имена се реализира с:");
	w34.AddOption("URL", 1);
	w34.AddOption("URN", -1);
	w34.AddOption("URI (и URL, и URN)", -1);
	exam.push_back(w34);
	
	Question w35("В SAX, приложните обекти, имащи достъп до XML сорса:");
	w35.AddOption("трябва да бъдат регистрирани (от програмиста) за callback функциите на парсера", -1);
	w35.AddOption("са регистрирани за callback функции или от програмиста, или от парсера", -1);
	w35.AddOption("не трябва да бъдат регистрирани от програмиста за callback функции, тъй като те са listeners", 1);
	exam.push_back(w35);
	
	Question w36("Annotation Property в OWL се използва за добавяне на метаданни:");
	w36.AddOption("само към класове", -1);
	w36.AddOption("към екземпляри и към свойства", -1);
	w36.AddOption("само към екземпляри", -1); 
	w36.AddOption("към класове и към свойства", -1);
	w36.AddOption("към класове, екземпляри и свойства", 1);
       	w36.AddOption("към класове и към екземпляри", -1);
	w36.AddOption("само към свойства (properties)", -1);
	exam.push_back(w36);
	
	Question w37("Всяко IDREF, декларирано в DTD, трябва да:");
	w37.AddOption("избере дадено определено ID", 1);
	w37.AddOption("избере кое да е ID", -1);
	w37.AddOption("избере можество ID-та", -1);
	exam.push_back(w37);
	
	Question w38("Кой от елементите ISBN по-долу не се описва от дефиницията <element name=\"ISBN\" type=\"cat:ISBNType\"/>, където ISBNType е:\n<datatype name=\"ISBNTYPE\" source=\"string\">\n\t<pattern value=\"\\d{5}-\\d{5}-\\d{5}/>\n</datatype>");
	w38.AddOption("12345-54321-98765", -1);
	w38.AddOption("63247-84365-12345", -1);
	w38.AddOption("4-256-76435-4", -1);
	w38.AddOption("6-32-47843-5", -1);
	exam.push_back(w38);
	
	Question w39("В CSS3, фиксираната (fixed) схема за позициониране:");
	w39.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", -1);
	w39.AddOption("се контролира от браузера с цел по-бързо показване на съдържанието", -1);
	w39.AddOption("предизвиква повторение на кутията на всяка страница при paged media", 1);
	w39.AddOption("предефинира top и left позициите на кутията", -1);
	exam.push_back(w39);

	Question w40("В CSS3, фиксираната (fixed) схема за позициониране:");
	w40.AddOption("предизвиква повторение на кутията на всяка страница при paged media", 1);
	w40.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", -1);
	w40.AddOption("предефинира top и left позициите на кутията", -1);
	w40.AddOption("се контролира от браузера с цел по-бързо показване на съдържанието", -1);
	exam.push_back(w40);


	Question w41("creator, title, publisher, contributor, date и format са име на елементи, дефинирани от:");
	w41.AddOption("RDFS", 1);
	w41.AddOption("DC", -1);
	w41.AddOption("FOAF", -1);
	w41.AddOption("OWL", -1);
	exam.push_back(w41);


	Question w42("При избиране на елемент, наречен MyElem и имащ атрибут Attr със стойност title, ние трябва да използваме:");
	w42.AddOption("select=\"MyElem[@Attr='title']\"", 1);
	w42.AddOption("select=\"MyElem{@Attr='title'}\"", -1);
	w42.AddOption("select=\"MyElem(@Attr='title')\"", -1);
	w42.AddOption("select=\"MyElem[Attr='title']\"", -1);
	exam.push_back(w42);


	Question w43("Какво не е възможно да бъде описано в DTD:");
	w43.AddOption("къде типът на елементите може да се среща", -1);
	w43.AddOption("какви имена могат да бъдат използувани за тип на елементите", -1);
	w43.AddOption("йерархия на документа и грануларност", -1);
	w43.AddOption("имена и типове на атрибутите на елементите", -1);
	w43.AddOption("минимален и максимален брой срещания на елемент", 1);
	exam.push_back(w43);


	Question w44("XSL елементът Apply-Templates се използва вътре в един шаблон (template) за извикване на други шаблони. Той:");
	w44.AddOption("активира нерекурсивно обработката на всички наследници на елемента, за който се отнася", -1);
	w44.AddOption("активира рекурсивно обработката на всички наследници на елемента, за който се отнася", 1);
	exam.push_back(w44);


	Question w45("Целта на валидацията на XML документ от XML парсера е да се провери дали XML документът е добре структуриран (well-formed).");
	w45.AddOption("вярно", -1);
	w45.AddOption("невярно", 1);
	exam.push_back(w45);


	Question w46("rdf:Seq задава:");
	w46.AddOption("група на подредени ресурси или литерали, с вероятно дублиране", 1);
	w46.AddOption("група на неподредени ресурси или литерали, без дублиране", -1);
	w46.AddOption("група на подредени ресурси или литерали, без дублиране", -1);
	w46.AddOption("група на неподредени ресурси или литерали, с вероятно дублиране", -1);
	w46.AddOption("група на алтернативни ресурси или литерали", -1);
	exam.push_back(w46);


	Question w47("В XSchema, локалните типове:");
	w47.AddOption("винаги са директни наследници на корена", -1);
	w47.AddOption("могат да бъдат директни наследници на корена", -1);
	w47.AddOption("могат да бъдат или да не бъдат директни наследници на корена", -1);
	w47.AddOption("не могат да бъдат директни наследници на корена", 1);
	exam.push_back(w47);


	Question w48("Кое е името на подразбиращото се (default) пространство от имена в декларацията по-долу:");
	w48.AddOption("и pers, и html", -1);
	w48.AddOption("html", -1);
	w48.AddOption("pers", -1);
	w48.AddOption("зависи от XML парсера", -1);
	w48.AddOption("няма подразбиращото се (default) пространство от имена", 1);
	exam.push_back(w48);


	Question w49("DocumentType::Node Interface се използва за получаване на информация за документ, описан в DTD.");
	w49.AddOption("DOM 1.0 разрешава редактиране на този възел", -1);
	w49.AddOption("DOM 1.0 не разрешава редактиране на този възел", 1);
	exam.push_back(w49);


	Question w50("Могат ли екземплярите на класовете да бъдат част от онтологията, описваща тези класове?");
	w50.AddOption("Да", 1);
	w50.AddOption("Не", -1);
	exam.push_back(w50);

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
















