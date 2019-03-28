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
	std::cout << "Test 1 po KMR\nIzgotven ot Mapmo\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Host SU-A smukva fail ot survur. Kakav e iztochnika na MAC adresa na freymovete, koito SU-A poluchava ot survura, pri polojenie chehost i syrvyr sa na edin Ethernet?");
	q1.AddOption("MAC adres na mrejoviq interface", 1);
	q1.AddOption("MAC adres na ruterskiq interface e0", -1);
	q1.AddOption("MAC adres na ruterskiq interface e1", -1);
	q1.AddOption("MAC adres na SU_A", -1);
	exam.push_back(q1);

	Question q2("Koi ot po-dolnite tvyrdeniq za OSI modela sa verni?");
	q2.AddOption("Predstavlqva otvoren standart", 0.5);
	q2.AddOption("Opisva metod za predavane na informaciq mejdu mrejovi ustroystva", -1);
	q2.AddOption("Preminavaneto na informaciqta mejdu sloevete samo vuzjhodqshto", -1);
	q2.AddOption("Vseki sloy se harakterizira s opredeleno predstavqne na informaciqta", 0.5);
	q2.AddOption("sustoi se ot 4ri sloq", -1);
	q2.AddOption("preminavaneto na informaciqta mejdu sloevete e samo nizhodqshto", -1);
	exam.push_back(q2);

	Question q3("Koe ot slednite e mrejovo ustroystvo?");
	q3.AddOption("server", -1);
	q3.AddOption("switch", 1);
	q3.AddOption("smartphone", -1);
	q3.AddOption("laptop", -1);
	exam.push_back(q3);

	Question q4("Kakvi polzi shte izvleche ot VLAN tehnologiqta edna golqma korporaciq?");
	q4.AddOption("VLAN-te osigurqvat metod za komunikacii mejdu IP adresi v golemi mreji", -1);
	q4.AddOption("VLAN-te pozvolqvat mrejovite uslugi da se organizirat po otdeli, a ne po fizichesko razpolojenie", 0.34);
	q4.AddOption("VLAN-te osigurqvat komunikacii s nisko zakusnenie i visoka propuskatelna sposobnost", -1);
	q4.AddOption("VLAN-te znachitelno ulesnqvat dobavqne, premestvane ili promqna na hostove v mrejata", 0.33);
	q4.AddOption("VLAN-te definirat segmentirani broadcast doman-i w mreji i komutatori", 0.33);
	q4.AddOption("VLAN-te povishavat sigurnostta chrez filtrirane na paketi", -1);
	exam.push_back(q4);

	Question q5("Kakva e celta na algoritama spanning-tree v komutiranata LAN?");
	q5.AddOption("Da predpazva ot zaciklqne na 2 sloy (switching loops) v mreji s rezervirani pytishta mejdu komutatorite", 1);
	q5.AddOption("Da predpazva ot zaciklqne na marshruti (routing loops) v mrejite", -1);
	q5.AddOption("Da upravlqva VLAN-i prez mnojestvo komutatori", -1);
	q5.AddOption("Osigurqva mehanizam za sledene na mreji v sredi s komutatori", -1);
	q5.AddOption("Da segmentira mrejata na mnojestvo koliziq domejni", -1);
	exam.push_back(q5);

	Question q6("Konfigurirate PPP na interface na router. Kakvi metodi na authentication mojete da izberete?");
	q6.AddOption("PAP", 0.5);
	q6.AddOption("SSL", -1);
	q6.AddOption("SLIP", -1);
	q6.AddOption("VNP", -1);
	q6.AddOption("CHAP", 0.5);
	q6.AddOption("LAPB", -1);
	exam.push_back(q6);

	Question q7("Koy adres se izpolzva v obrabotkata na vsichki Ethernet ustroystva?");
	q7.AddOption("MAC", 1);
	q7.AddOption("DNS", -1);
	q7.AddOption("User", -1);
	q7.AddOption("Host", -1);
	q7.AddOption("VPN", -1);
	exam.push_back(q7);

	Question q8("V transportniq sloy na TCP/IP modela koi sa validnite protokoli?");
	q8.AddOption("UDP", 0.5);
	q8.AddOption("ICMP", -1);
	q8.AddOption("ARP", -1);
	q8.AddOption("BootP", -1);
	q8.AddOption("TCP", 0.5);
	q8.AddOption("IP", -1);
	exam.push_back(q8);

	Question q9("Komunikacionniqt kanal se spodelq ot vsichki mashini v mrejata, ako mrejata e:");
	q9.AddOption("multicast", -1);
	q9.AddOption("Nikoe ot izbroenite", -1);
	q9.AddOption("broadcast", 1);
	q9.AddOption("unicast", -1);
	exam.push_back(q9);

	Question q10("Koq e maksimalnata skorost, opredelena ot IEEE 802.11n standarta za bezjichna LAN?");
	q10.AddOption("54 Mbps", -1);
	q10.AddOption("100 Mbps", -1);
	q10.AddOption("150-300 Mbps", 1);
	q10.AddOption("10 Mbps", -1);
	exam.push_back(q10);

	Question q11("Po koy adres vuv Frame Header-a se populva MAC Address tablicata v switchovete?");
	q11.AddOption("LAN", -1);
	q11.AddOption("Destination", 1);
	q11.AddOption("Source", -1);
	q11.AddOption("Host", -1);
	exam.push_back(q11);

	Question q12("Koi ot slednite tvurdeniq sa predimstva na VLAN-te?");
	q12.AddOption("Pozvolqvat logichesko grupirane na potrebitelite po funkcii", 0.34);
	q12.AddOption("Uvelichavat razmera na kolizionnite domeini", -1);
	q12.AddOption("Uvelichavat broq na broadcast domejnite kato syshtevremenno namalqvat razmera im", 0.33);
	q12.AddOption("Uvelichavat razmera na broadcast domeinite, kato syshtevremenno namalqvat broq im", -1);
	q12.AddOption("Podobrqvat sigurnostta na mrejata", -1);
	q12.AddOption("Oprostqvat administriraneto na komutatora", 0.33);
	exam.push_back(q12);

	Question q13("Komputarna mreja, koqto moje da se razprostranqva v region, durjava ili kontinent se naricha:");
	q13.AddOption("WAN", 0.5);
	q13.AddOption("VPN", 0.5);
	q13.AddOption("MAN", -1);
	q13.AddOption("LAN", -1);
	exam.push_back(q13);

	Question q14("Kakvi sa harakteristikite na portovete na komutator i most v napulno konvertirana spanning-tree mreja na 2 sloj?");
	q14.AddOption("Vsichki portove na komutator i bridge sa v sustoqni forwarding", -1);
	q14.AddOption("Vsichki portove na komutator ili bridge sa v sustoqni forwarding ili blocking", 1);
	q14.AddOption("Vsichki portove na komutator i bridge sa prisvoeni kato root, ili kato designated portove", -1);
	q14.AddOption("Vsichki portove na komutator i bridge sa v sustoqnie stand by", -1);
	q14.AddOption("Vsichki komutatoro i bridge-ove sa ili blokirani, ili v zaciklqne", -1);
	exam.push_back(q14);

	Question q15("Koe ne e podvlastno na elektro-magnitni smushteniq?");
	q15.AddOption("Category 5 STP kabel", -1);
	q15.AddOption("Debel koaksialen", -1);
	q15.AddOption("Tunuk koaksialen", -1);
	q15.AddOption("Category 5 UTP kabel", -1);
	q15.AddOption("Fiber optic kabel", 1);
	exam.push_back(q15);

	Question q16("Kakvo identificira proces, rabotesht vurhu host?");
	q16.AddOption("IPv6 address", -1);
	q16.AddOption("logicheski adres", -1);
	q16.AddOption("Nomer na port", 1);
	q16.AddOption("MAC adres", -1);
	q16.AddOption("Specifichen adres", -1);
	exam.push_back(q16);

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