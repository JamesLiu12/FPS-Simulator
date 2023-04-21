#include "map_new_Wall.h"

void ModelMap_new_Wall_Init(struct Mesh *map_new_wall) {
	Vector3_Set(&map_new_wall->vertices[0], -20.0, 0.0, -19.9);
	Vector3_Set(&map_new_wall->vertices[1], -20.0, 2.5, -19.9);
	Vector3_Set(&map_new_wall->vertices[2], -20.0, 0.0, -20.1);
	Vector3_Set(&map_new_wall->vertices[3], -20.0, 2.5, -20.1);
	Vector3_Set(&map_new_wall->vertices[4], 60.0, 0.0, -19.9);
	Vector3_Set(&map_new_wall->vertices[5], 60.0, 2.5, -19.9);
	Vector3_Set(&map_new_wall->vertices[6], 60.0, 0.0, -20.1);
	Vector3_Set(&map_new_wall->vertices[7], 60.0, 2.5, -20.1);
	Vector3_Set(&map_new_wall->vertices[8], -20.0, 0.0, 20.1);
	Vector3_Set(&map_new_wall->vertices[9], -20.0, 2.5, 20.1);
	Vector3_Set(&map_new_wall->vertices[10], -20.0, 0.0, 19.9);
	Vector3_Set(&map_new_wall->vertices[11], -20.0, 2.5, 19.9);
	Vector3_Set(&map_new_wall->vertices[12], 60.0, 0.0, 20.1);
	Vector3_Set(&map_new_wall->vertices[13], 60.0, 2.5, 20.1);
	Vector3_Set(&map_new_wall->vertices[14], 60.0, 0.0, 19.9);
	Vector3_Set(&map_new_wall->vertices[15], 60.0, 2.5, 19.9);
	Vector3_Set(&map_new_wall->vertices[16], -19.9, 0.0, 20.0);
	Vector3_Set(&map_new_wall->vertices[17], -19.9, 2.5, 20.0);
	Vector3_Set(&map_new_wall->vertices[18], -20.099998, 0.0, 20.0);
	Vector3_Set(&map_new_wall->vertices[19], -20.099998, 2.5, 20.0);
	Vector3_Set(&map_new_wall->vertices[20], -19.900002, 0.0, -20.0);
	Vector3_Set(&map_new_wall->vertices[21], -19.900002, 2.5, -20.0);
	Vector3_Set(&map_new_wall->vertices[22], -20.1, 0.0, -20.0);
	Vector3_Set(&map_new_wall->vertices[23], -20.1, 2.5, -20.0);
	Vector3_Set(&map_new_wall->vertices[24], 60.100002, 0.0, 20.0);
	Vector3_Set(&map_new_wall->vertices[25], 60.100002, 2.5, 20.0);
	Vector3_Set(&map_new_wall->vertices[26], 59.900002, 0.0, 20.0);
	Vector3_Set(&map_new_wall->vertices[27], 59.900002, 2.5, 20.0);
	Vector3_Set(&map_new_wall->vertices[28], 60.099998, 0.0, -20.0);
	Vector3_Set(&map_new_wall->vertices[29], 60.099998, 2.5, -20.0);
	Vector3_Set(&map_new_wall->vertices[30], 59.899998, 0.0, -20.0);
	Vector3_Set(&map_new_wall->vertices[31], 59.899998, 2.5, -20.0);
	Vector3_Set(&map_new_wall->vertices[32], -14.9, -2.6178e-2, 19.997795);
	Vector3_Set(&map_new_wall->vertices[33], -14.9, 2.473818, 20.002159);
	Vector3_Set(&map_new_wall->vertices[34], -15.099999, -2.6178e-2, 19.997795);
	Vector3_Set(&map_new_wall->vertices[35], -15.099999, 2.473818, 20.002159);
	Vector3_Set(&map_new_wall->vertices[36], -14.900001, 2.6182e-2, -10.002159);
	Vector3_Set(&map_new_wall->vertices[37], -14.900001, 2.526178, -9.997795);
	Vector3_Set(&map_new_wall->vertices[38], -15.1, 2.6182e-2, -10.002159);
	Vector3_Set(&map_new_wall->vertices[39], -15.1, 2.526178, -9.997795);
	Vector3_Set(&map_new_wall->vertices[40], -10.0, 0.0, -14.9);
	Vector3_Set(&map_new_wall->vertices[41], -10.0, 2.5, -14.9);
	Vector3_Set(&map_new_wall->vertices[42], -10.0, 0.0, -15.1);
	Vector3_Set(&map_new_wall->vertices[43], -10.0, 2.5, -15.1);
	Vector3_Set(&map_new_wall->vertices[44], 50.0, 0.0, -14.9);
	Vector3_Set(&map_new_wall->vertices[45], 50.0, 2.5, -14.9);
	Vector3_Set(&map_new_wall->vertices[46], 50.0, 0.0, -15.1);
	Vector3_Set(&map_new_wall->vertices[47], 50.0, 2.5, -15.1);
	Vector3_Set(&map_new_wall->vertices[48], -4.033919, 0.0, 14.815644);
	Vector3_Set(&map_new_wall->vertices[49], -4.033919, 2.5, 14.815644);
	Vector3_Set(&map_new_wall->vertices[50], -4.17534, 0.0, 14.674223);
	Vector3_Set(&map_new_wall->vertices[51], -4.17534, 2.5, 14.674223);
	Vector3_Set(&map_new_wall->vertices[52], 5.158469, 0.0, 5.623257);
	Vector3_Set(&map_new_wall->vertices[53], 5.158469, 2.5, 5.623257);
	Vector3_Set(&map_new_wall->vertices[54], 5.017047, 0.0, 5.481835);
	Vector3_Set(&map_new_wall->vertices[55], 5.017047, 2.5, 5.481835);
	Vector3_Set(&map_new_wall->vertices[56], -8.874012, 0.0, -1.73259);
	Vector3_Set(&map_new_wall->vertices[57], -8.874012, 2.5, -1.73259);
	Vector3_Set(&map_new_wall->vertices[58], -8.73259, 0.0, -1.874012);
	Vector3_Set(&map_new_wall->vertices[59], -8.73259, 2.5, -1.874012);
	Vector3_Set(&map_new_wall->vertices[60], 1.73259, 0.0, 8.874012);
	Vector3_Set(&map_new_wall->vertices[61], 1.73259, 2.5, 8.874012);
	Vector3_Set(&map_new_wall->vertices[62], 1.874012, 0.0, 8.73259);
	Vector3_Set(&map_new_wall->vertices[63], 1.874012, 2.5, 8.73259);
	Vector3_Set(&map_new_wall->vertices[64], 10.1, -7.869e-3, -5.773882);
	Vector3_Set(&map_new_wall->vertices[65], 10.1, 2.492127, -5.769519);
	Vector3_Set(&map_new_wall->vertices[66], 9.900001, -7.869e-3, -5.773882);
	Vector3_Set(&map_new_wall->vertices[67], 9.900001, 2.492127, -5.769519);
	Vector3_Set(&map_new_wall->vertices[68], 10.099999, 7.873e-3, -14.793868);
	Vector3_Set(&map_new_wall->vertices[69], 10.099999, 2.507869, -14.789505);
	Vector3_Set(&map_new_wall->vertices[70], 9.9, 7.873e-3, -14.793868);
	Vector3_Set(&map_new_wall->vertices[71], 9.9, 2.507869, -14.789505);
	Vector3_Set(&map_new_wall->vertices[72], -15.141779, 0.0, -15.000357);
	Vector3_Set(&map_new_wall->vertices[73], -15.141779, 2.5, -15.000357);
	Vector3_Set(&map_new_wall->vertices[74], -15.000357, 0.0, -15.141779);
	Vector3_Set(&map_new_wall->vertices[75], -15.000357, 2.5, -15.141779);
	Vector3_Set(&map_new_wall->vertices[76], -0.999643, 0.0, -0.858222);
	Vector3_Set(&map_new_wall->vertices[77], -0.999643, 2.5, -0.858222);
	Vector3_Set(&map_new_wall->vertices[78], -0.858222, 0.0, -0.999643);
	Vector3_Set(&map_new_wall->vertices[79], -0.858222, 2.5, -0.999643);
	Vector3_Set(&map_new_wall->vertices[80], -10.0, 0.0, 15.1);
	Vector3_Set(&map_new_wall->vertices[81], -10.0, 2.5, 15.1);
	Vector3_Set(&map_new_wall->vertices[82], -10.0, 0.0, 14.9);
	Vector3_Set(&map_new_wall->vertices[83], -10.0, 2.5, 14.9);
	Vector3_Set(&map_new_wall->vertices[84], 6.0, 0.0, 15.1);
	Vector3_Set(&map_new_wall->vertices[85], 6.0, 2.5, 15.1);
	Vector3_Set(&map_new_wall->vertices[86], 6.0, 0.0, 14.9);
	Vector3_Set(&map_new_wall->vertices[87], 6.0, 2.5, 14.9);
	Vector3_Set(&map_new_wall->vertices[88], 10.1, -4.361e-3, 14.887814);
	Vector3_Set(&map_new_wall->vertices[89], 10.1, 2.495635, 14.892178);
	Vector3_Set(&map_new_wall->vertices[90], 9.900001, -4.361e-3, 14.887814);
	Vector3_Set(&map_new_wall->vertices[91], 9.900001, 2.495635, 14.892178);
	Vector3_Set(&map_new_wall->vertices[92], 10.099999, 4.365e-3, 9.887821);
	Vector3_Set(&map_new_wall->vertices[93], 10.099999, 2.504361, 9.892185);
	Vector3_Set(&map_new_wall->vertices[94], 9.9, 4.365e-3, 9.887821);
	Vector3_Set(&map_new_wall->vertices[95], 9.9, 2.504361, 9.892185);
	Vector3_Set(&map_new_wall->vertices[96], 57.484146, 4.8842e-2, 3.600599);
	Vector3_Set(&map_new_wall->vertices[97], 57.484146, 4.108842, 3.600599);
	Vector3_Set(&map_new_wall->vertices[98], 57.484146, 4.8842e-2, -3.399401);
	Vector3_Set(&map_new_wall->vertices[99], 57.484146, 4.108842, -3.399401);
	Vector3_Set(&map_new_wall->vertices[100], 58.14415, 4.8842e-2, 3.600599);
	Vector3_Set(&map_new_wall->vertices[101], 58.14415, 4.108842, 3.600599);
	Vector3_Set(&map_new_wall->vertices[102], 58.14415, 4.8842e-2, -3.399401);
	Vector3_Set(&map_new_wall->vertices[103], 58.14415, 4.108842, -3.399401);
	Vector3_Set(&map_new_wall->vertices[104], 20.0, 0.0, 15.1);
	Vector3_Set(&map_new_wall->vertices[105], 20.0, 2.5, 15.1);
	Vector3_Set(&map_new_wall->vertices[106], 20.0, 0.0, 14.9);
	Vector3_Set(&map_new_wall->vertices[107], 20.0, 2.5, 14.9);
	Vector3_Set(&map_new_wall->vertices[108], 60.0, 0.0, 15.1);
	Vector3_Set(&map_new_wall->vertices[109], 60.0, 2.5, 15.1);
	Vector3_Set(&map_new_wall->vertices[110], 60.0, 0.0, 14.9);
	Vector3_Set(&map_new_wall->vertices[111], 60.0, 2.5, 14.9);
	Vector3_Set(&map_new_wall->vertices[112], 10.0, 0.0, 10.1);
	Vector3_Set(&map_new_wall->vertices[113], 10.0, 2.5, 10.1);
	Vector3_Set(&map_new_wall->vertices[114], 10.0, 0.0, 9.9);
	Vector3_Set(&map_new_wall->vertices[115], 10.0, 2.5, 9.9);
	Vector3_Set(&map_new_wall->vertices[116], 15.0, 0.0, 10.1);
	Vector3_Set(&map_new_wall->vertices[117], 15.0, 2.5, 10.1);
	Vector3_Set(&map_new_wall->vertices[118], 15.0, 0.0, 9.9);
	Vector3_Set(&map_new_wall->vertices[119], 15.0, 2.5, 9.9);
	Vector3_Set(&map_new_wall->vertices[120], 15.1, -2.1815e-2, 14.997799);
	Vector3_Set(&map_new_wall->vertices[121], 15.1, 2.478181, 15.002163);
	Vector3_Set(&map_new_wall->vertices[122], 14.900001, -2.1815e-2, 14.997799);
	Vector3_Set(&map_new_wall->vertices[123], 14.900001, 2.478181, 15.002163);
	Vector3_Set(&map_new_wall->vertices[124], 15.099999, 2.1819e-2, -10.002163);
	Vector3_Set(&map_new_wall->vertices[125], 15.099999, 2.521815, -9.997799);
	Vector3_Set(&map_new_wall->vertices[126], 14.9, 2.1819e-2, -10.002163);
	Vector3_Set(&map_new_wall->vertices[127], 14.9, 2.521815, -9.997799);
	Vector3_Set(&map_new_wall->vertices[128], 20.1, -1.7451e-2, 14.997803);
	Vector3_Set(&map_new_wall->vertices[129], 20.1, 2.482545, 15.002167);
	Vector3_Set(&map_new_wall->vertices[130], 19.9, -1.7451e-2, 14.997803);
	Vector3_Set(&map_new_wall->vertices[131], 19.9, 2.482545, 15.002167);
	Vector3_Set(&map_new_wall->vertices[132], 20.1, 1.7455e-2, -5.002167);
	Vector3_Set(&map_new_wall->vertices[133], 20.1, 2.517451, -4.997803);
	Vector3_Set(&map_new_wall->vertices[134], 19.9, 1.7455e-2, -5.002167);
	Vector3_Set(&map_new_wall->vertices[135], 19.9, 2.517451, -4.997803);
	Vector3_Set(&map_new_wall->vertices[136], 50.100002, -2.1815e-2, 9.872471);
	Vector3_Set(&map_new_wall->vertices[137], 50.100002, 2.478181, 9.876835);
	Vector3_Set(&map_new_wall->vertices[138], 49.900002, -2.1815e-2, 9.872471);
	Vector3_Set(&map_new_wall->vertices[139], 49.900002, 2.478181, 9.876835);
	Vector3_Set(&map_new_wall->vertices[140], 50.099998, 2.1819e-2, -15.127491);
	Vector3_Set(&map_new_wall->vertices[141], 50.099998, 2.521815, -15.123127);
	Vector3_Set(&map_new_wall->vertices[142], 49.899998, 2.1819e-2, -15.127491);
	Vector3_Set(&map_new_wall->vertices[143], 49.899998, 2.521815, -15.123127);
	Vector3_Set(&map_new_wall->vertices[144], 2.796786, 0.0, 2.938207);
	Vector3_Set(&map_new_wall->vertices[145], 2.796786, 2.5, 2.938207);
	Vector3_Set(&map_new_wall->vertices[146], 2.938207, 0.0, 2.796786);
	Vector3_Set(&map_new_wall->vertices[147], 2.938207, 2.5, 2.796786);
	Vector3_Set(&map_new_wall->vertices[148], 9.867853, 0.0, 10.009275);
	Vector3_Set(&map_new_wall->vertices[149], 9.867853, 2.5, 10.009275);
	Vector3_Set(&map_new_wall->vertices[150], 10.009275, 0.0, 9.867853);
	Vector3_Set(&map_new_wall->vertices[151], 10.009275, 2.5, 9.867853);
	Vector3_Set(&map_new_wall->vertices[152], 25.1, -1.3088e-2, 9.997807);
	Vector3_Set(&map_new_wall->vertices[153], 25.1, 2.486908, 10.002171);
	Vector3_Set(&map_new_wall->vertices[154], 24.9, -1.3088e-2, 9.997807);
	Vector3_Set(&map_new_wall->vertices[155], 24.9, 2.486908, 10.002171);
	Vector3_Set(&map_new_wall->vertices[156], 25.1, 1.3092e-2, -5.00217);
	Vector3_Set(&map_new_wall->vertices[157], 25.1, 2.513088, -4.997807);
	Vector3_Set(&map_new_wall->vertices[158], 24.9, 1.3092e-2, -5.00217);
	Vector3_Set(&map_new_wall->vertices[159], 24.9, 2.513088, -4.997807);
	Vector3_Set(&map_new_wall->vertices[160], 15.0, 0.0, -9.9);
	Vector3_Set(&map_new_wall->vertices[161], 15.0, 2.5, -9.9);
	Vector3_Set(&map_new_wall->vertices[162], 15.0, 0.0, -10.1);
	Vector3_Set(&map_new_wall->vertices[163], 15.0, 2.5, -10.1);
	Vector3_Set(&map_new_wall->vertices[164], 45.0, 0.0, -9.9);
	Vector3_Set(&map_new_wall->vertices[165], 45.0, 2.5, -9.9);
	Vector3_Set(&map_new_wall->vertices[166], 45.0, 0.0, -10.1);
	Vector3_Set(&map_new_wall->vertices[167], 45.0, 2.5, -10.1);
	Vector3_Set(&map_new_wall->vertices[168], 44.958744, -1.7451e-2, 14.997803);
	Vector3_Set(&map_new_wall->vertices[169], 44.958744, 2.482545, 15.002167);
	Vector3_Set(&map_new_wall->vertices[170], 44.758743, -1.7451e-2, 14.997803);
	Vector3_Set(&map_new_wall->vertices[171], 44.758743, 2.482545, 15.002167);
	Vector3_Set(&map_new_wall->vertices[172], 44.95874, 1.7455e-2, -5.002167);
	Vector3_Set(&map_new_wall->vertices[173], 44.95874, 2.517451, -4.997803);
	Vector3_Set(&map_new_wall->vertices[174], 44.758739, 1.7455e-2, -5.002167);
	Vector3_Set(&map_new_wall->vertices[175], 44.758739, 2.517451, -4.997803);
	Vector3_Set(&map_new_wall->vertices[176], 24.963116, 0.0, -4.9);
	Vector3_Set(&map_new_wall->vertices[177], 24.963116, 2.5, -4.9);
	Vector3_Set(&map_new_wall->vertices[178], 24.963116, 0.0, -5.1);
	Vector3_Set(&map_new_wall->vertices[179], 24.963116, 2.5, -5.1);
	Vector3_Set(&map_new_wall->vertices[180], 44.963116, 0.0, -4.9);
	Vector3_Set(&map_new_wall->vertices[181], 44.963116, 2.5, -4.9);
	Vector3_Set(&map_new_wall->vertices[182], 44.963116, 0.0, -5.1);
	Vector3_Set(&map_new_wall->vertices[183], 44.963116, 2.5, -5.1);
	Vector3_Set(&map_new_wall->vertices[184], 25.0, 0.0, 10.1);
	Vector3_Set(&map_new_wall->vertices[185], 25.0, 2.5, 10.1);
	Vector3_Set(&map_new_wall->vertices[186], 25.0, 0.0, 9.9);
	Vector3_Set(&map_new_wall->vertices[187], 25.0, 2.5, 9.9);
	Vector3_Set(&map_new_wall->vertices[188], 40.0, 0.0, 10.1);
	Vector3_Set(&map_new_wall->vertices[189], 40.0, 2.5, 10.1);
	Vector3_Set(&map_new_wall->vertices[190], 40.0, 0.0, 9.9);
	Vector3_Set(&map_new_wall->vertices[191], 40.0, 2.5, 9.9);
	Vector3_Set(&map_new_wall->vertices[192], 40.075665, -8.725e-3, 9.99781);
	Vector3_Set(&map_new_wall->vertices[193], 40.075665, 2.491271, 10.002174);
	Vector3_Set(&map_new_wall->vertices[194], 39.875668, -8.725e-3, 9.99781);
	Vector3_Set(&map_new_wall->vertices[195], 39.875668, 2.491271, 10.002174);
	Vector3_Set(&map_new_wall->vertices[196], 40.075665, 8.729e-3, -2.174e-3);
	Vector3_Set(&map_new_wall->vertices[197], 40.075665, 2.508725, 2.189e-3);
	Vector3_Set(&map_new_wall->vertices[198], 39.875668, 8.729e-3, -2.174e-3);
	Vector3_Set(&map_new_wall->vertices[199], 39.875668, 2.508725, 2.189e-3);
	Vector3_Set(&map_new_wall->vertices[200], 30.0, 0.0, 0.1);
	Vector3_Set(&map_new_wall->vertices[201], 30.0, 2.5, 0.1);
	Vector3_Set(&map_new_wall->vertices[202], 30.0, 0.0, -0.1);
	Vector3_Set(&map_new_wall->vertices[203], 30.0, 2.5, -0.1);
	Vector3_Set(&map_new_wall->vertices[204], 40.0, 0.0, 0.1);
	Vector3_Set(&map_new_wall->vertices[205], 40.0, 2.5, 0.1);
	Vector3_Set(&map_new_wall->vertices[206], 40.0, 0.0, -0.1);
	Vector3_Set(&map_new_wall->vertices[207], 40.0, 2.5, -0.1);
	Vector3_Set(&map_new_wall->vertices[208], 30.1, -4.361e-3, 4.997814);
	Vector3_Set(&map_new_wall->vertices[209], 30.1, 2.495635, 5.002178);
	Vector3_Set(&map_new_wall->vertices[210], 29.9, -4.361e-3, 4.997814);
	Vector3_Set(&map_new_wall->vertices[211], 29.9, 2.495635, 5.002178);
	Vector3_Set(&map_new_wall->vertices[212], 30.1, 4.365e-3, -2.178e-3);
	Vector3_Set(&map_new_wall->vertices[213], 30.1, 2.504361, 2.186e-3);
	Vector3_Set(&map_new_wall->vertices[214], 29.9, 4.365e-3, -2.178e-3);
	Vector3_Set(&map_new_wall->vertices[215], 29.9, 2.504361, 2.186e-3);
	Vector3_Set(&map_new_wall->vertices[216], 30.0, 0.0, 5.1);
	Vector3_Set(&map_new_wall->vertices[217], 30.0, 2.5, 5.1);
	Vector3_Set(&map_new_wall->vertices[218], 30.0, 0.0, 4.9);
	Vector3_Set(&map_new_wall->vertices[219], 30.0, 2.5, 4.9);
	Vector3_Set(&map_new_wall->vertices[220], 35.0, 0.0, 5.1);
	Vector3_Set(&map_new_wall->vertices[221], 35.0, 2.5, 5.1);
	Vector3_Set(&map_new_wall->vertices[222], 35.0, 0.0, 4.9);
	Vector3_Set(&map_new_wall->vertices[223], 35.0, 2.5, 4.9);

	Face_Set(&map_new_wall->triangles[0], 1, 2, 4);
	Face_Set(&map_new_wall->triangles[1], 3, 4, 8);
	Face_Set(&map_new_wall->triangles[2], 7, 8, 6);
	Face_Set(&map_new_wall->triangles[3], 5, 6, 2);
	Face_Set(&map_new_wall->triangles[4], 3, 7, 5);
	Face_Set(&map_new_wall->triangles[5], 8, 4, 2);
	Face_Set(&map_new_wall->triangles[6], 9, 10, 12);
	Face_Set(&map_new_wall->triangles[7], 11, 12, 16);
	Face_Set(&map_new_wall->triangles[8], 15, 16, 14);
	Face_Set(&map_new_wall->triangles[9], 13, 14, 10);
	Face_Set(&map_new_wall->triangles[10], 11, 15, 13);
	Face_Set(&map_new_wall->triangles[11], 16, 12, 10);
	Face_Set(&map_new_wall->triangles[12], 17, 18, 20);
	Face_Set(&map_new_wall->triangles[13], 19, 20, 24);
	Face_Set(&map_new_wall->triangles[14], 23, 24, 22);
	Face_Set(&map_new_wall->triangles[15], 21, 22, 18);
	Face_Set(&map_new_wall->triangles[16], 19, 23, 21);
	Face_Set(&map_new_wall->triangles[17], 24, 20, 18);
	Face_Set(&map_new_wall->triangles[18], 25, 26, 28);
	Face_Set(&map_new_wall->triangles[19], 27, 28, 32);
	Face_Set(&map_new_wall->triangles[20], 31, 32, 30);
	Face_Set(&map_new_wall->triangles[21], 29, 30, 26);
	Face_Set(&map_new_wall->triangles[22], 27, 31, 29);
	Face_Set(&map_new_wall->triangles[23], 32, 28, 26);
	Face_Set(&map_new_wall->triangles[24], 33, 34, 36);
	Face_Set(&map_new_wall->triangles[25], 35, 36, 40);
	Face_Set(&map_new_wall->triangles[26], 39, 40, 38);
	Face_Set(&map_new_wall->triangles[27], 37, 38, 34);
	Face_Set(&map_new_wall->triangles[28], 35, 39, 37);
	Face_Set(&map_new_wall->triangles[29], 40, 36, 34);
	Face_Set(&map_new_wall->triangles[30], 41, 42, 44);
	Face_Set(&map_new_wall->triangles[31], 43, 44, 48);
	Face_Set(&map_new_wall->triangles[32], 47, 48, 46);
	Face_Set(&map_new_wall->triangles[33], 45, 46, 42);
	Face_Set(&map_new_wall->triangles[34], 43, 47, 45);
	Face_Set(&map_new_wall->triangles[35], 48, 44, 42);
	Face_Set(&map_new_wall->triangles[36], 49, 50, 52);
	Face_Set(&map_new_wall->triangles[37], 51, 52, 56);
	Face_Set(&map_new_wall->triangles[38], 55, 56, 54);
	Face_Set(&map_new_wall->triangles[39], 53, 54, 50);
	Face_Set(&map_new_wall->triangles[40], 51, 55, 53);
	Face_Set(&map_new_wall->triangles[41], 56, 52, 50);
	Face_Set(&map_new_wall->triangles[42], 57, 58, 60);
	Face_Set(&map_new_wall->triangles[43], 59, 60, 64);
	Face_Set(&map_new_wall->triangles[44], 63, 64, 62);
	Face_Set(&map_new_wall->triangles[45], 61, 62, 58);
	Face_Set(&map_new_wall->triangles[46], 59, 63, 61);
	Face_Set(&map_new_wall->triangles[47], 64, 60, 58);
	Face_Set(&map_new_wall->triangles[48], 65, 66, 68);
	Face_Set(&map_new_wall->triangles[49], 67, 68, 72);
	Face_Set(&map_new_wall->triangles[50], 71, 72, 70);
	Face_Set(&map_new_wall->triangles[51], 69, 70, 66);
	Face_Set(&map_new_wall->triangles[52], 67, 71, 69);
	Face_Set(&map_new_wall->triangles[53], 72, 68, 66);
	Face_Set(&map_new_wall->triangles[54], 73, 74, 76);
	Face_Set(&map_new_wall->triangles[55], 75, 76, 80);
	Face_Set(&map_new_wall->triangles[56], 79, 80, 78);
	Face_Set(&map_new_wall->triangles[57], 77, 78, 74);
	Face_Set(&map_new_wall->triangles[58], 75, 79, 77);
	Face_Set(&map_new_wall->triangles[59], 80, 76, 74);
	Face_Set(&map_new_wall->triangles[60], 81, 82, 84);
	Face_Set(&map_new_wall->triangles[61], 83, 84, 88);
	Face_Set(&map_new_wall->triangles[62], 87, 88, 86);
	Face_Set(&map_new_wall->triangles[63], 85, 86, 82);
	Face_Set(&map_new_wall->triangles[64], 83, 87, 85);
	Face_Set(&map_new_wall->triangles[65], 88, 84, 82);
	Face_Set(&map_new_wall->triangles[66], 89, 90, 92);
	Face_Set(&map_new_wall->triangles[67], 91, 92, 96);
	Face_Set(&map_new_wall->triangles[68], 95, 96, 94);
	Face_Set(&map_new_wall->triangles[69], 93, 94, 90);
	Face_Set(&map_new_wall->triangles[70], 91, 95, 93);
	Face_Set(&map_new_wall->triangles[71], 96, 92, 90);
	Face_Set(&map_new_wall->triangles[72], 97, 98, 100);
	Face_Set(&map_new_wall->triangles[73], 99, 100, 104);
	Face_Set(&map_new_wall->triangles[74], 103, 104, 102);
	Face_Set(&map_new_wall->triangles[75], 101, 102, 98);
	Face_Set(&map_new_wall->triangles[76], 99, 103, 101);
	Face_Set(&map_new_wall->triangles[77], 104, 100, 98);
	Face_Set(&map_new_wall->triangles[78], 105, 106, 108);
	Face_Set(&map_new_wall->triangles[79], 107, 108, 112);
	Face_Set(&map_new_wall->triangles[80], 111, 112, 110);
	Face_Set(&map_new_wall->triangles[81], 109, 110, 106);
	Face_Set(&map_new_wall->triangles[82], 107, 111, 109);
	Face_Set(&map_new_wall->triangles[83], 112, 108, 106);
	Face_Set(&map_new_wall->triangles[84], 113, 114, 116);
	Face_Set(&map_new_wall->triangles[85], 115, 116, 120);
	Face_Set(&map_new_wall->triangles[86], 119, 120, 118);
	Face_Set(&map_new_wall->triangles[87], 117, 118, 114);
	Face_Set(&map_new_wall->triangles[88], 115, 119, 117);
	Face_Set(&map_new_wall->triangles[89], 120, 116, 114);
	Face_Set(&map_new_wall->triangles[90], 121, 122, 124);
	Face_Set(&map_new_wall->triangles[91], 123, 124, 128);
	Face_Set(&map_new_wall->triangles[92], 127, 128, 126);
	Face_Set(&map_new_wall->triangles[93], 125, 126, 122);
	Face_Set(&map_new_wall->triangles[94], 123, 127, 125);
	Face_Set(&map_new_wall->triangles[95], 128, 124, 122);
	Face_Set(&map_new_wall->triangles[96], 129, 130, 132);
	Face_Set(&map_new_wall->triangles[97], 131, 132, 136);
	Face_Set(&map_new_wall->triangles[98], 135, 136, 134);
	Face_Set(&map_new_wall->triangles[99], 133, 134, 130);
	Face_Set(&map_new_wall->triangles[100], 131, 135, 133);
	Face_Set(&map_new_wall->triangles[101], 136, 132, 130);
	Face_Set(&map_new_wall->triangles[102], 137, 138, 140);
	Face_Set(&map_new_wall->triangles[103], 139, 140, 144);
	Face_Set(&map_new_wall->triangles[104], 143, 144, 142);
	Face_Set(&map_new_wall->triangles[105], 141, 142, 138);
	Face_Set(&map_new_wall->triangles[106], 139, 143, 141);
	Face_Set(&map_new_wall->triangles[107], 144, 140, 138);
	Face_Set(&map_new_wall->triangles[108], 145, 146, 148);
	Face_Set(&map_new_wall->triangles[109], 147, 148, 152);
	Face_Set(&map_new_wall->triangles[110], 151, 152, 150);
	Face_Set(&map_new_wall->triangles[111], 149, 150, 146);
	Face_Set(&map_new_wall->triangles[112], 147, 151, 149);
	Face_Set(&map_new_wall->triangles[113], 152, 148, 146);
	Face_Set(&map_new_wall->triangles[114], 153, 154, 156);
	Face_Set(&map_new_wall->triangles[115], 155, 156, 160);
	Face_Set(&map_new_wall->triangles[116], 159, 160, 158);
	Face_Set(&map_new_wall->triangles[117], 157, 158, 154);
	Face_Set(&map_new_wall->triangles[118], 155, 159, 157);
	Face_Set(&map_new_wall->triangles[119], 160, 156, 154);
	Face_Set(&map_new_wall->triangles[120], 161, 162, 164);
	Face_Set(&map_new_wall->triangles[121], 163, 164, 168);
	Face_Set(&map_new_wall->triangles[122], 167, 168, 166);
	Face_Set(&map_new_wall->triangles[123], 165, 166, 162);
	Face_Set(&map_new_wall->triangles[124], 163, 167, 165);
	Face_Set(&map_new_wall->triangles[125], 168, 164, 162);
	Face_Set(&map_new_wall->triangles[126], 169, 170, 172);
	Face_Set(&map_new_wall->triangles[127], 171, 172, 176);
	Face_Set(&map_new_wall->triangles[128], 175, 176, 174);
	Face_Set(&map_new_wall->triangles[129], 173, 174, 170);
	Face_Set(&map_new_wall->triangles[130], 171, 175, 173);
	Face_Set(&map_new_wall->triangles[131], 176, 172, 170);
	Face_Set(&map_new_wall->triangles[132], 177, 178, 180);
	Face_Set(&map_new_wall->triangles[133], 179, 180, 184);
	Face_Set(&map_new_wall->triangles[134], 183, 184, 182);
	Face_Set(&map_new_wall->triangles[135], 181, 182, 178);
	Face_Set(&map_new_wall->triangles[136], 179, 183, 181);
	Face_Set(&map_new_wall->triangles[137], 184, 180, 178);
	Face_Set(&map_new_wall->triangles[138], 185, 186, 188);
	Face_Set(&map_new_wall->triangles[139], 187, 188, 192);
	Face_Set(&map_new_wall->triangles[140], 191, 192, 190);
	Face_Set(&map_new_wall->triangles[141], 189, 190, 186);
	Face_Set(&map_new_wall->triangles[142], 187, 191, 189);
	Face_Set(&map_new_wall->triangles[143], 192, 188, 186);
	Face_Set(&map_new_wall->triangles[144], 193, 194, 196);
	Face_Set(&map_new_wall->triangles[145], 195, 196, 200);
	Face_Set(&map_new_wall->triangles[146], 199, 200, 198);
	Face_Set(&map_new_wall->triangles[147], 197, 198, 194);
	Face_Set(&map_new_wall->triangles[148], 195, 199, 197);
	Face_Set(&map_new_wall->triangles[149], 200, 196, 194);
	Face_Set(&map_new_wall->triangles[150], 201, 202, 204);
	Face_Set(&map_new_wall->triangles[151], 203, 204, 208);
	Face_Set(&map_new_wall->triangles[152], 207, 208, 206);
	Face_Set(&map_new_wall->triangles[153], 205, 206, 202);
	Face_Set(&map_new_wall->triangles[154], 203, 207, 205);
	Face_Set(&map_new_wall->triangles[155], 208, 204, 202);
	Face_Set(&map_new_wall->triangles[156], 209, 210, 212);
	Face_Set(&map_new_wall->triangles[157], 211, 212, 216);
	Face_Set(&map_new_wall->triangles[158], 215, 216, 214);
	Face_Set(&map_new_wall->triangles[159], 213, 214, 210);
	Face_Set(&map_new_wall->triangles[160], 211, 215, 213);
	Face_Set(&map_new_wall->triangles[161], 216, 212, 210);
	Face_Set(&map_new_wall->triangles[162], 217, 218, 220);
	Face_Set(&map_new_wall->triangles[163], 219, 220, 224);
	Face_Set(&map_new_wall->triangles[164], 223, 224, 222);
	Face_Set(&map_new_wall->triangles[165], 221, 222, 218);
	Face_Set(&map_new_wall->triangles[166], 219, 223, 221);
	Face_Set(&map_new_wall->triangles[167], 224, 220, 218);
	Face_Set(&map_new_wall->triangles[168], 1, 3, 4);
	Face_Set(&map_new_wall->triangles[169], 3, 7, 8);
	Face_Set(&map_new_wall->triangles[170], 7, 5, 6);
	Face_Set(&map_new_wall->triangles[171], 5, 1, 2);
	Face_Set(&map_new_wall->triangles[172], 3, 1, 5);
	Face_Set(&map_new_wall->triangles[173], 8, 6, 2);
	Face_Set(&map_new_wall->triangles[174], 9, 11, 12);
	Face_Set(&map_new_wall->triangles[175], 11, 15, 16);
	Face_Set(&map_new_wall->triangles[176], 15, 13, 14);
	Face_Set(&map_new_wall->triangles[177], 13, 9, 10);
	Face_Set(&map_new_wall->triangles[178], 11, 9, 13);
	Face_Set(&map_new_wall->triangles[179], 16, 14, 10);
	Face_Set(&map_new_wall->triangles[180], 17, 19, 20);
	Face_Set(&map_new_wall->triangles[181], 19, 23, 24);
	Face_Set(&map_new_wall->triangles[182], 23, 21, 22);
	Face_Set(&map_new_wall->triangles[183], 21, 17, 18);
	Face_Set(&map_new_wall->triangles[184], 19, 17, 21);
	Face_Set(&map_new_wall->triangles[185], 24, 22, 18);
	Face_Set(&map_new_wall->triangles[186], 25, 27, 28);
	Face_Set(&map_new_wall->triangles[187], 27, 31, 32);
	Face_Set(&map_new_wall->triangles[188], 31, 29, 30);
	Face_Set(&map_new_wall->triangles[189], 29, 25, 26);
	Face_Set(&map_new_wall->triangles[190], 27, 25, 29);
	Face_Set(&map_new_wall->triangles[191], 32, 30, 26);
	Face_Set(&map_new_wall->triangles[192], 33, 35, 36);
	Face_Set(&map_new_wall->triangles[193], 35, 39, 40);
	Face_Set(&map_new_wall->triangles[194], 39, 37, 38);
	Face_Set(&map_new_wall->triangles[195], 37, 33, 34);
	Face_Set(&map_new_wall->triangles[196], 35, 33, 37);
	Face_Set(&map_new_wall->triangles[197], 40, 38, 34);
	Face_Set(&map_new_wall->triangles[198], 41, 43, 44);
	Face_Set(&map_new_wall->triangles[199], 43, 47, 48);
	Face_Set(&map_new_wall->triangles[200], 47, 45, 46);
	Face_Set(&map_new_wall->triangles[201], 45, 41, 42);
	Face_Set(&map_new_wall->triangles[202], 43, 41, 45);
	Face_Set(&map_new_wall->triangles[203], 48, 46, 42);
	Face_Set(&map_new_wall->triangles[204], 49, 51, 52);
	Face_Set(&map_new_wall->triangles[205], 51, 55, 56);
	Face_Set(&map_new_wall->triangles[206], 55, 53, 54);
	Face_Set(&map_new_wall->triangles[207], 53, 49, 50);
	Face_Set(&map_new_wall->triangles[208], 51, 49, 53);
	Face_Set(&map_new_wall->triangles[209], 56, 54, 50);
	Face_Set(&map_new_wall->triangles[210], 57, 59, 60);
	Face_Set(&map_new_wall->triangles[211], 59, 63, 64);
	Face_Set(&map_new_wall->triangles[212], 63, 61, 62);
	Face_Set(&map_new_wall->triangles[213], 61, 57, 58);
	Face_Set(&map_new_wall->triangles[214], 59, 57, 61);
	Face_Set(&map_new_wall->triangles[215], 64, 62, 58);
	Face_Set(&map_new_wall->triangles[216], 65, 67, 68);
	Face_Set(&map_new_wall->triangles[217], 67, 71, 72);
	Face_Set(&map_new_wall->triangles[218], 71, 69, 70);
	Face_Set(&map_new_wall->triangles[219], 69, 65, 66);
	Face_Set(&map_new_wall->triangles[220], 67, 65, 69);
	Face_Set(&map_new_wall->triangles[221], 72, 70, 66);
	Face_Set(&map_new_wall->triangles[222], 73, 75, 76);
	Face_Set(&map_new_wall->triangles[223], 75, 79, 80);
	Face_Set(&map_new_wall->triangles[224], 79, 77, 78);
	Face_Set(&map_new_wall->triangles[225], 77, 73, 74);
	Face_Set(&map_new_wall->triangles[226], 75, 73, 77);
	Face_Set(&map_new_wall->triangles[227], 80, 78, 74);
	Face_Set(&map_new_wall->triangles[228], 81, 83, 84);
	Face_Set(&map_new_wall->triangles[229], 83, 87, 88);
	Face_Set(&map_new_wall->triangles[230], 87, 85, 86);
	Face_Set(&map_new_wall->triangles[231], 85, 81, 82);
	Face_Set(&map_new_wall->triangles[232], 83, 81, 85);
	Face_Set(&map_new_wall->triangles[233], 88, 86, 82);
	Face_Set(&map_new_wall->triangles[234], 89, 91, 92);
	Face_Set(&map_new_wall->triangles[235], 91, 95, 96);
	Face_Set(&map_new_wall->triangles[236], 95, 93, 94);
	Face_Set(&map_new_wall->triangles[237], 93, 89, 90);
	Face_Set(&map_new_wall->triangles[238], 91, 89, 93);
	Face_Set(&map_new_wall->triangles[239], 96, 94, 90);
	Face_Set(&map_new_wall->triangles[240], 97, 99, 100);
	Face_Set(&map_new_wall->triangles[241], 99, 103, 104);
	Face_Set(&map_new_wall->triangles[242], 103, 101, 102);
	Face_Set(&map_new_wall->triangles[243], 101, 97, 98);
	Face_Set(&map_new_wall->triangles[244], 99, 97, 101);
	Face_Set(&map_new_wall->triangles[245], 104, 102, 98);
	Face_Set(&map_new_wall->triangles[246], 105, 107, 108);
	Face_Set(&map_new_wall->triangles[247], 107, 111, 112);
	Face_Set(&map_new_wall->triangles[248], 111, 109, 110);
	Face_Set(&map_new_wall->triangles[249], 109, 105, 106);
	Face_Set(&map_new_wall->triangles[250], 107, 105, 109);
	Face_Set(&map_new_wall->triangles[251], 112, 110, 106);
	Face_Set(&map_new_wall->triangles[252], 113, 115, 116);
	Face_Set(&map_new_wall->triangles[253], 115, 119, 120);
	Face_Set(&map_new_wall->triangles[254], 119, 117, 118);
	Face_Set(&map_new_wall->triangles[255], 117, 113, 114);
	Face_Set(&map_new_wall->triangles[256], 115, 113, 117);
	Face_Set(&map_new_wall->triangles[257], 120, 118, 114);
	Face_Set(&map_new_wall->triangles[258], 121, 123, 124);
	Face_Set(&map_new_wall->triangles[259], 123, 127, 128);
	Face_Set(&map_new_wall->triangles[260], 127, 125, 126);
	Face_Set(&map_new_wall->triangles[261], 125, 121, 122);
	Face_Set(&map_new_wall->triangles[262], 123, 121, 125);
	Face_Set(&map_new_wall->triangles[263], 128, 126, 122);
	Face_Set(&map_new_wall->triangles[264], 129, 131, 132);
	Face_Set(&map_new_wall->triangles[265], 131, 135, 136);
	Face_Set(&map_new_wall->triangles[266], 135, 133, 134);
	Face_Set(&map_new_wall->triangles[267], 133, 129, 130);
	Face_Set(&map_new_wall->triangles[268], 131, 129, 133);
	Face_Set(&map_new_wall->triangles[269], 136, 134, 130);
	Face_Set(&map_new_wall->triangles[270], 137, 139, 140);
	Face_Set(&map_new_wall->triangles[271], 139, 143, 144);
	Face_Set(&map_new_wall->triangles[272], 143, 141, 142);
	Face_Set(&map_new_wall->triangles[273], 141, 137, 138);
	Face_Set(&map_new_wall->triangles[274], 139, 137, 141);
	Face_Set(&map_new_wall->triangles[275], 144, 142, 138);
	Face_Set(&map_new_wall->triangles[276], 145, 147, 148);
	Face_Set(&map_new_wall->triangles[277], 147, 151, 152);
	Face_Set(&map_new_wall->triangles[278], 151, 149, 150);
	Face_Set(&map_new_wall->triangles[279], 149, 145, 146);
	Face_Set(&map_new_wall->triangles[280], 147, 145, 149);
	Face_Set(&map_new_wall->triangles[281], 152, 150, 146);
	Face_Set(&map_new_wall->triangles[282], 153, 155, 156);
	Face_Set(&map_new_wall->triangles[283], 155, 159, 160);
	Face_Set(&map_new_wall->triangles[284], 159, 157, 158);
	Face_Set(&map_new_wall->triangles[285], 157, 153, 154);
	Face_Set(&map_new_wall->triangles[286], 155, 153, 157);
	Face_Set(&map_new_wall->triangles[287], 160, 158, 154);
	Face_Set(&map_new_wall->triangles[288], 161, 163, 164);
	Face_Set(&map_new_wall->triangles[289], 163, 167, 168);
	Face_Set(&map_new_wall->triangles[290], 167, 165, 166);
	Face_Set(&map_new_wall->triangles[291], 165, 161, 162);
	Face_Set(&map_new_wall->triangles[292], 163, 161, 165);
	Face_Set(&map_new_wall->triangles[293], 168, 166, 162);
	Face_Set(&map_new_wall->triangles[294], 169, 171, 172);
	Face_Set(&map_new_wall->triangles[295], 171, 175, 176);
	Face_Set(&map_new_wall->triangles[296], 175, 173, 174);
	Face_Set(&map_new_wall->triangles[297], 173, 169, 170);
	Face_Set(&map_new_wall->triangles[298], 171, 169, 173);
	Face_Set(&map_new_wall->triangles[299], 176, 174, 170);
	Face_Set(&map_new_wall->triangles[300], 177, 179, 180);
	Face_Set(&map_new_wall->triangles[301], 179, 183, 184);
	Face_Set(&map_new_wall->triangles[302], 183, 181, 182);
	Face_Set(&map_new_wall->triangles[303], 181, 177, 178);
	Face_Set(&map_new_wall->triangles[304], 179, 177, 181);
	Face_Set(&map_new_wall->triangles[305], 184, 182, 178);
	Face_Set(&map_new_wall->triangles[306], 185, 187, 188);
	Face_Set(&map_new_wall->triangles[307], 187, 191, 192);
	Face_Set(&map_new_wall->triangles[308], 191, 189, 190);
	Face_Set(&map_new_wall->triangles[309], 189, 185, 186);
	Face_Set(&map_new_wall->triangles[310], 187, 185, 189);
	Face_Set(&map_new_wall->triangles[311], 192, 190, 186);
	Face_Set(&map_new_wall->triangles[312], 193, 195, 196);
	Face_Set(&map_new_wall->triangles[313], 195, 199, 200);
	Face_Set(&map_new_wall->triangles[314], 199, 197, 198);
	Face_Set(&map_new_wall->triangles[315], 197, 193, 194);
	Face_Set(&map_new_wall->triangles[316], 195, 193, 197);
	Face_Set(&map_new_wall->triangles[317], 200, 198, 194);
	Face_Set(&map_new_wall->triangles[318], 201, 203, 204);
	Face_Set(&map_new_wall->triangles[319], 203, 207, 208);
	Face_Set(&map_new_wall->triangles[320], 207, 205, 206);
	Face_Set(&map_new_wall->triangles[321], 205, 201, 202);
	Face_Set(&map_new_wall->triangles[322], 203, 201, 205);
	Face_Set(&map_new_wall->triangles[323], 208, 206, 202);
	Face_Set(&map_new_wall->triangles[324], 209, 211, 212);
	Face_Set(&map_new_wall->triangles[325], 211, 215, 216);
	Face_Set(&map_new_wall->triangles[326], 215, 213, 214);
	Face_Set(&map_new_wall->triangles[327], 213, 209, 210);
	Face_Set(&map_new_wall->triangles[328], 211, 209, 213);
	Face_Set(&map_new_wall->triangles[329], 216, 214, 210);
	Face_Set(&map_new_wall->triangles[330], 217, 219, 220);
	Face_Set(&map_new_wall->triangles[331], 219, 223, 224);
	Face_Set(&map_new_wall->triangles[332], 223, 221, 222);
	Face_Set(&map_new_wall->triangles[333], 221, 217, 218);
	Face_Set(&map_new_wall->triangles[334], 219, 217, 221);
	Face_Set(&map_new_wall->triangles[335], 224, 222, 218);
}

struct Mesh* ModelMap_new_Wall_New() {
	struct Mesh *map_new_wall= New_Mesh(336, 224);
	ModelMap_new_Wall_Init(map_new_wall);
	return map_new_wall;
}
