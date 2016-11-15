//Artistic compatibility layer for Resolume Arena
//By: Jeremy Cooper

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//interface to midi library
//#include "midi.h"
//internal models and interfaces for attached software
#include "models.h"
#include "testmodel.h"
#include "controllers.h"
#include "apc80.h"
#include "mapping.cpp"
#include "router.cpp"

typedef vector<map<int, map<int, Member_Pointer>>> midimap;

int main()
{
	Test model {};
	APC80 controller {};
	midimap mapping = parse_mapping(&model, &controller);
	
	mapping[0][1][2]();

	//controller(1, 2, 3);

	//route(&midimap);

	return 0;
}
