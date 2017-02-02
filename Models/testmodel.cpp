//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r0"] =				{ 176, 0 };
	dict["r1"] =				{ 176, 0 };
	dict["r2"] =				{ 146, 0 };

	dict["g0"] =				{ 176, 1 };
	dict["g1"] =				{ 145, 1 };
	dict["g2"] =				{ 146, 1 };

	dict["b0"] =				{ 176, 2 };
	dict["b1"] =				{ 145, 2 };
	dict["b2"] =				{ 146, 2 };

	dict["selectLayer0"] =		{ 144, 0 };
	dict["selectLayer1"] =		{ 144, 10 };
	dict["selectLayer2"] =		{ 144, 19 };

	dict["speed0"] =			{ 176, 0 };
	dict["speed1"] =			{ 176, 9 };
	dict["speed2"] =			{ 176, 19 };

	dict["opacity0"] =			{ 176, 1 };
	dict["opacity1"] =			{ 176, 10 };
	dict["opacity2"] =			{ 176, 20 };

	dict["reverse0"] =			{ 144, 1 };
	dict["reverse1"] =			{ 144, 10 };
	dict["reverse2"] =			{ 144, 20 };

	dict["forward0"] =			{ 144, 2 };
	dict["forward1"] =			{ 144, 11 };
	dict["forward2"] =			{ 144, 21 };

	dict["random0"] =			{ 144, 3 };
	dict["random1"] =			{ 144, 12 };
	dict["random2"] =			{ 144, 22 };
	
	dict["width0"] =			{ 144, 20 };
	dict["width1"] =			{ 144, 20 };
	dict["width2"] =			{ 144, 20 };

	dict["height0"] =			{ 144, 20 };
	dict["height1"] =			{ 144, 20 };
	dict["height2"] =			{ 144, 20 };

	dict["scale0"] =			{ 144, 20 };
	dict["scale1"] =			{ 144, 20 };
	dict["scale2"] =			{ 144, 20 };

	dict["rotateX0"] =			{ 144, 20 };
	dict["rotateX1"] =			{ 144, 20 };
	dict["rotateX2"] =			{ 144, 20 };

	dict["rotateY0"] =			{ 144, 20 };
	dict["rotateY1"] =			{ 144, 20 };
	dict["rotateY2"] =			{ 144, 20 };

	dict["rotateZ0"] =			{ 144, 20 };
	dict["rotateZ1"] =			{ 144, 20 };
	dict["rotateZ2"] =			{ 144, 20 };

/* blend */
	dict["blend_0:0"] =			{ 144, 20 };
	dict["blend_0:1"] =			{ 144, 20 };
	dict["blend_0:2"] =			{ 144, 20 };

	dict["blend_1:0"] =			{ 144, 20 };
	dict["blend_1:1"] =			{ 144, 20 };
	dict["blend_1:2"] =			{ 144, 20 };

	dict["blend_2:0"] =			{ 144, 20 };
	dict["blend_2:1"] =			{ 144, 20 };
	dict["blend_2:2"] =			{ 144, 20 };

/* effect 0 */
	dict["effect_0:param_0:0"] = { 176, 0 };
	dict["effect_0:param_0:1"] = { 176, 0 };
	dict["effect_0:param_0:2"] = { 176, 0 };

	dict["effect_0:param_1:0"] = { 176, 0 };
	dict["effect_0:param_1:1"] = { 176, 0 };
	dict["effect_0:param_1:2"] = { 176, 0 };

/* effect 1 */
	dict["effect_1:param_0:0"] = { 176, 0 };
	dict["effect_1:param_0:1"] = { 176, 0 };
	dict["effect_1:param_0:2"] = { 176, 0 };

	dict["effect_1:param_1:0"] = { 176, 0 };
	dict["effect_1:param_1:1"] = { 176, 0 };
	dict["effect_1:param_1:2"] = { 176, 0 };

/* effect 2 */
	dict["effect_2:param_0:0"] = { 176, 0 };
	dict["effect_2:param_0:1"] = { 176, 0 };
	dict["effect_2:param_0:2"] = { 176, 0 };

	dict["effect_2:param_1:0"] = { 176, 0 };
	dict["effect_2:param_1:1"] = { 176, 0 };
	dict["effect_2:param_1:2"] = { 176, 0 };

/* effect 3 */
	dict["effect_3:param_0:0"] = { 176, 0 };
	dict["effect_3:param_0:1"] = { 176, 0 };
	dict["effect_3:param_0:2"] = { 176, 0 };

	dict["effect_3:param_1:0"] = { 176, 0 };
	dict["effect_3:param_1:1"] = { 176, 0 };
	dict["effect_3:param_1:2"] = { 176, 0 };

