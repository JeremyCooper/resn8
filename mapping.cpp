//mapping.cpp
//
//

#include <fstream>
#include "mapping.h"
typedef vector<map<int, map<int, Member_Pointer>>> midimap;

midimap parse_mapping(Test * model, APC80 * controller)
{
	midimap mapping;
	//open file "config", and read number of pages
	//
	mapping.resize(4); //number of pages
	mapping[0][1][2] = Member_Pointer('C', "blah", model, controller);
	mapping[1][1][2] = Member_Pointer('M', "lala", model, controller);
	//open file "page1", and read line-by-line, populating mapping vector
	//open file "page1", and read line-by-line, populating mapping vector
	//
	mapping[0][1][2]();
	mapping[1][1][2]();
	return mapping;
}
