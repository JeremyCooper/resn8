//mapping.h
//
//

class Member_Pointer
{
public:
	Member_Pointer() { obj = '!'; }
	Member_Pointer(Test * model, string operation_name, vector<int> args);
	Member_Pointer(APC80 * controller, string operation_name, vector<int> args);
	char operator()(Test::TestPtr& controller_out, APC80::ApcPtr& model_out);
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
char Member_Pointer::operator()(
		Test::TestPtr& model_out, APC80::ApcPtr& controller_out)
{
	if (obj == '!')
	{
		return '!';
	}
	else if (obj == 'M')
	{
		model_out = model_oper;
		return 'M';
	}
	else if (obj == 'C')
	{
		controller_out = contrl_oper;
		return 'C';
	}
}

typedef vector<map<int, map<int, Member_Pointer>>> midimap;
