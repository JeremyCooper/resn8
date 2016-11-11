//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
//config
using namespace std;
//typedef vector<map<int, map<int, operation>>> midimap;
//midimap[page][channel][note]
//interface to midi library
//#include "midi.h"
//internal models and interfaces for attached software
#include "models.h"
#include "testmodel.h"
#include "controllers.cpp"
#include "mapping.cpp"
#include "router.cpp"

int main()
{
	Test model {};
	APC40 controller {};
	midimap mapping = parse_mapping();

	model.blah();
	controller(1, 2, 3);

	route(&model, &controller, &mapping);

	return 0;
}
