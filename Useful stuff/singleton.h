class S
{
public:
	static S& getInstance()
	{
		static S    instance;
		return instance;
	}
private:
	S() {}
	S(S const&);              // Don't Implement.
	void operator=(S const&); // Don't implement
};