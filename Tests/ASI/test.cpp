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
	std::cout << "За да отговорите на някой въпрос въведете буквата(буквите), и когато сте готовои въведете s'\n";
	std::cout << "Syobrazete se kak raboti std::cin\nAко желаете симулация без повторни опити натиснете r\nАко желаете въпросите, които объркате да се записват натиснете произволен бутон\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("clear");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Документът на спецификацията на системата описва:?");
	q1.AddOption("Използваните алгоритми и структури от данни", -1);
	q1.AddOption("Функционирането и поведението на софтуерната система", 1);
	q1.AddOption("Имплементирането на всеки елемент на софтуерната система", -1);
	q1.AddOption("Модулите на софтуерната система", -1);
	
	Question q2("Вярно ли е твърдението \"Бизнес и потребителски изисквания са едно и също нещо, но в различна терминология\"?");
	q2.AddOption("Да", -1);
	q2.AddOption("Не", 1);
	
	Question q3("Моделът на софтуерната система се валидира чрез:?");
	q3.AddOption("автоматични софтуерни инструменти – CASЕ tools support", 0.5);
	q3.AddOption("перифразиране на модела", 0.5);
	q3.AddOption("използване на инженеринг на изисквания от самото начало", -1);
	q3.AddOption("чрез комуникиране с клиента", -1);
	
	Question q4("Коя от дейностите не се извършва като част от етапа анализ на изискванията?");
	q4.AddOption("Планиране и изготвяне на график", 1);
	q4.AddOption("Преглед и оценка на спецификацията", -1);
	q4.AddOption("Моделиране и изясняване на аспектите на системата", -1);
	q4.AddOption("Дискутиране и договаряне на спецификацията", -1);
	
	Question q5("Кои от изброените са дейност в процеса на извличане (elicitation) на изискванията?");
	q5.AddOption("Проучване на нуждите и ограниченията на заинтересованите лица (stakeholders)", 0.5);
	q5.AddOption("Проверка за точност и пълнота на изискванията", -1);
	q5.AddOption("Проучване на приложната област, в която ще се използва системата", 0.5);
	q5.AddOption("Разрешаване на конфликти в изискванията", -1);
	
	Question q6("Кои от изброените не са пeрспектива при инженеринга на изискванията?");
	q6.AddOption("Данните", -1);
	q6.AddOption("Обектите", 0.5);
	q6.AddOption("Поведението", -1);
	q6.AddOption("Ограниченията", 0.5);
	
	Question q7("Кои два аспекта първо трябва да се отчетат, когато се избира подходяща техника за извличане на изискванията?");
	q7.AddOption("Достъпност на заинтересованите лица (stakeholders)", -1);
	q7.AddOption("Възрастта на заинтересованите лица (stakeholders)", -1);
	q7.AddOption("Сроковете и бюджета на проекта", 0.5);
	q7.AddOption("Областта, в която ще се използва продукта", 0.5);
	
	Question q8("Неустойчивите (volatile) изисквания са такива, които описват:?");
	q8.AddOption("приложната област на системата", -1);
	q8.AddOption("същността на системата", -1);
	q8.AddOption("средата, в която системата работи", 1);
	q8.AddOption("начина на използване на системата", -1);
	
	Question q9("Техниката за извличане на изискванията, при която представители на разработващия екип обсъждат системата с отделни стейкхолдъри, за да разберат, какви са техните изисквания е:?");
	q9.AddOption("интервюта", 1);
	q9.AddOption("анализ на пазара", -1);
	q9.AddOption("създаване на прототип", -1);
	q9.AddOption("използване на вече готова система", -1);
	
	Question q10("Технологичните ограничения в изискванията са свързани с:");
	q10.AddOption("Качествата на системата", -1);
	q10.AddOption("Опита и знанията на разработчиците", -1);
	q10.AddOption("Техниките и ресурсите за изграждане на системата", 1);
	q10.AddOption("Колко и каква документация е необходима", -1);
	
	Question q11("Кое от изброените не се отнася за SMARTT изискванията?");
	q11.AddOption("Достижими (Attainable)", -1);
	q11.AddOption("Управляеми (Manageable)", 1);
	q11.AddOption("Верифицируеми (Testable)", -1);
	q11.AddOption("Реалистични (Realisable)", -1);
	
	Question q12("Прототипът за валидиране изисква/означава:?");
	q12.AddOption("функционалностите, които в достатъчна степен покават практическата използваемост на сoфт. система", 1);
	q12.AddOption("всички функционалности на софт. система", -1);
	q12.AddOption("най-трудните за определяне функционалности на софт. система", -1);
	q12.AddOption("най-лесните за определяне функционалности на софт. система", -1);
	
	Question q13("Проследимост означава?");
	q13.AddOption("да се установи кой е предложил дадено изискване, с какви други изисквания е свързано и ако е свързано с дизайна на системата и имплементацията.", 1);
	q13.AddOption("да се знае кой е отговорен за дадено изискване", -1);
	q13.AddOption("да се разреши конфликт на изисквания", -1);
	q13.AddOption("всяко ново изискване да може да бъде ясно реализирано", -1);
	
	Question q14("Кое от изброените е невярно за MoSCoW??");
	q14.AddOption("M - MUST", -1);
	q14.AddOption("S - SHOULD", -1);
	q14.AddOption("C - COULD", -1);
	q14.AddOption("W - WILL", 1);
	
	Question q15("За справяне със сложността на софтуерните системи се използват?");
	q15.AddOption("структуриране", -1);
	q15.AddOption("абстракция", 0.5);
	q15.AddOption("декомпозиция", 0.5);
	q15.AddOption("анализ", -1);
	
	Question q16("Кои от изброените не са от вида напред-от(forward from) проследяемост?");
	q16.AddOption("изисквания – имплементация", -1);
	q16.AddOption("изисквания – ресурс на изискванията", 0.5);
	q16.AddOption("изисквания – архитектура на системата", -1);
	q16.AddOption("дизайн - изисквания", 0.5);
	
	Question q17("При метода VORD се определят:");
	q17.AddOption("директни и индиректни гледни точки като се използва обектен модел", -1);
	q17.AddOption("дирекни и индиректни гледни точки", 1);
	q17.AddOption("само директните гледни точки", -1);
	q17.AddOption("гледните точки като се използва обектен модел", -1);
	
	Question q18("Кои от изброените са верни за методите, ориентирани към гледни точки?");
	q18.AddOption("предоставят пълнота на изискванията", -1);
	q18.AddOption("предоставят единна нотация", -1);
	q18.AddOption("предоставят по-лесен механизъм за проследяване на изискванията", -1);
	q18.AddOption("предоставят средства за стейкхолдерите да идентифицират и верифицират своя принос към изискванията", 1);
	
	Question q19("В какво се състои основната разлика между throw-away и еволюционното прототипиране?");
	q19.AddOption("във времето необходимо за създаване на прототипа", -1);
	q19.AddOption("в изискванията, които се прототипират", 1);
	q19.AddOption("в начина на изработване на прототипа", -1);
	q19.AddOption("в начина на представяне на прототипа", -1);
	
	Question q20("Множество от факти, наблюдавани и моделирани според конкретен аспект от реалността, се нарича:?");
	q20.AddOption("перспектива", 1);
	q20.AddOption("съвкупност", -1);
	q20.AddOption("поточков метод", -1);
	q20.AddOption("изискване", -1);
	
	Question q21("Кои от изброените са характерни за съхранението на изисквания в база данни?");
	q21.AddOption("Има автоматична навигация от едно изискване към друго", 0.5);
	q21.AddOption("Не може да се свържат изискванията с предложени промени", -1);
	q21.AddOption("Лесно се поддържа версиониране на ниво изисквания", 0.5);
	q21.AddOption("Лесно се генерира финалния документ (SRS)", -1);
	
	Question q22("В кои случаи не е икономически обосновано в процеса на извличане на изискванията (RE Process) да се разработи прототип на системата?");
	q22.AddOption("Когато изискванията на разработваната система са ясни и разбираеми", 0.5);
	q22.AddOption("Когато трудно се разбират изискванията на системата", -1);
	q22.AddOption("При разработката на потребителския интерфейс", -1);
	q22.AddOption("Когато за разработване на прототип се изисква много време", 0.5);
	
	Question q23("Кое от изброените не е стъпка при метода CORE??");
	q23.AddOption("Графично представяне на гледната точка", 1);
	q23.AddOption("Структуриране на данните", -1);
	q23.AddOption("Моделиране на отделна гледна точка", -1);
	q23.AddOption("Структуриране на гледните точки", -1);
	
	Question q24("Основната концепция на моделиране на същност – връзка (entity relationship modeling) е да:");
	q24.AddOption("Представи капсулиран запис на данните", -1);
	q24.AddOption("Опише взаимодействието на данните с други външни или вътрешни обекти", -1);
	q24.AddOption("Опише данните на базата на математически принципи", -1);
	q24.AddOption("Опише логическата структура на данните, обработвани в системата", 1);
	
	Question q25("Кой е най-близкият предшественик на обектно ориентирания модел?");
	q25.AddOption("Модел на потока на данните (Data flow model)", -1);
	q25.AddOption("Модел на процеса (Process model)", -1);
	q25.AddOption("Модел същност-връзка (Entity relationship model)", 1);
	q25.AddOption("Модел на преход на състоянието (State transition model)", -1);
	
	Question q26("Задача на предварителния преглед на документа на изискванията в етапа на валидиране е:");
	q26.AddOption("Проверка за съгласуваност със стандартите", 1);
	q26.AddOption("Проверка за двусмислие в изискванията", -1);
	q26.AddOption("Проверка за приложимост на тест", -1);
	q26.AddOption("Проверка за липсващи изисквания", -1);
	
	Question q27("Диаграмата на случаите на употреба не показва:");
	q27.AddOption("Правилата за използване на приложението", 1);
	q27.AddOption("Актьорите на приложението", -1);
	q27.AddOption("Използването на приложението", -1);
	q27.AddOption("Границата между приложението и неговата среда", -1);
	
	Question q28("Кои от изброените характеристики са недостатъци на формалните модели за описание на изискванията??");
	q28.AddOption("Базират се на специфичка нотация", 0.5);
	q28.AddOption("За разработването им е необходим висок интелектуален потенциал", 0.5);
	q28.AddOption("Фокусира се върху данните и функционалността на системата", -1);
	q28.AddOption("Постига се голяма точност в ранен етап от разработването на софтуерната система", -1);
	
	Question q29("Коя от следните групи от по три вида модели могат да опишат пълно функционалността на определена система:?");
	q29.AddOption("State Transition Diagram, ER Model, Behavior Model", -1);
	q29.AddOption("State Chart, Data-Flow Diagram, Object Oriented Model", 1);
	q29.AddOption("State Transition Model, ER Model, Object Oriented Model", -1);
	q29.AddOption("Behavior Model, State Transition Model, ER Model", -1);
	
	Question q30("Обхватът на софтуерната система се определя от??");
	q30.AddOption("границата на системата", 1);
	q30.AddOption("контекста на системата", -1);
	q30.AddOption("границата на контекста на системата", -1);
	q30.AddOption("средата на системата", -1);
	
	Question q31("Кое от изброените е входна информация на процеса на инженеринг на изискванията?");
	q31.AddOption("Идентифициране на изискванията", 1);
	q31.AddOption("Структурирано описание на системата", -1);
	q31.AddOption("Изясняване на контекста на системата", -1);
	q31.AddOption("Анализ на изискванията", -1);
	
	Question q32("Кое от изброените е входна информация на процеса на инженеринг на изискванията?");
	q32.AddOption("Системни модели", -1);
	q32.AddOption("Списък на заинтересованите лица", -1);
	q32.AddOption("Списък на актьори на системата", -1);
	q32.AddOption("Организационни стандарти", 1);
	
	Question q33("Кои от следните групи изисквания най-лесно могат да бъдат извличани чрез етнографски анализ?");
	q33.AddOption("Изисквания, произтичащи от социалния живот на хората", 0.5);
	q33.AddOption("Изисквания от областта на продукта", -1);
	q33.AddOption("Изисквания от организационен характер", 0.5);
	q33.AddOption("Изисквания за качеството на продукта", -1);
	
	Question q34("Кое от изброените е техника за валидиране на изискванията?");
	q34.AddOption("Систематичен преглед на изискванията", 1);
	q34.AddOption("Анкетиране на заинтересовани лица", -1);
	q34.AddOption("Съставяне на матрица на взаимодействие на изискванията", -1);
	q34.AddOption("Споразумение на изискванията", -1);
	
	Question q35("Върху код модел на софтуерната система се базира подход на различни гледни точки, реализирани чрез метода SADT (структурен анализ и техника за проектиране)?");
	q35.AddOption("Обектно ориентиран подход", -1);
	q35.AddOption("Модел на състоянията на системата", -1);
	q35.AddOption("Модел на потока на данните", 1);
	q35.AddOption("Модел същност-връзка", -1);
	
	Question q36("За коя от изброените дейности от процеса на инженеринга на изискванията са налични софтуерни инструменти, които подпомагат дейността?");
	q36.AddOption("Приоритизиране на изискванията", -1);
	q36.AddOption("Анализ на осъществимост", -1);
	q36.AddOption("Идентифициране на изискванията", -1);
	q36.AddOption("Управление на изискванията", 1);
	
	Question q37("Кое качество на изискванията е задължително, за да могат да се управляват изискванията на продукта?");
	q37.AddOption("специфичност", -1);
	q37.AddOption("недвусмисленост", -1);
	q37.AddOption("проследимост", 1);
	q37.AddOption("точност", -1);
	
	Question q38("Кое от изброените е постоянно изискване?");
	q38.AddOption("изискване, специфицирано по време на проектирането на системата", -1);
	q38.AddOption("изискване на свързаност на системата с други системи и устройства", -1);
	q38.AddOption("изискване, свързано с приложната област на системата", 1);
	q38.AddOption("изискване за начина на използване на системата", -1);
	
	Question q39("Кое от изброените е основна дейност в етапа на управление на изискванията?");
	q39.AddOption("моделиране на системата", -1);
	q39.AddOption("съставяне на тест на изискванията", -1);
	q39.AddOption("оценка на връзките между изискванията", 1);
	q39.AddOption("договаряне на изискванията", -1);
	
	Question q40("Информация за какъв вид изисквания се съдържа в Матрицата на взаимодействията?");
	q40.AddOption("Изисквания, които са сложни", -1);
	q40.AddOption("Изисквания, които са в конфликт", 1);
	q40.AddOption("Изисквания, които са двусмислени", -1);
	q40.AddOption("Изисквания, които са променливи", -1);
	
	Question q41("При кой от изброените процеси се използва техниката \"списък за проверка\" (\"checkout\")?");
	q41.AddOption("специфициране на изискванията", -1);
	q41.AddOption("анализ на изискванията", 1);
	q41.AddOption("управление на изискванията", -1);
	q41.AddOption("извличане на изискванията", -1);
	
	Question q42("Кой от изброените модели е най-подходящ за използване в началния етап на процеса на инженеринг на изискванията?");
	q42.AddOption("Структурен модел", -1);
	q42.AddOption("Обектен модел", -1);
	q42.AddOption("Контекстен модел", 1);
	q42.AddOption("Модел на поведението", -1);
	
	Question q43("Кои от моделите се използват за допълнително пояснение на сценариите?");
	q43.AddOption("Диаграма на действията", -1);
	q43.AddOption("Диаграма на последователностите", 1);
	q43.AddOption("Диаграма на потока на информацията", -1);
	q43.AddOption("Диаграма на поведението", -1);
	
	Question q44("Кои от изброените са от вида <<напред, от>> (forward-from) последователност?");
	q44.AddOption("Изисквания -> Имплементация", 0.5);
	q44.AddOption("Изисквания -> Ресурс на изискванията", -1);
	q44.AddOption("Изисквания -> Архитектура на системата", 0.5);
	q44.AddOption("Източник -> Изисквания", -1);
	
	Question q45("Кое от изброените определя метода MOSKOW?");
	q45.AddOption("техника за определяне на качествата на изискванията", -1);
	q45.AddOption("техника за постигане на споразумение за важността за изпълнение на всяко изискване", 1);
	q45.AddOption("техника за валидиране на изискванията", -1);
	q45.AddOption("техника за анализ на изискванията", -1);
	
	Question q46("Кои са предимствата на метода на различните гледни точки в сравнение с другите методи за извличане на изискванията?");
	q46.AddOption("Позволяват използване на различни структурни модели", -1);
	q46.AddOption("Разпознават източниците на изискванията", 0.5);
	q46.AddOption("Представят механизъм за оргранизация у структуриране на разнообразна информация", 0.5);
	q46.AddOption("Позволяват да се позлват различни техники за извличане на изисквания", -1);
	
	Question q47("Кои от изброените са характерни за съхранението на изисквания в база данни?");
	q47.AddOption("Има автоматична навигация от едно изискване към друго", 0.5);
	q47.AddOption("Не може да се свържат изискванията с предложени промени", -1);
	q47.AddOption("Лесно се поддържат версии на нови изисквания", 0.5);
	q47.AddOption("Лесно се генерира финалния документ", -1);
	
	Question q48("Основната концепция на описанието с обектно-ориентиран модел е да:");
	q48.AddOption("Опише взаимодействието на данните с други външни или вътрешни обекти", -1);
	q48.AddOption("Представи капсулиран запис на данните", 1);
	q48.AddOption("Опише данните на базата на математически принципи", -1);
	q48.AddOption("Опише логическата структура на данните, обработвена в системата", -1);
	
	Question q49("Задачата на предварителния преглед на документа на изискванията в етапа на валидиране е:");
	q49.AddOption("Проверка за липсващи изисквания", 0.5);
	q49.AddOption("Проверка за двусмислие в изискванията", -1);
	q49.AddOption("Проверка за съгласуваност със стандартите", 0.5);
	q49.AddOption("Проверка за приложимост на тест", -1);
	
	Question q50("Диаграмата на потока на данните показва?");
	q50.AddOption("Източници на информация", 0.5);
	q50.AddOption("Заинтересованите лица на системата", -1);
	q50.AddOption("Актьори на системата", -1);
	q50.AddOption("Правилата за използване на системата", 0.5);
	
	Question q51("Кое не е задължителен принцип при извличане и специфициране на софтуерните изисквания??");
	q51.AddOption("обединяване на спцифични знания", -1);
	q51.AddOption("дефиниране на класове", 1);
	q51.AddOption("организация според гледни точки и/или перспективи", -1);
	q51.AddOption("абстракция", -1);
	
	Question q52("В кои от следните дейности от процеса на анализ и оценка на промените на изскванията искането за промяна може да бъде отхвърлено?");
	q52.AddOption("Проверка за валидност на исканата промяна", 0.5);
	q52.AddOption("Откриване на зависимите изисквания", -1);
	q52.AddOption("Предложение за промяна на изискванията", 0.5);
	q52.AddOption("Оценка на цената на промяната", -1);
	
	Question q53("Кои от изброеите изисквания не са подходящи за преизползване (requirements reuse)?");
	q53.AddOption("Проверка за валидност на исканата промяна", 0.5);
	q53.AddOption("Откриване на зависимите изисквания", -1);
	q53.AddOption("Предложение за промяна на изискванията", 0.5);
	q53.AddOption("Оценка на цената на промяната", -1);
	
	Question q54("Проверката за валидност на кой модел на софтуерна система може да бъде избегната?");
	q54.AddOption("Модел на потока на данните", -1);
	q54.AddOption("Модел същност-връзка", -1);
	q54.AddOption("Формален модел", 1);
	q54.AddOption("Обектно-ориентиран модел", -1);
	
	Question q55("Кои от изброените изисквания не са подходящи за преизползване (requirements reuse)?");
	q55.AddOption("Изисквания за структурата на базата данни", 0.5);
	q55.AddOption("Изисквания за интерфейса на системата", -1);
	q55.AddOption("Изисквания за ограничения, произтичащи от приложната област", -1);
	q55.AddOption("Изисквания за надеждност на системата", 0.5);
	
	Question q56("В коя от дейностите на инженеринга на изискванията се прилага техниката на описание на Случаи на употреба (Use cases):");
	q56.AddOption("Идентифициране на изискванията", 0.5);
	q56.AddOption("Структурирано описание на системата", -1);
	q56.AddOption("Изискване на контекста на системата", -1);
	q56.AddOption("Анализ на изискванията", 0.5);
