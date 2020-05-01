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

	Question q1("How can AWS services be accessed?\nchoose 1 or more");
	q1.AddOption("API access ", 0.5);
	q1.AddOption("Amazon Prime Account", -1);
	q1.AddOption("AWS Management Console", 0.5);
	q1.AddOption("AWS Datacenter", -1);
	q1.AddOption("AWS Datacenter", -1);
	
	Question q2("The AWS cloud is a?");
	q2.AddOption("Hybrid cloud ", -1);
	q2.AddOption("Public Cloud", 1);
	q2.AddOption("Private CLoud", -1);
	q2.AddOption("Personal Cloud", -1);
	
	Question q3("What replaced the traditional client-server architecture?");
	q3.AddOption("Typewriter", -1);
	q3.AddOption("CPU", -1);
	q3.AddOption("The Cloud ", 1);
	q3.AddOption("Database", -1);
	
	Question q4("What type of cloud is used by traditional on-premise methods?");
	q4.AddOption("Public cloud", -1);
	q4.AddOption("Hybrid cloud", -1);
	q4.AddOption("Personal cloud", -1);
	q4.AddOption("Private cloud ", 1);
	
	Question q5("What type of service(s) does AWS provide? Please select the most appropriate answer.");
	q5.AddOption("SaaS", -1);
	q5.AddOption("IaaS", -1);
	q5.AddOption("AWS offers all of these types of services ", 1);
	q5.AddOption("PaaS", -1);
	
	Question q6("Which of the following is an example of a SaaS?");
	q6.AddOption("All of the infrastructure, operating systems, and software without help from a third party.", -1);
	q6.AddOption("All of or most of an infrastructure platform being provided by a third party.", -1);
	q6.AddOption("All of the infrastructure and operating systems is provided by a third party.", -1);
	q6.AddOption("All of the infrastructure, operating system and software are provided by a third party. ", 1);
	
	Question q7("Which of the following was not a business challenge before the cloud?");
	q7.AddOption("Differing security protocols for a distributed workforce.", -1);
	q7.AddOption("Cost Control of an on-premise datacenter", -1);
	q7.AddOption("Slow Provisioning of on-premise data centers.", -1);
	q7.AddOption("Fully-customizable infrastructure with on-premise data centers. ", 1);
	
	Question q8("Which of these is descriptive of an Availability Zone?");
	q8.AddOption("The physical building containing the physical hardware of AWS infrastructure", -1);
	q8.AddOption("An Availability Zone is an Edge location ", -1);
	q8.AddOption("An Availability Zone is a Point of Presence", -1);
	q8.AddOption("An Availability Zone is an area containing datacenters in which AWS resources are available", 1);
	
	Question q9("Which of these is not a general category of AWS services?");
	q9.AddOption("Storage", -1);
	q9.AddOption("Compute", -1);
	q9.AddOption("Internet", -1);
	q9.AddOption("Database", -1);
	
	Question q10("Which of these types of a cloud is an example of using on-premises data centers in combination with AWS?");
	q10.AddOption("Hybrid Cloud", 1);
	q10.AddOption("Public Cloud", -1);
	q10.AddOption("Personal Cloud", -1);
	q10.AddOption("Private Cloud", -1);

	Question q11("You are getting a network timeout when trying to SSH into your EC2 instance?");
	q11.AddOption("your security groups are misconfigured", -1);
	q11.AddOption("the linux instance is misconfigured ", -1);
	q11.AddOption("your key is missing permissions", 1);
	
	Question q12("Availability Zones are?");
	q12.AddOption("IN ISOLATED DATA CENTERS ", 1);
	q12.AddOption(" ALL TOGETHER IN ONE DATA CENTER", -1);
	
	Question q13("You are getting a permission error exception when trying to SSH into your Linux Instance");
	q13.AddOption("The security group is misconfigured", -1);
	q13.AddOption("The Linux instance is misconfigured", -1);
	q13.AddOption("The key is missing permissions chmod 0400", 1);
	
	Question q14("Security groups can reference all of the following except:");
	q14.AddOption("IP address", -1);
	q14.AddOption("CIDR block", -1);
	q14.AddOption("Security Group", 1);
	q14.AddOption("DNS name", -1);
	
	Question q15("You should share your IAM credentials with colleagues if they quickly need access to help you?");
	q15.AddOption("NO", 1);
	q15.AddOption("YES", -1);
	
	Question q16("An IAM user can belong to multiple groups?");
	q16.AddOption("TRUE", -1);
	q16.AddOption("FALSE", -1);
	
	Question q17("IAM Users are defined on a per-region basis?");
	q17.AddOption("TRUE", -1);
	q17.AddOption("FALSE", 1);
	
	Question q18("You are getting started with AWS and your manager wants things to remain simple yet secure. He wants management of engineers to be easy, and not re-invent the wheel every time someone joins your company. What will you do?");
	q18.AddOption("Create multiple IAM users and assign each user their own policy", -1);
	q18.AddOption("Create multiple IAM users and groups and assign policies to groups. New users will be added to groups", 1);
	q18.AddOption("Create one IAM user and everyone will share the credentials", -1);
	
	Question q19("You pay for an EC2 instance compute component?");
	q19.AddOption(" if it's \"running\" and \"stopped\" state ", -1);
	q19.AddOption(" Only when it's in \"running\" state", 1);
	
	Question q20("You want to provide startup instructions to your EC2 instances, you should be using?");
	q20.AddOption("EC2 Startup Data", -1);
	q20.AddOption("EC2 Meta Data", -1);
	q20.AddOption("EC2 User Data", -1);
	
	Question q21("All of these are IAM components except...");
	q21.AddOption("Policies", -1);
	q21.AddOption("Roles", -1);
	q21.AddOption("Organizations", 1);
	q21.AddOption("Users", -1);
	q21.AddOption("Groups", -1);
	
	Question q22("Ap-northeast-1a is a…");
	q22.AddOption("Region", -1);
	q22.AddOption("Availability Zone", 1);
	
	Question q23("When a security group is created, what is the default behavior??");
	q23.AddOption("Deny all traffic inbound and deny all traffic outbound", -1);
	q23.AddOption("Allow all traffic inbound and allow all traffic outbound", -1);
	q23.AddOption("Deny all traffic inbound and allow all traffic outbound", 1);
	q23.AddOption("Allow all traffic inbound and deny all traffic outbound ", -1);
	
	Question q24("Which of the following are found in an IAM policy? (Choose 2 answers)");
	q24.AddOption("Access Key", -1);
	q24.AddOption("Password", -1);
	q24.AddOption("Effect", 0.5);
	q24.AddOption("Action", 0.5);
	
	Question q25("Which of the following are benefits of using Amazon EC2 roles? (Choose 2 answers)?");
	q25.AddOption("Integration with Active Directory is automatic.", -1);
	q25.AddOption("Key rotation is not necessary.", 0.5);
	q25.AddOption("Credentials do not need to be stored on the Amazon EC2 instance.", 0.5);
	q25.AddOption("No policies are required.", -1);
	
	Question q26("What is the format of an IAM policy?");
	q26.AddOption("XML", -1);
	q26.AddOption("JSON", -1);
	q26.AddOption("Tab-delimited text", -1);
	q26.AddOption("Key/value pairs", -1);
	
	Question q27("Which of the following methods will allow an application using an AWS SDK to be authenticated as a principal to access AWS Cloud services? (Choose 2 answers)");
	q27.AddOption("Make all the API calls over an SSL connection", -1);
	q27.AddOption("Create an IAM user and store the user name and password for the user in the application’s configuration.", 0.5);
	q27.AddOption("Create an IAM user and store both parts of the access key for the user in the application’s configuration.", -1);
	q27.AddOption("Run the application on an Amazon EC2 instance with an assigned IAM role.", 0.5);
	
	Question q28("Which of the following are based on temporary security tokens? (Choose 2 answers)");
	q28.AddOption("Amazon EC2 roles ", 0.5);
	q28.AddOption("Federation", 0.5);
	q28.AddOption("MFA", -1);
	q28.AddOption("Root user ", -1);
	
	Question q29("Which of the following actions can be authorized by IAM? (Choose 2 answers)");
	q29.AddOption("Querying an Oracle database", -1);
	q29.AddOption("Adding a message to an Amazon Simple Queue Service (Amazon SQS) queue", 0.5);
	q29.AddOption("Launching an Amazon Linux EC2 instance", 0.5);
	q29.AddOption("Installing ASP.NET on a Windows Server", -1);
	
	Question q30("Which of the following are IAM security features? (Choose 2 answers)");
	q30.AddOption("Consolidated Billing", -1);
	q30.AddOption("MFA", 0.5);
	q30.AddOption("Amazon DynamoDB global secondary indexes", -1);
	q30.AddOption("Password policies", 0.5);
	
	Question q31("You built and published an AMI in the ap-southeast-2 region, and your colleague in us-east-1 region cannot see it?");
	q31.AddOption("An AMI created for a region can only be seen in that region ", 1);
	q31.AddOption("You need to share the AMI with them explicitly", -1);
	q31.AddOption("Their AMI permissions are wrong", -1);
	
	Question q32("You would like to make sure your EC2 instances have the highest performance while talking to each other as you're performing big data analysis. Which placement group should you choose?");
	q32.AddOption("Cluster ", 1);
	q32.AddOption("Spread", -1);
	
	Question q33("You are running a critical workload of three hours per week, on Monday. As a solutions architect, which EC2 Instance Launch Type should you choose to maximize the cost savings while ensuring the application stability?");
	q33.AddOption("Spot Instances", -1);
	q33.AddOption("Scheduled Reserved Instances", -1);
	q33.AddOption("On-Demand Instances", -1);
	q33.AddOption("Reserved Instances", 1);
	
	Question q34("You would like to deploy a database technology and the vendor license bills you based on the physical cores and underlying network socket visibility. Which EC2 launch modes allows you to get visibility into them?");
	q34.AddOption("Reserved Instance", -1);
	q34.AddOption("Dedicated Host", 1);
	q34.AddOption("Spot Instance", -1);
	q34.AddOption("On-Demand", -1);
	
	Question q35("You are launching an application on EC2 and the whole process of installing the application takes about 30 minutes. You would like to minimize the total time for your instance to boot up and be operational to serve traffic. What do you recommend?");
	q35.AddOption("Provision an R4.xlarge instance type ", -1);
	q35.AddOption("Create an AMI after installing the application and launch from the AMI ", 1);
	q35.AddOption("Install the application using EC2 User Data", -1);
	q35.AddOption("Use the EC2 Cluster Placement Group", -1);
	
	Question q36("?");
	q36.AddOption("", -1);
	q36.AddOption("", -1);
	q36.AddOption("", -1);
	q36.AddOption("", -1);
	
	Question q37("?");
	q37.AddOption("", -1);
	q37.AddOption("", -1);
	q37.AddOption("", -1);
	q37.AddOption("", -1);
	
	Question q38("?");
	q38.AddOption("", -1);
	q38.AddOption("", -1);
	q38.AddOption("", -1);
	q38.AddOption("", -1);
	
	Question q39("?");
	q39.AddOption("", -1);
	q39.AddOption("", -1);
	q39.AddOption("", -1);
	q39.AddOption("", -1);
	
	Question q40("?");
	q40.AddOption("", -1);
	q40.AddOption("", -1);
	q40.AddOption("", -1);
	q40.AddOption("", -1);
	
	Question q41("?");
	q41.AddOption("", -1);
	q41.AddOption("", -1);
	q41.AddOption("", -1);
	q41.AddOption("", -1);
	
	Question q42("?");
	q42.AddOption("", -1);
	q42.AddOption("", -1);
	q42.AddOption("", -1);
	q42.AddOption("", -1);
	
	Question q43("?");
	q43.AddOption("", -1);
	q43.AddOption("", -1);
	q43.AddOption("", -1);
	q43.AddOption("", -1);
	
	Question q44("?");
	q44.AddOption("", -1);
	q44.AddOption("", -1);
	q44.AddOption("", -1);
	q44.AddOption("", -1);
	
	Question q45("?");
	q45.AddOption("", -1);
	q45.AddOption("", -1);
	q45.AddOption("", -1);
	q45.AddOption("", -1);
	
	Question q46("?");
	q46.AddOption("", -1);
	q46.AddOption("", -1);
	q46.AddOption("", -1);
	q46.AddOption("", -1);
	
	Question q47("?");
	q47.AddOption("", -1);
	q47.AddOption("", -1);
	q47.AddOption("", -1);
	q47.AddOption("", -1);
	
	Question q48("?");
	q48.AddOption("", -1);
	q48.AddOption("", -1);
	q48.AddOption("", -1);
	q48.AddOption("", -1);
	
	Question q49("?");
	q49.AddOption("", -1);
	q49.AddOption("", -1);
	q49.AddOption("", -1);
	q49.AddOption("", -1);
	
	Question q50("?");
	q50.AddOption("", -1);
	q50.AddOption("", -1);
	q50.AddOption("", -1);
	q50.AddOption("", -1);
	
	Question q51("?");
	q51.AddOption("", -1);
	q51.AddOption("", -1);
	q51.AddOption("", -1);
	q51.AddOption("", -1);
	
	Question q52("?");
	q52.AddOption("", -1);
	q52.AddOption("", -1);
	q52.AddOption("", -1);
	q52.AddOption("", -1);
	
	Question q53("?");
	q53.AddOption("", -1);
	q53.AddOption("", -1);
	q53.AddOption("", -1);
	q53.AddOption("", -1);
	
	Question q54("?");
	q54.AddOption("", -1);
	q54.AddOption("", -1);
	q54.AddOption("", -1);
	q54.AddOption("", -1);
	
	Question q55("?");
	q55.AddOption("", -1);
	q55.AddOption("", -1);
	q55.AddOption("", -1);
	q55.AddOption("", -1);
	
	Question q56("?");
	q56.AddOption("", -1);
	q56.AddOption("", -1);
	q56.AddOption("", -1);
	q56.AddOption("", -1);
	
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
