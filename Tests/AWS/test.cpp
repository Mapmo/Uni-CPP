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
	q9.AddOption("Internet", 1);
	q9.AddOption("Database", -1);
	
	Question q10("Which of these types of a cloud is an example of using on-premises data centers in combination with AWS?");
	q10.AddOption("Hybrid Cloud", 1);
	q10.AddOption("Public Cloud", -1);
	q10.AddOption("Personal Cloud", -1);
	q10.AddOption("Private Cloud", -1);

	Question q11("You are getting a network timeout when trying to SSH into your EC2 instance?");
	q11.AddOption("your security groups are misconfigured", 1);
	q11.AddOption("the linux instance is misconfigured ", -1);
	q11.AddOption("your key is missing permissions", -1);
	
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
	q16.AddOption("TRUE", 1);
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
	q20.AddOption("EC2 User Data", 1);
	
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
	q26.AddOption("JSON", 1);
	q26.AddOption("Tab-delimited text", -1);
	q26.AddOption("Key/value pairs", -1);
	
	Question q27("Which of the following methods will allow an application using an AWS SDK to be authenticated as a principal to access AWS Cloud services? (Choose 2 answers)");
	q27.AddOption("Make all the API calls over an SSL connection", -1);
	q27.AddOption("Create an IAM user and store the user name and password for the user in the application’s configuration.", -1);
	q27.AddOption("Create an IAM user and store both parts of the access key for the user in the application’s configuration.", 0.5);
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
	
	Question q36("You are launching an EC2 instance in us-east-1 using this Python script snippet:(we will see SDK in a later section, for now just look at the code reference ImageId) ec2.create_instances(ImageId='ami-b23a5e7', MinCount=1, MaxCount=1) It works well, so you decide to deploy your script in us-west-1 as well. There, the script does not work and fails with \"ami not found\" error. What's the problem?");
	q36.AddOption("The AMI needs to first be shared to another region. The same ID can then be used.", 1);
	q36.AddOption("AMI is region locked and the same ID cannot be used across regions", -1);
	
	Question q37("You plan on running an open-source MongoDB database year-round on EC2. Which instance launch mode should you choose?");
	q37.AddOption("Reserved Instance ", 1);
	q37.AddOption("On-Demand", -1);
	q37.AddOption("Spot Instance", -1);
	
	Question q38("You would like to deploy a database technology and the vendor license bills you based on the physical cores and underlying network socket visibility. Which EC2 launch modes allows you to get visibility into them?");
	q38.AddOption("Dedicated Host", 1);
	q38.AddOption("Spot Instance", -1);
	q38.AddOption("On-Demand", -1);
	q38.AddOption("Reserved Instance", -1);
	
	Question q39("You would like to provide internet access to your instances in private subnets with IPv4, while making sure this solution requires a least amount of administration and scales seamlessly. What should you use?");
	q39.AddOption("NAT Instances with Source/Destination Check flag off", -1);
	q39.AddOption("NAT Gateway", 1);
	q39.AddOption("Egress Only Internet Gateway", -1);
	
	Question q40("Your company has created a REST API that it will sell to hundreds of customers as a SaaS. Your customers are on AWS and are using their own VPC. You would like to allow your customers to access your SaaS without going through the public internet while ensuring your infrastructure is not left exposed to network attacks. What do you recommend?");
	q40.AddOption("Create a VPC peering connection", -1);
	q40.AddOption("Create a ClassicLink", -1);
	q40.AddOption("Create a PrivateLink", 1);
	q40.AddOption("Create a VPC Endpoint", -1);
	
	Question q41("You have set-up a direct connect between your Corporate Data Center and your VPC A. You need to access VPC B in another region from your Corporate Data Center as well. What should you do?");
	q41.AddOption("Setup a NAT Gateway ", -1);
	q41.AddOption("Enable VPC Peering", -1);
	q41.AddOption("Use a Direct Connect", -1);
	q41.AddOption("Use a Direct Connect Gateway", 1);
	
	Question q42("You plan on creating a subnet and want it to have at least capacity for 28 EC2 instances. What's the minimum size you need to have for your subnet?");
	q42.AddOption("/25", -1);
	q42.AddOption("/26", 1);
	q42.AddOption("/27", -1);
	q42.AddOption("/28", -1);
	
	Question q43("Which are the only two services that have a Gateway Endpoint instead of an Interface Endpoint as a VPC endpoint?");
	q43.AddOption("Amazon S3 &amp; DynamoDB", 1);
	q43.AddOption("Amazon S3 &amp; Amazon SQS", -1);
	q43.AddOption("Amazon SQS &amp; DynamoDB", -1);
	
	Question q44("VPC Peering has been enabled between VPC A and VPC B, and the route tables have been updated for VPC A. Still, you instances cannot communicate. What is the likely issue?");
	q44.AddOption("Check the route tables in VPC B", 1);
	q44.AddOption("Check the NACL", -1);
	q44.AddOption("Check the instance security group", -1);
	q44.AddOption("Check if DNS Resolutions is enabled", -1);
	
	Question q45("You have setup an internet gateway in your VPC, but your EC2 instances still don't have access to the internet. What is NOT a possible issue?");
	q45.AddOption("The security group does not allow network in", 1);
	q45.AddOption("The NACL does not allow network traffic out ", -1);
	q45.AddOption("Route Tables are missing entries", -1);
	
	Question q46("Your company has several on-premise sites across the USA. These sites are currently linked using a private connection, but your private connection provider has been recently quite unstable, making your IT architecture partially offline. You would like to create a backup connection that will use the public internet to link your on-premise sites, that you can failover in case of issues with your provider. What do you recommend?");
	q46.AddOption("Site-to-Site VPN", -1);
	q46.AddOption("Direct Connect", -1);
	q46.AddOption("VPN CloudHub", 1);
	q46.AddOption("PrivateLink", -1);
	
	Question q47("You have a corporate network of size 10.0.0.0/8 and a satellite office of size 192.168.0.0/16. Which CIDR is acceptable for your AWS VPC if you plan on connecting your networks later on?");
	q47.AddOption("192.168.4.0/18", -1);
	q47.AddOption("172.16.0.0/16", 1);
	q47.AddOption("10.0.16.0/16", -1);
	q47.AddOption("172.16.0.0/12", -1);
	
	Question q48("What does this CIDR correspond to? 10.0.4.0/28?");
	q48.AddOption("10.0.4.0 to 10.0.4.28", -1);
	q48.AddOption("10.0.4.0 to 10.0.4.15", 1);
	q48.AddOption("10.0.0.0 to 10.0.16.0", -1);
	q48.AddOption("10.0.4.0 to 10.0.32.0", -1);

	Question q49("Which of the following is a Serverless data analysis service allowing you to query data in S3?");
	q49.AddOption("Athena", 1);
	q49.AddOption("RDS", -1);
	q49.AddOption("S3 Analytics", -1);
	q49.AddOption("Redshift", -1);
	
	Question q50("You've added files in your bucket and then enabled versioning. The files you've already added will have which version?");
	q50.AddOption("0", -1);
	q50.AddOption("null", 1);
	q50.AddOption("1", -1);
	q50.AddOption("-1", -1);
	
	Question q51("You're trying to upload a 25 GB file on S3 and it's not working");
	q51.AddOption("The S3 service must be down", -1);
	q51.AddOption("The file size limit on S3 is 5GB", -1);
	q51.AddOption("You should use Multi Part upload when your file is bigger then 5GB", 1);
	
	Question q52("You are looking to build an index of your files in S3, using Amazon RDS PostgreSQL. To build this index, it is necessary to read the first 250 bytes of each object in S3, which contains some metadata about the content of the file itself. There is over 100,000 files in your S3 bucket, amounting to 50TB of data. how can you build this index efficiently?");
	q52.AddOption("Create an application that will traverse the S3 bucket, use S3 select to get the first 250 bytes ,and store that information in RDS.", -1);
	q52.AddOption("Create an application that will traverse the S3 bucket, issue a Byte Range Fetch for the first 250 bytes, and store that information in RDS.", 1);
	q52.AddOption("Create an application that will traverse the S3 bucket, read all the files and one by one, extract the first 250 bytes, and store that information in RDS.", -1);
	q52.AddOption("Use the RDS Import feature to load the data from S3 to PostgreSQL, and run a SQL query to build the index", -1);
	
	Question q53("You would like all your files in S3 to be encrypted by default. What is the optimal way of achieving this?");
	q53.AddOption("Enable versioning", -1);
	q53.AddOption("Enable \"Default Encryption\" on S3", 1);
	q53.AddOption("Use a Bucket Policy that forces HTTPS connections", -1);
	
	Question q54("You are looking to provide temporary URLs to a growing list of federated users in order to allow them to perform a file upload on S3 to a specific location. What should you use?");
	q54.AddOption("S3 Bucket Policies", -1);
	q54.AddOption("IAM Users", -1);
	q54.AddOption("S3 Pre-Signed URL", 1);
	q54.AddOption("S3 CORS", -1);
	
	Question q55("You have a website that loads files from another S3 bucket. When you try the URL of the files directly in your Chrome browser it works, but when the website you're visiting tries to load these files it doesn't. What's the problem?");
	q55.AddOption("The IAM policy is wrong", -1);
	q55.AddOption("Encryption is wrong", -1);
	q55.AddOption("CORS is wrong", 1);
	q55.AddOption("The bucket policy must be wrong", -1);
	
	Question q56("The bucket policy allows our users to read / write files in the bucket, yet we were not able to perform a PutObject API call.");
	q56.AddOption("You need to contact AWS Support to lift this limit", -1);
	q56.AddOption("The IAM user must have an explicit DENY in the attached IAM policy", 1);
	q56.AddOption("The bucket policy must be wrong", -1);
	
	Question q57("How can you automate the transition of S3 objects between their different tiers?");
	q57.AddOption("Use AWS Lambda", 1);
	q57.AddOption("Use CloudWatch Events", -1);
	q57.AddOption("Use S3 Lifecycle Rules", -1);
	
	Question q58("Your company does not trust S3 for encryption and wants it to happen on the application. You recommend");
	q58.AddOption("SSE-S3", -1);
	q58.AddOption("Client Side Encryption", 1);
	q58.AddOption("SSE-C", -1);
	q58.AddOption("SSE-KMS", -1);
	
	Question q59("Your client wants to make sure the encryption is happening in S3, but wants to fully manage the encryption");
	q59.AddOption("Client Side Encryption", 1);
	q59.AddOption("SSE-C", -1);
	q59.AddOption("SSE-KMS", -1);
	q59.AddOption("SSE-S3", -1);
	
	Question q60("Your company wants data to be encrypted in S3, and maintain control of the rotation policy for the encryption keys, but not know the encryption keys values. You recommend");
	q60.AddOption("SSE-C", -1);
	q60.AddOption("SSE-S3", -1);
	q60.AddOption("Client Side Encryption", -1);
	q60.AddOption("SSE-KMS", 1);
	
	Question q61("Which of the following is NOT a Glacier retrieval mode?");
	q61.AddOption("Bulk (5 to 12 hours)", -1);
	q61.AddOption("Expedited (1 to 5 minutes)", -1);
	q61.AddOption("Instant (10 seconds)", 1);
	q61.AddOption("Standard (3 to 5 hours)", -1);
	
	Question q62("You have enabled versioning and want to be extra-careful when it comes to deleting files on S3. What should you enable to prevent accidental permanent deletions?");
	q62.AddOption("Enable MFA Delete", 1);
	q62.AddOption("Use a bucket policy", -1);
	q62.AddOption("Encrypt the files", -1);
	q62.AddOption("Disable versioning", -1);
	
	Question q63("You are looking for your entire S3 bucket to be available fully in a different region so you can perform data analysis optimally at the lowest possible cost. Which feature should you use?");
	q63.AddOption("CloudFront distributions", -1);
	q63.AddOption("S3 versioning", -1);
	q63.AddOption("S3 Cross Region Replication", 1);
	q63.AddOption("S3 Websites", -1);
	
	Question q64("I tried creating an S3 bucket named \"dev\" but it didn't work. This is a new AWS Account and I have no buckets at all. What is the cause?");
	q64.AddOption("I'm missing IAM permissions to create a bucket", -1);
	q64.AddOption("Bucket names must be globally unique and \"dev\" is already taken.", 1);
	
	Question q65("You suspect some of your employees to try to access files in S3 that they don't have access to. How can you verify this is indeed the case without them noticing?");
	q65.AddOption("Restrict their IAM policies and look at CloudTrail logs", -1);
	q65.AddOption("Use a bucket policy", -1);
	q65.AddOption("Enable S3 Access Logs and analyse them using Athena", 1);
	
	Question q66("The use of a cluster placement group is ideal ___");
	q66.AddOption("Your fleet of EC2 instances requires high network throughput and low latency within a single availability zone.", 1);
	q66.AddOption("Your fleet of EC2 Instances requires low latency and high network throughput across multiple availability zones.", -1);
	q66.AddOption("When you need to deploy EC2 instances that require high disk IO.", -1);
	q66.AddOption("When you need to distribute content on a CDN network.", -1);
	
	Question q67("Standard Reserved Instances can be moved between regions");
	q67.AddOption("False", -1);
	q67.AddOption("True", 1);
	
	Question q68("Is it possible to perform actions on an existing Amazon EBS Snapshot?");
	q68.AddOption("No", -1);
	q68.AddOption("It depends on the region.", -1);
	q68.AddOption("Yes, through the AWS APIs, CLI, and AWS Console.", 1);
	q68.AddOption("EBS does not have snapshot functionality.", -1);
	
	Question q69("Which EC2 feature allows you to utilize SR-IOV?");
	q69.AddOption("Enhanced Networking", 1);
	q69.AddOption("IAM Roles", -1);
	q69.AddOption("Bootstrap Scripts (User Data)", -1);
	q69.AddOption("CloudWatch Agent", -1);
	
	Question q70("What is the underlying Hypervisor for EC2?  (Possible Correct: 2)");
	q70.AddOption("ESX", -1);
	q70.AddOption("Xen", 0.5);
	q70.AddOption("OVM", -1);
	q70.AddOption("Hyper-V", -1);
	q70.AddOption("Nitro", 0.5);
	
	Question q71("You need to know both the private IP address and public IP address of your EC2 instance. You should ___ .");
	q71.AddOption("Use the following command: AWS EC2 DisplayIP.", -1);
	q71.AddOption("Retrieve the instance User Data from http://169.254.169.254/latest/user-data/.", -1);
	q71.AddOption("Retrieve the instance Metadata from http://169.254.169.254/latest/meta-data/.", 1);
	q71.AddOption("Run IPCONFIG (Windows) or IFCONFIG (Linux).", -1);
	
	Question q72("EBS Snapshots are backed up to S3 in what manner?");
	q72.AddOption("Differentially", -1);
	q72.AddOption("EBS snapshots are NOT stored on S3.", -1);
	q72.AddOption("Exponentially", -1);
	q72.AddOption("Incrementally", 1);
	
	Question q73("Spread Placement Groups can be deployed across multiple Availability Zones");
	q73.AddOption("False", -1);
	q73.AddOption("True", 1);
	
	Question q74("If an Amazon EBS volume is attached as an additional disk (not the root volume), can I detach it without stopping the instance?");
	q74.AddOption("Yes, although it may take some time.", 1);
	q74.AddOption("No, you will need to stop the instance.", -1);
	
	Question q75("What type of storage are Amazon's EBS volumes based on?");
	q75.AddOption("Database-based", -1);
	q75.AddOption("File-based", -1);
	q75.AddOption("Block-based", 1);
	q75.AddOption("Object-based", -1);
	
	Question q76("Can Spread Placement Groups be deployed across multiple Availability Zones?");
	q76.AddOption("Yes", 1);
	q76.AddOption("No", -1);
	q76.AddOption("Yes, but only using the AWS API.", -1);
	q76.AddOption("Only in Us-East-1.", -1);
	
	Question q77("Which AWS CLI command should I use to create a snapshot of an EBS volume?");
	q77.AddOption("aws ec2 create-snapshot", 1);
	q77.AddOption("aws ec2 fresh-snapshot", -1);
	q77.AddOption("aws ec2 new-snapshot", -1);
	q77.AddOption("aws ec2 deploy-snapshot", -1);
	
	Question q78("When creating a new security group, all inbound traffic is allowed by default.");
	q78.AddOption("True", -1);
	q78.AddOption("False", 1);
	
	Question q79("Which of the following provide the lowest cost EBS options? (Possible Correct: 2)");
	q79.AddOption("Cold (sc1)", 0.5);
	q79.AddOption("General Purpose (gp2)", -1);
	q79.AddOption("Throughput Optimized (st1)", 0.5);
	q79.AddOption("Provisioned IOPS (io1)", -1);
	
	Question q80("To retrieve instance metadata or user data you will need to use the following IP Address:");
	q80.AddOption("http://10.0.0.1", -1);
	q80.AddOption("http://192.168.0.254", -1);
	q80.AddOption("http://169.254.169.254", 1);
	q80.AddOption("http://127.0.0.1", -1);
	
	Question q81("When updating the policy used by an IAM Role attached to an EC2 instance, what needs to happen for the changes to take effect?");
	q81.AddOption("Reattach the IAM Role to the EC2 instance", -1);
	q81.AddOption("Nothing - It will take effect immediately", 1);
	q81.AddOption("Wait up to 15 minutes for the change to take effect", -1);
	q81.AddOption("Reboot the instance to force the change", -1);
	
	Question q82("Will an Amazon EBS root volume persist independently from the life of the terminated EC2 instance to which it was previously attached? In other words, if I terminated an EC2 instance, would that EBS root volume persist?");
	q82.AddOption("No - Unless 'Delete on Termination' is unchecked for the root volume", 1);
	q82.AddOption("No - It will always be deleted immediately on termination", -1);
	q82.AddOption("Yes - But only for certain instance types", -1);
	q82.AddOption("Yes - It will always persist until deleted manually", -1);
	
	Question q83("To help you manage your Amazon EC2 instances, you can assign your own metadata in the form of ___");
	q83.AddOption("Wildcards", -1);
	q83.AddOption("Tags", 1);
	q83.AddOption("Notes", -1);
	q83.AddOption("Certificates", -1);
	
	Question q84("When can you attach/replace an IAM role on an EC2 instance?");
	q84.AddOption("Anytime, but only if there isn't already an attached IAM Role", -1);
	q84.AddOption("Only during launch and cannot be changed once the instance is launched", -1);
	q84.AddOption("Anytime, but the instance must be stopped", -1);
	q84.AddOption("To attach an IAM role to an instance that has no role, the instance can be in the stopped or running state. To replace the IAM role on an instance that already has an attached IAM role, the instance must be in the running state.", 1);
	
	Question q85("In order to enable encryption at rest using EC2 and Elastic Block Store, you must ___");
	q85.AddOption("Configure encryption using X.509 certificates", -1);
	q85.AddOption("Mount the EBS volume in to S3 and then encrypt the bucket using a bucket policy.", -1);
	q85.AddOption("Configure encryption using the appropriate Operating Systems file system", -1);
	q85.AddOption("Configure encryption when creating the EBS volume", 1);
	
	Question q86("Where in the AWS Global Infrastructure are EC2 instance provisioned?");
	q86.AddOption("In Regions", -1);
	q86.AddOption("In Availability Zones", 1);
	q86.AddOption("Globally", -1);
	
	Question q87("Can I delete a snapshot of an EBS Volume that is used as the root device of a registered AMI?");
	q87.AddOption("No", 1);
	q87.AddOption("Only via the Command-Line.", -1);
	q87.AddOption("Only using the AWS API.", -1);
	q87.AddOption("Yes", -1);
	
	Question q88("Which service would you use to run a general Windows File Server with minimal overhead?");
	q88.AddOption("EFS", -1);
	q88.AddOption("EBS Multi Attach", -1);
	q88.AddOption("FSx for Windows", 1);
	q88.AddOption("S3", -1);
	
	Question q89("With new RDS DB instances, automated backups are enabled by default?");
	q89.AddOption("False", -1);
	q89.AddOption("True", 1);
	
	Question q90("Under what circumstances would I choose provisioned IOPS over standard storage when creating an RDS instance?");
	q90.AddOption("If this was a test Database.", -1);
	q90.AddOption("If your business was trying to save money.", -1);
	q90.AddOption("If you use online transaction processing in your production environment.", 1);
	q90.AddOption("If you have workloads that are not sensitive to latency/lag.", -1);
	
	Question q91("Which RDS database technology does NOT support IAM authentication?");
	q91.AddOption("PostgreSQL", -1);
	q91.AddOption("Oracle", 1);
	q91.AddOption("MySQL", -1);
	
	Question q92("Which of the following is not a feature of DynamoDB?");
	q92.AddOption("Data reads that are either eventually consistent or strongly consistent", -1);
	q92.AddOption("Single availability zone by default", 1);
	q92.AddOption("The ability to perform operations by using a user-defined primary key", -1);
	q92.AddOption("The primary key can either be a single-attribute or a composite", -1);
	
	Question q93("Which set of RDS database engines is currently available?");
	q93.AddOption("PostgreSQL, MariaDB, MongoDB, Aurora", -1);
	q93.AddOption("Amazon Aurora, MySQL, MariaDB, Oracle, SQL Server, and PostgreSQL", 1);
	q93.AddOption("Aurora, MySQL, SQL Server, Cassandra", -1);
	q93.AddOption("MariaDB, SQL Server, MySQL, Cassandra", -1);
	
	Question q94("If I wanted to run a database on an EC2 instance, which of the following storage options would Amazon recommend?");
	q94.AddOption("EBS", 1);
	q94.AddOption("S3", -1);
	q94.AddOption("Glacier", -1);
	q94.AddOption("RDS", -1);
	
	Question q95("Your company has a production Node.js application that is using RDS MySQL 5.6 as its data backend. A new application programmed in Java will perform some heavy analytics workload to create a dashboard, on a regular hourly basis. You want to the final solution to minimize costs and have minimal disruption on the production application, what should you do?");
	q95.AddOption("Create a Read Replica in a different AZ and run the analytics workload on the replica database", -1);
	q95.AddOption("Create a Read Replica in a different AZ and run the analytics workload on the source database", -1);
	q95.AddOption("Create a Read Replica in the same AZ and run the analytics workload on the replica database", 1);
	q95.AddOption("Enable Multi-AZ for the RDS database and run the analytics workload on the standby database", -1);
	
	Question q96("You would like to create a disaster recovery strategy for your RDS PostgreSQL database so that in case of a regional outage, a database can be quickly made available for Read and Write workload in another region. The DR database must be highly available. What do you recommend?");
	q96.AddOption("Enable Multi-Region on the main database", -1);
	q96.AddOption("Create a Read Replica in the same region and enable multi-AZ on the main database", -1);
	q96.AddOption("Create a Read Replica in a different region and enable multi-AZ on the main database", 1);
	q96.AddOption("Create a Read Replica in the same region and enable multi-AZ on the read replica", -1);
	
	Question q97("You want to ensure your Redis cluster will always be available?");
	q97.AddOption("Enable Multi AZ", 1);
	q97.AddOption("Enable Read Replicas", -1);
	
	Question q98("One analytics application is currently performing its queries against your main production database. These queries slow down the database which impacts the main user experience. What should you do to improve the situation?");
	q98.AddOption("Run the analytics queries at night", -1);
	q98.AddOption("Setup Multi AZ", -1);
	q98.AddOption("Increase the RDS instance size", -1);
	q98.AddOption("Setup a Read Replica", 1);
	
	Question q99("Which of the following AWS services is a non-relational database?");
	q99.AddOption("Redshift", -1);
	q99.AddOption("RDS", -1);
	q99.AddOption("DynamoDB", 1);
	q99.AddOption("ElastiCache", -1);
	
	Question q100("You are managing a PostgreSQL database and for security reasons, you would like to ensure users are authenticated using short-lived credentials. What do you suggest doing?");
	q100.AddOption("Use PostgreSQL for RDS and authenticate using a token obtained through the RDS service", 1);
	q100.AddOption("Install PostgreSQL on EC2 and install the pg_iam module. Authenticate using IAM username and password.", -1);
	q100.AddOption("Use PostreSQL for RDS and install the pg_iam module. Authenticate using IAM username and password.", -1);
	q100.AddOption("Use PostgreSQL for RDS and force SSL connections. Authenticate using SSL certificates that you regularly rotate.", -1);
	
	Question q101("Which of the following data formats does Amazon Athena support?");
	q101.AddOption("Apache ORC", -1);
	q101.AddOption("JSON", -1);
	q101.AddOption("Apache Parquet", 1);
	q101.AddOption("XML", -1);
	
	Question q102("Which RDS Classic (not Aurora) feature does not require us to change our SQL connection string?");
	q102.AddOption("Mutli AZ", 1);
	q102.AddOption("Read Replicas", -1);
	
	Question q103("An application is running in production, using an Aurora database as its backend. Your development team would like to run a version of the application in a scaled-down application, but still, be able to perform some heavy workload on a need-basis. Most of the time, the application will be unused. Your CIO has tasked you with helping the team while minimizing costs. What do you suggest?");
	q103.AddOption("Use an Aurora Global Database", -1);
	q103.AddOption("Run Aurora on EC2, and write a script to shut down the EC2 instance at night", -1);
	q103.AddOption("Use an RDS database instead", -1);
	q103.AddOption("Use Aurora Serverless", 1);
	
	Question q104("You are hosting a MySQL database on the root volume of an EC2 instance. The database is using a large number of IOPS, and you need to increase the number of IOPS available to it. What should you do?");
	q104.AddOption("Migrate the database to an S3 bucket", -1);
	q104.AddOption("Use CloudFront to cache the database", -1);
	q104.AddOption("Add 2 additional EBS SSD volumes and create a RAID 0 volume to host the database", 1);
	q104.AddOption("Migrate the database to Glacier", -1);
	
	Question q105("Amazon's ElastiCache uses which two engines?");
	q105.AddOption("Memcrush", -1);
	q105.AddOption("Redis &amp; Memcached", 1);
	q105.AddOption("Redis &amp; Memory", -1);
	q105.AddOption("MyISAM &amp; InnoDB", -1);
	
	Question q106("You have a requirement to use TDE (Transparent Data Encryption) on top of KMS. Which database technology does NOT support TDE on RDS?");
	q106.AddOption("PostrgreSQL", 1);
	q106.AddOption("MySQL Server", -1);
	q106.AddOption("Oracle", -1);
	
	Question q107("In RDS, what is the maximum value I can set for my backup retention period?");
	q107.AddOption("30 days", -1);
	q107.AddOption("35 days", 1);
	q107.AddOption("45 days", -1);
	q107.AddOption("15 days", -1);
	
	Question q108("Which of the following is most suitable for OLAP?");
	q108.AddOption("RDS", -1);
	q108.AddOption("ElastiCache", -1);
	q108.AddOption("Redshift", 1);
	q108.AddOption("DynamoDB", -1);
	
	Question q109("Our RDS database struggles to keep up with the demand of the users from our website. Our million users mostly read news, and we don't post news very often. Which solution is NOT adapted to this problem?");
	q109.AddOption("RDS Read Replicas", -1);
	q109.AddOption("An ElastiCache cluster", -1);
	q109.AddOption("RDS Multi AZ", 1);
	
	Question q110("Which AWS service is ideal for Business Intelligence Tools/Data Warehousing?");
	q110.AddOption("ElastiCache", -1);
	q110.AddOption("Redshift", 1);
	q110.AddOption("DynamoDB", -1);
	q110.AddOption("Elastic Beanstalk", -1);
	
	Question q111("We have setup read replicas on our RDS database, but our users are complaining that upon updating their social media posts, they do not see the update right away?");
	q111.AddOption("We should have setup multi-az instead", -1);
	q111.AddOption("Read Replicas have asynchronous replication and therefore it's likely our users will only observe eventual consistency.", 1);
	q111.AddOption("There must be a bug in our application", -1);
	
	Question q112("What happens to the I/O operations of a single-AZ RDS instance during a database snapshot or backup?");
	q112.AddOption("I/O operations to the database are sent to a Secondary instance of a Multi-AZ installation (for the duration of the snapshot.)", -1);
	q112.AddOption("I/O may be briefly suspended while the backup process initializes (typically under a few seconds), and you may experience a brief period of elevated latency.", 1);
	q112.AddOption("I/O operations will function normally", -1);
	q112.AddOption("Nothing.", -1);
	
	Question q113("Which of the following DynamoDB features are chargeable, when using a single region?");
	q113.AddOption("Read and Write Capacity", 0.5);
	q113.AddOption("The number of tables created", -1);
	q113.AddOption("Storage of Data", 0.5);
	q113.AddOption("Incoming Data Transfer", -1);
	
	Question q114("RDS Reserved instances are available for multi-AZ deployments.");
	q114.AddOption("False", -1);
	q114.AddOption("True", 1);
	
	Question q115("How can you enhance the security of your Redis cache to force users to enter a password?");
	q115.AddOption("Use Security Groups", -1);
	q115.AddOption("USE IAM Auth", -1);
	q115.AddOption("Use Redis Auth", 1);
	
	Question q116("When creating an RDS instance, you can select the Availability Zone into which you deploy it,");
	q116.AddOption("False", -1);
	q116.AddOption("True", 1);
	
	Question q117("You would like to ensure you have a database available in another region if a disaster happens to your main region. Which database do you recommend?");
	q117.AddOption("RDS Read Replicas", -1);
	q117.AddOption("Aurora Read Replicas", -1);
	q117.AddOption("RDS Multi AZ", -1);
	q117.AddOption("Aurora Global Database", 1);
	
	Question q118("You can RDP or SSH into an RDS instance to see what is going on with the operating system.");
	q118.AddOption("False", 1);
	q118.AddOption("True", -1);
	
	Question q119("How many copies of my data does RDS - Aurora store by default?");
	q119.AddOption("2", -1);
	q119.AddOption("6", 1);
	q119.AddOption("1", -1);
	q119.AddOption("3", -1);
	
	Question q120("DB security groups are used with DB instances that are not in a VPC and on the EC2-Classic platform. When you create a DB security group, you need to specify a destination port number.");
	q120.AddOption("False", 1);
	q120.AddOption("True", -1);
	
	Question q121("MySQL installations default to port number ___");
	q121.AddOption("3306", 1);
	q121.AddOption("1433", -1);
	q121.AddOption("80", -1);
	q121.AddOption("3389", -1);
	
	Question q122("AWS's NoSQL product offering is known as ___");
	q122.AddOption("DynamoDB", 1);
	q122.AddOption("MongoDB", -1);
	q122.AddOption("MySQL", -1);
	q122.AddOption("RDS", -1);
	
	Question q123("If you are using Amazon RDS Provisioned IOPS storage with a Microsoft SQL Server database engine, what is the maximum size RDS volume you can have by default?");
	q123.AddOption("32TB", -1);
	q123.AddOption("1TB", -1);
	q123.AddOption("500GB", -1);
	q123.AddOption("16TB", 1);
	q123.AddOption("6TB", -1);
	
	Question q124("My company would like to have a MySQL database internally that is going to be available even in case of a disaster in the AWS Cloud. I should setup");
	q124.AddOption("Read Replicas", -1);
	q124.AddOption("Encryption", -1);
	q124.AddOption("Multi AZ", 1);
	
	Question q125("What data transfer charge is incurred when replicating data from your primary Amazon RDS MySQL instance to your read replica?");
	q125.AddOption("There is no charge associated with this action", 1);
	q125.AddOption("The charge is double the standard data transfer charge", -1);
	q125.AddOption("The charge is the same as the standard data transfer charge", -1);
	q125.AddOption("The charge is half of the standard data transfer charge", -1);
	
	Question q126("Which AWS DB platform is most suitable for OLTP?");
	q126.AddOption("RDS", 1);
	q126.AddOption("DynamoDB", -1);
	q126.AddOption("Redshift", -1);
	q126.AddOption("ElastiCache", -1);
	
	Question q127("If you want your application to check RDS for an error, have it look for an __ code in the response from the Amazon RDS API.");
	q127.AddOption("Error", 1);
	q127.AddOption("Incorrect", -1);
	q127.AddOption("Abort", -1);
	q127.AddOption("Exit", -1);
	
	Question q128("In RDS, changes to the backup window take effect ___");
	q128.AddOption("You cannot back up in RDS", -1);
	q128.AddOption("After 30 minutes", -1);
	q128.AddOption("The next day", -1);
	q128.AddOption("Immediately", 1);
	
	Question q129("Are you permitted to conduct your own vulnerability scans on your own VPC without alerting AWS first?");
	q129.AddOption("Depends on the type of scan and the service being scanned. Some scans can be performed without alerting AWS, some require you to alert", 1);
	q129.AddOption("Yes. You can perform any scan without alerting AWS first", -1);
	q129.AddOption("No. You must always alert AWS before performing any type of vulnerability scan", -1);
	
	Question q130("What is the advantage of running your AWS VPN connection through your Direct Connect connection over using the ordinary Internet? (Two ansers)?");
	q130.AddOption("Improved security", 0.5);
	q130.AddOption("Faster performance", 0.5);
	q130.AddOption("No data transfer charges when using Direct Connect", -1);
	q130.AddOption("Can use Transit Gateway to service multiple accounts/VPCs", -1);
	
	Question q131("True or False: You can accelerate your application by adding a second Internet Gateway to your VPC");
	q131.AddOption("True", -1);
	q131.AddOption("False", 1);
	
	Question q132("Which of the following offers the largest range of internal IP addresses?");
	q132.AddOption("/20", -1);
	q132.AddOption("/24", -1);
	q132.AddOption("/28", -1);
	q132.AddOption("/16", 1);
	
	Question q133("How many internet gateways be attached to a custom VPC?");
	q133.AddOption("1", 1);
	q133.AddOption("One per Availability Zone", -1);
	q133.AddOption("2", -1);
	q133.AddOption("3", -1);
	
	Question q134("By default, instances in new subnets in a custom VPC can communicate with each other across Availability Zones?");
	q134.AddOption("True", 1);
	q134.AddOption("False", -1);
	
	Question q135("Which of the following is a chief advantage of using VPC gateway endpoints to connect your VPC to services such as S3 and DynamoDB?");
	q135.AddOption("VPC gateway endpoints are dedicated hardware devices that cannot be accessed without the correct IAM credentials.", -1);
	q135.AddOption("VPC gateway endpoints ensure traffic between your VPC and the other service does not leave the Amazon network.", 1);
	q135.AddOption("VPC gateway endpoints offer a faster path through the public internet than with a NAT instance.", -1);
	q135.AddOption("VPC gateway endpoints require public IP addresses, offering rapid connectivity from the public internet.", -1);
	
	Question q136("In a default VPC, when you launch an EC2 instance and don't specify a subnet, the EC2 instances are assigned 2 IP addresses at launch. What are they?");
	q136.AddOption("An Elastic IP Address &amp; Public IP Address", -1);
	q136.AddOption("An IPv6 Address and Elastic IP Address", -1);
	q136.AddOption("A Private IP Address &amp; Public IP Address", 1);
	q136.AddOption("A Public IP Address &amp; Secret IP Address", -1);
	
	Question q137("A VPN connection consists of which of the following components? (Two answers)");
	q137.AddOption("Virtual Private Gateway", 0.5);
	q137.AddOption("Cross Connect", -1);
	q137.AddOption("Customer Gateway", 0.5);
	q137.AddOption("Direct Connect Gateway", -1);
	
	Question q138("At which of the following levels can VPC Flow Logs be created? (Possible Correct: 3)");
	q138.AddOption("Subnet Level", 0.3);
	q138.AddOption("Account Level", -1);
	q138.AddOption("Network Access Control List Level", -1);
	q138.AddOption("Network Interface Level", 0.4);
	q138.AddOption("Security Group Level", -1);
	q138.AddOption("VPC Level", 0.3);
	
	Question q139("What is the purpose of an egress-only internet gateway? (Two answers)");
	q139.AddOption("Prevents IPv6 based internet resources to initiate a connection into a VPC", 0.5);
	q139.AddOption("Prevents IPv6 traffic from accessing the internet by utilizing security groups", -1);
	q139.AddOption("Allows VPC based IPv6 traffic to communicate to the internet", 0.5);
	q139.AddOption("Allow instances communicating over IPv4 or IPv6 to access the internet", -1);
	
	Question q140("When I create a new security group, all outbound traffic is allowed by default.");
	q140.AddOption("False", -1);
	q140.AddOption("True", 1);
	
	Question q141("Which of the following statements are NOT true of EC2 instances in a VPC?");
	q141.AddOption("It is possible to have private subnets in a VPC.", -1);
	q141.AddOption("You may have only 1 active internet gateway for your instances per VPC.", -1);
	q141.AddOption("In Amazon VPC, an EBS backed instance retains its private IP when stopped and started", -1);
	q141.AddOption("In Amazon VPC, an instance retains its public IP when stopped and started.", 1);
	
	Question q142("Which of the following options allows you to securely administer an EC2 instance located in a private subnet?");
	q142.AddOption("Bastion Host", 1);
	q142.AddOption("NAT Instance", -1);
	q142.AddOption("NAT Gateway", -1);
	q142.AddOption("Internet Gateway", -1);
	
	Question q143("Which of the following are true for security groups? (3 answers)");
	q143.AddOption("Security groups evaluate all rules before deciding whether to allow traffic.", 0.3);
	q143.AddOption("Security groups support \"allow\" rules only", -1);
	q143.AddOption("Security groups operate at the instance level", 0.3);
	q143.AddOption("Security groups operate at the subnet level", -1);
	q143.AddOption("Security groups process rules in number order when deciding whether to allow traffic", 0.4);
	q143.AddOption("Security groups support both \"allow\" and \"deny\" rules", -1);
	
	Question q144("To save administration headaches, a consultant advises that you leave all security groups in web-facing subnets open on port 22 to 0.0.0.0/0 CIDR. That way, you can connect wherever you are in the world. Is this a good security design?");
	q144.AddOption("True", -1);
	q144.AddOption("False", 1);
	
	Question q145("What is the name given to an isolated unit with its own set of physical infrastructure which is used to provide global accelerator services?");
	q145.AddOption("Availability Zone", -1);
	q145.AddOption("Network Zone", 1);
	q145.AddOption("Network Segment", -1);
	q145.AddOption("Accelerator Zone", -1);
	
	Question q146("When peering VPCs, you may peer your VPC only with another VPC in your same AWS account.");
	q146.AddOption("False", 1);
	q146.AddOption("True", -1);
	
	Question q147("Which of these is NOT a component of the AWS Global Accelerator service?");
	q147.AddOption("Static IP Address", -1);
	q147.AddOption("Listeners", -1);
	q147.AddOption("Endpoint Groups", -1);
	q147.AddOption("CloudFront", 1);
	
	Question q148("You have five VPCs in a 'hub and spoke' configuration, with VPC 'A' in the center and individually paired with VPCs 'B', 'C', 'D', and 'E', which make up the spokes. There are no other VPC connections. Which of the following VPCs can VPC 'B' communicate with directly?");
	q148.AddOption("VPCs 'A' and 'C'", -1);
	q148.AddOption("VPCs 'C', 'D', and 'E'", -1);
	q148.AddOption("VPCs 'A' and 'E'", -1);
	q148.AddOption("VPC 'A'", 1);
	
	Question q149("Security groups act like a firewall at the instance level, whereas ____ are an additional layer of security that act at the subnet level. (Fill in the blank with the correct answer.)");
	q149.AddOption("Database Security Groups", -1);
	q149.AddOption("Network ACLs", 1);
	q149.AddOption("Route Tables", -1);
	q149.AddOption("VPC Security Groups", -1);
	
	Question q150("When you create a custom VPC, which of the following are created automatically? (3 answers)");
	q150.AddOption("Security Group", 1);
	q150.AddOption("Access Control List", 1);
	q150.AddOption("NAT Gateway", -1);
	q150.AddOption("Subnets", -1);
	q150.AddOption("Route Table", 1);
	q150.AddOption("Internet Gateway", -1);
	
	Question q151("True or False: An Application Load Balancer must be deployed into at least two Availability Zone subnets");
	q151.AddOption("False", -1);
	q151.AddOption("True", 1);
	
	Question q152("VPC stands for");
	q152.AddOption("Virtual Private Cloud", 1);
	q152.AddOption("Very Public Cloud", -1);
	q152.AddOption("Very Private Cloud", -1);
	q152.AddOption("Virtual Public Cloud", -1);
	
	Question q153("True or False: A subnet can span multiple Availability Zones");
	q153.AddOption("True", -1);
	q153.AddOption("False", 1);
	
	Question q154("By default, how many VPCs am I allowed in each AWS Region?");
	q154.AddOption("2", -1);
	q154.AddOption("1", -1);
	q154.AddOption("5", 1);
	q154.AddOption("6", -1);
	
	Question q155("Which of the following is true?");
	q155.AddOption("Security groups are stateless and Network Access Control Lists (NACLs) are stateful", -1);
	q155.AddOption("Security groups are stateful and Network Access Control Lists (NACLs) are stateless", 1);
	q155.AddOption("Both security groups and Network Access Control Lists (NACLs) are stateful", -1);
	q155.AddOption("Both Security Groups and Network Access Control Lists are stateless", -1);
	
	Question q156("Having just created a new VPC and launching an instance into its Public Subnet, you realize that you have forgotten to assign a Public IP to the instance during creation. What is the simplest way to make your instance reachable from the outside world?");
	q156.AddOption("Create an Elastic IP and new Network Interface. Associate the Elastic IP to the new Network Interface, and the new Network Interface to your instance", -1);
	q156.AddOption("Associate the Private IP of your instance to the Public IP of the Internet Gateway", -1);
	q156.AddOption("Create an Elastic IP address and associate it with your instance", -1);
	q156.AddOption("Nothing – by default all instances deployed into any Public Subnet will automatically receive a Public IP", 1);
	
	Question q157("You want your users to get the best possible user experience and that means minimizing the response time from your servers to your users. Which routing policy will help?");
	q157.AddOption("Weighted", -1);
	q157.AddOption("Multi Value", -1);
	q157.AddOption("Latency", 1);
	q157.AddOption("Geo location", -1);
	
	Question q158("You have a Lambda function that will process data for 25 minutes before successfully completing. The code is working fine in your machine, but in AWS Lambda it just fails with a \"timeout\" issue after 3 seconds. What should you do?");
	q158.AddOption("Run your code somewhere else than Lambda - the maximum timeout is 15 minutes", 1);
	q158.AddOption("Set the memory to 3GB", -1);
	q158.AddOption("Set the timeout to 25 minutes", -1);
	
	Question q159("Your application functions on an ASG behind an ALB. Users have to constantly log back in and you'd rather not enable stickiness on your ALB as you fear it will overload some servers. What should you do?");
	q159.AddOption("Store session data in ElastiCache", 1);
	q159.AddOption("Create your own Load Balancer and deploy that on EC2 instances", -1);
	q159.AddOption("Store session data in a Shared EBS volume", -1);
	q159.AddOption("Store session data in RDS", -1);
	
	Question q160("You'd like to have a dynamic DB_URL variable loaded in your Lambda code");
	q160.AddOption("Place it in the code itself", -1);
	q160.AddOption("Place it in the code zip file", -1);
	q160.AddOption("Place it in the environment variables", 1);
	
	Question q161("You have deployed a new Elastic Beanstalk environment and would like to direct 5% of your production traffic to this new environment, in order to monitor for CloudWatch metrics and ensuring no bugs exist. What type of Route 53 records allows you to do so?");
	q161.AddOption("Simple", -1);
	q161.AddOption("Failover", -1);
	q161.AddOption("Weighted", 1);
	q161.AddOption("Latency", -1);
	
	Question q162("You have purchased \"mycoolcompany.com\" on the AWS registrar and would like for it to point to lb1-1234.us-east-2.elb.amazonaws.com . What sort of Route 53 record is impossible to setup for this?");
	q162.AddOption("Alias", -1);
	q162.AddOption("CNAME", 1);
	
	Question q163("You have purchased a domain on Godaddy and would like to use it with Route 53. What do you need to change to make this work?");
	q163.AddOption("Create a public hosted zone and update the Route 53 NS records", -1);
	q163.AddOption("Create a public hosted zone and update the 3rd party registrar NS records", 1);
	q163.AddOption("Create a private hosted zone and update the 3rd party registrar NS records", -1);
	q163.AddOption("Request for a domain transfer", -1);
	
	Question q164("You have a legal requirement that people in any country but France should not be able to access your website. Which Route 53 record helps you in achieving this?");
	q164.AddOption("Geo location", 1);
	q164.AddOption("Latency", -1);
	q164.AddOption("Weighted", -1);
	q164.AddOption("Multi Value", -1);
	
	Question q165("After updating a Route 53 record to point \"myapp.mydomain.com\" from an old Load Balancer to a new load balancer, it looks like the users are still not redirected to your new load balancer. You are wondering why...");
	q165.AddOption("it's because of the TTL", 1);
	q165.AddOption("it's because of the health checks", -1);
	q165.AddOption("it's because of the CNAME record", -1);
	q165.AddOption("it's because of the alias record", -1);
	
/*	
	Question q166("?");
	q166.AddOption("", -1);
	q166.AddOption("", -1);
	q166.AddOption("", -1);
	q166.AddOption("", -1);
	
	Question q167("?");
	q167.AddOption("", -1);
	q167.AddOption("", -1);
	q167.AddOption("", -1);
	q167.AddOption("", -1);
	
	Question q168("?");
	q168.AddOption("", -1);
	q168.AddOption("", -1);
	q168.AddOption("", -1);
	q168.AddOption("", -1);
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
        exam.push_back(q151);
        exam.push_back(q152);
        exam.push_back(q153);
        exam.push_back(q154);
        exam.push_back(q155);
        exam.push_back(q156);
        exam.push_back(q157);
        exam.push_back(q158);
        exam.push_back(q159);
        exam.push_back(q160);
        exam.push_back(q161);
        exam.push_back(q162);
        exam.push_back(q163);
        exam.push_back(q164);
        exam.push_back(q165);
/*
        exam.push_back(q166);
        exam.push_back(q167);
        exam.push_back(q168);
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
