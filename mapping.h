//mapping.h
//
//

class Member_Pointer
{
public:
	Member_Pointer() {}
	Member_Pointer(const char, string, Test *, APC80 *);
	void operator()();
	void function1();
private:
	char obj;
	Test * model;
	APC80 * controller;
	Test::TestPtr model_oper;
	APC80::ApcPtr contrl_oper;
};
Member_Pointer::Member_Pointer(
		char obj, string operation_name, Test * model, APC80 * controller)
		: obj (obj), model (model), controller (controller)
{
	if (obj == 'M')
	{
		model_oper = model->returnPointer(operation_name);
		this->obj = 'M';
	}
	else if (obj == 'C')
	{
		contrl_oper = controller->returnPointer(operation_name);
		this->obj = 'C';
	}
//	operation_name
}
void Member_Pointer::operator()()
{
	if (obj == 'M')
		(*model.*model_oper)();
	else if (obj == 'C')
		(*controller.*contrl_oper)();
}
