//mapping.cpp
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/erase.hpp>
using namespace std;

struct Operation
{
	Operation() {};
	Operation(string name, Controller::Ptr ptr, vector<int> params) :
		name(name), ptr(ptr), params(params) {}
	string name;
	Controller::Ptr ptr;
	vector<int> params;
};

typedef vector<map<int, map<int, Operation>>> midimap;

midimap parse_mapping(Controller * controller)
{
	midimap mapping;
	mapping.resize(4); //number of pages

	ifstream mapFileIn {"config.txt", ios::in };
	string readLine;

	int currentGroup = 0;

	while(mapFileIn.good())
	{
		string line, page_, channel_, note_;
		//boost::iterator_range<string::iterator> pos, pos2;
		size_t pos, pos2;
		int page, channel, note;
		string obj, operation, rawparams;
		vector<int> params;

		getline(mapFileIn, line);
		if (line == "")
			continue;
		if (line[0] == '/' && line[1] == '/')
			continue;
#ifdef d_parser
		cout << endl;
#endif
		if (line[0] == '#')
		{
			pos = line.find(' ');
			currentGroup = stoi(line.substr(pos));
#ifdef d_parser
			cout << "Found a group number: (" << currentGroup << ")" << endl;
#endif
			continue;
		}

		pos = line.find(',');
		page_ = line.substr(0, pos);
		boost::algorithm::trim(page_);
#ifdef d_parser
		cout << "Page: (" << page_ << ")" << endl;
#endif
		pos2 = line.find(',', pos+1);
		channel_ = line.substr(pos+1, (pos2-pos)-1); 
		boost::algorithm::trim(channel_);
#ifdef d_parser
		cout << "Channel: (" << channel_ << ")" << endl;
#endif
		pos = line.find(',', pos2+1);
		note_ = line.substr(pos2+1, (pos-pos2)-1);
		boost::algorithm::trim(note_);
#ifdef d_parser
		cout << "Note: (" << note_ << ")" << endl;
#endif
		pos2 = line.find('(');
		operation = line.substr(pos+1, (pos2-pos)-1);
		boost::algorithm::trim(operation);
#ifdef d_parser
		cout << "Operation: (" << operation << ")" << endl;
#endif
		pos = line.find(')');
		rawparams = line.substr(pos2+1, (pos-pos2)-1);
		boost::algorithm::erase_all(rawparams, " ");
		if (rawparams.length() != 0)
		{
			//need to seperate individual params, delimited by commas
			size_t pos = 0;
			string token;
#ifdef d_parser
			cout << "Params: (";
#endif
			while ((pos = rawparams.find(",")) != string::npos)
			{
				token = rawparams.substr(0, pos);
				params.push_back(stoi(token));
#ifdef d_parser
				cout << token << ",";
#endif
				rawparams.erase(0, pos + 1);
			}
			//this method leaves out the last param, grab it here
			token = rawparams.substr(0, rawparams.length());
			params.push_back(stoi(token));
#ifdef d_parser
			cout << token << ")" << endl;
#endif
		}

		page = stoi(page_);
		channel = stoi(channel_);
		note = stoi(note_);

		currentGroupPage[currentGroup].second++;
		groups[{channel, note}] = currentGroup;
#ifdef d_parser
		cout << "Group: (" << groups[{channel, note}] << ")" << endl;
#endif

		Controller::Ptr controllerptr = controller->returnPointer(operation);
		mapping[page][channel][note] = Operation {operation, controllerptr, params};
	}
	return mapping;
}
