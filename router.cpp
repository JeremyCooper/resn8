//router.cpp
//
//

typedef void (*fn) ();

void route(APC40 * controller)
{
	int page = 0;
	int channel = 2;
	int note = 3;

	cout << page << channel << note << endl;

	//Operation operation = (*mapping)[page][channel][note];
	//fn fnptr = blah;
	//operation.set_target(blah);
	//cout << operation.return_target()() << endl;

	//auto fn5(1) = std::bind(model.opacity, 45);
}