/*	
	Question q57("?");
	q57.AddOption("", -1);
	q57.AddOption("", -1);
	q57.AddOption("", -1);
	q57.AddOption("", -1);
	
	Question q58("?");
	q58.AddOption("", -1);
	q58.AddOption("", -1);
	q58.AddOption("", -1);
	q58.AddOption("", -1);
	
	Question q59("?");
	q59.AddOption("", -1);
	q59.AddOption("", -1);
	q59.AddOption("", -1);
	q59.AddOption("", -1);
	
	Question q60("?");
	q60.AddOption("", -1);
	q60.AddOption("", -1);
	q60.AddOption("", -1);
	q60.AddOption("", -1);
	
	Question q61("?");
	q61.AddOption("", -1);
	q61.AddOption("", -1);
	q61.AddOption("", -1);
	q61.AddOption("", -1);
	
	Question q62("?");
	q62.AddOption("", -1);
	q62.AddOption("", -1);
	q62.AddOption("", -1);
	q62.AddOption("", -1);
	
	Question q63("?");
	q63.AddOption("", -1);
	q63.AddOption("", -1);
	q63.AddOption("", -1);
	q63.AddOption("", -1);
	
	Question q64("?");
	q64.AddOption("", -1);
	q64.AddOption("", -1);
	q64.AddOption("", -1);
	q64.AddOption("", -1);
	
	Question q65("?");
	q65.AddOption("", -1);
	q65.AddOption("", -1);
	q65.AddOption("", -1);
	q65.AddOption("", -1);
	
	Question q66("?");
	q66.AddOption("", -1);
	q66.AddOption("", -1);
	q66.AddOption("", -1);
	q66.AddOption("", -1);
	
	Question q67("?");
	q67.AddOption("", -1);
	q67.AddOption("", -1);
	q67.AddOption("", -1);
	q67.AddOption("", -1);
	
	Question q68("?");
	q68.AddOption("", -1);
	q68.AddOption("", -1);
	q68.AddOption("", -1);
	q68.AddOption("", -1);
	
	Question q69("?");
	q69.AddOption("", -1);
	q69.AddOption("", -1);
	q69.AddOption("", -1);
	q69.AddOption("", -1);
	
	Question q70("?");
	q70.AddOption("", -1);
	q70.AddOption("", -1);
	q70.AddOption("", -1);
	q70.AddOption("", -1);
	
	Question q71("?");
	q71.AddOption("", -1);
	q71.AddOption("", -1);
	q71.AddOption("", -1);
	q71.AddOption("", -1);
	
	Question q72("?");
	q72.AddOption("", -1);
	q72.AddOption("", -1);
	q72.AddOption("", -1);
	q72.AddOption("", -1);
	
	Question q73("?");
	q73.AddOption("", -1);
	q73.AddOption("", -1);
	q73.AddOption("", -1);
	q73.AddOption("", -1);
	
	Question q74("?");
	q74.AddOption("", -1);
	q74.AddOption("", -1);
	q74.AddOption("", -1);
	q74.AddOption("", -1);
	
	Question q75("?");
	q75.AddOption("", -1);
	q75.AddOption("", -1);
	q75.AddOption("", -1);
	q75.AddOption("", -1);
	
	Question q76("?");
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	
	Question q77("?");
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	
	Question q78("?");
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	
	Question q79("?");
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	
	Question q80("?");
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	
	Question q81("?");
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	
	Question q82("?");
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	
	Question q83("?");
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	
	Question q84("?");
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	
	Question q85("?");
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	
	Question q86("?");
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	
	Question q87("?");
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	
	Question q88("?");
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	
	Question q89("?");
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	
	Question q90("?");
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	
	Question q91("?");
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	
	Question q92("?");
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	
	Question q93("?");
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	
	Question q94("?");
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	
	Question q95("?");
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	
	Question q96("?");
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	
	Question q97("?");
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	
	Question q98("?");
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	
	Question q99("?");
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	
	Question q100("?");
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	
	Question q101("?");
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	
	Question q102("?");
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	
	Question q103("?");
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	
	Question q104("?");
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	
	Question q105("?");
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	
	Question q106("?");
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	
	Question q107("?");
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	
	Question q108("?");
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	
	Question q109("?");
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	
	Question q110("?");
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	
	Question q111("?");
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	
	Question q112("?");
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	
	Question q113("?");
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	
	Question q114("?");
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	
	Question q115("?");
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	
	Question q116("?");
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	
	Question q117("?");
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	
	Question q118("?");
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	
	Question q119("?");
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	
	Question q120("?");
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	
	Question q121("?");
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	
	Question q122("?");
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	
	Question q123("?");
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	
	Question q124("?");
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	
	Question q125("?");
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	
	Question q126("?");
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	
	Question q127("?");
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	
	Question q128("?");
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	
	Question q129("?");
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	
	Question q130("?");
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	
	Question q131("?");
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	
	Question q132("?");
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	
	Question q133("?");
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	
	Question q134("?");
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	
	Question q135("?");
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	
	Question q136("?");
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	
	Question q137("?");
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	
	Question q138("?");
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	
	Question q139("?");
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	
	Question q140("?");
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	
	Question q141("?");
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	
	Question q142("?");
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	
	Question q143("?");
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	
	Question q144("?");
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	
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
/*
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
        exam.push_back(q145);
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
			std::cout << "Секция със сгрешени въпроси\nнатиснете някой бутон\n";
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
