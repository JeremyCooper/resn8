pair<int, vector<int>> animation(int type, int  mpb, int bars)
{
	int dur = bars * mpb;
	vector<int> values;
	float wait;
	if (type == 0) // ascending
	{
		wait = dur / 127.0;
		for (int i=0; i!=128; ++i)
		{
			values.push_back(i);
		}
		pair<int, vector<int>> timing_messages = {wait, values};
		return timing_messages;
	} else if (type == 1) {
		wait = dur / 127.0;
		for (int i=127; i!=0; --i)
		{
			values.push_back(i);
		}
		values.push_back(0);
		pair<int, vector<int>> timing_messages = {wait, values};
		return timing_messages;
	} else if (type == 2) {
		pair<int, vector<int>> timing_messages;
		return timing_messages;
	} else {
		pair<int, vector<int>> timing_messages;
		return timing_messages;
	}
}
