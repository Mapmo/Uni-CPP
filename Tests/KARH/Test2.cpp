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
	std::cout << "Test 2 po KARH\nIzgotven ot Mapmo, Dakata, Ikbal i M.\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Kakva e celta na izpolzvaneto na CMOVZ?");
	q1.AddOption("Reducirane na uuslovnite prehodi", 1);
	q1.AddOption("Spestqvane na pamet", -1);
	q1.AddOption("Izbqgvane na logicheska greshka", -1);
	q1.AddOption("Predotvratqvane na mehuri v konveyera", -1);
	exam.push_back(q1);

	Question q2("Koi ot izbroenite abreviaturi sa imena na shini?");
	q2.AddOption("USB, CAN, I2C", 1);
	q2.AddOption("LPT, PWM, I2C", -1);
	q2.AddOption("Com-port, PCA, PWM", -1);
	q2.AddOption("PCA, ISA, RJ11", -1);
	exam.push_back(q2);

	Question q3("Koi ot posochenite komponenti osushtestvqva vruzka s vutreshna shina?");
	q3.AddOption("USB", -1);
	q3.AddOption("LPT", -1);
	q3.AddOption("Com-port", -1);
	q3.AddOption("PCI", 0.5);
	q3.AddOption("ISA", 0.5);
	q3.AddOption("Ethernet", -1);
	exam.push_back(q3);

	Question q4("Koi ot posochenite komponenti osushtestvqva vruzka s vunshna shina?");
	q4.AddOption("USB", 0.25);
	q4.AddOption("LPT", 0.25);
	q4.AddOption("Com-port", 0.25);
	q4.AddOption("PCI", -1);
	q4.AddOption("ISA", -1);
	q4.AddOption("Ethernet", 0.25);
	exam.push_back(q4);

	Question q5("Kak se sluchvat vav vremeto REQ i GNT?");
	q5.AddOption("Poluchava se GNT, a sled tova REQ", -5);
	q5.AddOption("Poluchava se REQ, sled koeto GNT", 1);
	q5.AddOption("Sled poluchavane na REQ, vednaga se generiran GNT", -1);
	q5.AddOption("Sled poluchavane na GNT, vednaga se generira REQ", -5);
	exam.push_back(q5);

	Question q6("Mejdu T3 i T4 koy ustanovqva signalite za danni na shinata za purvata chast na kartinkata?\nIMG not found");
	q6.AddOption("Master", -1);
	q6.AddOption("Slave", 1);
	exam.push_back(q6);
	
	Question q7("Mejdu T3 i T4 koy ustanovqva signalite za danni na shinata za vtorata chast na kartinkata?\nIMG not found");
	q7.AddOption("Master", 1);
	q7.AddOption("Slave", -1);
	exam.push_back(q7);

	Question q8("Zashto ima po edna strelka vuv vsqka posoka?");
	q8.AddOption("Zashtoto sa diferencialni dvoyki", -1);
	q8.AddOption("Zashtoto ne stiga chestotnata liniq", -1);
	q8.AddOption("Za postigane na po-visoki skorosti", -1);
	q8.AddOption("Vsichki sa verni", 1);
	exam.push_back(q8);

	Question q9("Kakvo oznachava CRC?");
	q9.AddOption("Cyclic Redundancy Check", 1);
	q9.AddOption("Complete Register Content", -1);
	q9.AddOption("Connection Regulating Chip", -1);
	q9.AddOption("Create Read Clear", -1);
	exam.push_back(q9);

	Question q10("Koq shina ima posoka ot uC HOST kum Ethernet?\nImg not found");
	q10.AddOption("TXD", 1);
	q10.AddOption("RXD", -1);
	exam.push_back(q10);

	Question q11("Koq shina ima posoka ot Ethernet kum ucHost?\nImg not found");
	q11.AddOption("TXD", -1);
	q11.AddOption("RXD", 1);
	exam.push_back(q11);

	Question q12("Kakvo e DMA?");
	q12.AddOption("Direct Memory Access", 1);
	q12.AddOption("Digital Machine Accumulator", -1);
	q12.AddOption("Digital Memory Access", -1);
	q12.AddOption("Detector of Masked Attacks", -1);
	exam.push_back(q12);

	Question q13("Kolko provodna e USB3 shinata?");
	q13.AddOption("9", 1);
	q13.AddOption("3", -1);
	q13.AddOption("6", -1);
	q13.AddOption("1", -1);
	exam.push_back(q13);

	Question q14("Kolko provodna e USB2 shinata?");
	q14.AddOption("4", 1);
	q14.AddOption("2", -1);
	q14.AddOption("8", -1);
	q14.AddOption("1", -1);
	exam.push_back(q14);

	Question q15("Zashto D+ i D- sa usukani?");
	q15.AddOption("Za povishavane na skorostta", -1);
	q15.AddOption("Za po-golqma zdravina", -1);
	q15.AddOption("Za po-dobra guvkavost na kabela", -1);
	q15.AddOption("Za shumoustoychivost", 1);
	exam.push_back(q15);

	Question q16("Kakvo e SOF?");
	q16.AddOption("Start of Frame", 1);
	q16.AddOption("Superior orbital fissure", -100);
	q16.AddOption("Sequence of Files", -1);
	q16.AddOption("Single Offset Flag", -1);
	exam.push_back(q16);

	Question q17("Koy freim e za chetene?");
	q17.AddOption("Purvi", 1);
	q17.AddOption("Vtori", -1);
	q17.AddOption("Treti", -1);
	q17.AddOption("Chetvrti", -1);
	exam.push_back(q17);

	Question q18("Koy freim e za pisane?");
	q18.AddOption("Purvi", -1);
	q18.AddOption("Vtori", -1);
	q18.AddOption("Treti", 1);
	q18.AddOption("Chetvrti", -1);
	exam.push_back(q18);

	Question q19("Za kakvo slujat rezistorite?");
	q19.AddOption("Za suzdavane na elektrichesko suprotivlenie", 1);
	q19.AddOption("Za po-burza vruzka s pametta", -1);
	q19.AddOption("Za zashtita ot udari", -1);
	q19.AddOption("Za uskorqvane na vruzkata mejdu shinite i procesora", -1);
	exam.push_back(q19);

	Question q20("Kakvo e prednaznachenieto na predicate?");
	q20.AddOption("Da opishe daden proces", 1);
	q20.AddOption("Da optimizira operaciq", -1);
	q20.AddOption("Da namali latentnostta", -1);
	q20.AddOption("Da uskori rabotata s procesora", -1);
	exam.push_back(q20);

	Question q21("Ima srqzana kartinka i Rusalcho pita koe e pyrvo");
	q21.AddOption("Read", 1);
	q21.AddOption("Write", -1);
	q21.AddOption("Idle", -1);
	exam.push_back(q21);

	Question q22("Ima srqzana kartinka i Rusalcho pita koe e po sredata");
	q22.AddOption("Read", -1);
	q22.AddOption("Write", -1);
	q22.AddOption("Idle", 1);
	exam.push_back(q22);

	Question q23("Ima srqzana kartinka i Rusalcho pita koe e nakraq");
	q23.AddOption("Read", -1);
	q23.AddOption("Write", 1);
	q23.AddOption("Idle", -1);
	exam.push_back(q23);

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