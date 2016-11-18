//mapping.h
//
//

class Member_Pointer
{
public:
	Member_Pointer() {}
	Member_Pointer(Test * model, string operation_name);
	Member_Pointer(APC80 * controller, string operation_name);
	int operator()(float value);
	void function1();
private:
	char obj;
	Test * model;
	APC80 * controller;
	Test::TestPtr model_oper;
	APC80::ApcPtr contrl_oper;
};
Member_Pointer::Member_Pointer(Test * model, string operation_name)
{
	model_oper = model->returnPointer(operation_name);
	obj = 'M';
}
Member_Pointer::Member_Pointer(APC80 * controller, string operation_name)
{
	contrl_oper = controller->returnPointer(operation_name);
	obj = 'C';
}
int Member_Pointer::operator()(float value)
{
	if (obj == 'M')
		return (*model.*model_oper)(value);
	else if (obj == 'C')
		return (*controller.*contrl_oper)(value);
	return 1;
}

typedef vector<map<int, map<int, Member_Pointer>>> midimap;
