//models.h
//
//Load models including their internal interface and states

class Model
{
public:
	void operator()();
private:
	typedef void (Model::*ptr) ();
	map<string, ptr>  hooks;
};
void Model::operator()() {}

typedef void (Model::*ModelPtr) ();
