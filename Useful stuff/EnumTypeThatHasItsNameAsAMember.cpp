enum age {Medieval, ModernTimes, age};

int main()
{
	/*
	I encountered this issue and it took me some time to find the problem, because I have unintentaionally added the enum name as a value,
	and therefore when I was using it to define a variable, I was receiving an error which was as it follows:
	*/
	age now;//enum age::age = 2  => enum value has higher priority than the enum type name which can prevent some critical errors

	return 0;
}