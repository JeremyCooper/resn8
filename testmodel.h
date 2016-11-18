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
	int lala(float value) {
		cout << "Test::lala()" << endl << "Value: " << value << endl;
		return 0;
	}
	typedef int (Test::*TestPtr) (float);
	TestPtr returnPointer(string operation_name);
private:
	map<string, TestPtr> hooks;
};
Test::TestPtr Test::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}

