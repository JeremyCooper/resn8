//apc80.h
//
//Interface and implementation for APC80 ADVANCED CONTROLLER

class APC80 : public Controller
{
public:
	void blah()
	{
		cout << "BLAH BLAH BLAH" << endl;
	}
	//controller methods signature should look like this:
	//template <typename T>
	//int (float value, T ... params)
	//
	//where value = midivalue
	//and
	//params is a variadic parameter list populated by hard-coded params in mapping file
};
