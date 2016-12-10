//operation.h
struct Operation
{
	Operation() {};
	Operation(string name, APC80::Ptr ptr, vector<int> params) :
		name(name), ptr(ptr), params(params) {}
	//unsigned int group;
	string name;
	APC80::Ptr ptr;
	vector<int> params;
};
