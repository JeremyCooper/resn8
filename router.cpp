//router.cpp
//
//

void route(Test * model, APC40 * controller, midimap * mapping)
{
	int page = 0;
	int channel = 2;
	int note = 3;

	Operation operation = (*mapping)[page][channel][note];
	cout << operation.return_parameter(1) << endl;
}
