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
	void blah() { cout << "APC80::blah()" << endl; }
	//controller methods signature should look like this:
	//template <typename T>
	//int (float value, T ... params)
	//
	//where value = midivalue
	//and
	//params is a variadic parameter list populated by hard-coded params in mapping file
	typedef void (APC80::*ApcPtr) ();
	ApcPtr returnPointer(string operation_name);
private:
	map<string, ApcPtr> hooks;
};
APC80::ApcPtr APC80::returnPointer(string operation_name)
{
	auto index = hooks.find(operation_name);
	if (index != hooks.end())
	{
		return hooks[operation_name];
	}
	return nullptr;
}
