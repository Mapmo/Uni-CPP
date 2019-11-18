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

	Question w22("XML Schema разрешава да се прави разлика между уникална стойност (unique) и ключ (key).");
	w22.AddOption("вярно", 1);
	w22.AddOption("невярно", -1);
	exam.push_back(w22);

	Question w24("Осъществяването на embedding (а не inlining) на Style Sheet според CSS правилата е възможно посредством:");
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
	
	Question w33("Binary entity може да се използва само като атрибут от тип ENTITY.");
	w33.AddOption("вярно", 1);
	w33.AddOption("невярно", -1);
	exam.push_back(w33);
	
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
	w38.AddOption("6-32-47843-5", 1);
	exam.push_back(w38);
	
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

	Question w47("В XSchema, локалните типове:");
	w47.AddOption("винаги са директни наследници на корена", -1);
	w47.AddOption("могат да бъдат директни наследници на корена", -1);
	w47.AddOption("могат да бъдат или да не бъдат директни наследници на корена", -1);
	w47.AddOption("не могат да бъдат директни наследници на корена", 1);
	exam.push_back(w47);

	Question w48("Описанието\nex:adrian foaf:knows ex:gerd.\nex:adrian foafage \"41\"^^xs:int.\nпредставя RDF Triples в:");
	w48.AddOption("RDF/XML формат.", -1);
	w48.AddOption("N3 формат.", 1);
	w48.AddOption("Turtle формат.", -1);
	w48.AddOption("RDFa формат.", -1);
	exam.push_back(w48);

	Question w49("CDATA съдържанията са:");
	w49.AddOption("или парсвани, или игнорирани от XML парсерите в зависимост от CDATA директивата", -1);
	w49.AddOption("игнорирани от XML парсерите", 1);
	w49.AddOption("парсвани от XML парсерите", -1);
	exam.push_back(w49);
	
	Question w51("Кой от следните изрази е валиден пример за дефиниране на избор (choice) от елементи в DTD:");
	w51.AddOption("(A ˇ B ˇ C)", -1);
	w51.AddOption("(A | B | C)", 1);
	w51.AddOption("(A or B or C)", -1);
	w51.AddOption("(A, B, C)", -1);
	exam.push_back(w51);

	Question w52("XML пространствата от имена се използват за разграничаване:");
	w52.AddOption("нито на XML елементи, нито на XML атрибути", -1);
	w52.AddOption("и на XML елементи, и на XML атрибути", 1);
	w52.AddOption("само на XML елементи", -1);
	w52.AddOption("само на XML атрибути", -1);
	exam.push_back(w52);

	Question w53("Person, title, familyName, knows, age, Document и Organization са име на елементи, дефинирани от:");
	w53.AddOption("OWL", -1);
	w53.AddOption("FOAF", 1);
	w53.AddOption("RDFS", -1);
	exam.push_back(w53);

	Question w54("Ако сме дефинирали XSL променлива като\n<xsl:variable name=\"price\">low</xsl:variable>\n, то тя може да се използва в XSL елемент като:");
	w54.AddOption("<xsl:value-of select=\"{$price}\"/>", -1);
	w54.AddOption("<xsl:value-of select=\"@price\"/>", -1);
	w54.AddOption("<xsl:value-of select=\"$price\"/>", 1);
	exam.push_back(w54);

	Question w55("Разгледайте <xsl:value-of> елемента. Ако стойността на неговия select атрибут е select='.', тогава ние избираме:");
	w55.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", 1);
	exam.push_back(w55);

	Question w56("Изпълнението на XSLT (*XSTL*) декларациите\n<xsl:value-of select=\".\"и\n<xsl:value-of select=\"text()\"/>\nводи:");
	w56.AddOption("до един и същ или до различни резултати в зависимост от типа на съдържанието на текущия елемент", 1);
	exam.push_back(w56);

	Question w57("В XSLT, (*XSTL*) взимането на решение кои елементи ще бъдат обработени се задава със следния XSLT елемент");
	w57.AddOption("<xsl:apply-templates>", 1);
	exam.push_back(w57);

	Question w58("При приилагането на XSLT трансформацията (shrink) Bob Steve <name>");
	w58.AddOption("със съдържанието на елементите в изходящото дърво", 1);
	exam.push_back(w58);

	Question w59("XPath изразът //book[@pages] връща");
	w59.AddOption("всички book елементи, които имат атрибут pages", 1);
	exam.push_back(w59);

	Question w60("XPath изразът ./book[author/last=\"пробен изпит\" връща:");
	w60.AddOption("елемент book - наследник на текущия елемент, който има елемент author с поделемент last равен на 'пробен изпит'", 1);
	exam.push_back(w60);

	Question w61("Всеки DOM възел (Node) може да има деца.");
	w61.AddOption("вярно", 1);

	Question w62("Методът getAttributes() на DOM интерфейса Node връща:");
	w62.AddOption("NamedNodeMap", 1);

	Question w63("DOMException връща HIERARCHY_REQUEST_ERR при опит за:");
	w63.AddOption("вмъкване на възел на неподходящо място в йерархията на DOM дървото", 1);

	Question w64("SAX служи както за четене на XML документи, така и за генериране на XML");
	w64.AddOption("Невярно", 1);

	Question w65("XMLReader в SAX 2.0 разширява стандартния Java Reader интерфейс");
	w65.AddOption("Невярно", 1);

	Question w66("Събитието processingInstruction възниква, когато SAX парсерът достигне до всяка една инструкция за обработка, включително и до XML декларацията.");
	w66.AddOption("Невярно", 1);

	Question w67("Изберете едно");
	w67.AddOption("SAX използва push парсване, StAX - парсване от тип pull", 1);

	Question w68("При парсване на XML документи посредством StAX, можем да се придвижваме само напред в XML документа.");
	w68.AddOption("Истина", 1);

	Question w69("В CSS3 абсолютна (absolute) схема за позициониране:");
	w69.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", 1);

	Question w70("В CSS, задаването на елемент, чийто атрибут attr има стойност, съдържаща на произволно място в себе си стойността xpto, става чрез");
	w70.AddOption("[attr~=xpto]", 1);

	Question q00("Редът <!ATTLIST point honorific (Mr|Ms|Mrs|Rev|Dr) ... > е валиден DTD пример за:");
        q00.AddOption("namegroup", 1);
        q00.AddOption("CDATA", -1);
        q00.AddOption("NMTOKENS", -1);
        q00.AddOption("notation", -1);
        exam.push_back(q00);

	Question q03("RDF Literals могат да бъдат зададени само като обект в RDF тройка.");
        q03.AddOption("верно", 1);
        q03.AddOption("неверно", -1);
        exam.push_back(q03);

	Question q04("Разгледайте имената на XML празните елементи <emptyTag /> и <emptyTag/ >. Те са:");
        q04.AddOption("и двата валидни", -1);
        q04.AddOption("първият е валиден, вторият е невалиден", 1);
        q04.AddOption("нито едно от по-горе посочените", -1);
        q04.AddOption("и двата невалидни", -1);
	q04.AddOption("първият е невалиден, вторият е валиден", -1);
        exam.push_back(q04);

	Question q05("В XLink, входящите дъги (inbound arcs) могат да имат:");
        q05.AddOption("точно два участващи в тях ресурса", 1);
        q05.AddOption("произволен краен брой участващи в тях ресурси", -1);
        exam.push_back(q05);

	Question q07("Resource Description Framework (RDF) представя информация за ресурси, които:");
        q07.AddOption("трябва да бъдат достъпни в Уеб", -1);
        q07.AddOption("не могат да бъдат достъпни в Уеб", -1);
        q07.AddOption("могат да бъдат или да не бъдат достъпни в Уеб", 1);
        exam.push_back(q07);

	Question q08("Даден CSS стил може да бъде inlined (а не embedded) в документ посредством:");
        q08.AddOption("елемента INLINE", -1);
        q08.AddOption("атрибута INLINE", -1);
        q08.AddOption("елемента STYLE", -1);
        q08.AddOption("атрибута STYLE", 1);
        exam.push_back(q08);

	Question q09("Една XLink дъга (arc), която има локален стартов ресурс и отдалечен краен ресурс, се нарича:");
        q09.AddOption("outbound", 1);
        q09.AddOption("inbound", -1);
        q09.AddOption("сочеща трети (third-party) ресурс", -1);
        exam.push_back(q09);

	Question q10("Записът\n@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>.\n@prefix contact: <http://www.w3.org/2000/10/swap/pim/contact#>.\n<http://www.w3.org/People/EM/contact#me>\nrdf:type contact:Person;\ncontact:fullName Eric Miller;\ncontact:mailbox <mailto:em@w3.org>;\ncontact:personalTitle \"Dr.\".\nпредставя по-долния RDF граф в:");
        q10.AddOption("N3", -1);
        q10.AddOption("RDFa", -1);
        q10.AddOption("Turtle", 1);
        q10.AddOption("RDF/XML", -1);
        exam.push_back(q10);

	Question q11("MEDIA атрибутите като screen, aural, braille, tty, и т.н., са част от:");
        q11.AddOption("само от CSS1 спецификацията", -1);
        q11.AddOption("CSS1 и CSS2 спецификациите", -1);
        q11.AddOption("CSS2 и CSS3 спецификациите", 1);
        q11.AddOption("само от CSS3 спецификацията", -1);
	q11.AddOption("само от CSS2 спецификацията", -1);
        exam.push_back(q11);

	Question q13("Изберете верното:");
        q13.AddOption("Един URI не може да бъде нито URL, нито URN", -1);
        q13.AddOption("Един URI може да бъде или URL, или URN", 1);
        q13.AddOption("Един URI може да бъде URL и URN едновременно", -1);
        q13.AddOption("Един URN може да бъде или URL, или URI", -1);
	q13.AddOption("Един URL може да бъде или URI, или URN", -1);
        exam.push_back(q13);

	Question q14("Могат ли екземплярите на класовете да бъдат част от онтологията, описваща тези класове?");
        q14.AddOption("да", 1);
        q14.AddOption("не", -1);
        exam.push_back(q14);

	Question q15("В XML Schema, ние можем да построим производни (derived) types:");
        q15.AddOption("само с restrictions", -1);
        q15.AddOption("само с extensions", -1);
        q15.AddOption("както с extensions, така и с restrictions", 1);
        exam.push_back(q15);

	Question q17("Разгледайте P:first-letter { font-size: 200% } . Това е:");
        q17.AddOption("CSS клас", -1);
        q17.AddOption("псевдо-атрибут (pseudo-attribute)", -1);
        q17.AddOption("нито едно от по-горе посочените", -1);
        q17.AddOption("псевдо-елемент (pseudo-element)", 1);
        exam.push_back(q17);

	Question q19("XSchema шаблонен фасет (pattern facet) е фасет за данни от тип:");
        q19.AddOption("decimal", -1);
        q19.AddOption("integer", -1);
        q19.AddOption("string", 1);
        q19.AddOption("binary", -1);
        exam.push_back(q19);

	Question q20("Единственото изискване един XML документ да бъде валиден е този документ да е структуриран (формиран) съгласно правилата за XML синтаксиса.");
        q20.AddOption("верно", 1);
        q20.AddOption("неверно", -1);
        exam.push_back(q20);

	Question q21("Регулярният израз [^0-9]x дефинира XSchema стрингови стойности, които представляват:");
        q21.AddOption("x пъти повторение на който и да е цифров символ", -1);
        q21.AddOption("x пъти повторение на който и да е не-цифров символ", -1);
        q21.AddOption("символът ^, последван от произволна цифра следвана от символа x", -1);
        q21.AddOption("който и да е не-цифров символ, следван от символа x", 1);
        exam.push_back(q21);

	Question q26("Уникална идентификация на пространство от имена се реализира с:");
        q26.AddOption("URI (и URL, и URN)", -1);
        q26.AddOption("URL", 1);
        q26.AddOption("URN", -1);
        exam.push_back(q26);

	Question q27("rdf:Seq задава:");
        q27.AddOption("група на подредени ресурси или литерали, с вероятно дублиране", 1);
        q27.AddOption("група на неподредени ресурси или литерали, без дублиране", -1);
        q27.AddOption("група на неподредени ресурси или литерали, с вероятно дублиране", -1);
        q27.AddOption("група на подредени ресурси или литерали, без дублиране", -1);
	q27.AddOption("група на алтернативни ресурси или литерали", -1);
        exam.push_back(q27);

	Question q28("В XSchema, типът на всеки елемент на еквивалентен клас трябва да бъде:");
        q28.AddOption("различен от типа на елемента-екземпляр", -1);
        q28.AddOption("дериват на типа на елемента-екземпляр", -1);
        q28.AddOption("същият като типа на елемента-екземпляр", -1);
        q28.AddOption("същият като типа на елемента-екземпляр, или негов дериват", 1);
        exam.push_back(q28);

	Question q29("В XSchema, референцията (напр. ) може да реферира:");
        q29.AddOption("само към глобални типове", 1);
        q29.AddOption("нито към локални, нито към глобални типове", -1);
        q29.AddOption("както към локални, така и към глобални типове", -1);
        q29.AddOption("само към локални типове", -1);
        exam.push_back(q29);

	Question q30("За постигане на по-малък, ефикасен и бърз код с използване на StAX, се препоръчва:");
        q30.AddOption("StAX Events API", -1);
        q30.AddOption("cursor API", 1);
        q30.AddOption("iterator API", -1);
        q30.AddOption("StAX Direct Mapping API", -1);
        exam.push_back(q30);

	Question q33("Атрибутите на XML са чувствителни към регистъра.");
        q33.AddOption("невярно", -1);
        q33.AddOption("вярно", 1);
        exam.push_back(q33);

	Question q35("При използването на XPath text() функцията, ние избираме:");
        q35.AddOption("същият текстов контекст както когато използваме <xsl:value-of select='.'> елемента", -1);
        q35.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", -1);
        q35.AddOption("текстовия контекст само на елемента", -1);
        q35.AddOption("текстовия контекст на всички наследници на елемента", 1);
        exam.push_back(q35);

	Question q36("Ако в XSchema дефинираме exact тип, то:");
        q36.AddOption("той може да има дериватни типове, и те могат да бъдат използвани в XML документа вместо този exact тип", -1);
        q36.AddOption("b. той може да има дериватни типове, но те не могат да бъдат използвани в XML документа вместо този exact тип", 1);
        q36.AddOption("c. той може да има дериватни типове, но те могат да бъдат използвани в XML документа вместо този exact тип само при определени условия", -1);
        q36.AddOption("той не може да има дериватни типове", -1);
        exam.push_back(q36);

	Question q37("В SAX, приложните обекти, имащи достъп до XML сорса:");
        q37.AddOption("са регистрирани за callback функции или от програмиста, или от парсера", 1);
        q37.AddOption("трябва да бъдат регистрирани (от програмиста) за callback функциите на парсера", -1);
        q37.AddOption("не трябва да бъдат регистрирани от програмиста за callback функции, тъй като те са listeners", -1);
        exam.push_back(q37);

	Question q38("Ако няма специфицирано кодиране за един XML документ и документът не е нито в UTF-8, нито в UTF-16, тогава резултатът е:");
        q38.AddOption("ERROR", 1);
        q38.AddOption("UTF-8", -1);
        q38.AddOption("ISO 8859-1", -1);
        q38.AddOption("UTF-16", -1);
        exam.push_back(q38);

	Question q41("Кой от следните изрази е валиден пример за дефиниране на последователност (sequence) от елементи в DTD:");
        q41.AddOption("(A, B, C)", 1);
        q41.AddOption("(A ^ B ^ C)", -1);
        q41.AddOption("(A and B and C", -1);
        q41.AddOption("(A | B | C)", -1);
        exam.push_back(q41);

	Question q47("С един DOM Element обект:");
        q47.AddOption("може да направите разлика между подразбираща се (default) стойност, определена в DTD, и стойността, дадена в XML файла", -1);
        q47.AddOption("не може да направите разлика между подразбираща се (default) стойност, определена в DTD, и стойността, дадена в XML файла", 1);
        exam.push_back(q47);

	Question q48("В RDFS, Property е подмножество на RDFS Resources и има за домейн (rdfs:domain):");
        q48.AddOption("класa, асоцииран с това Property", 1);
        q48.AddOption("множество от отделни стойности на това Property", -1);
        q48.AddOption("типa на стойностите на това Property", -1);
        q48.AddOption("класa rdfs:Resource, на който принадлежат всички екземпляри на ресурса ой от елементите ISBN по-долу не се описва от дефиницията <element name=\"ISBN\"", -1);
        exam.push_back(q48);

	Question q50("що текстово Entity:");
        q50.AddOption("Може да бъде използвано рекурсивно и може да се появи в съдържанието на елемент, но не и в стойност на атрибут", 1);
        q50.AddOption("Не може да бъде използвано рекурсивно, но може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        q50.AddOption("Може да бъде използвано рекурсивно и може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        q50.AddOption("Може да бъде използвано рекурсивно, но не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        q50.AddOption("Не може да бъде използвано рекурсивно и не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
        exam.push_back(q50);

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
