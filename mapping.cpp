//mapping.cpp
//
//

#include <fstream>
#include "mapping.h"

//example mapping:
// 1, 2, 3, blah(1, 2, 3)
midimap parse_mapping(Test * model, APC80 * controller)
{
	midimap mapping;
	mapping.resize(4); //number of pages

	mapping[0][1][2] = Member_Pointer(controller, "blah");
	mapping[1][1][2] = Member_Pointer(model, "lala");
	//open file "page1", and read line-by-line, populating mapping vector

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
