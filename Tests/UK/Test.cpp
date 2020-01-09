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
	
	Question q9("При тестването по метода на черната кутия (black box testing) се проверява дали:");
	q9.AddOption("Външните функции на софтуерната система са коректни ", 0.5);
	q9.AddOption("Програмните единици на софтуерната система са коректно реализирани ", -1);
	q9.AddOption("Наблюдаваното поведение на софтуерната система съответства на потребителските очаквания или продуктовата спецификация", 0.5);
	q9.AddOption("Програмните единици на софтуерната система са коректно интегрирани помежду си", -1);
	
	Question q10("При тестването по метода на бялата кутия (white box testing) се проверява дали:");
	q10.AddOption("Външните функции на софтуерната система са коректни ", -1);
	q10.AddOption("Програмните единици на софтуерната система са коректно реализирани", 0.5);
	q10.AddOption("Наблюдаваното поведение на софтуерната система съответства на потребителските очаквания или продуктовата спецификация", -1);
	q10.AddOption("Програмните единици на софтуерната система са коректно интегрирани помежду си", 0.5);
	
	Question q11("Кое от следните НЕ е вярно за структурното тестване?");
	q11.AddOption("Софтуерната система се разглежда като бяла кутия ", -1);
	q11.AddOption("Откриването на дефекти е по-лесно, тъй като се отстраняват проблеми в малки програмни единици ", -1);
	q11.AddOption("Прилага се на по-късните етапи от разработката на софтуерната система", 1);
	q11.AddOption("Използва специфични техники на тестване", -1);
	
	Question q12("Какво тестване се прилага на ниво разработване върху компонентите?");
	q12.AddOption("Юнит „блек бокс“ тестване", -1);
	q12.AddOption("Юнит „уайт бокс“ тестване", 1);
	q12.AddOption("Интеграционно ", -1);
	q12.AddOption("Тестване за приемане", -1);
	
	Question q13("Кога тестов процес може да спре?");
	q13.AddOption("Когато са отстранени всички дефекти в софтуерната система ", -1);
	q13.AddOption("Когато е достигнато определено ниво на тестово покритие", 0.5);
	q13.AddOption("Когато е достигнато определено ниво на надеждност", 0.5);
	q13.AddOption("Когато всички тестови сценарии са изпълнени успешно", -1);
	
	Question q14("Тестовите сценарии се състоят от:");
	q14.AddOption("Последователни стъпки за реализиране на определен тестов процес,  предпоставки и входни данни за изпълнение на тези стъпки, очаквани разултати при използване на определен набор от входни данни ", 1);
	q14.AddOption("Тестови проекти за изследване на определени бизнес процеси в дадена софтуерна система", -1);
	
	Question q15("Какво е предназначението на тестовия оракул?");
	q15.AddOption("Предсказване на очаквания резултат от изпълнението на тестовите сценарии ", 1);
	q15.AddOption("Планиране на тестовия процес", -1);
	q15.AddOption("Предсказване на получения резултат от изпълнението на тестовите сценарии ", -1);
	
	Question q16("Кои от изброените дейности подлежат на автоматизация?");
	q16.AddOption("Изпълнение на тестове ", 0.5);
	q16.AddOption("Анализ на тестовото покритие", 0.5);
	q16.AddOption("Фиксиране на проблеми", -1);
	q16.AddOption("Планиране на тестовата процедура ", -1);
	
	Question q17("Кое от изброените НЕ е свойство на софтуерното измерване?");
	q17.AddOption("Обективност", -1);
	q17.AddOption("Валидност", -1);
	q17.AddOption("Консистентност", 1);
	q17.AddOption("Надеждност", -1);
	
	Question q18("Кое от изброентие НЕ е дейност на софтуерното измерване?");
	q18.AddOption("Формулиране на метричната система", -1);
	q18.AddOption("Анализиране" , -1);
	q18.AddOption("Верифициране" , 1);
	q18.AddOption("Осъществяване на обратна връзка ", -1);
	
	Question q19("От коя гледна точка за качеството означава съответствие със спецификацията?");
	q19.AddOption("абстрактна", -1);
	q19.AddOption("потребителска", -1);
	q19.AddOption("на производителя/разработчика", 1);
	q19.AddOption("базиран на цената", -1);
	
	Question q20("Какво НЕ е характерно за класическите модели на качество?");
	q20.AddOption("Фокусират се върху качеството на крайния продукт", -1);
	q20.AddOption("Задават ключовите атрибути на качеството от гледна точка на потребителите", 1);
	q20.AddOption("Дават представа за това как избраните фактори на качество се развиват в рамките на проекта", -1);
	
	Question q21("Кое от изброените НЕ е аспект на качеството от универсалния модел ISO  - 9 126?");
	q21.AddOption("Качество при промяна на продукта", 1);
	q21.AddOption("Качество на процеса за създаване на продукт ", -1);
	q21.AddOption("Вътрешно качество на продукта", -1);
	q21.AddOption("Вътрешно качество на продукта", -1);
	
	Question q22("Коя от изброените НЕ е под-характеристика на характеристиката Usability според стандарта за качество ISO - 9 126?");
	q22.AddOption("Recoverability", 1);
	q22.AddOption("Learnability", -1);
	q22.AddOption("Understandability", -1);
	q22.AddOption("Operability", -1);
	
	Question q23("Коя от изброените НЕ е под-характеристика на характеристиката Funcionality според стандарта за качество ISO - 9 126?");
	q23.AddOption("Interoperability", -1);
	q23.AddOption("Suitability ", -1);
	q23.AddOption("Accuracy", -1);
	q23.AddOption("Understandability", -1);
	
	Question q24("Коя от изброените НЕ е под-характеристика на характеристиката Maintainability според стандарта за качество ISO - 9 126?");
	q24.AddOption("Changeability ", -1);
	q24.AddOption("Testability", -1);
	q24.AddOption("Installability", 1);
	q24.AddOption("Stability", -1);
	
	Question q25("Коя от изброените НЕ е под-характеристика на характеристиката Portability според стандарта за качество ISO - 9 126?");
	q25.AddOption("Changeability", 1);
	q25.AddOption("Testability", -1);
	q25.AddOption("Installability", -1);
	q25.AddOption("Stability", -1);
	
	Question q26("Кое е характерно за съвременните модели на качество?");
	q26.AddOption("Фокусират се върху качеството на крайния продукт ", 0.5);
	q26.AddOption("Дават представа за това как избраните фактори за качество се развиват в рамките на проекта", 0.5);
	q26.AddOption("Задават ключовите атрибути на качеството от гледна точка на потребителите", -1);
	q26.AddOption("Йерархични модели са", -1);
	
	Question q27("Кои от изброените твърдения са верни за модела на качество на  NASA –SATC?");
	q27.AddOption("Дефинира множество от цели, които са свързани с факторите за качество на софтуерния продукт", 0.5);
	q27.AddOption("Обхваща три обособени области в употребата на софтуерния продукт", -1);
	q27.AddOption("Обвързан е силно с управлението на риска в проекта", 0.5);
	q27.AddOption("Статичен е и не дава представа как избраните фактори за качество се развиват в рамките на проекта", -1);
	
	Question q28("Кои от изброените са метрики за ефективност на тестването на модел NASA - SATC?");
	q28.AddOption("Грешки и оценка за критичността им", 0.5);
	q28.AddOption("Време за откриване на грешките", 0.5);
	q28.AddOption("Честота на грешките", -1);
	q28.AddOption("Сериозност на грешките", -1);
	
	Question q29("Какво означава Уместна метрика на качеството?");
	q29.AddOption("Не измерва атрибути, вече измервани от други метрики", -1);
	q29.AddOption("Приложима в различни ситуации", -1);
	q29.AddOption("Измерва атрибут от голямо значение", 1);
	q29.AddOption("Измерва искания атрибут", -1);
	
	Question q30("Какво означава свойството Надеждност на софтуерното измерване?");
	q30.AddOption("Мярката да има необходимата различаваща способност", -1);
	q30.AddOption("Получаваните мерки да отразяват реално свойствата на измервания обект", -1);
	q30.AddOption("Получаваните мерки да не зависят от субекта, извършващ измерването", -1);
	q30.AddOption("При повтаряне на измерването при еднакви условия да се получават еднакви резултати", 1);
	
	Question q31("Кои от изброените са метрики за качество на софтуерния процес?");
	q31.AddOption("Честота на грешите ", 0.5);
	q31.AddOption("MTTF (Време между две аварии)", -1);
	q31.AddOption("Проблеми, идентифицирани от потребителите", -1);
	q31.AddOption("Сериозност на грешките", 0.5);
	
	Question q32("Метриката многократно използване на код (code reuse) е свързана с");
	q32.AddOption("Качество на проекта", -1);
	q32.AddOption("Качество на софтуерния продукт", -1);
	q32.AddOption("Качество на софтуерния процес", -1);
	q32.AddOption("Продуктивност на софтуерния процес", 1);
	
	Question q33("Кои от изброените са метрики за продукт?");
	q33.AddOption("MTTF Време между две аварии", 1);
	q33.AddOption("Ниво на дефектите ", -1);
	q33.AddOption("Честота на грешките ", -1);
	q33.AddOption("Сериозност на грешките", -1);
	
	Question q34("Кои от изброените са метрики за поддръжка на софтуера?");
	q34.AddOption("Време за отстраняване на грешките", 0.5);
	q34.AddOption("Брой погрешно обработени грешки", 0.5);
	q34.AddOption("Честота на грешки от кодиране", -1);
	q34.AddOption("Средна сериозност на грешки от разработване", -1);
	
	Question q35("При коя от изброените дейности НЕ се регистрират грешки?");
	q35.AddOption("Специфиране на софтуерните изисквания", 1);
	q35.AddOption("Ревю на документацията – в спецификациите за проекта или в потребителската документация", -1);
	q35.AddOption("Преглед на фазите и инспекция на проекта", -1);
	q35.AddOption("Работа на системата в гаранционен период", -1);
	
	Question q36("Използването на контролни списъци се ограничава поради:");
	q36.AddOption("Трудности при покриване на всички функционални или структурни компоненти от различни гледни точки и при различни нива на гранулярност", 0.5);
	q36.AddOption("Трудности при създаване на контролни списъци от елементите на спецификацията", -1);
	q36.AddOption("Трудности при създаване на контролни списъци от характеристиките на софтуерната система ", -1);
	q36.AddOption("Трудности при описание на сложни взаимодействия между различните системни компоненти или между главните системни функции", 0.5);
	
	Question q37("Кое от следните свойства е характерно за класовете на еквивалентност?");
	q37.AddOption("Изградени са от подмножества, които се припокриват", -1);
	q37.AddOption("Изградени са от множества, които са взаимно изчерпателни", -1);
	q37.AddOption("Изградени са от подмножества, в които елементите предизвикват различно поведение на софтуерната система", 1);
	
	Question q38("При тестване с класове на еквивалентност се извършва разделяне на тестовите сценарии на групи:");
	q38.AddOption("Които са с еднакви гранични стойности", -1);
	q38.AddOption("За които при еднакви входни данни се получават различни тестови резултати", -1);
	q38.AddOption("За които се предполага, че предизвикват еквивалентно поведение на системата ", 1);
	
	Question q39("При статистическото тестване, базирано на употреба се използват:");
	q39.AddOption("Контролни списъци", -1);
	q39.AddOption("Класове на еквивалентност", -1);
	q39.AddOption("Таблици за взимане на решения", -1);
	q39.AddOption("Оперативни профили", 1);
	
	Question q40("Какво представлява оперативния профил?");
	q40.AddOption("Количествена характеристика за начина, по който системата се използва", 1);
	q40.AddOption("Модел на функционалността, предлагана от системата", -1);
	q40.AddOption("Набор от качествени показатели за работата на системата", -1);
	
	Question q41("При създаването на оперативен профил по процедурата Муса-1 се извършва:");
	q41.AddOption("Дефиниране на цялостното множество от клиентски категории с теглови коефициенти, определени от фактор за използване", -1);
	q41.AddOption("Идентифициране на множества от операции, които се използват съвместно и определяне на съответстващите им теглови коефициенти", -1);
	q41.AddOption("Транслиране на функциите от високо ниво в детайлни операции и определяне на тяхната вероятност за използване", 1);
	
	Question q42("Какви са трудностите при действителното измерване на използваемостта при потребителите?");
	q42.AddOption("Ниска точност на създадения оперативен профил", -1);
	q42.AddOption("Невъзможност за приложение при нови продукти и нови приложения", 0.5);
	q42.AddOption("Наличие на ограничения при използване на корпоративни и лични данни", 0.5);
	q42.AddOption("Точността на проучването се влияе от познанията на потребителите за функционалността на продукта", -1);
	
	Question q43("Как се интерпретират проблемите с изходите при машините на крайните състояния?");
	q43.AddOption("Като проблеми с преходите", 1);
	q43.AddOption("Като проблеми със състоянията", -1);
	q43.AddOption("Като проблеми с преходите и състоянията", -1);
	
	Question q44("От какво зависи броят на тестовите сценарии при тестване с машина на крайните състояния?");
	q44.AddOption("Общия брой състояния ", -1);
	q44.AddOption("Броят на входните и изходните състояния", 1);
	q44.AddOption("Броят на преходите", -1);
	q44.AddOption("Разнообразието на входните и изходните данни", -1);
	
	Question q45("Кой от следните проблеми е типичен за тестването с машина на крайните състояния?");
	q45.AddOption("Невъзможност за тестване на обектно-ориентирани системи", -1);
	q45.AddOption("Невъзможност за тестване на софтуерни системи с графичен потребителски интерфейс", -1);
	q45.AddOption("Трудно постигане на тестово покритие при големи софтуерни системи", 1);
	
	Question q46("Как се осигурява пълно покритие при домейн тестването?");
	q46.AddOption("Избират се гранични точки от всеки поддомейн", -1);
	q46.AddOption("Избира се по една вътрешна точка от всеки поддомейн", 1);
	q46.AddOption("Избират се минимум две вътрешни точки от всеки поддомейн", -1);
	
	Question q47("При тестване на входния домейн каква е причината дадена софтуерна система да произвежда различни изходи при един и същ вход?");
	q47.AddOption("Дефиниране на изчислителни процедури за отделни поддомейни, някои от които се припокриват", 1);
	q47.AddOption("Дефиниране на изчислителни процедури само за определени поддомейни от общия входен домейн", -1);
	q47.AddOption("Дефиниране на изчислителни процедури за взаимоизключващи се поддомейни", -1);
	
	Question q48("От какво естество са проблемите, свързани с изместване на граница на домейн?");
	q48.AddOption("Специфициране на отворена граница като отворене и реализиране като затворена", -1);
	q48.AddOption("Разминаване между очакваната и действително специфицирана или реализирана граница ", 1);
	q48.AddOption("Сливане на два различни поддомейна в общ поддомейн", -1);
	q48.AddOption("Наличие на поддомейни, които са с еднакви свойства", -1);
	
	Question q49("Какъв е броят на тестовите сценарии при тестване с комбинация на екстремни точки?");
	q49.AddOption("2^n", -1);
	q49.AddOption("2^n + 1", -1);
	q49.AddOption("4^n", -1);
	q49.AddOption("4^n  + 1", 1);
	
	Question q50("Определете тестовите точки за едномерен домейн 0 ≤ x < 21 в случай на тестване с комбинация от екстремни точки?");
	q50.AddOption("-1,0,10,21,22", 1);
	q50.AddOption("-1,0,1,10,20,21,22", -1);
	q50.AddOption("1,0,1,20,21,22", -1);
	q50.AddOption("1,0,21,22", -1);
	
	Question q51("Как се избира "OFF" точка при затворена граница, когато се прилага стратегията \"weak N x 1\"?");
	q51.AddOption("Като OFF точка се избира външна точка, която е много близо до границата", 1);
	q51.AddOption("Като OFF точка се избира вътрешна точка, която е много близо до границата", -1);
	q51.AddOption("Като OFF точка се избира произволна точка", -1);
	
	Question q52("Къде се намира OFF точката, когато се прилага стратегията weak Nx1, ако границата е затворена и е налице изместване на границата?");
	q52.AddOption("OFF точката е на дистанция ε от границата ", -1);
	q52.AddOption("OFF точката ще бъде извън поддомейна", 1);
	q52.AddOption("OFF точката ще бъде в поддомейна", -1);
	
	Question q53("Какви са ON и OFF точките за едномерен домейн 0 ≤ x < 21, когато се прилага стратегията weak N x 1?");
	q53.AddOption("ON точки: x = 0 и x = 21; OFF точки: x = -1", -1);
	q53.AddOption("ON точки: x = 0 и x = 21; OFF точки: x = -1 и x = 20", 1);
	q53.AddOption("ON точки: x = 0 и x = 21; OFF точки: x = 20", -1);
	
	Question q54("Boundary Value Testing е техника за:");
	q54.AddOption("Оптимизация на Test cases", -1);
	q54.AddOption("Проектиране на тестове за сигурност", 1);
	q54.AddOption("Задължителна техника при System testing", -1);
	
	Question q55("Таблицата на решенията е техника за тестване при която се:");
	q55.AddOption("Изследва ефекта от комбинацията на различни входове и други състояния на софтуера, които трябва правилно да имплементират бизнес правила.", 1);
	q55.AddOption("Изследва ефекта при подаване на еднакви входове на систамата и се очаква получаване на различни изходи в зависимост от настъпили събития", -1);
	q55.AddOption("Изследва ефекта от настъпването на различни събития в системата", -1);
	
	Question q56("ои пътища се елиминират при конкатенация на два бинарни подграфа с противоположни условия C1 = -C2, в случай на тестване с граф на управляващия поток?");
	q56.AddOption("TT и FF", 1);
	q56.AddOption("TF и FF", -1);
	q56.AddOption("TT FT", -1);
	q56.AddOption("", -1);
	
	Question q57("Кой път се елиминира при конкатенация на два бинарни подграфа с противоположни условия C1 = (x > 0) и C2 = (x < 100) в случай на тестване с граф на управляващия поток?");
	q57.AddOption("TT", -1);
	q57.AddOption("FT", -1);
	q57.AddOption("TF", -1);
	q57.AddOption("FF", 1);
	
	Question q58("Какви проблеми могат да бъдат открити при тестване на долна граница на цикъл, когато цикълът се изпълнява еднократно?");
	q58.AddOption("Проблеми, които пречат на повторното изпълнение на цикъла", -1);
	q58.AddOption("Проблеми, свързани с инициализацията на цикъла и начално установяване", 1);
	q58.AddOption("Проблеми, свързани с инициализацията на цикъла", -1);
	
	Question q59("Каква е целта на тестването на данновите зависимости?");
	q59.AddOption("Верификация на коректното реализиране на взаимовръзките между програмните променливи", 1);
	q59.AddOption("Верификация на логическата последователност на изпълнение на програмата", -1);
	q59.AddOption("Верификация на коректното реализиране на взаимовръзките между програмните модули", -1);
	
	Question q60("Коя от изброените релации се игнорира при анализ на данновите зависимости?");
	q60.AddOption("D-U реалция", -1);
	q60.AddOption("D-D релация", -1);
	q60.AddOption("U-U релация", 1);
	q60.AddOption("U-D релация", -1);
	
	Question q61("Какъв тип са релациите при конструирането на граф на данновите зависимости?");
	q61.AddOption("D-U релация", 1);
	q61.AddOption("D-D релация", -1);
	q61.AddOption("U-D релация", -1);
	q61.AddOption("U-U релация", -1);
	
	Question q62("Как се инициализират променливите, представляващи даннов вход при тестване с граф на управляващия поток?");
	q62.AddOption("Избира се стойност, която осигурява подходящо изчисляване на предиката", -1);
	q62.AddOption("Избира се случайна стойност", 1);
	q62.AddOption("Избира се стойност, която осигурява получаване на точно определен изход от изпълнението на програмата", -1);
	
	Question q63("Кое от следните твърдения НЕ е вярно за графа на данновия поток?");
	q63.AddOption("Представлява специален тип машина на крайните състояния", 1);
	q63.AddOption("Представя детайлите на взаимодействието и данновите зависимости", -1);
	q63.AddOption("Характеризира се с по-големи ограничения при представяне на циклите в сравнение с графа на управляващия поток", -1);
	
	Question q64("Кое от следните твърдения НЕ е вярно за графа на управляващия поток?");
	q64.AddOption("Представлява специален тип машина на крайните състояния", -1);
	q64.AddOption("Представлява програмен код или потока на изпълнение, асоцииран с последователните изчислителни модели", -1);
	q64.AddOption("Характеризира се с по-голяма сложност в сравнение с графа на данновия поток", 1);
	
	Question q65("Коя от изброените активности за осигуряване на качеството НЕ се класифицира като активност на валидация?");
	q65.AddOption("Интеграционно тестване (Integration testing)", 1);
	q65.AddOption("Тестване на ниво система (System testing)", -1);
	q65.AddOption("Активности, свързани с осигуряване на сигурност(Software safety assurance activities)", -1);
	q65.AddOption("Активности, свързани с отказоустойчивост (Software fault tolerance)", -1);
	
	Question q66("Кога може да се извърши тестването за приемане на системата?");
	q66.AddOption("В края на системното тестване", 1);
	q66.AddOption("След бета тестването", -1);
	q66.AddOption("В края на интеграционното тестване", -1);
	
	Question q67("Kакво представлява мутацията на софтуерна единица?");
	q67.AddOption("Модификация в програмата, реализирана чрез въвеждане на единична, малка, синтактично неправилна промяна в кода", -1);
	q67.AddOption("Модификация в програмата, реализирана чрез оптимизация на нейния код", -1);
	q67.AddOption("Модификация в програмата, реализирана чрез въвеждане на единична, малка, синтактично правилна промяна в кода", -1);
	
	Question q68("Регресионното тестване включва:");
	q68.AddOption("Създаване на нови тестове и тяхното изпълнение", -1);
	q68.AddOption("Приоритизиране на съществуващи тестове и тяхното изпълнение", -1);
	q68.AddOption("Изпълнение на всички съществуващи тестове", 1);
	q68.AddOption("Създаване на нови тестове и тяхното изпълнение заедно със съществуващи тестове", -1);
	
	Question q69("Целта на регресионното тестване е да удовлетвори:");
	q69.AddOption("Правилната имплементаия на определен бизнес процес след корекция  на регистрирани грешки, при което не са възникнали нови грешки в свързани с този процес сценарии (модули)", 1);
	q69.AddOption("Работоспособността на софтуерното решение при максимално допустимо натоварване", -1);
	
	Question q70("Каква е същността на стрес тестовете?");
	q70.AddOption("Доказване, че софтуерната система не може да обработи големи обеми от данни, специфицирани в целите й", -1);
	q70.AddOption("Натоварване на софтуерната система с голям обем от данни или дейности за кратък период от време", 1);
	q70.AddOption("Проверка дали изходът от софтуерната система е смислен за потребителя", -1);
	q70.AddOption("Доказване, че софтуерната система може да се възстанови след срив", -1);
	
	Question q71("Stress testing се изпълнява за да се изследват изисквания, свързани с:");
	q71.AddOption("Security requirements", -1);
	q71.AddOption("Performance Requirements", 1);
	q71.AddOption("Functional Requirements ", -1);
	
	Question q72("Кои свойства на софтуерната система се тестват при тестване на използваемостта?");
	q72.AddOption("Съответствие на потребителския интерфейс и индивидуалните характеристики на потребителите", 0.5);
	q72.AddOption("Време за отговор", -1);
	q72.AddOption("Разбираемост на съобщенията за грешка", 0.5);
	q72.AddOption("Обемът данни, който може да бъде обработен от софтуерната система", -1);
	
	Question q73("Кое е цел на тестването на производителност:");
	q73.AddOption("Да се проследи времето за отговор на системата", 0.5);
	q73.AddOption("Да се валидира дали системата покрива бизнес изискванията", 0.5);
	q73.AddOption("Да се намери оптималната конфигурация на хардуерните и софтуерните ресурси", -1);
	q73.AddOption("Да се открие максимален брой потребители", -1);
	
	Question q74(""Кое от изброените НЕ е цел на тестването на производителност?);
	q74.AddOption("Да се проследи времето за отговор на системата", -1);
	q74.AddOption("Да се валидира дали системата покрива бизнес изискванията", -1);
	q74.AddOption("Да се намери оптималната конфигурация на хардуерните и софтуерните ресурси", 0.5);
	q74.AddOption("Да се открие максимален брой потребители", 0.5);
	
	Question q75("Кои свойства на софтуерната система НЕ се тестват при тестване на производителността:");
	q75.AddOption("Време за отговор", -1);
	q75.AddOption("Пропускателна способност", -1);
	q75.AddOption("Конфигурируемост", 0.5);
	q75.AddOption("Унифицираност на потребителския интерфейс", 0.5);
	
	Question q76("");
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	q76.AddOption("", -1);
	
	Question q77("");
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	q77.AddOption("", -1);
	
	Question q78("");
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	q78.AddOption("", -1);
	
	Question q79("");
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	q79.AddOption("", -1);
	
	Question q80("");
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	q80.AddOption("", -1);
	
	Question q81("");
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	q81.AddOption("", -1);
	
	Question q82("");
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	q82.AddOption("", -1);
	
	Question q83("");
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	q83.AddOption("", -1);
	
	Question q84("");
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	q84.AddOption("", -1);
	
	Question q85("");
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	q85.AddOption("", -1);
	
	Question q86("");
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	q86.AddOption("", -1);
	
	Question q87("");
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	q87.AddOption("", -1);
	
	Question q88("");
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	q88.AddOption("", -1);
	
	Question q89("");
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	q89.AddOption("", -1);
	
	Question q90("");
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	q90.AddOption("", -1);
	
	Question q91("");
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	q91.AddOption("", -1);
	
	Question q92("");
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	q92.AddOption("", -1);
	
	Question q93("");
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	q93.AddOption("", -1);
	
	Question q94("");
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	q94.AddOption("", -1);
	
	Question q95("");
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	q95.AddOption("", -1);
	
	Question q96("");
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	q96.AddOption("", -1);
	
	Question q97("");
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	q97.AddOption("", -1);
	
	Question q98("");
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	q98.AddOption("", -1);
	
	Question q99("");
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	q99.AddOption("", -1);
	
	Question q100("");
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	q100.AddOption("", -1);
	
	Question q101("");
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	q101.AddOption("", -1);
	
	Question q102("");
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	q102.AddOption("", -1);
	
	Question q103("");
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	q103.AddOption("", -1);
	
	Question q104("");
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	q104.AddOption("", -1);
	
	Question q105("");
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	q105.AddOption("", -1);
	
	Question q106("");
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	q106.AddOption("", -1);
	
	Question q107("");
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	q107.AddOption("", -1);
	
	Question q108("");
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	q108.AddOption("", -1);
	
	Question q109("");
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	q109.AddOption("", -1);
	
	Question q110("");
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	q110.AddOption("", -1);
	
	Question q111("");
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	q111.AddOption("", -1);
	
	Question q112("");
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	q112.AddOption("", -1);
	
	Question q113("");
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	q113.AddOption("", -1);
	
	Question q114("");
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	q114.AddOption("", -1);
	
	Question q115("");
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	q115.AddOption("", -1);
	
	Question q116("");
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	q116.AddOption("", -1);
	
	Question q117("");
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	q117.AddOption("", -1);
	
	Question q118("");
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	q118.AddOption("", -1);
	
	Question q119("");
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	q119.AddOption("", -1);
	
	Question q120("");
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	q120.AddOption("", -1);
	
	Question q121("");
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	q121.AddOption("", -1);
	
	Question q122("");
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	q122.AddOption("", -1);
	
	Question q123("");
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	q123.AddOption("", -1);
	
	Question q124("");
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	q124.AddOption("", -1);
	
	Question q125("");
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	q125.AddOption("", -1);
	
	Question q126("");
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	q126.AddOption("", -1);
	
	Question q127("");
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	q127.AddOption("", -1);
	
	Question q128("");
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	q128.AddOption("", -1);
	
	Question q129("");
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	q129.AddOption("", -1);
	
	Question q130("");
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	q130.AddOption("", -1);
	
	Question q131("");
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	q131.AddOption("", -1);
	
	Question q132("");
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	q132.AddOption("", -1);
	
	Question q133("");
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	q133.AddOption("", -1);
	
	Question q134("");
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	q134.AddOption("", -1);
	
	Question q135("");
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	q135.AddOption("", -1);
	
	Question q136("");
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	q136.AddOption("", -1);
	
	Question q137("");
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	q137.AddOption("", -1);
	
	Question q138("");
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	q138.AddOption("", -1);
	
	Question q139("");
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	q139.AddOption("", -1);
	
	Question q140("");
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	q140.AddOption("", -1);
	
	Question q141("");
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	q141.AddOption("", -1);
	
	Question q142("");
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	q142.AddOption("", -1);
	
	Question q143("");
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	q143.AddOption("", -1);
	
	Question q144("");
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	q144.AddOption("", -1);
	
	Question q145("");
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	q145.AddOption("", -1);
	
	Question q146("");
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	q146.AddOption("", -1);
	
	Question q147("");
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	q147.AddOption("", -1);
	
	Question q148("");
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	q148.AddOption("", -1);
	
	Question q149("");
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	q149.AddOption("", -1);
	
	Question q150("");
	q150.AddOption("", -1);
	q150.AddOption("", -1);
	q150.AddOption("", -1);
	q150.AddOption("", -1);
	
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
        exam.push_back(q145);
        exam.push_back(q146);
        exam.push_back(q147);
        exam.push_back(q148);
        exam.push_back(q149);
        exam.push_back(q150);	

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
