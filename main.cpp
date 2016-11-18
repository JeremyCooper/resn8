//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//internal models and interfaces for attached software and user-defined controllers
#include "models.h"
#include "testmodel.h"
#include "controllers.h"
#include "apc80.h"
//Member_Pointer object, midimap structure, and mapping file parser
#include "mapping.cpp"
//implements midi library and routes midi input to relevant pointer
#include "router.cpp"


int main()
{
	Test model {};
	APC80 controller {};
	midimap mapping = parse_mapping(&model, &controller);
	
	//controller(1, 2, 3);

	route(&mapping);

	return 0;
}
