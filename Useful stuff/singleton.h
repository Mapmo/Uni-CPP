class S
{
public:
	static S* getInstance()
	{
		static S    instance;
		return &instance;
	}
	//~S(); if needed make it public
private:
	S() {} //it still needs a constructor to create object S, but now it's private => an object can only be created within the class
	S(S const&);//does not need to be implemented
	void operator=(S const&);//can also use =delete, but it's not necessary
};

/*Singleton is an implementation that allows only one object of a the class to exist
 The idea is to have a function that creates a static object and then to return a pointer to its address, being unable to create another object of that class
Here is how it will look like in main.cpp
*/

int main()
{
    S* Sptr = S::getInstance();
    return 0;
}

//after that you can use *Sptr to do whatever you like with the object
