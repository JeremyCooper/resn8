//testmodel.cpp
#include "testmodel.h"
using namespace std;
void Test::fillDictionary()
{
	dict["r0"] =				{ 176, 60, 64 };
	dict["r1"] =				{ 176, 61, 64 };
	dict["r2"] =				{ 176, 62, 64 };

	dict["g0"] =				{ 176, 63, 64 };
	dict["g1"] =				{ 176, 64, 64 };
	dict["g2"] =				{ 176, 65, 64 };

	dict["b0"] =				{ 176, 66, 64 };
	dict["b1"] =				{ 176, 67, 64 };
	dict["b2"] =				{ 176, 68, 64 };

	dict["selectLayer0"] =		{ 144, 9 };
	dict["selectLayer1"] =		{ 144, 10 };
	dict["selectLayer2"] =		{ 144, 11 };

	dict["speed0"] =			{ 176, 0, 13 };
	dict["speed1"] =			{ 176, 1, 13 };
	dict["speed2"] =			{ 176, 2, 13 };

	dict["opacity0"] =			{ 176, 3, 50 };
	dict["opacity1"] =			{ 176, 4, 50 };
	dict["opacity2"] =			{ 176, 5, 50 };

	dict["reverse0"] =			{ 144, 12 };
	dict["reverse1"] =			{ 144, 13 };
	dict["reverse2"] =			{ 144, 14 };

	dict["forward0"] =			{ 144, 15, 127 };
	dict["forward1"] =			{ 144, 16, 127 };
	dict["forward2"] =			{ 144, 17, 127 };

	dict["random0"] =			{ 144, 18 };
	dict["random1"] =			{ 144, 19 };
	dict["random2"] =			{ 144, 20 };
	
	dict["width0"] =			{ 176, 6, 15 };
	dict["width1"] =			{ 176, 7, 15 };
	dict["width2"] =			{ 176, 8, 15 };

	dict["height0"] =			{ 176, 9, 8 };
	dict["height1"] =			{ 176, 10, 8 };
	dict["height2"] =			{ 176, 11, 8 };

	dict["scale0"] =			{ 176, 12, 13 };
	dict["scale1"] =			{ 176, 13, 13 };
	dict["scale2"] =			{ 176, 14, 13 };

	dict["rotateX0"] =			{ 176, 15, 64 };
	dict["rotateX1"] =			{ 176, 16, 64 };
	dict["rotateX2"] =			{ 176, 17, 64 };

	dict["rotateY0"] =			{ 176, 18, 64 };
	dict["rotateY1"] =			{ 176, 19, 64 };
	dict["rotateY2"] =			{ 176, 20, 64 };

	dict["rotateZ0"] =			{ 176, 21, 64 };
	dict["rotateZ1"] =			{ 176, 22, 64 };
	dict["rotateZ2"] =			{ 176, 23, 64 };

/* blend */
	dict["blend_0:0"] =			{ 144, 21 };
	dict["blend_0:1"] =			{ 144, 22 };
	dict["blend_0:2"] =			{ 144, 23 };

	dict["blend_1:0"] =			{ 144, 24 };
	dict["blend_1:1"] =			{ 144, 25 };
	dict["blend_1:2"] =			{ 144, 26 };

	dict["blend_2:0"] =			{ 144, 27 };
	dict["blend_2:1"] =			{ 144, 28 };
	dict["blend_2:2"] =			{ 144, 29 };

/* effect 0 */
	dict["effect_0:param_0:0"] = { 176, 24, 63 };
	dict["effect_0:param_0:1"] = { 176, 25, 63 };
	dict["effect_0:param_0:2"] = { 176, 26, 63 };

	dict["effect_0:param_1:0"] = { 176, 27, 63 };
	dict["effect_0:param_1:1"] = { 176, 28, 63 };
	dict["effect_0:param_1:2"] = { 176, 29, 63 };

	dict["effect_0:param_2:0"] = { 176, 30 };
	dict["effect_0:param_2:1"] = { 176, 31 };
	dict["effect_0:param_2:2"] = { 176, 32 };

/* effect 1 */
	dict["effect_1:param_0:0"] = { 176, 33 };
	dict["effect_1:param_0:1"] = { 176, 34 };
	dict["effect_1:param_0:2"] = { 176, 35 };

	dict["effect_1:param_1:0"] = { 176, 36 };
	dict["effect_1:param_1:1"] = { 176, 37 };
	dict["effect_1:param_1:2"] = { 176, 38 };

	dict["effect_1:param_2:0"] = { 176, 39 };
	dict["effect_1:param_2:1"] = { 176, 40 };
	dict["effect_1:param_2:2"] = { 176, 41 };

/* effect 2 */
	dict["effect_2:param_0:0"] = { 176, 42 };
	dict["effect_2:param_0:1"] = { 176, 43 };
	dict["effect_2:param_0:2"] = { 176, 44 };

	dict["effect_2:param_1:0"] = { 176, 45 };
	dict["effect_2:param_1:1"] = { 176, 46 };
	dict["effect_2:param_1:2"] = { 176, 47 };

	dict["effect_2:param_2:0"] = { 176, 48 };
	dict["effect_2:param_2:1"] = { 176, 49 };
	dict["effect_2:param_2:2"] = { 176, 50 };

/* effect 3 */
	dict["effect_3:param_0:0"] = { 176, 51 };
	dict["effect_3:param_0:1"] = { 176, 52 };
	dict["effect_3:param_0:2"] = { 176, 53 };

	dict["effect_3:param_1:0"] = { 176, 54 };
	dict["effect_3:param_1:1"] = { 176, 55 };
	dict["effect_3:param_1:2"] = { 176, 56 };

	dict["effect_3:param_2:0"] = { 176, 57 };
	dict["effect_3:param_2:1"] = { 176, 58 };
	dict["effect_3:param_2:2"] = { 176, 59 };

/* preview */
/* preview (layer 0) */
	dict["preview_0:0"] =		 { 144, 30 };
	dict["preview_1:0"] =		 { 144, 31 };
	dict["preview_2:0"] =		 { 144, 32 };
	dict["preview_3:0"] =		 { 144, 33 };
	dict["preview_4:0"] =		 { 144, 34 };
	dict["preview_5:0"] =		 { 144, 35 };
	dict["preview_6:0"] =		 { 144, 36 };
	dict["preview_7:0"] =		 { 144, 37 };
	dict["preview_8:0"] =		 { 144, 38 };
	dict["preview_9:0"] =		 { 144, 39 };
	dict["preview_10:0"] =		 { 144, 40 };
	dict["preview_11:0"] =		 { 144, 41 };
	dict["preview_12:0"] =		 { 144, 42 };

/* preview (layer 1) */
	dict["preview_0:1"] =		 { 144, 43 };
	dict["preview_0:1"] =		 { 144, 44 };
	dict["preview_1:1"] =		 { 144, 45 };
	dict["preview_2:1"] =		 { 144, 46 };
	dict["preview_3:1"] =		 { 144, 47 };
	dict["preview_4:1"] =		 { 144, 48 };
	dict["preview_5:1"] =		 { 144, 49 };
	dict["preview_6:1"] =		 { 144, 50 };
	dict["preview_7:1"] =		 { 144, 51 };
	dict["preview_8:1"] =		 { 144, 52 };
	dict["preview_9:1"] =		 { 144, 53 };
	dict["preview_10:1"] =		 { 144, 54 };
	dict["preview_11:1"] =		 { 144, 55 };
	dict["preview_12:1"] =		 { 144, 56 };

/* preview (layer 2) */
	dict["preview_0:2"] =		 { 144, 57 };
	dict["preview_0:2"] =		 { 144, 58 };
	dict["preview_1:2"] =		 { 144, 59 };
	dict["preview_2:2"] =		 { 144, 60 };
	dict["preview_3:2"] =		 { 144, 61 };
	dict["preview_4:2"] =		 { 144, 62 };
	dict["preview_5:2"] =		 { 144, 63 };
	dict["preview_6:2"] =		 { 144, 64 };
	dict["preview_7:2"] =		 { 144, 65 };
	dict["preview_8:2"] =		 { 144, 66 };
	dict["preview_9:2"] =		 { 144, 67 };
	dict["preview_10:2"] =		 { 144, 68 };
	dict["preview_11:2"] =		 { 144, 69 };
	dict["preview_12:2"] =		 { 144, 70 };

/* select */
/* select layer 0) */
	dict["select_0:0"] =		 { 144, 71 };
	dict["select_1:0"] =		 { 144, 72 };
	dict["select_2:0"] =		 { 144, 73 };
	dict["select_3:0"] =		 { 144, 74 };
	dict["select_4:0"] =		 { 144, 75 };
	dict["select_5:0"] =		 { 144, 76 };
	dict["select_6:0"] =		 { 144, 77 };
	dict["select_7:0"] =		 { 144, 78 };
	dict["select_8:0"] =		 { 144, 79 };
	dict["select_9:0"] =		 { 144, 80 };
	dict["select_10:0"] =		 { 144, 81 };
	dict["select_11:0"] =		 { 144, 82 };
	dict["select_12:0"] =		 { 144, 83 };

/* select (layer 1) */
	dict["select_0:1"] =		 { 144, 84 };
	dict["select_0:1"] =		 { 144, 85 };
	dict["select_1:1"] =		 { 144, 86 };
	dict["select_2:1"] =		 { 144, 87 };
	dict["select_3:1"] =		 { 144, 88 };
	dict["select_4:1"] =		 { 144, 89 };
	dict["select_5:1"] =		 { 144, 90 };
	dict["select_6:1"] =		 { 144, 91 };
	dict["select_7:1"] =		 { 144, 92 };
	dict["select_8:1"] =		 { 144, 93 };
	dict["select_9:1"] =		 { 144, 94 };
	dict["select_10:1"] =		 { 144, 95 };
	dict["select_11:1"] =		 { 144, 96 };
	dict["select_12:1"] =		 { 144, 97 };

/* select (layer 2) */
	dict["select_0:2"] =		 { 144, 98 };
	dict["select_0:2"] =		 { 144, 99 };
	dict["select_1:2"] =		 { 144, 100 };
	dict["select_2:2"] =		 { 144, 101 };
	dict["select_3:2"] =		 { 144, 102 };
	dict["select_4:2"] =		 { 144, 103 };
	dict["select_5:2"] =		 { 144, 104 };
	dict["select_6:2"] =		 { 144, 105 };
	dict["select_7:2"] =		 { 144, 106 };
	dict["select_8:2"] =		 { 144, 107 };
	dict["select_9:2"] =		 { 144, 108 };
	dict["select_10:2"] =		 { 144, 109 };
	dict["select_11:2"] =		 { 144, 110 };
	dict["select_12:2"] =		 { 144, 111 };
}
Test::Test(SendMidi * sendmidi) : sendmidi(sendmidi)
{
	fillDictionary();
}
int Test::operator()(string element, int value)
{
	//dict[element].value = value;
	sendmidi->send(dict[element], value);
	//cout << dict[element].channel << ", " << dict[element].note << ", " << value << endl;
	return 0;
}
