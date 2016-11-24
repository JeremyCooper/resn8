//mapping.h
//
//

class Member_Pointer
{
public:
	Member_Pointer() { obj = '!'; }
	Member_Pointer(Test * model, string operation_name, vector<int> args);
	Member_Pointer(APC80 * controller, string operation_name, vector<int> args);
	int operator()(float value);
	void function1();
private:
	char obj;
	vector<int> arguments;
	Test * model;
	APC80 * controller;
	Test::TestPtr model_oper;
	APC80::ApcPtr contrl_oper;
};
Member_Pointer::Member_Pointer(Test * model, string operation_name, vector<int> args)
{
	model_oper = model->returnPointer(operation_name);
	arguments = args;
	obj = 'M';
}
Member_Pointer::Member_Pointer(APC80 * controller, string operation_name, vector<int> args)
{
	contrl_oper = controller->returnPointer(operation_name);
	arguments = args;
	obj = 'C';
}
int Member_Pointer::operator()(float value)
{
	if (obj == '!')
		return 99;
	else if (obj == 'M')
		return (*model.*model_oper)(value, arguments);
	else if (obj == 'C')
		return (*controller.*contrl_oper)(value, arguments);
	return 1;
}

typedef vector<map<int, map<int, Member_Pointer>>> midimap;
