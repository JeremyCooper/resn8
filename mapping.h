//mapping.h
//
//

class Operation
{
public:
	void set_target(int target) { this->target = target; }
	void set_parameters(vector<int> parameters) { this->parameters = parameters; }
	int return_target() { return this->target; }
	int return_parameter(unsigned int index);
private:
	int target;
	vector<int> parameters;
};

int Operation::return_parameter(unsigned int index)
{
	if ((index >= 0) && (index < parameters.size()))
	{
		return parameters[index];
	} else {
		return 99;
	}
}
