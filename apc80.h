//apc80.h
//
//Interface and implementation for APC80 ADVANCED CONTROLLER

class APC80 : public Controller
{
public:
	APC80(Test * model) : model(model), page(1)
	{
		hooks["blah"] = &APC80::blah;
		hooks["master"] = &APC80::master;
		testInt = 42;
	}
	int master(int value, vector<int> args) { cout << testInt << endl; }
	int blah(int value, vector<int> args);
	typedef int (APC80::*ApcPtr) (int, vector<int>);
	ApcPtr returnPointer(string operation_name);
	Test * model;
	int page;
private:
	map<string, ApcPtr> hooks;
	int testInt;
};
int APC80::blah(int value, vector<int> args)
{
	cout << "APC80::blah" << endl;
	cout << "Arguments: ";
	for (unsigned int i=0; i!=args.size(); ++i)
		cout << args[i] << ", ";
	cout << endl << "Value: " << value << endl;
	return 0;
}
APC80::ApcPtr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
