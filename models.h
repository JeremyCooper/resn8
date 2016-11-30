//models.h
//
//Load models including their internal interface and states

struct Reference
{
	Reference() {}
	Reference(int channel, int note) : channel(channel), note(note) {}
	int channel, note;
};

class Model
{
public:
	void operator()();
private:
	typedef void (Model::*ptr) ();
	map<string, ptr>  hooks;
};
void Model::operator()() {}
