//mapping.h
struct Operation
{
	Operation() {};
	Operation(APC80::Ptr ptr, vector<int> params) :
		ptr(ptr), params(params) {}
	APC80::Ptr ptr;
	vector<int> params;
};
