//testmodel.h
//
//test model do not reply

class Test : public Model 
{
public:
	Test(void (*sendMidi) (Reference, int)) : sendMidi(sendMidi)
	{
		hooks["lala"] = &Test::lala;
		fillDictionary();
	}
	//Mappable functions//
	int lala(int, vector<int>);
	int master(int, vector<int>);
	//////////////////////
	void fillDictionary();
	typedef int (Test::*TestPtr) (int, vector<int>);
	TestPtr returnPointer(string operation_name);
private:
	void (*sendMidi) (Reference, int); //pointer to sendMidi function
	map<string, TestPtr> hooks;
	map<string, Reference> dict;
};

//Mappable functions//
int Test::lala(int value, vector<int> args)
{
	cout << "Test::lala" << endl;
	cout << "Arguments: ";
	for (unsigned int i=0; i!=args.size(); ++i)
		cout << args[i] << ", ";
	cout << endl << "Value: " << value << endl;
	return 0;
}
//////////////////////
void Test::fillDictionary()
{
	dict["master"] = { 144, 20 };
}
Test::TestPtr Test::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
