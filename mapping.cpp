//mapping.cpp
//
//

#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/erase.hpp>
#include "mapping.h"
//example mapping:
// 1, 2, 3, blah(1, 2, 3)
midimap parse_mapping(APC80 * controller)
{
	midimap mapping;
	mapping.resize(4); //number of pages

	ifstream mapFileIn {"mapping.txt", ios::in };
	string readLine;

	while(mapFileIn.good())
	{
		//returns once unneededly at the end
		string page_, channel_, note_;
		int page, channel, note;
		string obj, operation, rawparams;
		vector<int> params;
		//grab page
		getline(mapFileIn, page_, ',');
		boost::algorithm::trim(page_);
		//grab channel
		getline(mapFileIn, channel_, ',');
		boost::algorithm::trim(channel_);
		//grab note
		getline(mapFileIn, note_, ',');
		boost::algorithm::trim(note_);
		//grab obj
		getline(mapFileIn, obj, ',');
		boost::algorithm::trim(obj);
		//grab operation
		getline(mapFileIn, operation, '(');
		boost::algorithm::trim(operation);
		//grab params
		getline(mapFileIn, rawparams, ')');
		//break params by ',', trim whitespace, add to vector
		boost::algorithm::erase_all(rawparams, " ");
		//how to gracefully exit if reading an empty line?
		if (operation == "")
			break;
		size_t pos = 0;
		string token;
		while ((pos = rawparams.find(",")) != string::npos)
		{
			token = rawparams.substr(0, pos);
			params.push_back(stoi(token));
			rawparams.erase(0, pos + 1);
		}
		//get last argument
		token = rawparams.substr(0, rawparams.length());
		params.push_back(stoi(token));

		page = stoi(page_);
		channel = stoi(channel_);
		note = stoi(note_);

		if (obj == "model")
			mapping[page][channel][note] =
				Member_Pointer(controller->model, operation, params);
		else if (obj == "controller")
			mapping[page][channel][note] = Member_Pointer(controller, operation, params);
	}

	return mapping;
}

/*
 * controller methods signature should look like this:
 * template <typename T>
 * int (float value, T ... params)
 *
 * where value = midivalue
 * and params is a variadic parameter list
 * populated by hard-coded values from mapping file
 */
