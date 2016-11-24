//testmodel.h
//
//test model do not reply

class Test : public Model 
{
public:
	Test()
	{
		//page = 0;
		hooks["lala"] = &Test::lala;
	}
	int lala(float, vector<int>);
	typedef int (Test::*TestPtr) (float, vector<int>);
	TestPtr returnPointer(string operation_name);
	//int page;
private:
	map<string, TestPtr> hooks;
};
int Test::lala(float value, vector<int> args)
{
	cout << "Test::lala" << endl;
	cout << "Arguments: ";
	for (unsigned int i=0; i!=args.size(); ++i)
		cout << args[i] << ", ";
	cout << endl << "Value: " << value << endl;
	return 0;
}
Test::TestPtr Test::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
