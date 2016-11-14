//controllers.h
//
//

class Controller
{
public:
	//Controller(Model * model, midimap * mapping) : model(model), mapping(mapping);
	void operator()(const int i1, const int i2, const int i3);
private:
	//Model * model;
	//midimap * mapping;
};
void Controller::operator()(const int i1, const int i2, const int i3)
{
	//midimap[i1][i2][i3]
}

class APC40 : public Controller
{
public:
private:
};
