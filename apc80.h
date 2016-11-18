//apc80.h
//
//Interface and implementation for APC80 ADVANCED CONTROLLER

class APC80 : public Controller
{
public:
	APC80()
	{
		hooks["blah"] = &APC80::blah;
	}
	int blah(float value) {
		cout << "APC80::blah()" << endl << "Value: " << value << endl;
		return 0;
	}
	typedef int (APC80::*ApcPtr) (float);
	ApcPtr returnPointer(string operation_name);
private:
	map<string, ApcPtr> hooks;
};
APC80::ApcPtr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
		return hooks[operation_name];
	return nullptr;
}
