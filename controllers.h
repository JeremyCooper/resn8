//controllers.h
//
//

class Controller
{
public:
	void operator()(const int i1, const int i2, const int i3);
private:
};

class APC40 : public Controller
{
public:
	void operator()(const int i1, const int i2, const int i3)
	{
		cout << i1 << ", " << i2 << ", " << i3 << endl;
	}
private:
};
