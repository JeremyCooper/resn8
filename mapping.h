//mapping.h
//
//

class Member_Pointer
{
public:
	Member_Pointer() {}
	Member_Pointer(const char, string, Test *, APC80 *);
	Member_Pointer(Test * model, string operation_name);
	Member_Pointer(APC80 * controller, string operation_name);
	void operator()();
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
void Member_Pointer::operator()()
{
	if (obj == 'M')
		(*model.*model_oper)();
	else if (obj == 'C')
		(*controller.*contrl_oper)();
}

typedef vector<map<int, map<int, Member_Pointer>>> midimap;
