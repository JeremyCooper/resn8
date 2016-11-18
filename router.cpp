//router.cpp
//
//

void route(midimap * mapping)
{
	int page = 0;
	int channel = 1;
	int note = 2;
	float value = 127.0;
	cout << page << channel << note << endl;

	(*mapping)[page][channel][note](value);
}
