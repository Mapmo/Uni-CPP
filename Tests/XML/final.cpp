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
		{
			tmpToInt -= 65;
		
		}
		else
		{
			tmpToInt -= 97;
		}

		if(tmpToInt < m_Answers.size()) //because people complained that the code is very fragile in terms of incorrect input
		{
			m_Score += m_Answers[tmpToInt].val;
		
		}
		
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
	std::cout << "Test 1 po UK\nIzgotven ot Mapmo\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simulaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("clear");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("При включването на документа \"xpto.xml\" с използване на <xi:include href=\"xpto.xml\" parse=\"text\"/>, документът \"xpto.xml\" ще бъде включен:");
	q1.AddOption("като обикновен текст", 1);
	q1.AddOption("като XML документ, но само ако той е добре конструиран", -1);
	q1.AddOption("като XML документ, но само ако той е добре конструиран и валиден спрямо схема или DTD", -1);
	q1.AddOption("винаги като XML документ", -1);
	
	Question q2("XML пространствата от имена се дефинират чрез атрибути и могат да бъдат специфицирани в кой да е XML елемент.?");
	q2.AddOption("вeрно", 1);
	q2.AddOption("невeрно", -1);
	
	Question q3("При използване на вътрешна и външна DTD дефиниция, вътрешната DTD може да предефинира:");
	q3.AddOption("само ENTITY и ATTLIST на външната дефиниция", 1);
	q3.AddOption("само ENTITY и NOTATION на външната дефиниция", -1);
	q3.AddOption("само ENTITY, ATTLIST и NOTATION на външната дефиниция", -1);
	q3.AddOption("всички дефиниции на външната DTD", -1);
	
	Question q4("В XSchema, референцията към тип може да реферира:");
	q4.AddOption("нито към локални, нито към глобални типове", -1);
	q4.AddOption("само към глобални типове", 1);
	q4.AddOption("както към локални, така и към глобални типове", -1);
	q4.AddOption("само към локални типове", -1);
	
	Question q5("В примера по-долу:\n<x xmlns:n1=\"http://www.hayde-de.org\" xmlns=\"http://www.hayde-de.org\" >\n<ok a=\"1\" b=\"2\" />\n<hmmm a=\"1\" n1:a=\"2\" /> </x>");
	q5.AddOption("Дефиницията на елемента <hmmm> е невалидна според спецификацията на пространствата от имена.", -1);
	q5.AddOption("Дефиницията на елемента <hmmm> е валидна според спецификацията на пространствата от имена.", 1);
	
	Question q6("Приложения, които имат нужда от сложни структурни манипулации на много от XML елементите, трябва да използват:");
	q6.AddOption("StAX API", -1);
	q6.AddOption("SAX", -1);
	q6.AddOption("CSS", -1);
	q6.AddOption("DOM", 1);
	
	Question q7("При избиране на елемент, наречен MyElem и имащ атрибут Attr със стойност title, в XSLT ние трябва да използваме:");
	q7.AddOption("select=\"MyElem(@Attr='title')\"", -1);
	q7.AddOption("select=\"MyElem{@Attr='title'}\"", -1);
	q7.AddOption("select=\"MyElem[@Attr='title']\"", 1);
	q7.AddOption("select=\"MyElem[Attr='title']\"", -1);
	
	Question q8("Атрибутите, специфицирани в DTD посредством ключовата дума IMPLIED:");
	q8.AddOption("могат да бъдат определени (специфицирани) в XML", 1);
	q8.AddOption("имат стойност по подразбиране, ако не са определени (специфицирани) в XML", -1);
	q8.AddOption("имат само една допустима стойност", -1);
	q8.AddOption("трябва да бъдат определени (специфицирани) в XML", -1);
	
	Question q9("Binary entity може да се използва само като атрибут от тип ENTITY?");
	q9.AddOption("неверно", -1);
	q9.AddOption("верно", 1);
	
	Question q10("В XML Schema, ние можем да построим производни (derived) types:");
	q10.AddOption("само с extensions", -1);
	q10.AddOption("само с restrictions", -1);
	q10.AddOption("както с extensions, така и с restrictions", 1);
	
	Question q11("В CSS3, абсолютната (аbsolute) схема за позициониране:");
	q11.AddOption("предефинира top и left позициите на кутията", -1);
	q11.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", 1);
	q11.AddOption("предизвиква повторение на кутията на всяка страница при paged media", -1);
	q11.AddOption("задава липса на движение на кутията при движение на документа за continuous media", -1);
	
	Question q12("Разгледайте имената на XML празните елементи <emptyTag /> и <emptyTag/ >. Те са");
	q12.AddOption("и двата невалидни", -1);
	q12.AddOption("първият е невалиден, вторият е валиден", -1);
	q12.AddOption("и двата валидни", -1);
	q12.AddOption("първият е валиден, вторият е невалиден", 1);
	
	Question q13("xml:id e псевдо-атрибут, който задава условие за уникална стойност, като това:");
	q13.AddOption("е необходимо да се декларира в XML схема.", -1);
	q13.AddOption("е необходимо да се декларира в DTD или XML схема.", -1);
	q13.AddOption("е необходимо да се декларира в DTD.", -1);
	q13.AddOption("не е необходимо да се декларира в DTD или XML схема.", 1);
	
	Question q14("В XSchema, глобалните типове:");
	q14.AddOption("могат да бъдат или да не бъдат директни наследници на корена", -1);
	q14.AddOption("не могат да бъдат директни наследници на корена", -1);
	q14.AddOption("винаги са директни наследници на корена", 1);
	q14.AddOption("могат да не бъдат директни наследници на корена", -1);
	
	Question q15("DocumentType::Node Interface се използва за получаване на информация за документ, описан в DTD.");
	q15.AddOption("DOM 1.0 не разрешава редактиране на този възел", 1);
	q15.AddOption("DOM 1.0 разрешава редактиране на този възел", -1);
	
	Question q16("Ако няма специфицирано кодиране за един XML документ и документът не е нито в UTF-8, нито в UTF-16, тогава резултатът е:");
	q16.AddOption("UTF-8", -1);
	q16.AddOption("UTF-16", -1);
	q16.AddOption("ISO 8859-1", -1);
	q16.AddOption("ERROR", 1);
	
	Question q17("XPath изразът //book[@pages] връща:");
	q17.AddOption("всички book елементи, които имат атрибут pages", 1);
	q17.AddOption("първият book елемент, който има атрибут pages", -1);
	q17.AddOption("първият book елемент, който има непразен атрибут pages", -1);
	q17.AddOption("всички book елементи, които имат непразен атрибут pages", -1);
	
	Question q18("XLink не може да дефинира фрагментни идентификатори за URI, сочещи към възли или части от тях в XML ресурси.");
	q18.AddOption("верно", 1);
	q18.AddOption("неверно", -1);
	
	Question q19("Една XLink дъга (arc), която има локален стартов ресурс и отдалечен краен ресурс, се нарича:");
	q19.AddOption("сочеща трети (third-party) ресурс", -1);
	q19.AddOption("outbound", 1);
	q19.AddOption("inbound", -1);
	
	Question q20("Единственото изискване един XML документ да бъде валиден е този документ да е структуриран (формиран) съгласно правилата за XML синтаксиса.");
	q20.AddOption("верно", -1);
	q20.AddOption("неверно", 1);
	
	Question q21("Кой от отговорите по-долу не съдържа име на RDFS свойство:");
	q21.AddOption("rdfs:comment", -1);
	q21.AddOption("rdfs:range", -1);
	q21.AddOption("rdfs:subClassOf", -1);
	q21.AddOption("rdfs:subRange", 1);
	
	Question q22("rdf:Seq задава:");
	q22.AddOption("група на неподредени ресурси или литерали, с вероятно дублиране", -1);
	q22.AddOption("група на алтернативни ресурси или литерали", -1);
	q22.AddOption("група на подредени ресурси или литерали, с вероятно дублиране", 1);
	q22.AddOption("група на подредени ресурси или литерали, без дублиране", -1);
	
	Question q23("Записът\n@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>. @prefix contact: <http://www.w3.org/2000/10/swap/pim/contact#>.\n<http://www.w3.org/People/EM/contact#me> rdf:type contact:Person;\ncontact:fullName \"Eric Miller\"; contact:mailbox <mailto:em@w3.org>; contact:personalTitle \"Dr.\".\nпредставя по-долния RDF граф в:");
	q23.AddOption("Turtle", 1);
	q23.AddOption("RDFa", -1);
	q23.AddOption("N3", -1);
	q23.AddOption("RDF/XML", -1);
	
	Question q24("\"Формална, експлицитна спецификация на споделена концептуализация\" е дефиниция за:");
	q24.AddOption("валиден XML документ, представящ антология в даден жанр", -1);
	q24.AddOption("валиден RDF/XML документ", -1);
	q24.AddOption("нещо друго, което не присъства в тези отговори", 1);
	q24.AddOption("валиден XML документ", -1);
	
	Question q25("Resource Description Framework (RDF) представя информация за ресурси, които:");
	q25.AddOption("трябва да бъдат достъпни в Уеб", -1);
	q25.AddOption("могат да бъдат или да не бъдат достъпни в Уеб", 1);
	q25.AddOption("не могат да бъдат достъпни в Уеб", -1);
	
	Question q26("RDF Literals могат да бъдат зададени само като обект в RDF тройка.");
	q26.AddOption("неверно", -1);
	q26.AddOption("верно", 1);
	
	Question q27("Йерархичната подредба на понятия заедно с информация за допълнителни отношения като по-широко/по-тясно понятие, синоними, еквивалентност и др., задава:");
	q27.AddOption("Таксономия", 1);
	q27.AddOption("Списък от термини", -1);
	q27.AddOption("Онтология", -1);
	q27.AddOption("Тезаурус", 1);
	
	Question q28("На показаната фигура на RDF граф, T-shirt е:");
	q28.AddOption("предикат", -1);
	q28.AddOption("дериват", -1);
	q28.AddOption("субект", 1);
	
	Question q29("Annotation Property в OWL се използва за добавяне на метаданни:");
	q29.AddOption("към класове, екземпляри и свойства", 1);
	q29.AddOption("към класове и към екземпляри", -1);
	q29.AddOption("само към свойства (properties)", -1);
	q29.AddOption("към екземпляри и към свойства", -1);
	q29.AddOption("само към класовеи", -1);	
	q29.AddOption("само към свойства (properties)", -1);
	
	Question q30("Кое от показаните на фигурата средства не е пряко свързано с изграждане на семантичния Уеб: Error 404 image not found");
	q30.AddOption("Logical Support", -1);
	q30.AddOption("Semantic Annotations", -1);
	q30.AddOption("Tools", -1);
	q30.AddOption("Collaboration synchronization", 1);
	
	Question q31("В OWL, също както и в ООП, не може да съществуват два класа с общи екземпляри.");
	q31.AddOption("верно", -1);
	q31.AddOption("неверно", 1);
	
	Question q32("RDF графът от фигурата задава:");
	q32.AddOption("Лекцията е посетена от Джон, Мери, Крис и от никой друг.", -1);
	q32.AddOption("Лекцията е посетена от Джон, Мери и Крис.", 1);
	q32.AddOption("Лекцията е посетена от Джон, Мери или Крис.", -1);
	q32.AddOption("Лекцията е посетена от Джон, Мери и Крис - в този ред.", -1);
	
	Question q33("Ако свойството P е дефинирано с обхват (range) C и ресурсът R е обект в тройка с предикат P, то следва, че:");
	q33.AddOption("P rdf:type R", -1);
	q33.AddOption("R rdf:type C", 1);
	q33.AddOption("R rdf:type P", -1);
	q33.AddOption("C rdf:type P", -1);
	q33.AddOption("C rdf:type R", -1);
	
	Question q34("В RDF, група от алтернативни стойности се задава чрез:");
	q34.AddOption("<rdf:Case>", -1);
	q34.AddOption("<rdf:Alt>", 1);
	q34.AddOption("<rdf:Opt>", -1);
	q34.AddOption("<rdf:Switch>", -1);
	
	Question q35("В RDFS, Property е подмножество на RDFS Resources и има за домейн (rdfs:domain):");
	q35.AddOption("класa, асоцииран с това Property", 1);
	q35.AddOption("типa на стойностите на това Property", -1);
	q35.AddOption("множество от отделни стойности на това Property", -1);
	q35.AddOption("класa rdfs:Resource, на който принадлежат всички екземпляри на ресурса", -1);
	
	Question q36("Могат ли екземплярите на класовете да бъдат част от онтологията, описваща тези класове?");
	q36.AddOption("не", -1);
	q36.AddOption("да", 1);
	
	Question q37("Описанието\nex:adrian foaf:knows ex:gerd. ex:adrian foaf:age \"41\"^^xs:int.\nпредставя RDF Triples в:");
	q37.AddOption("Turtle формат.", -1);
	q37.AddOption("RDFa формат.", -1);
	q37.AddOption("N3 формат.", 1);
	q37.AddOption("RDF/XML формат.", -1);
	
	Question q38("Методът getAttributes() на DOM интерфейса Node връща:");
	q38.AddOption("NamedNodeMap", 1);
	q38.AddOption("Attr", -1);
	q38.AddOption("Text", -1);
	q38.AddOption("NodeList", -1);
	
	Question q39("Resource Description Framework (RDF) служи за описания, предназначени:");
	q39.AddOption("за потребителско визуализиране на метаданни", -1);
	q39.AddOption("нито за обработка от софтуерни приложения, нито за потребителско визуализиране на метаданни", -1);
	q39.AddOption("за обработка от софтуерни приложения", 1);
	q39.AddOption("както за обработка от софтуерни приложения, така и за потребителско визуализиране на метаданни", -1);
	
	Question q40("rdf:Bag задава:");
	q40.AddOption("група от ресурси или литерали, които са алтернативи", -1);
	q40.AddOption("група на неподредени ресурси или литерали, с вероятно дублиране", 1);
	q40.AddOption("група на подредени ресурси или литерали, с вероятно дублиране", -1);
	q40.AddOption("група на неподредени ресурси или литерали, без дублиране", -1);
	
	Question q41("За представяне на стойности в XML файлове, ние можем да използваме XML атрибути или XML елементи. Кой от следващите отговори не е аргумент за употреба на атрибути вместо на елементи?");
	q41.AddOption("използваме атрибути за валидация на прост (simple) тип данни", -1);
	q41.AddOption("използваме атрибут, когато той е свойство на елемента", -1);
	q41.AddOption("използваме атрибути за валидация на сложна структура", 1);
	q41.AddOption("използваме атрибут, когато информацията е присъщa за елемента, а не за под-елементите", -1);
	
	Question q42("XML Schema разрешава да се прави разлика между уникална стойност (unique) и ключ (key).");
	q42.AddOption("верно", 1);
	q42.AddOption("неверно", -1);
	
	Question q43("В XSchema, типът на всеки елемент на еквивалентен клас трябва да бъде:");
	q43.AddOption("същият като типа на елемента-екземпляр, или негов дериват", 1);
	q43.AddOption("същият като типа на елемента-екземпляр", -1);
	q43.AddOption("дериват на типа на елемента-екземпляр", -1);
	q43.AddOption("различен от типа на елемента-екземпляр", -1);
	
	Question q44("Кой от елементите ISBN по-долу не се описва от дефиницията <element name=\"ISBN\" type=\"cat:ISBNType\"/>, където ISBNType е:");
	q44.AddOption("4-256-76435-4", -1);
	q44.AddOption("1-23-579321-3", -1);
	q44.AddOption("12345-54321-98765", -1);
	q44.AddOption("6-32-47843-5", 1);
	
	Question q45("Кое от твърденията е истина:");
	q45.AddOption("само DOM Element обектите имат атрибути", 1);
	q45.AddOption("и DOM Element, и DOM Node обектите имат атрибути", -1);
	q45.AddOption("само DOM Node обектите имат атрибути", -1);
	
	Question q46("SAX Element обектите:");
	q46.AddOption("могат да разграничават атрибутите, дефинирани изрично, от тези специфицирани в DTD", 1);
	q46.AddOption("не могат да разграничават атрибути, дефинирани изрично, от тези специфицирани в DTD", -1);
	q46.AddOption("зависи от SAX парсера", -1);
	
	Question q47("В CSS3, фиксираната (fixed) схема за позициониране:");
	q47.AddOption("предизвиква повторение на кутията на всяка страница при paged media", 1);
	q47.AddOption("се характеризира със задаване на явно отместване (explicit offset) спрямо съдържащия блок", -1);
	q47.AddOption("предефинира top и left позициите на кутията", -1);
	q47.AddOption("се контролира от браузера с цел по-бързо показване на съдържанието", -1);
	
	Question q48("XSL елементът Apply-Templates се използва вътре в един шаблон (template) за извикване на други шаблони. Той: ");
	q48.AddOption("активира нерекурсивно обработката на всички наследници на елемента, за който се отнася", -1);
	q48.AddOption("активира рекурсивно обработката на всички наследници на елемента, за който се отнася", 1);
	
	Question q49("Всяко IDREF, декларирано в DTD, трябва да:");
	q49.AddOption("избере можество ID-та", -1);
	q49.AddOption("избере дадено определено ID", 1);
	q49.AddOption("избере кое да е ID", -1);
	
	Question q50("При парсване на XML документи посредством StAX, можем да се придвижваме само напред в XML документа.");
	q50.AddOption("Истина", 1);
	q50.AddOption("Лъжа", -1);
	
	Question q51("Квалифицирано XML име (наречено QName) е:");
	q51.AddOption("всяко валидно XML име", -1);
	q51.AddOption("име от вида namespace_prefix:local_name", 1);
	q51.AddOption("всяко XML име на пространство от имена", -1);
	q51.AddOption("всяко име на XML елемент", -1);
	
	Question q52("Уникална идентификация на пространство от имена се реализира с:");
	q52.AddOption("URN", -1);
	q52.AddOption("URL", 1);
	q52.AddOption("URI (и URL, и URN)", -1);
	
	Question q53("Ако сме дефинирали според стойността на атрибута \"context\"XSL променлива като\n <xsl:variable name=\"price\">low</xsl:variable>\n, то тя може да се използва в XSL елемент като:");
	q53.AddOption("<xsl:value-of select=\"@price\"/>", -1);
	q53.AddOption("<xsl:value-of select=\"$price\"/>", 1);
	q53.AddOption("<xsl:value-of select=\"{$price}\"/>", -1);
	q53.AddOption("<xsl:value-of select=\"price\"/>", -1);
	
	Question q54("В XSchema, локалните типове:");
	q54.AddOption("не могат да бъдат директни наследници на корена", 1);
	q54.AddOption("винаги са директни наследници на корена", -1);
	q54.AddOption("могат да бъдат директни наследници на корена", -1);
	q54.AddOption("могат да бъдат или да не бъдат директни наследници на корена", -1);
	
	Question q55("Ако свойството P e за субекта S, който участва в RDF тройката S P O, и имаме\nP rdfs:domain C,\nто следва, че:");
	q55.AddOption("P rdf:type S", -1);
	q55.AddOption("S rdf:type C", 1);
	q55.AddOption("S rdf:type P", -1);
	q55.AddOption("P rdf:type C", -1);
	
	Question q56("creator, title, publisher, contributor, date и format са име на елементи, дефинирани от:");
	q56.AddOption("DC", 1);
	q56.AddOption("FOAF", -1);
	q56.AddOption("RDFS", -1);
	q56.AddOption("OWL", -1);
	
	Question q57("В XLink, изходящите връзки (outbound links) могат да имат:");
	q57.AddOption("произволен краен брой участващи в тях ресурси", 1);
	q57.AddOption("точно два участващи в тях ресурса", -1);
	q57.AddOption("не по-малко от два участващи ресурса", -1);
	
	Question q58("Речник с документиран процес за актуализация се нарича:");
	q58.AddOption("контролиран", 1);
	q58.AddOption("менажиран", -1);
	q58.AddOption("деклариран", -1);
	q58.AddOption("управляван", -1);
	
	Question q59("Кой от отговорите по-долу не съдържа име на RDFS клас:");
	q59.AddOption("rdfs:Datatype", -1);
	q59.AddOption("rdfs:ContainerMembershipProperty", -1);
	q59.AddOption("rdfs:Class", -1);
	q59.AddOption("rdfs:Property", 1);
	
	Question q60("Описанието в RDF на групa, съдържащa само зададените в описанието членове, става чрез използване на:");
	q60.AddOption("колекция", 1);
	q60.AddOption("множество", -1);
	q60.AddOption("последователност", -1);
	q60.AddOption("bag", -1);
	
	Question q61("Регулярният израз [1-9]?[0-9] дефинира XSchema стрингови стойности, които са:");
	q61.AddOption("от 1 до 99", -1);
	q61.AddOption("от 1 до 90", -1);
	q61.AddOption("от 0 до 99", 1);
	q61.AddOption("от 1 до 9", -1);

	Question q62("Person, title, familyName, knows, age, Document и Organization са име на елементи, дефинирани от:");
	q62.AddOption("DC", -1);
	q62.AddOption("FOAF", 1);
	q62.AddOption("RDFS", -1);
	q62.AddOption("OWL", -1);
	
	Question q63("В RDFS, Property е подмножество на RDFS Resources и има за обхват (rdfs:range):");
	q63.AddOption("класa, асоцииран с това Property", -1);//100% wrong
	q63.AddOption("типa на стойностите на това Property", -1);
	q63.AddOption("класa rdfs:Resource, на който принадлежат всички екземпляри на ресурса", -1);
	q63.AddOption("множество от отделни стойности на това Property", 1);
	
	Question q64("Целта на валидацията на XML документ от XML парсера е да се провери дали XML документът е добре структуриран (well-formed).");
	q64.AddOption("верно", -1);
	q64.AddOption("неверно", 1);
	
	Question q65("За постигане на по-малък, ефикасен и бърз код с използване на StAX, се препоръчва:");
	q65.AddOption("iterator API", -1);
	q65.AddOption("StAX Direct Mapping API", -1);
	q65.AddOption("StAX Events API", -1);
	q65.AddOption("cursor API", 1);
	
	Question q66("Редът <!ATTLIST point honorific (Mr|Ms|Mrs|Rev|Dr) ... > е валиден DTD пример за:");
	q66.AddOption("CDATA", -1);
	q66.AddOption("notation", -1);
	q66.AddOption("name group", 1);
	q66.AddOption("NMTOKENS", -1);
	
	Question q67("В XML схема, уникалността на key и keyref елементите е:");
	q67.AddOption("според стойността на атрибута \"range\"", -1);
	q67.AddOption("винаги за целия документ", -1);
	q67.AddOption("само за йерархията на съответните елементи в документа-екземпляр, за които са дефинирани key и keyref", 1);
	q67.AddOption("според стойността на атрибута \"context\"", -1);
	
	Question q68("MEDIA атрибутите като screen, aural, braille, tty, и т.н., са част от:");
	q68.AddOption("само от CSS1 спецификацията", -1);
	q68.AddOption("CSS2 и CSS3 спецификациите", 1);
	q68.AddOption("CSS1 и CSS2 спецификациите", -1);
	q68.AddOption("само от CSS3 спецификацията", -1);
	
	Question q69("В XLink информацията за това как се преминава през двойка ресурси (напр. посока на преминаване и за поведение при преминаването), се нарича:");
	q69.AddOption("траверс", -1);
	q69.AddOption("ребро", -1);
	q69.AddOption("дъга", 1);
	q69.AddOption("ресурс", -1);
	
	Question q70("Чрез XPointer можем да реферираме към повече от един елемента в XML документ.");
	q70.AddOption("неверно", -1);
	q70.AddOption("верно", 1);
	
	Question q71("Ако в XSchema дефинираме exact тип, то");
	q71.AddOption("той може да има дериватни типове, но те могат да бъдат използвани в XML документа вместо този exact тип само при определени условия", -1);
	q71.AddOption("той може да има дериватни типове, но те не могат да бъдат използвани в XML документа вместо този exact тип", 1);
	q71.AddOption("той може да има дериватни типове, и те могат да бъдат използвани в XML документа вместо този exact тип", -1);
	q71.AddOption("той не може да има дериватни типове", -1);
	
	Question q72("С един DOM Element обект:");
	q72.AddOption("може да направите разлика между подразбираща се (default) стойност, определена в DTD, и стойността, дадена в XML файла", -1);
	q72.AddOption("не може да направите разлика между подразбираща се (default) стойност, определена в DTD, и стойността, дадена в XML файла", 1);
	
	Question q73("Общо текстово Entity:");
	q73.AddOption("Може да бъде използвано рекурсивно и може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
	q73.AddOption("Не може да бъде използвано рекурсивно и не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
	q73.AddOption("Може да бъде използвано рекурсивно, но не може да се появи в съдържанието на елемент и/или в стойност на атрибут", -1);
	q73.AddOption("Не може да бъде използвано рекурсивно, но може да се появи в съдържанието на елемент и/или в стойност на атрибут", 1);
	
	Question q74("Какво не е възможно да бъде описано в DTD:");
	q74.AddOption("какви имена могат да бъдат използувани за тип на елементите", -1);
	q74.AddOption("къде типът на елементите може да се среща", -1);
	q74.AddOption("минимален и максимален брой срещания на елемент", 1);
	q74.AddOption("йерархия на документа и грануларност", -1);
	q74.AddOption("имена и типове на атрибутите на елементите  минимален и максимален брой срещания на елемент", -1);

	Question q75("XSL кодът, показан на фигурата, ще даде като резултат:");
	q75.AddOption("същите елементи в изходния XML файл както в сорс XML файла, но с добавено в края съдържание \"My own contents!\"", -1);
	q75.AddOption("същите елементи в изходния XML файл както в сорс XML файла, и с коментар \"My own contents!\" за всеки един елемент", -1);
	q75.AddOption("изходните XML елементи ще бъдат с имена, еднакви със съдържанието на елементите от сорс дървото, и със съдържание \"My own contents!\"", 1);
	
	Question q76("Кое е името на подразбиращото се (default) пространство от имена в декларацията по-долу:");
	q76.AddOption("няма подразбиращото се (default) пространство от имена", 1);
	q76.AddOption("pers", -1);
	q76.AddOption("html", -1);
	q76.AddOption("и pers, и html", -1);
	
	Question q77("Всеки два OWL класа принципно могат да се препокриват, т.е. да имат общи екземпляри.");
	q77.AddOption("верно", 1);
	q77.AddOption("неверно", -1);
	
	Question q78("CDATA съдържанията са:");
	q78.AddOption("или парсвани, или игнорирани от XML парсерите в зависимост от CDATA директивата", -1);
	q78.AddOption("игнорирани от XML парсерите", 1);
	q78.AddOption("парсвани от XML парсерите", -1);

	Question q79("Даден CSS стил може да бъде inlined (а не embedded) в документ посредством:");
	q79.AddOption("елемента INLINE", -1);
	q79.AddOption("атрибута INLINE", -1);
	q79.AddOption("атрибута STYLE", 1);
	q79.AddOption("елемента STYLE", -1);
	
	Question q80("Параметрично Entity:");
	q80.AddOption("се дефинира в XML документа и може да се използва в който и да е XML документ", -1);
	q80.AddOption("се дефинира в маркъп декларациите в DTD, но може да се използва в който и да е XML документ", -1);
	q80.AddOption("се дефинира в маркъп декларациите в DTD и може да се използва само в DTD дефиниции", 1);
	
	Question q81("Кой от следните изрази е валиден пример за дефиниране на избор (choice) от елементи в DTD:");
	q81.AddOption("(A ˇ B ˇ C)", -1);
	q81.AddOption("(A | B | C)", 1);
	q81.AddOption("(A or B or C)", -1);
	q81.AddOption("(A, B, C)", -1);
	
	Question q82("XML пространствата от имена се използват за разграничаване:");
	q82.AddOption("нито на XML елементи, нито на XML атрибути", -1);
	q82.AddOption("и на XML елементи, и на XML атрибути", 1);
	q82.AddOption("само на XML елементи", -1);
	q82.AddOption("само на XML атрибути", -1);
	
	Question q83("Регулярният израз [^0-9]x дефинира XSchema стрингови стойности, които представляват:");
	q83.AddOption("който и да е не-цифров символ, следван от символа x", 1);
	q83.AddOption("символът ^, последван от произволна цифра следвана от символа x", -1);
	q83.AddOption("x пъти повторение на който и да е цифров символ", -1);
	q83.AddOption("x пъти повторение на който и да е не-цифров символ", -1);
	
	Question q84("Осъществяването на еmbedding (а не inlining) на Style Sheet според CSS правилата е възможно посредством:");
	q84.AddOption("елемента EMBED", -1);
	q84.AddOption("елемента STYLE", 1);
	q84.AddOption("елемента LINK", -1);
	q84.AddOption("атрибута STYLE", -1);
	
	Question q85("Всеки DOM възел (Node) може да има деца");
	q85.AddOption("Верно", -1);
	q85.AddOption("Неверно", 1);
	q85.AddOption("зависи от децата", -1);
	
	Question q86("Кой от следните изрази е валиден пример за дефиниране на последователност (sequence) от елементи в DTD:");
	q86.AddOption("(A and B and C)", -1);
	q86.AddOption("(A ^ B ^ C)", -1);
	q86.AddOption("(A, B, C)", 1);
	q86.AddOption("(A | B | C)", -1);
	
	Question q87("Един XML документ може да има повече от едно вътрешно DTD.");
	q87.AddOption("Неверно", 1);
	q87.AddOption("Верно", -1);
	
	Question q88("Един XML документ може да има повече от едно DTD");
	q88.AddOption("Верно", 1);
	q88.AddOption("Неверно", -1);
	
	Question q89("Разгледайте <xsl:value-of> елемента. Ако стойността на неговия select атрибут е select='.', тогава ние избираме:");
	q89.AddOption("текстовия контекст само на елемента", -1);
	q89.AddOption("същия текстов контекст, както когато използваме text() функцията", -1);
	q89.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", 1);
	q89.AddOption("текстовия контекст на всички наследници на елемента", -1);
	
	Question q90("XSchema шаблонен фасет (pattern facet) е фасет за данни от тип:");
	q90.AddOption("String", 1);
	q90.AddOption("Integer", -1);
	q90.AddOption("Binary", -1);
	q90.AddOption("Decimal", -1);
	
	Question q91("В SAX, приложните обекти, имащи достъп до XML сорса:");
	q91.AddOption("са регистрирани за callback функции или от програмиста, или от парсера", -1);
	q91.AddOption("не трябва да бъдат регистрирани от програмиста за callback функции, тъй като те са listeners", -1);
	q91.AddOption("трябва да бъдат регистрирани (от програмиста) за callback функциите на парсера", 1);
	
	Question q92("Изберете верното:");
	q92.AddOption("Един URI не може да бъде нито URL, нито URN", -1);
	q92.AddOption("Един URL може да бъде или URI, или URN", -1);
	q92.AddOption("Един URI може да бъде URL и URN едновременно", -1);
	q92.AddOption("Един URN може да бъде или URL, или URI", -1);
	q92.AddOption("Един URI може да бъде или URL, или URN", 1);
	
	Question q93("Атрибутите на XML са чувствителни към регистъра.");
	q93.AddOption("Невeрно", -1);
	q93.AddOption("Верно", 1);
	
	Question q94("XSL се използва за:");
	q94.AddOption("трансформиране на XML документ към друг текстов документ", 1);
	q94.AddOption("трансформиране на XML документ към друг документ само в HTML формат", -1);
	q94.AddOption("трансформиране на XML документ към друг документ само в XML или HTML формат", -1);
	q94.AddOption("трансформиране на XML документ към друг документ само в XML формат", -1);
	
	Question q95("Разгледайте P:first-letter { font-size: 200% } . Това е:");
	q95.AddOption("CSS клас", -1);
	q95.AddOption("псевдо-атрибут (pseudo-attribute)", -1);
	q95.AddOption("нито едно от по-горе посочените", -1);
	q95.AddOption("псевдо-елемент (pseudo-element)", 1);
	
	Question q96("В XLink, входящите дъги (inbound arcs) могат да имат:");
	q96.AddOption("Произволен краен брой участващи в тях ресурси", 1);
	q96.AddOption("точно два участващи в тях ресурси", -1);
	
	Question q97("Разгледайте имената на XML елементите <xml-tag> and <tag-xml>. Те са:");
	q97.AddOption("нито едно от по-горе посочените", -1);
	q97.AddOption("и двата валидни", -1);
	q97.AddOption("и двата невалидни", -1);
	q97.AddOption("първият е валиден, вторият е невалиден", -1);
	q97.AddOption("първият е невалиден, вторият е валиден", 1);
	
	Question q98("При използването на XPath text() функцията, ние избираме:");
	q98.AddOption("същият текстов контекст както когато използваме <xsl:value-of select='.'> елемента", -1);
	q98.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", -1);
	q98.AddOption("текстовия контекст само на елемента", 1);
	q98.AddOption("текстовия контекст на всички наследници на елемента", -1);
	
	Question q99("CDATA съдържанията са:");
	q99.AddOption("игнорирани от XML парсерите", 1);
	q99.AddOption("парсвани от XML парсерите", -1);
	q99.AddOption("или парсвани, или игнорирани от XML парсерите в зависимост от CDATA директивата", -1);
	
	Question q100("При използването на XPath text() функцията, ние избираме:");
	q100.AddOption("същият текстов контекст както когато използваме <xsl:value-of select=’.’>  елемента", -1);
	q100.AddOption("текстовия контекст на елемента и текстовия контекст на всички наследници на елемента", -1);
	q100.AddOption("текстовия контекст само на елемента", 1);
	q100.AddOption("текстовия контекст на всички наследници на елемента", -1);
	
	Question q101("Ако даден атрибут на XML елемент има само локално име (т.е. името му не е QName), то:");
	q101.AddOption("Той не се отнася към каквото и да било пространство от имена за документа, в който е дефиниран.", -1);
	q101.AddOption("Той се отнася към пространството от имена по подразбиране (default namespace).", -1);
	q101.AddOption(" Той не се отнася към пространството от имена на елемента, към който принадлежи.", -1);
	q101.AddOption(" Той се отнася неявно към пространството от имена на елемента, към който принадлежи.", 1);
	
	Question q102("Кой от следните елементи не е с грешен XML синтаксис:");
	q102.AddOption("<birth>28.04.1990, Gabrovo</ birth>", -1);
	q102.AddOption("<birth>28.04.1990, Gabrovo< /birth>", -1);
	q102.AddOption("<birth>28.04.1990, Gabrovo</birth >", 1);
	q102.AddOption("<birth>28.04.1990, Gabrovo</bir th>", -1);
	q102.AddOption("Всичките останали отговори съдържат елемент с грешен XML синтаксис. ", -1);
	
	Question q103("В XSchema, за глобалните типове:");
	q103.AddOption("minOccurs и maxOccurs може да се дефинират само за глобални типове, които се реферират", 1);
	q103.AddOption("minOccurs и maxOccurs не може да се дефинират", -1);
	q103.AddOption("minOccurs и maxOccurs може да се дефинират винаги", -1);
	q103.AddOption("minOccurs и maxOccurs може да се дефинират само за глобални типове, които не се реферират", -1);
	
	Question q104("SAX служи както за четене на XML документи, така и за генериране на XML");
	q104.AddOption("Истина", -1);
	q104.AddOption("Лъжа", 1); //само четене
	
	Question q105("Задаването на мрежа от хора чрез FOAF твърдения става посредством релацията:");
	q105.AddOption("foaf:linkedTo", 1);
	q105.AddOption("foaf:relatedTo", -1);
	q105.AddOption("нито една от изброените", -1);
	q105.AddOption("Foaf:follows", -1);
	q105.AddOption("Foaf:knows", 1);
	
	Question q106("\"other\" и  \"none\" са възможни стойности за XLink атрибутите:");
	q106.AddOption("arcrole и role", -1);
	q106.AddOption("actuate и show", 1);
	q106.AddOption("actuate и arcrole", -1);
	q106.AddOption("show и role", -1);
	q106.AddOption("show и arcrole", -1);
	
	Question q107("B CSS, задаването на елемент, чийто атрибут attr завършва с дадена стойност xpto, става чрез:");
	q107.AddOption("[attr$=xpto]", -1);
	q107.AddOption("[attr|=xpto]", -1);
	q107.AddOption("[attr=xpto]", -1);
	q107.AddOption("[attr~=xpto]", 1);
	
	Question q108("Описание (конкретизация) на твърдение с използване на RDF речника се извършва чрез:");
	q108.AddOption("типа rdf:Consideration и свойствата rdf:subject, rdf:predicate и rdf:object", -1);
	q108.AddOption("типа rdf:Reification и свойствата rdf:subject, rdf:predicate и rdf:object", -1);
	q108.AddOption("използване на други средства", -1);
	q108.AddOption("типа rdf:Statement и свойствата rdf:subject, rdf:predicate и rdf:object", 1);
	
	Question q109("Свойството rdfs:isDefinedBy е специален (под)тип на:");
	q109.AddOption("rdfs:is", -1);
	q109.AddOption("rdfs:seeAlso", 1);
	q109.AddOption("rdfs:isCreatedBy", -1);
	q109.AddOption("rdfs:isDescribedBy", -1);
	
	Question q110("При автоматичното разпознаване на анотации, отношението броя на правилно разпознатите анотации към броя на всички съществуващи правилни анотации се нарича:");
	q110.AddOption("пълнотата  на връщане (recall)", -1);
	q110.AddOption("устойчивост (стабилност)", -1);
	q110.AddOption("достоверност на резултата (reliability)", -1);
	q110.AddOption("точност (precision) ", 1);
	
	Question q111("Дефинирането на референция (Reference) към ключ (Key) в XSD може да има полета, които са:");
	q111.AddOption("само елементи", -1);
	q111.AddOption("само атрибути", -1);
	q111.AddOption("както атрибути, така и елементи, като всеки един атрибут (или елемент) трябва да съответства на атрибут (или на елемент) в ключа", -1);
	q111.AddOption("както атрибути, така и елементи, като всички полета трябва да съответстват на типа и на позицията на тези в ключа", 1);
	
	Question q112("RDF поддържа описания на групи, съдържащи само определени членове, посредством:");
	q112.AddOption("RDF вектори", -1);
	q112.AddOption("RDF колекции", 1);
	q112.AddOption("RDF масиви", -1);
	q112.AddOption("RDF enumeration", -1);
	
	Question q113("В RDF, класовете могат да бъдат екземпляри на други класове.");
	q113.AddOption("Неверно", -1);
	q113.AddOption("Верно", 1);
	
	Question q114("В XML Schema дефиницията за елементно съдържание ... order=\"all\" ...  е еквивалентна на ANY в DTD.");
	q114.AddOption("Верно", -1);
	q114.AddOption("Неверно", 1);
	
	Question q115("RDF твърдението\ndbpedia:Mount_Etna rdf:type my-pref:Mountain, my-pref:Volcano\nе допустимо и валидно.");
	q115.AddOption("Верно", 1);
	q115.AddOption("Неверно", -1);
	
	Question q116("В RDF твърдението\nS rdf:type O");
	q116.AddOption("S задава клас (категория), а О задава екземпляр на този клас", -1);
	q116.AddOption("О задава клас (категория), а S задава екземпляр на този клас", 1);
	q116.AddOption("S и О задават класове на екземпляри", -1);
	q116.AddOption("S и О задават екземпляри на класове", -1);
	
	Question q117("Множественото наследяване (multiple inheritance) не е допустимо в RDFS.");
	q117.AddOption("Неверно", 1);
	q117.AddOption("Верно", -1);
	
	Question q118("В какъв формат е следният запис:");
	q118.AddOption("друг формат, различен от останалите", -1);
	q118.AddOption("RDF/XML", -1);
	q118.AddOption("N3", -1);
	q118.AddOption("N-Triples", -1);
	
	Question q119("Описанието (конкретизацията) на RDF твърдение чрез използване на RDF речника се нарича:");
	q119.AddOption("reification", 1);
	q119.AddOption("сoncretization", -1);
	q119.AddOption("оbjectification", -1);
	q119.AddOption("consideration", -1);
	
	Question q120("Ако имаме дефинирани две еднакви CSS свойства с различни стойности за един и същи елемент, то ще се приложи последно дефинираното свойство:");
	q120.AddOption("винаги", -1);
	q120.AddOption("винаги, освен когато правилото за прилагане на едно от свойствата взима под внимание кой е предходният елемент", -1);
	q120.AddOption("винаги, освен когато едно от свойствата е по-специфично или правилото за прилагането му взима под внимание кой е предходният елемент", -1);
	q120.AddOption("винаги, освен когато едно от свойствата е по-специфично", 1);
	
	Question q121("Елементите от прост тип в една XML Schema са от даден предефиниран тип и:");
	q121.AddOption("не могат да имат атрибути и под-елементи", 1);
	q121.AddOption("могат да имат под-елементи, но не и атрибути", -1);
	q121.AddOption("могат да имат атрибути и под-елементи", -1);
	q121.AddOption("могат да имат атрибути, но не и под-елементи", -1);
	
	Question q122("В RDFS един ресурс може да е екземпляр на няколко класа.");
	q122.AddOption("Вeрно", -1);
	q122.AddOption("Невeрно", -1);
	
	Question q123("За разлика от SAX при използване на StAX можем да се движим както напред така и назад в XML документа");
	q123.AddOption("Вeрно", -1);
	q123.AddOption("Невeрно", 1);
	
	Question q124("В DOM, неопределена колекция от възли се дефинира чрез интерфейс с име:");
	q124.AddOption("UnorderedNodeCollection", -1);
	q124.AddOption("UnorderedNodeSet", -1);
	q124.AddOption("NodeAttr", -1);
	q124.AddOption("NodeList", -1);
	q124.AddOption("NamedNodeMap", -1);

	Question q125("Използването на пространства от имена в XPointer изрази е:");
	q125.AddOption("Разрешено", -1);
	q125.AddOption("Забранено", -1);
	
	Question q126("Кои два от изброените по-долу атрибути НЕ МОГАТ да участват в елемент от XLink тип arc:\nИзберете едно или повече");
	q126.AddOption("role", 0.5);
	q126.AddOption("from", -1);
	q126.AddOption("show", -1);
	q126.AddOption("href", 0.5);
	q126.AddOption("title", -1);
	q126.AddOption("to", -1);
	q126.AddOption("actuate", -1);
	q126.AddOption("type", -1);
	
	Question q127("Методите за работа с атрибути на DOM Element интерфейса: (****no answer)");
	q127.AddOption("Разграничават стойността на атрибут дефинирана изрично в XML документа, от стойността по подразбиране, зададена в DTD, само ако Node:setAttrDistinction(Boolean param) е извикан предварително с параметър param със стойност True", -1);
	q127.AddOption("не могат да разграничават стойността на атрибут, дефиниран изрично в XML документа, от стойността по подразбиране, зададена в DTD", -1);
	q127.AddOption("могат да разграничават стойността на атрибут, дефинирана изрично в XML документа, от стойността по подразбиране, зададена в DTD", -1);
	q127.AddOption("зависи от настройките на DOM парсера", -1);
	
	Question q128("(***no answer) При прилагане на XSLT трансформацията (има Steve & Bob)");
	q128.AddOption("c името \"name\"", -1);
	q128.AddOption("с имената на елементите в изходящото дърво", -1);
	q128.AddOption("със съдържанието на елементите в изходящото дърво", -1);
	q128.AddOption("със съдържанието на атрибутите в изходящото дърво", -1);
	q128.AddOption("с имената на атрибутите в изходящото дърво", -1);
	
	Question q129("Елементите contributor, creator, publisher и rights са част от:");
	q129.AddOption("DCQ пространството (Dublin Core квалификатори)", -1);
	q129.AddOption("DCM пространството (Dublin Core метаданни)", -1);
	q129.AddOption("DC пространството (Dublin Core ядро)", 1);
	q129.AddOption("DCT пространството (Dublin Core термини)", -1);
	
	Question q130("XLink използва отдалечени (remote) ресурси, за да представя:");
	q130.AddOption("нито един от останалите отговори не е верен", -1);
	q130.AddOption("само външни за документа ресурси, но не и вътрешни ресурси, достъпни по URI", -1);
	q130.AddOption("само вътрешни за документа ресурси, достъпни по URI, но не и външни ресурси", -1);
	q130.AddOption("нито външни за документа ресурси, нито вътрешни ресурси, достъпни по URI", -1);
	q130.AddOption("Както външни за документа ресурси, така и вътрешни ресурси, достъпни по URI", 1);

	Question q131("Кой(кои) RDF контейнер(и) задава(т) ресурси или литерали, които могат да бъдат евентуално дублирани:");
	q131.AddOption("rdf:Seq и rdf:Alt", -1);
	q131.AddOption("Само rdf:Bag", -1);
	q131.AddOption("rdf:Bag и rdf:Seq", 1);
	q131.AddOption("rdf:Bag и rdf:Alt", -1);
	
	Question q132("RDF реификация се задава чрез:");
	q132.AddOption("Типа rdf:Reification и свойствата rdf:about, rdf:property и rdf:object", -1);
	q132.AddOption("Типа rdf:Statement и свойствата rdf:subject, rdf:predicate и rdf:object", 1);
	q132.AddOption("Типа rdf:Description и свойствата rdf:subject, rdf:predicate и rdf:object", -1);
	q132.AddOption("Типа rdf:Reification и свойствата rdf:subject, rdf:predicate и rdf:object", -1);
	
	Question q133("Кои от изброените по-долу качества НЕ СА ПРИСЪЩИ на спецификация на онтология:\nИзберете едно или повече:");
	q133.AddOption("споделена", -1);
	q133.AddOption("неявна", 0.5);
	q133.AddOption("концептуална", -1);
	q133.AddOption("машинно-четима", -1);
	q133.AddOption("неформална", 0.5);

	Question q134("B CSS, задаването на елемент, чийто атрибут attr има стойност, съдържаща на произволно място в себе си думата xpto, става чрез:");
	q134.AddOption("[attr$=xpto]", -1);
	q134.AddOption("[attr|=xpto]", -1);
	q134.AddOption("[attr^=xpto]", -1);
	q134.AddOption("[attr~=xpto]", 1);
	
	Question q135("NO ANSWER**?В DOM, възли-деца могат да имат единствено възлите от тип:");
	q135.AddOption("Root, Parent, и Ancestor", -1);
	q135.AddOption("Document, DocumentFragment и Element", -1);
	q135.AddOption("CharacterData, Text и Comment", -1);
	q135.AddOption("Notation, Entity, EntityReference", -1);
	
	Question q136("XQUERY изразът \nFor $o in catalog/cd\nLet $I := $o/tracklist\nWhere $I/@num=”1”\nReturn $I/track");
	q136.AddOption("стойността на първия елемент track, който е под-елемент на tracklist, имащ атрибут num равен на 1 и който е наследник на елемент cd", -1);
	q136.AddOption("стойността на всички елементи track, които са под-елементи на tracklist, наследник на елемент cd с атрибут равен на 1", -1);
	q136.AddOption("нито един от останалите въпроси не е верен", -1);
	q136.AddOption("стойността на всички елементи track, които са под-елементи на tracklist, имащ атрибут num равен на 1 и който е наследник на елемент cd", 1);
	
	Question q137("RDF литералите могат да се явяват както като субект, така и като обект в RDF тройка");
	q137.AddOption("Вярно", -1);
	q137.AddOption("Невярно", -1);
	
	Question q138("OWL клас, за който са описани както задължителните, така и достатъчните свойства за членство в класа, се нарича:");
	q138.AddOption("disjoint клас", -1);
	q138.AddOption("примитивен клас", -1);
	q138.AddOption("анонимен клас", -1);
	q138.AddOption("дефиниран клас", 1);
	
	Question q139("В OWL, един екземпляр може да бъде:");
	q139.AddOption("член на множество класове", -1);
	q139.AddOption("единствено член на само един клас", -1);
	
	Question q140("DOMException  връща HIERARCHY_REQUEST_ERR при опит за:");
	q140.AddOption("Вмъкване на невалиден възел в йерархията на DOM дървото", -1);
	q140.AddOption("Заявка за получаване на йерархията на възел с дълбочина, по-голяма от съществуващата на възела", -1);
	q140.AddOption("Вмъкване на възел на неподходящо място в йерархията на DOM дървото ", 1);
	q140.AddOption("Заявка за получаване на йерархията на елемент без наследници", -1);
	
	Question q141("В SAX 2, управляваме събитията относно съдържанието на документа чрез:");
	q141.AddOption("имплементиране на ContentHandler или разширяване на DefaultHandler", 1);
	q141.AddOption("имплементиране на EventHandler или разширяване на BaseHandler", -1);
	q141.AddOption("имплементиране на HandlerBase или разширяване на DocumentHandler", -1);
	q141.AddOption("имплементиране на DocumentHandler или разширяване на HandlerBase", -1);
	
	Question q142("Кой от следните типове не се среща в описанието на разширена връзка в XLink:");
	q142.AddOption("title", -1);
	q142.AddOption("locator", -1);
	q142.AddOption("arc", -1);
	q142.AddOption("edge", -1);
	
	Question q143("********8В RDF един екземпляр може да има няколко типа (т.e. да участва като субект в няколко релации rdf:type)");
	q143.AddOption("Неверно", -1);
	q143.AddOption("Верно", -1);
	
	Question q144("********В XML схема, уникалността на key и keyref елементите е:");
	q144.AddOption("винаги за целия документ", -1);
	q144.AddOption("само за йерархията на съответните елементи в документа-екземпляр, за които са дефинирани key и keyref", -1);
	q144.AddOption("според стойността на атрибута \"context\"", -1);
	q144.AddOption("според стойността на атрибута \"range\"", -1);
/*	
	Question q145("?");
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	
	Question q146("?");
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	
	Question q147("?");
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	
	Question q148("?");
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	
	Question q149("?");
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	
	Question q150("?");
	q150.AddOption("", -1);
	q150.AddOption("", -1);
	q150.AddOption("", -1);
        q150.AddOption("", -1);
*/	
        exam.push_back(q1);
        exam.push_back(q2);
        exam.push_back(q3);
        exam.push_back(q4);
        exam.push_back(q5);
        exam.push_back(q6);
        exam.push_back(q7);
        exam.push_back(q8);
        exam.push_back(q9);
        exam.push_back(q10);
        exam.push_back(q11);
        exam.push_back(q12);
        exam.push_back(q13);
        exam.push_back(q14);
        exam.push_back(q15);
        exam.push_back(q16);
        exam.push_back(q17);
        exam.push_back(q18);
        exam.push_back(q19);
        exam.push_back(q20);
        exam.push_back(q21);
        exam.push_back(q22);
        exam.push_back(q23);
        exam.push_back(q24);
        exam.push_back(q25);
        exam.push_back(q26);
        exam.push_back(q27);
        exam.push_back(q28);
        exam.push_back(q29);
        exam.push_back(q30);
        exam.push_back(q31);
        exam.push_back(q32);
        exam.push_back(q33);
        exam.push_back(q34);
        exam.push_back(q35);
        exam.push_back(q36);
        exam.push_back(q37);
        exam.push_back(q38);
        exam.push_back(q39);
        exam.push_back(q40);
        exam.push_back(q41);
        exam.push_back(q42);
        exam.push_back(q43);
        exam.push_back(q44);
        exam.push_back(q45);
        exam.push_back(q46);
        exam.push_back(q47);
        exam.push_back(q48);
        exam.push_back(q49);
        exam.push_back(q50);
        exam.push_back(q51);
        exam.push_back(q52);
        exam.push_back(q53);
        exam.push_back(q54);
        exam.push_back(q55);
        exam.push_back(q56);
        exam.push_back(q57);
        exam.push_back(q58);
        exam.push_back(q59);
        exam.push_back(q60);
        exam.push_back(q61);
        exam.push_back(q62);
        exam.push_back(q63);
        exam.push_back(q64);
        exam.push_back(q65);
        exam.push_back(q66);
        exam.push_back(q67);
        exam.push_back(q68);
        exam.push_back(q69);
        exam.push_back(q70);
        exam.push_back(q71);
        exam.push_back(q72);
        exam.push_back(q73);
        exam.push_back(q74);
        exam.push_back(q75);
        exam.push_back(q76);
        exam.push_back(q77);
	exam.push_back(q78);
      	exam.push_back(q79);
        exam.push_back(q80);
        exam.push_back(q81);
        exam.push_back(q82);
        exam.push_back(q83);
        exam.push_back(q84);
        exam.push_back(q85);
        exam.push_back(q86);
        exam.push_back(q87);
        exam.push_back(q88);
        exam.push_back(q89);
        exam.push_back(q90);
        exam.push_back(q91);
        exam.push_back(q92);
        exam.push_back(q93);
        exam.push_back(q94);
        exam.push_back(q95);
        exam.push_back(q96);
        exam.push_back(q97);
        exam.push_back(q98);
        exam.push_back(q99);
        exam.push_back(q100);
        exam.push_back(q101);
        exam.push_back(q102);
        exam.push_back(q103);
        exam.push_back(q104);
        exam.push_back(q105);
        exam.push_back(q106);
        exam.push_back(q107);
        exam.push_back(q108);
        exam.push_back(q109);
        exam.push_back(q110);
        exam.push_back(q111);
        exam.push_back(q112);
        exam.push_back(q113);
        exam.push_back(q114);
        exam.push_back(q115);
        exam.push_back(q116);
        exam.push_back(q117);
        exam.push_back(q118);
        exam.push_back(q119);
        exam.push_back(q120);
        exam.push_back(q121);
        exam.push_back(q122);
        exam.push_back(q123);
        exam.push_back(q124);
        exam.push_back(q125);
        exam.push_back(q126);
        exam.push_back(q127);
        exam.push_back(q128);
        exam.push_back(q129);
        exam.push_back(q130);
        exam.push_back(q131);
        exam.push_back(q132);
        exam.push_back(q133);
        exam.push_back(q134);
        exam.push_back(q135);
        exam.push_back(q136);
        exam.push_back(q137);
        exam.push_back(q138);
        exam.push_back(q139);
        exam.push_back(q140);
        exam.push_back(q141);
        exam.push_back(q142);
        exam.push_back(q143);
        exam.push_back(q144);
 /*       exam.push_back(q145);
        exam.push_back(q146);
        exam.push_back(q147);
        exam.push_back(q148);
        exam.push_back(q149);
        exam.push_back(q150);
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
