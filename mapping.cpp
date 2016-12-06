//mapping.cpp
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/erase.hpp>
#include "mapping.h"
using namespace std;

typedef vector<map<int, map<int, Operation>>> midimap;

midimap parse_mapping(APC80 * controller)
{
	midimap mapping;
	mapping.resize(4); //number of pages

	ifstream mapFileIn {"mapping.txt", ios::in };
	string readLine;

	while(mapFileIn.good())
	{
		string page_, channel_, note_;
		int page, channel, note;
		string obj, operation, rawparams;
		vector<int> params;
		getline(mapFileIn, page_, ',');
		boost::algorithm::trim(page_);

		getline(mapFileIn, channel_, ',');
		boost::algorithm::trim(channel_);

		getline(mapFileIn, note_, ',');
		boost::algorithm::trim(note_);

		getline(mapFileIn, operation, '(');
		boost::algorithm::trim(operation);

		getline(mapFileIn, rawparams, ')');
		boost::algorithm::erase_all(rawparams, " ");
		//how to gracefully exit if reading an empty line?
		if (operation == "")
			break;

		if (rawparams.length() != 0)
		{
			//need to seperate individual params, delimited by commas
			size_t pos = 0;
			string token;
			while ((pos = rawparams.find(",")) != string::npos)
			{
				token = rawparams.substr(0, pos);
				params.push_back(stoi(token));
				rawparams.erase(0, pos + 1);
			}
			//this method leaves out the last param, grab it here
			token = rawparams.substr(0, rawparams.length());
			params.push_back(stoi(token));
		}

		page = stoi(page_);
		channel = stoi(channel_);
		note = stoi(note_);

		APC80::Ptr apcptr = controller->returnPointer(operation);
		mapping[page][channel][note] = Operation {apcptr, params};
	}

	return mapping;
}
