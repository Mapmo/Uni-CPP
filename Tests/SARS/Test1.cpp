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
	std::cout << "Izpit po SARS\nIzgotven ot Mapmo, M. i Dakata, redakciq ot tantanita\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simuaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question r34("Koe ot slednite ne e primer za arhitekturen pohvat za postigane na nadejdnost v softuernite\nsistemi?\nIzberete edno");
	r34.AddOption("Shared Bus", 1);
	r34.AddOption("Izlishyk (redundancy)", -1);
	r34.AddOption("N-Version programming", -1);
	r34.AddOption("Heartbeat (Keepaive)", -1);
	exam.push_back(r34);

	Question r33("Arhitektirniqt stil Circuit Breaker\nIzberete Edno");
	r33.AddOption("Znachitelno podobrqva izmenqemostta na sistemata", -1);
	r33.AddOption("Podobrqva samo nadejdnostta na sistemata", 1);
	r33.AddOption("Podobrqva nadejdnostta i proizvoditelnostta na sistemata", -1);
	r33.AddOption("Namalqva znachitelno izmenqemostta na sistemata", -1);
	exam.push_back(r33);

	Question r32("Shablonyt fasada se izpolzva pri neobhodimost ot uvelichavane na byrzodeystvieto na programata");
	r32.AddOption("True", -1);
	r32.AddOption("False", 1);
	exam.push_back(r32);

	Question r31("Koe ot izbroenite ne vliqe vurhu izbora na arhitekturni taktiki\nIzberete edno");
	r31.AddOption("Bydeshti planove za razvitie na organizaciqta", -1);
	r31.AddOption("Broqt i kvalifikaciqta na nalichnite razrabotchici", -1);
	r31.AddOption("Kvalifikaciqta na manager-a na proekta", 1);
	r31.AddOption("Nalichie na legacy software", -1);
	exam.push_back(r31);

	Question r30("V stilyt neqvno izvikvane (implicit invocation) komponentite vzaimodejstvat pomejdu si chrez:\nIzberete edno");
	r30.AddOption("Izprashtane na t.nar sybitiq, pri koito izprashtashtiq komponent ne znae nishto za poluchatelq", 1);
	r30.AddOption("Izvikvane na metod, pri koeto izprashtashtiq komponent izchakva za otgovor, predi da prodylji sys svoeto izpylnenie", -1);
	r30.AddOption("Izprashtane na t.nar sybitiq, pri koito izprashtashtiq komponent ima informaciq za poluchatelq", -1);
	exam.push_back(r30);

	Question r29("Koe ot slednite tvyrdeniq e vqrno za stila kanal-filter (pipe and fileter)\nIzberete edno");
	r29.AddOption("V tozi arhitekturen stil nqma syedinitelni moduli", -1);
	r29.AddOption("Tozi stil ne se preporychva pri razrabotka na sistemi, koito obrabotvat razlichni po format danni", 1);
	r29.AddOption("Komponentite v stila kanal-filter se realizirat samo na ezika Java", -1);
	r29.AddOption("Vseki modul (komponent) v sistemata predava dannite v proizvolen red na sledvashtiq komponent", -1);
	exam.push_back(r29);

	Question r28("Kakvo predstavlqvat arhitekturnite drivers ot gledna tochka na procesa na proektirane \nIzberete edno");
	r28.AddOption("Vryzka mejdu arhitekturata na sistemata i realizaciqta i", -1);
	r28.AddOption("Sredstvo za ulesnqvane na proektiraneto na softuerna arhitektura", -1);
	r28.AddOption("Iziskvaniqta kym sistemata, koito imat nay-visok prioritet", 1);
	r28.AddOption("Nay-vajnite tehnologii, koito shte bydat izpolzvani", -1);
	exam.push_back(r28);

	Question r27("Broqt na strukturite, koito shte bydat vklucheni v dokumentaciqta na softuernata arhitektura\nzavisi ot\nIzberete edno ili poveche");
	r27.AddOption("Vidyt na zainteresovanite lica", 0.5);
	r27.AddOption("Softuertnata sistema", -1);
	r27.AddOption("Prilojnata oblast, kydeto shte se vnedrqva softuernata sistema", 0.5);
	r27.AddOption("Kodyt na sistemata", -1);
	exam.push_back(r27);

	Question r26("Koi ot slednite moje da harakterizirat nadejdnost na sistemata\nIzberete edno ili poveche");
	r26.AddOption("Procent uspeshni izvikvaniq", 0.5);
	r26.AddOption("Veroqtnost za otkaz", 0.5);
	r26.AddOption("Latentnost", -1);
	r26.AddOption("Vreme za izpylnenie", -1);
	exam.push_back(r26);

	Question r25("Koe ot slednite tvyrdeniq ne e vqrno po otnoshenie na nefunkcionalnite iziskvaniq (NFI)\nIzberete edno");
	r25.AddOption("NFI sa chesto protivorechivi i se nalaga da se pravqt kompromisi mejdu tqh", -1);
	r25.AddOption("NFI si vliqqt s iziskvaniqta po funkcionalnostta na sistemata", -1);
	r25.AddOption("NFI trqbva da se balansirat sprqmo interesite na zainteresovanite lica", -1);
	r25.AddOption("NFI ne sa opredelqshti za dekompoziciqta na modulite na sistemata", 1);
	exam.push_back(r25);

	Question r24("Spored vas primer za dobre napravena dekompoziciq na modulite li e pokazanata diagrama\n(3 modula computation, communication, processing)\nIzberete edno");
	r24.AddOption("True", -1);
	r24.AddOption("False", 1);
	exam.push_back(r24);

	Question r23("Sigurnost i otkazoustoichivost (fault tolerance) sa dve nefunkcionalni harakteristiki,\nkoito chesto si protivorechat\nIzberete edno");
	r23.AddOption("True", 1);
	r23.AddOption("False", -1);
	exam.push_back(r23);

	Question r22("Sofuernata arhitektura ne e\nIzberete edno");
	r22.AddOption("Abstraktno opisanie na sistemata ot razlichnite gledni tochki, koeto zasqga minimalen broy ot zainteresovanite lica", 1);
	r22.AddOption("Dokument, v koyto lipsvat podrobnosti za koda na sistemata", -1);
	r22.AddOption("Model na upravlenieto na procesite v sistemata", -1);
	r22.AddOption("Syvkupnost ot predstavqne na sistemata ot razlichni gledni tochki", -1);
	exam.push_back(r22);

	Question r21("V stila client-server komponentite vzaimodeystvat pomejdu si chrez izprashtane na\nsyobshteniq(ili izvikvane na metod) pri koeto izprashtashtiq komponent ne znae nishto za poluchatelq?\nIzberete edno");
	r21.AddOption("True", 1);
	r21.AddOption("False", -1);
	exam.push_back(r21);

	Question r20("Koe ot slednite tvyrdeniq e nevqrno\nIzberete edno");
	r20.AddOption("Pri mnogosloyniq arhitekturen stil interface opredelqt protokol za vzaimodeystvie mejdu nivata", -1);
	r20.AddOption("Za da se priloji mnogosloyniq arhitekturen stil se iziskva specializiran hardware", 1);
	r20.AddOption("Mrejoviqt model na OSI e proektiran spored principite na mnogosloyniq arhitekturen stil", -1);
	r20.AddOption("Pri mnogosloyniq arhitekturen stil, vsqko nivo predostavq interface na nivoto pod nego\ni izpolzva interface na nivoto tochno nad nego", -1);
	exam.push_back(r20);

	Question r19("V arhitekturniq stil shared-data:\nIzberete edno");
	r19.AddOption("Nito edin ot posochenite otgovori ne e veren", -1);
	r19.AddOption("Lesno se realizira paraleno izlyplenie na procesite, koito obrabotvat dannite", -1);
	r19.AddOption("Vsichki uchastvashti komponenti imat vyzmojnost za dostyp do spodeleni danni", 1);
	r19.AddOption("Dannite se izprashtat ednovremenno do vsichki uchastvashti komponenti", -1);
	exam.push_back(r19);

	Question r18("Moje li da se tvyrdi sys sigurnost, che izpolzvaneto na replikaciq na sistemata\nili chasti ot neq, s cel usigurqvane na nadejdnost, vliqe otricatelno na sigurnostta\nIzberete edno");
	r18.AddOption("Da", -1);
	r18.AddOption("Ne", -1);
	r18.AddOption("Zavisi", 1);
	exam.push_back(r18);

	Question r17("Spored definiciqta softuernata arhitektura predstavlqva nabor ot strukturi.\nV tazi vryzka moje li da se kaje, che dekompoziciqta na moduli e arhitektura na sistemata\nIzberete edno");
	r17.AddOption("True", -1);
	r17.AddOption("False", 1);
	exam.push_back(r17);

	Question r16("Dokumentaciqta na softuernata arhitektura:\nIzberete edno ili poveche");
	r16.AddOption("Vkluchva kolkoto e vyzmojno poveche strukturi", -1);
	r16.AddOption("Vkluchva kolkoto e vyzmojno po-malko strukturi", -1);
	r16.AddOption("Vkluchva opredeleni strukturi, v zavisimost ot samata sistema i tova koy shte chete dokumentaciqta", 0.5);
	r16.AddOption("Vkluchva opisanie na strukturite na arhitekturata plus pridrujavashti dokumenti", 0.5);
	exam.push_back(r16);

	Question q1("Koi ot slednite sa primer sa dobre formuliran scenarii za kachestvo?\nIzberete edno 1 ili poveche");
	q1.AddOption("Dopustimo e sistemata da e v rejim na poddrujka za ne poveche ot 3 chasa sedmichno", 0.5);
	q1.AddOption("Potrebitelqt vliza v sistemata, izbira opciqta za tursene I vuvejda operedelen simvolen niz", -1);
	q1.AddOption("Promeni v sistemata da se pravqt vyzmovno nai-byrzo", -1);
	q1.AddOption("Otgovoryt na potrebitelskite zaqvki trqbva da stane do 30 sec", 0.5);
	exam.push_back(q1);

	Question q2("Smisulut na nefukcionalnite iziskvaniq kum sistemata e\nIzberete edno");
	q2.AddOption("Da se ulesni razrabotkata na sistemata", -1);
	q2.AddOption("Da se izpolzvat nai-suvremennite tehnologii I programni ezici", -1);
	q2.AddOption("Da se namali cenata na razrabotka na softuerna sistema", -1);
	q2.AddOption("Da se ytochni po kakuv nachin I pri kakvi ysloviq shte raboti sistemata", 1);
	exam.push_back(q2);

	Question q3("V 4+1 modela na softuerna arhitektyra izgledut na procesi pokazva kak\nsistemata se dokompozira na sustavni softuerni elementi(modyli)");
	q3.AddOption("Istina", -1);
	q3.AddOption("Luja", 1);
	exam.push_back(q3);

	Question q4("Pod proizvoditelnost v softuernite sistemi se rabira\nIzberete edno");
	q4.AddOption("Vuzmojnost na sistemata da osiguri rabota bez otkaz", -1);
	q4.AddOption("Vremeto, za koeto sistemata reagira na vuznikvashti subitiq", 1);
	q4.AddOption("Mqrka za sebestoinostta na promenite v sistemata", -1);
	q4.AddOption("Vuzmojnost na potrebitql burzo da ovladee sistemata", -1);
	exam.push_back(q4);

	Question q5("V koi ot slednite redove e dopusnata greshka?\nIzberete edno");
	q5.AddOption("Vuzdeistvie, algorithm, iztochnik sa elementi na scenarii na kachestvo", 1);
	q5.AddOption("Vuzdeistvie, kolichestveni parametri, kontekst sa elementi na scenarii na kachestvo", -1);
	q5.AddOption("Vuzdeistvie, rezultat, iztochnik sa elementi na scenarii na kachestvo", -1);
	q5.AddOption("Vuzdeistvie, obekt, iztochnik sa elementi na scenarii na kachestvo", -1);
	exam.push_back(q5);

	Question q6("Proektiraneto na softuerna arhitektura e iterativen proces");
	q6.AddOption("True", 1);
	q6.AddOption("False", -1);
	exam.push_back(q6);

	Question q7("Cost Benefit Analysis Method(CBAM) e proces pri koito:\nIzberete edno");
	q7.AddOption("se opredelqt nai-vajnite iziskvaniq kum dokymentaciqta na arhitekturata", -1);
	q7.AddOption("nito edno ot izbroenite ne e vqrno", 1);
	q7.AddOption("se ocenqva proizvoditelnostta na sistemata", -1);
	q7.AddOption("se proverqva dali proektiranta veche architektura udovletvorqva postavenite iziskvaniq", -1);
	exam.push_back(q7);

	Question q8("Pri kakuv tip sistemi e nai-podhodqshto da se izpolzva stryktyrata na vnedrqvaneto\nIzberete edno");
	q8.AddOption("Koito se izpylnqvat na edna mashina", -1);
	q8.AddOption("Sistemi s mnogo potrebiteli", -1);
	q8.AddOption("Nito edin ot posochenite", 1);
	q8.AddOption("Koito se izpulnqvat v cloud", -1);
	exam.push_back(q8);

	Question q9("Architektyrniq stil predstavlqva\nIzberete edno");
	q9.AddOption("Obektno oprientiran model na softuernata sistema", -1);
	q9.AddOption("Opisanie na softuernata arhitektura", -1);
	q9.AddOption("Tipovo arhitekturno reshenie, koeto se dokazalo pri upotreba v konkretni sityacii", 1);
	q9.AddOption("Model za prehod ot softuerna arhitektyra kym kod", -1);
	exam.push_back(q9);

	Question q10("Pri proektiraneto na arhitektyrata moje da se ogranichi borq na modyli,\ns koito daden komponent komunikira, za da se:\nIzberete edno");
	q10.AddOption("ogranichi neobhodimostta ot promeni s drugi moduli, s koito dadeniqt komunikira", 1);
	q10.AddOption("namali slovnostta na sistemata I da se yskori procesa na razrabotka", -1);
	q10.AddOption("napravi arhitekturata po-qsna i da se razbira ot vsichki zainteresovani lica", -1);
	q10.AddOption("ne se prilaga takava taktika", -1);
	exam.push_back(q10);

	Question q11("Stuktura na procesite:");
	q11.AddOption("Posochva zadyljeniqta na otdelnite zainteresovani lica", -1);
	q11.AddOption("Pokazwa posledovatelnostta na izpulnenie na otdelnite komponenti v sistemata", 1);
	q11.AddOption("E izgotven ot manager-a na proekta dokument, koito naznachava zadachite\nna ostanlite uchastnici v razrabotkata na proekta", -1);
	q11.AddOption("Pokazva abstraktni grupi ot hora, koito realizirat modulite na sistemata", -1);
	exam.push_back(q11);

	Question q12("Koe ot slednite ne e vqrno za arhitektyren stil Pipe-Filter:\nIzberete edno");
	q12.AddOption("Ima trudnosti pri realizaciqta na interaktivni prilojeniq", -1);
	q12.AddOption("Wodi do prosti za proektirane I realizaciq arhitekturi", -1);
	q12.AddOption("Nqma vyzmojnost za paralelna obrabotka na informaciqta", 1);
	q12.AddOption("Strukturata mu e identichna sys strukturata na powecheto standartni biznes procesi w organizaciite", -1);
	exam.push_back(q12);

	Question q13("V softuernata arhitektura e redno da se opiswat swoistwa I metodi na klasowete,\nkoito izgrajdat obektite w sistemata");
	q13.AddOption("True", -1);
	q13.AddOption("False", 1);
	exam.push_back(q13);

	Question q14("V koi ot slednite deynosti e redno da vzimat uchastie softuernite arhitekti?\nIzberete edno ili poveche");
	q14.AddOption("Opredelqne na algoritmite za razabotka na sistemata", -1);
	q14.AddOption("Razrabotka na sistemata", 0.25);
	q14.AddOption("Utochnqvane na iziskvaniqta kym softuernata sistema", 0.25);
	q14.AddOption("Proektirane na arhitekturata", 0.25);
	q14.AddOption("Izgotvqne na biznes plan na proekta", 0.25);
	exam.push_back(q14);

	/*
	Question r1("\nIzberete edno");
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	r1.AddOption("", -1);
	exam.push_back(r1);
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
