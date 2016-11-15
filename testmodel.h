//testmodel.h
//
//test model do not reply

class Test : public Model 
{
public:
	Test()
	{
		hooks["lala"] = &Test::lala;
	}
	void lala()
	{
		cout << "Test::lala()" << endl;
	}
	typedef void (Test::*TestPtr) ();
	TestPtr returnPointer(string operation_name);
private:
	map<string, TestPtr> hooks;
};
Test::TestPtr Test::returnPointer(string operation_name)
{
	TestPtr ptr = &Test::lala;
	return ptr;
}

