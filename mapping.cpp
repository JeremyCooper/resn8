//mapping.cpp
//
//

#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include "mapping.h"
//example mapping:
// 1, 2, 3, blah(1, 2, 3)
midimap parse_mapping(Test * model, APC80 * controller)
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
		boost::algorithm::trim(rawparams);

		/*cout << page << channel << note << endl;
		cout << obj << operation << rawparams << endl;*/

		//how to gracefully exit if reading an empty line?
		if (operation == "")
			break;

		page = stoi(page_);
		channel = stoi(channel_);
		note = stoi(note_);

		if (obj == "model")
			mapping[page][channel][note] = Member_Pointer(model, operation);
		else if (obj == "controller")
			mapping[page][channel][note] = Member_Pointer(controller, operation);
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
