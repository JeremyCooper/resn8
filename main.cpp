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
#include "mapping.cpp"
#include "controllers.h"
#include "router.cpp"
//user controllers
#include "apc80.h"

int main()
{
	Test model {};
	//midimap mapping = parse_mapping();
	//APC40 controller {&model, &mapping};
	
	void (Test::*fptr) ();
   	fptr = &Test::blah;
	(model.*fptr)();
	fptr = &Test::lala;
	(model.*fptr)();
	//Member_Pointer<model*> model_pointer;

	//controller(1, 2, 3);

	//route "presses the buttons" on the virtual controller
	//route(&controller);

	return 0;
}