/* preview */
/* preview (layer 0) */
	dict["preview_0:0"] =		 { 144, 20 };
	dict["preview_1:0"] =		 { 144, 20 };
	dict["preview_2:0"] =		 { 144, 20 };
	dict["preview_3:0"] =		 { 144, 20 };
	dict["preview_4:0"] =		 { 144, 20 };
	dict["preview_5:0"] =		 { 144, 20 };
	dict["preview_6:0"] =		 { 144, 20 };
	dict["preview_7:0"] =		 { 144, 20 };
	dict["preview_8:0"] =		 { 144, 20 };
	dict["preview_9:0"] =		 { 144, 20 };
	dict["preview_10:0"] =		 { 144, 20 };
	dict["preview_11:0"] =		 { 144, 20 };
	dict["preview_12:0"] =		 { 144, 20 };

/* preview (layer 1) */
	dict["preview_0:1"] =		 { 144, 20 };
	dict["preview_0:1"] =		 { 144, 20 };
	dict["preview_1:1"] =		 { 144, 20 };
	dict["preview_2:1"] =		 { 144, 20 };
	dict["preview_3:1"] =		 { 144, 20 };
	dict["preview_4:1"] =		 { 144, 20 };
	dict["preview_5:1"] =		 { 144, 20 };
	dict["preview_6:1"] =		 { 144, 20 };
	dict["preview_7:1"] =		 { 144, 20 };
	dict["preview_8:1"] =		 { 144, 20 };
	dict["preview_9:1"] =		 { 144, 20 };
	dict["preview_10:1"] =		 { 144, 20 };
	dict["preview_11:1"] =		 { 144, 20 };
	dict["preview_12:1"] =		 { 144, 20 };

/* preview (layer 2) */
	dict["preview_0:2"] =		 { 144, 20 };
	dict["preview_0:2"] =		 { 144, 20 };
	dict["preview_1:2"] =		 { 144, 20 };
	dict["preview_2:2"] =		 { 144, 20 };
	dict["preview_3:2"] =		 { 144, 20 };
	dict["preview_4:2"] =		 { 144, 20 };
	dict["preview_5:2"] =		 { 144, 20 };
	dict["preview_6:2"] =		 { 144, 20 };
	dict["preview_7:2"] =		 { 144, 20 };
	dict["preview_8:2"] =		 { 144, 20 };
	dict["preview_9:2"] =		 { 144, 20 };
	dict["preview_10:2"] =		 { 144, 20 };
	dict["preview_11:2"] =		 { 144, 20 };
	dict["preview_12:2"] =		 { 144, 20 };

/* select */
/* select layer 0) */
	dict["select_0:0"] =		 { 144, 20 };
	dict["select_1:0"] =		 { 144, 20 };
	dict["select_2:0"] =		 { 144, 20 };
	dict["select_3:0"] =		 { 144, 20 };
	dict["select_4:0"] =		 { 144, 20 };
	dict["select_5:0"] =		 { 144, 20 };
	dict["select_6:0"] =		 { 144, 20 };
	dict["select_7:0"] =		 { 144, 20 };
	dict["select_8:0"] =		 { 144, 20 };
	dict["select_9:0"] =		 { 144, 20 };
	dict["select_10:0"] =		 { 144, 20 };
	dict["select_11:0"] =		 { 144, 20 };
	dict["select_12:0"] =		 { 144, 20 };

/* select (layer 1) */
	dict["select_0:1"] =		 { 144, 20 };
	dict["select_0:1"] =		 { 144, 20 };
	dict["select_1:1"] =		 { 144, 20 };
	dict["select_2:1"] =		 { 144, 20 };
	dict["select_3:1"] =		 { 144, 20 };
	dict["select_4:1"] =		 { 144, 20 };
	dict["select_5:1"] =		 { 144, 20 };
	dict["select_6:1"] =		 { 144, 20 };
	dict["select_7:1"] =		 { 144, 20 };
	dict["select_8:1"] =		 { 144, 20 };
	dict["select_9:1"] =		 { 144, 20 };
	dict["select_10:1"] =		 { 144, 20 };
	dict["select_11:1"] =		 { 144, 20 };
	dict["select_12:1"] =		 { 144, 20 };

/* select (layer 2) */
	dict["select_0:2"] =		 { 144, 20 };
	dict["select_0:2"] =		 { 144, 20 };
	dict["select_1:2"] =		 { 144, 20 };
	dict["select_2:2"] =		 { 144, 20 };
	dict["select_3:2"] =		 { 144, 20 };
	dict["select_4:2"] =		 { 144, 20 };
	dict["select_5:2"] =		 { 144, 20 };
	dict["select_6:2"] =		 { 144, 20 };
	dict["select_7:2"] =		 { 144, 20 };
	dict["select_8:2"] =		 { 144, 20 };
	dict["select_9:2"] =		 { 144, 20 };
	dict["select_10:2"] =		 { 144, 20 };
	dict["select_11:2"] =		 { 144, 20 };
	dict["select_12:2"] =		 { 144, 20 };
}
Test::Test(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	dict[element].value = value;
	sendmidi->send(dict[element], value);
	//cout << dict[element].channel << ", " << dict[element].note << ", " << value << endl;
	return 0;
}
