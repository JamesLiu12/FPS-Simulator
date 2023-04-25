#include "map_new_Wall.h"

void ModelMap_new_Wall_Init(struct Mesh *map_new_wall) {
	Vector3_Set(&map_new_wall->vertices[0], -20.0, -19.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[1], -20.0, -19.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[2], -20.0, -20.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[3], -20.0, -20.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[4], 60.0, -19.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[5], 60.0, -19.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[6], 60.0, -20.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[7], 60.0, -20.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[8], -20.0, 20.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[9], -20.0, 20.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[10], -20.0, 19.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[11], -20.0, 19.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[12], 60.0, 20.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[13], 60.0, 20.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[14], 60.0, 19.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[15], 60.0, 19.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[16], -19.9, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[17], -19.9, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[18], -20.099998, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[19], -20.099998, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[20], -19.900002, -20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[21], -19.900002, -20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[22], -20.1, -20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[23], -20.1, -20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[24], 60.100002, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[25], 60.100002, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[26], 59.900002, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[27], 59.900002, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[28], 60.099998, -20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[29], 60.099998, -20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[30], 59.899998, -20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[31], 59.899998, -20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[32], -14.9, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[33], -14.9, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[34], -15.099999, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[35], -15.099999, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[36], -14.900001, -10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[37], -14.900001, -10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[38], -15.1, -10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[39], -15.1, -10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[40], 10.0, -14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[41], 10.0, -14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[42], 10.0, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[43], 10.0, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[44], 50.0, -14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[45], 50.0, -14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[46], 50.0, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[47], 50.0, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[48], -4.025483, 14.666904, 0.0);
	Vector3_Set(&map_new_wall->vertices[49], -4.025483, 14.666904, 2.5);
	Vector3_Set(&map_new_wall->vertices[50], -4.166904, 14.525483, 0.0);
	Vector3_Set(&map_new_wall->vertices[51], -4.166904, 14.525483, 2.5);
	Vector3_Set(&map_new_wall->vertices[52], 5.166904, 5.474517, 0.0);
	Vector3_Set(&map_new_wall->vertices[53], 5.166904, 5.474517, 2.5);
	Vector3_Set(&map_new_wall->vertices[54], 5.025483, 5.333096, 0.0);
	Vector3_Set(&map_new_wall->vertices[55], 5.025483, 5.333096, 2.5);
	Vector3_Set(&map_new_wall->vertices[56], -8.874012, -1.73259, 0.0);
	Vector3_Set(&map_new_wall->vertices[57], -8.874012, -1.73259, 2.5);
	Vector3_Set(&map_new_wall->vertices[58], -8.73259, -1.874012, 0.0);
	Vector3_Set(&map_new_wall->vertices[59], -8.73259, -1.874012, 2.5);
	Vector3_Set(&map_new_wall->vertices[60], 1.73259, 8.874012, 0.0);
	Vector3_Set(&map_new_wall->vertices[61], 1.73259, 8.874012, 2.5);
	Vector3_Set(&map_new_wall->vertices[62], 1.874012, 8.73259, 0.0);
	Vector3_Set(&map_new_wall->vertices[63], 1.874012, 8.73259, 2.5);
	Vector3_Set(&map_new_wall->vertices[64], 10.1, -6.05, 0.0);
	Vector3_Set(&map_new_wall->vertices[65], 10.1, -6.05, 2.5);
	Vector3_Set(&map_new_wall->vertices[66], 9.900001, -6.05, 0.0);
	Vector3_Set(&map_new_wall->vertices[67], 9.900001, -6.05, 2.5);
	Vector3_Set(&map_new_wall->vertices[68], 10.099999, -15.05, 0.0);
	Vector3_Set(&map_new_wall->vertices[69], 10.099999, -15.05, 2.5);
	Vector3_Set(&map_new_wall->vertices[70], 9.9, -15.05, 0.0);
	Vector3_Set(&map_new_wall->vertices[71], 9.9, -15.05, 2.5);
	Vector3_Set(&map_new_wall->vertices[72], -10.0, 15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[73], -10.0, 15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[74], -10.0, 14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[75], -10.0, 14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[76], 6.0, 15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[77], 6.0, 15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[78], 6.0, 14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[79], 6.0, 14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[80], 10.1, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[81], 10.1, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[82], 9.900001, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[83], 9.900001, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[84], 10.099999, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[85], 10.099999, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[86], 9.9, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[87], 9.9, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[88], 57.484146, 3.600599, 4.8842e-2);
	Vector3_Set(&map_new_wall->vertices[89], 57.484146, 3.600599, 4.108842);
	Vector3_Set(&map_new_wall->vertices[90], 57.484146, -3.399401, 4.8842e-2);
	Vector3_Set(&map_new_wall->vertices[91], 57.484146, -3.399401, 4.108842);
	Vector3_Set(&map_new_wall->vertices[92], 58.14415, 3.600599, 4.8842e-2);
	Vector3_Set(&map_new_wall->vertices[93], 58.14415, 3.600599, 4.108842);
	Vector3_Set(&map_new_wall->vertices[94], 58.14415, -3.399401, 4.8842e-2);
	Vector3_Set(&map_new_wall->vertices[95], 58.14415, -3.399401, 4.108842);
	Vector3_Set(&map_new_wall->vertices[96], 20.0, 15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[97], 20.0, 15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[98], 20.0, 14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[99], 20.0, 14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[100], 60.0, 15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[101], 60.0, 15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[102], 60.0, 14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[103], 60.0, 14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[104], 10.0, 10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[105], 10.0, 10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[106], 10.0, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[107], 10.0, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[108], 15.0, 10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[109], 15.0, 10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[110], 15.0, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[111], 15.0, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[112], 15.1, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[113], 15.1, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[114], 14.900001, 20.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[115], 14.900001, 20.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[116], 15.099999, -10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[117], 15.099999, -10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[118], 14.9, -10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[119], 14.9, -10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[120], 20.1, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[121], 20.1, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[122], 19.9, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[123], 19.9, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[124], 20.1, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[125], 20.1, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[126], 19.9, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[127], 19.9, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[128], 50.100002, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[129], 50.100002, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[130], 49.900002, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[131], 49.900002, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[132], 50.099998, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[133], 50.099998, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[134], 49.899998, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[135], 49.899998, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[136], -11.477313, -11.035891, 0.0);
	Vector3_Set(&map_new_wall->vertices[137], -11.477313, -11.035891, 2.5);
	Vector3_Set(&map_new_wall->vertices[138], -11.335891, -11.177313, 0.0);
	Vector3_Set(&map_new_wall->vertices[139], -11.335891, -11.177313, 2.5);
	Vector3_Set(&map_new_wall->vertices[140], 9.73589, 10.177313, 0.0);
	Vector3_Set(&map_new_wall->vertices[141], 9.73589, 10.177313, 2.5);
	Vector3_Set(&map_new_wall->vertices[142], 9.877313, 10.035891, 0.0);
	Vector3_Set(&map_new_wall->vertices[143], 9.877313, 10.035891, 2.5);
	Vector3_Set(&map_new_wall->vertices[144], 25.1, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[145], 25.1, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[146], 24.9, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[147], 24.9, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[148], 25.1, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[149], 25.1, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[150], 24.9, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[151], 24.9, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[152], 15.0, -9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[153], 15.0, -9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[154], 15.0, -10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[155], 15.0, -10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[156], 45.0, -9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[157], 45.0, -9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[158], 45.0, -10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[159], 45.0, -10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[160], 45.100002, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[161], 45.100002, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[162], 44.900002, 15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[163], 44.900002, 15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[164], 45.099998, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[165], 45.099998, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[166], 44.899998, -5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[167], 44.899998, -5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[168], 25.0, -4.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[169], 25.0, -4.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[170], 25.0, -5.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[171], 25.0, -5.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[172], 45.0, -4.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[173], 45.0, -4.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[174], 45.0, -5.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[175], 45.0, -5.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[176], 25.0, 10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[177], 25.0, 10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[178], 25.0, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[179], 25.0, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[180], 40.0, 10.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[181], 40.0, 10.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[182], 40.0, 9.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[183], 40.0, 9.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[184], 40.099998, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[185], 40.099998, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[186], 39.900002, 10.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[187], 39.900002, 10.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[188], 40.099998, 0.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[189], 40.099998, 0.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[190], 39.900002, 0.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[191], 39.900002, 0.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[192], 30.0, 0.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[193], 30.0, 0.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[194], 30.0, -0.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[195], 30.0, -0.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[196], 40.0, 0.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[197], 40.0, 0.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[198], 40.0, -0.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[199], 40.0, -0.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[200], 30.1, 5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[201], 30.1, 5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[202], 29.9, 5.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[203], 29.9, 5.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[204], 30.1, 0.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[205], 30.1, 0.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[206], 29.9, 0.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[207], 29.9, 0.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[208], 30.0, 5.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[209], 30.0, 5.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[210], 30.0, 4.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[211], 30.0, 4.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[212], 35.0, 5.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[213], 35.0, 5.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[214], 35.0, 4.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[215], 35.0, 4.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[216], -9.3, -14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[217], -9.3, -14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[218], -9.3, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[219], -9.3, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[220], 6.7, -14.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[221], 6.7, -14.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[222], 6.7, -15.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[223], 6.7, -15.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[224], 6.9, -11.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[225], 6.9, -11.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[226], 6.9, -12.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[227], 6.9, -12.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[228], 9.9, -11.9, 0.0);
	Vector3_Set(&map_new_wall->vertices[229], 9.9, -11.9, 2.5);
	Vector3_Set(&map_new_wall->vertices[230], 9.9, -12.1, 0.0);
	Vector3_Set(&map_new_wall->vertices[231], 9.9, -12.1, 2.5);
	Vector3_Set(&map_new_wall->vertices[232], 6.9, -12.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[233], 6.9, -12.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[234], 6.7, -12.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[235], 6.7, -12.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[236], 6.9, -15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[237], 6.9, -15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[238], 6.7, -15.0, 0.0);
	Vector3_Set(&map_new_wall->vertices[239], 6.7, -15.0, 2.5);
	Vector3_Set(&map_new_wall->vertices[240], -1.663397, -4.918911, 0.0);
	Vector3_Set(&map_new_wall->vertices[241], -1.663397, -4.918911, 2.5);
	Vector3_Set(&map_new_wall->vertices[242], -1.836602, -5.018911, 0.0);
	Vector3_Set(&map_new_wall->vertices[243], -1.836602, -5.018911, 2.5);
	Vector3_Set(&map_new_wall->vertices[244], 1.836602, -10.981089, 0.0);
	Vector3_Set(&map_new_wall->vertices[245], 1.836602, -10.981089, 2.5);
	Vector3_Set(&map_new_wall->vertices[246], 1.663397, -11.081089, 0.0);
	Vector3_Set(&map_new_wall->vertices[247], 1.663397, -11.081089, 2.5);

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
	Face_Set(&map_new_wall->triangles[168], 225, 226, 228);
	Face_Set(&map_new_wall->triangles[169], 227, 228, 232);
	Face_Set(&map_new_wall->triangles[170], 231, 232, 230);
	Face_Set(&map_new_wall->triangles[171], 229, 230, 226);
	Face_Set(&map_new_wall->triangles[172], 227, 231, 229);
	Face_Set(&map_new_wall->triangles[173], 232, 228, 226);
	Face_Set(&map_new_wall->triangles[174], 233, 234, 236);
	Face_Set(&map_new_wall->triangles[175], 235, 236, 240);
	Face_Set(&map_new_wall->triangles[176], 239, 240, 238);
	Face_Set(&map_new_wall->triangles[177], 237, 238, 234);
	Face_Set(&map_new_wall->triangles[178], 235, 239, 237);
	Face_Set(&map_new_wall->triangles[179], 240, 236, 234);
	Face_Set(&map_new_wall->triangles[180], 241, 242, 244);
	Face_Set(&map_new_wall->triangles[181], 243, 244, 248);
	Face_Set(&map_new_wall->triangles[182], 247, 248, 246);
	Face_Set(&map_new_wall->triangles[183], 245, 246, 242);
	Face_Set(&map_new_wall->triangles[184], 243, 247, 245);
	Face_Set(&map_new_wall->triangles[185], 248, 244, 242);
	Face_Set(&map_new_wall->triangles[186], 1, 3, 4);
	Face_Set(&map_new_wall->triangles[187], 3, 7, 8);
	Face_Set(&map_new_wall->triangles[188], 7, 5, 6);
	Face_Set(&map_new_wall->triangles[189], 5, 1, 2);
	Face_Set(&map_new_wall->triangles[190], 3, 1, 5);
	Face_Set(&map_new_wall->triangles[191], 8, 6, 2);
	Face_Set(&map_new_wall->triangles[192], 9, 11, 12);
	Face_Set(&map_new_wall->triangles[193], 11, 15, 16);
	Face_Set(&map_new_wall->triangles[194], 15, 13, 14);
	Face_Set(&map_new_wall->triangles[195], 13, 9, 10);
	Face_Set(&map_new_wall->triangles[196], 11, 9, 13);
	Face_Set(&map_new_wall->triangles[197], 16, 14, 10);
	Face_Set(&map_new_wall->triangles[198], 17, 19, 20);
	Face_Set(&map_new_wall->triangles[199], 19, 23, 24);
	Face_Set(&map_new_wall->triangles[200], 23, 21, 22);
	Face_Set(&map_new_wall->triangles[201], 21, 17, 18);
	Face_Set(&map_new_wall->triangles[202], 19, 17, 21);
	Face_Set(&map_new_wall->triangles[203], 24, 22, 18);
	Face_Set(&map_new_wall->triangles[204], 25, 27, 28);
	Face_Set(&map_new_wall->triangles[205], 27, 31, 32);
	Face_Set(&map_new_wall->triangles[206], 31, 29, 30);
	Face_Set(&map_new_wall->triangles[207], 29, 25, 26);
	Face_Set(&map_new_wall->triangles[208], 27, 25, 29);
	Face_Set(&map_new_wall->triangles[209], 32, 30, 26);
	Face_Set(&map_new_wall->triangles[210], 33, 35, 36);
	Face_Set(&map_new_wall->triangles[211], 35, 39, 40);
	Face_Set(&map_new_wall->triangles[212], 39, 37, 38);
	Face_Set(&map_new_wall->triangles[213], 37, 33, 34);
	Face_Set(&map_new_wall->triangles[214], 35, 33, 37);
	Face_Set(&map_new_wall->triangles[215], 40, 38, 34);
	Face_Set(&map_new_wall->triangles[216], 41, 43, 44);
	Face_Set(&map_new_wall->triangles[217], 43, 47, 48);
	Face_Set(&map_new_wall->triangles[218], 47, 45, 46);
	Face_Set(&map_new_wall->triangles[219], 45, 41, 42);
	Face_Set(&map_new_wall->triangles[220], 43, 41, 45);
	Face_Set(&map_new_wall->triangles[221], 48, 46, 42);
	Face_Set(&map_new_wall->triangles[222], 49, 51, 52);
	Face_Set(&map_new_wall->triangles[223], 51, 55, 56);
	Face_Set(&map_new_wall->triangles[224], 55, 53, 54);
	Face_Set(&map_new_wall->triangles[225], 53, 49, 50);
	Face_Set(&map_new_wall->triangles[226], 51, 49, 53);
	Face_Set(&map_new_wall->triangles[227], 56, 54, 50);
	Face_Set(&map_new_wall->triangles[228], 57, 59, 60);
	Face_Set(&map_new_wall->triangles[229], 59, 63, 64);
	Face_Set(&map_new_wall->triangles[230], 63, 61, 62);
	Face_Set(&map_new_wall->triangles[231], 61, 57, 58);
	Face_Set(&map_new_wall->triangles[232], 59, 57, 61);
	Face_Set(&map_new_wall->triangles[233], 64, 62, 58);
	Face_Set(&map_new_wall->triangles[234], 65, 67, 68);
	Face_Set(&map_new_wall->triangles[235], 67, 71, 72);
	Face_Set(&map_new_wall->triangles[236], 71, 69, 70);
	Face_Set(&map_new_wall->triangles[237], 69, 65, 66);
	Face_Set(&map_new_wall->triangles[238], 67, 65, 69);
	Face_Set(&map_new_wall->triangles[239], 72, 70, 66);
	Face_Set(&map_new_wall->triangles[240], 73, 75, 76);
	Face_Set(&map_new_wall->triangles[241], 75, 79, 80);
	Face_Set(&map_new_wall->triangles[242], 79, 77, 78);
	Face_Set(&map_new_wall->triangles[243], 77, 73, 74);
	Face_Set(&map_new_wall->triangles[244], 75, 73, 77);
	Face_Set(&map_new_wall->triangles[245], 80, 78, 74);
	Face_Set(&map_new_wall->triangles[246], 81, 83, 84);
	Face_Set(&map_new_wall->triangles[247], 83, 87, 88);
	Face_Set(&map_new_wall->triangles[248], 87, 85, 86);
	Face_Set(&map_new_wall->triangles[249], 85, 81, 82);
	Face_Set(&map_new_wall->triangles[250], 83, 81, 85);
	Face_Set(&map_new_wall->triangles[251], 88, 86, 82);
	Face_Set(&map_new_wall->triangles[252], 89, 91, 92);
	Face_Set(&map_new_wall->triangles[253], 91, 95, 96);
	Face_Set(&map_new_wall->triangles[254], 95, 93, 94);
	Face_Set(&map_new_wall->triangles[255], 93, 89, 90);
	Face_Set(&map_new_wall->triangles[256], 91, 89, 93);
	Face_Set(&map_new_wall->triangles[257], 96, 94, 90);
	Face_Set(&map_new_wall->triangles[258], 97, 99, 100);
	Face_Set(&map_new_wall->triangles[259], 99, 103, 104);
	Face_Set(&map_new_wall->triangles[260], 103, 101, 102);
	Face_Set(&map_new_wall->triangles[261], 101, 97, 98);
	Face_Set(&map_new_wall->triangles[262], 99, 97, 101);
	Face_Set(&map_new_wall->triangles[263], 104, 102, 98);
	Face_Set(&map_new_wall->triangles[264], 105, 107, 108);
	Face_Set(&map_new_wall->triangles[265], 107, 111, 112);
	Face_Set(&map_new_wall->triangles[266], 111, 109, 110);
	Face_Set(&map_new_wall->triangles[267], 109, 105, 106);
	Face_Set(&map_new_wall->triangles[268], 107, 105, 109);
	Face_Set(&map_new_wall->triangles[269], 112, 110, 106);
	Face_Set(&map_new_wall->triangles[270], 113, 115, 116);
	Face_Set(&map_new_wall->triangles[271], 115, 119, 120);
	Face_Set(&map_new_wall->triangles[272], 119, 117, 118);
	Face_Set(&map_new_wall->triangles[273], 117, 113, 114);
	Face_Set(&map_new_wall->triangles[274], 115, 113, 117);
	Face_Set(&map_new_wall->triangles[275], 120, 118, 114);
	Face_Set(&map_new_wall->triangles[276], 121, 123, 124);
	Face_Set(&map_new_wall->triangles[277], 123, 127, 128);
	Face_Set(&map_new_wall->triangles[278], 127, 125, 126);
	Face_Set(&map_new_wall->triangles[279], 125, 121, 122);
	Face_Set(&map_new_wall->triangles[280], 123, 121, 125);
	Face_Set(&map_new_wall->triangles[281], 128, 126, 122);
	Face_Set(&map_new_wall->triangles[282], 129, 131, 132);
	Face_Set(&map_new_wall->triangles[283], 131, 135, 136);
	Face_Set(&map_new_wall->triangles[284], 135, 133, 134);
	Face_Set(&map_new_wall->triangles[285], 133, 129, 130);
	Face_Set(&map_new_wall->triangles[286], 131, 129, 133);
	Face_Set(&map_new_wall->triangles[287], 136, 134, 130);
	Face_Set(&map_new_wall->triangles[288], 137, 139, 140);
	Face_Set(&map_new_wall->triangles[289], 139, 143, 144);
	Face_Set(&map_new_wall->triangles[290], 143, 141, 142);
	Face_Set(&map_new_wall->triangles[291], 141, 137, 138);
	Face_Set(&map_new_wall->triangles[292], 139, 137, 141);
	Face_Set(&map_new_wall->triangles[293], 144, 142, 138);
	Face_Set(&map_new_wall->triangles[294], 145, 147, 148);
	Face_Set(&map_new_wall->triangles[295], 147, 151, 152);
	Face_Set(&map_new_wall->triangles[296], 151, 149, 150);
	Face_Set(&map_new_wall->triangles[297], 149, 145, 146);
	Face_Set(&map_new_wall->triangles[298], 147, 145, 149);
	Face_Set(&map_new_wall->triangles[299], 152, 150, 146);
	Face_Set(&map_new_wall->triangles[300], 153, 155, 156);
	Face_Set(&map_new_wall->triangles[301], 155, 159, 160);
	Face_Set(&map_new_wall->triangles[302], 159, 157, 158);
	Face_Set(&map_new_wall->triangles[303], 157, 153, 154);
	Face_Set(&map_new_wall->triangles[304], 155, 153, 157);
	Face_Set(&map_new_wall->triangles[305], 160, 158, 154);
	Face_Set(&map_new_wall->triangles[306], 161, 163, 164);
	Face_Set(&map_new_wall->triangles[307], 163, 167, 168);
	Face_Set(&map_new_wall->triangles[308], 167, 165, 166);
	Face_Set(&map_new_wall->triangles[309], 165, 161, 162);
	Face_Set(&map_new_wall->triangles[310], 163, 161, 165);
	Face_Set(&map_new_wall->triangles[311], 168, 166, 162);
	Face_Set(&map_new_wall->triangles[312], 169, 171, 172);
	Face_Set(&map_new_wall->triangles[313], 171, 175, 176);
	Face_Set(&map_new_wall->triangles[314], 175, 173, 174);
	Face_Set(&map_new_wall->triangles[315], 173, 169, 170);
	Face_Set(&map_new_wall->triangles[316], 171, 169, 173);
	Face_Set(&map_new_wall->triangles[317], 176, 174, 170);
	Face_Set(&map_new_wall->triangles[318], 177, 179, 180);
	Face_Set(&map_new_wall->triangles[319], 179, 183, 184);
	Face_Set(&map_new_wall->triangles[320], 183, 181, 182);
	Face_Set(&map_new_wall->triangles[321], 181, 177, 178);
	Face_Set(&map_new_wall->triangles[322], 179, 177, 181);
	Face_Set(&map_new_wall->triangles[323], 184, 182, 178);
	Face_Set(&map_new_wall->triangles[324], 185, 187, 188);
	Face_Set(&map_new_wall->triangles[325], 187, 191, 192);
	Face_Set(&map_new_wall->triangles[326], 191, 189, 190);
	Face_Set(&map_new_wall->triangles[327], 189, 185, 186);
	Face_Set(&map_new_wall->triangles[328], 187, 185, 189);
	Face_Set(&map_new_wall->triangles[329], 192, 190, 186);
	Face_Set(&map_new_wall->triangles[330], 193, 195, 196);
	Face_Set(&map_new_wall->triangles[331], 195, 199, 200);
	Face_Set(&map_new_wall->triangles[332], 199, 197, 198);
	Face_Set(&map_new_wall->triangles[333], 197, 193, 194);
	Face_Set(&map_new_wall->triangles[334], 195, 193, 197);
	Face_Set(&map_new_wall->triangles[335], 200, 198, 194);
	Face_Set(&map_new_wall->triangles[336], 201, 203, 204);
	Face_Set(&map_new_wall->triangles[337], 203, 207, 208);
	Face_Set(&map_new_wall->triangles[338], 207, 205, 206);
	Face_Set(&map_new_wall->triangles[339], 205, 201, 202);
	Face_Set(&map_new_wall->triangles[340], 203, 201, 205);
	Face_Set(&map_new_wall->triangles[341], 208, 206, 202);
	Face_Set(&map_new_wall->triangles[342], 209, 211, 212);
	Face_Set(&map_new_wall->triangles[343], 211, 215, 216);
	Face_Set(&map_new_wall->triangles[344], 215, 213, 214);
	Face_Set(&map_new_wall->triangles[345], 213, 209, 210);
	Face_Set(&map_new_wall->triangles[346], 211, 209, 213);
	Face_Set(&map_new_wall->triangles[347], 216, 214, 210);
	Face_Set(&map_new_wall->triangles[348], 217, 219, 220);
	Face_Set(&map_new_wall->triangles[349], 219, 223, 224);
	Face_Set(&map_new_wall->triangles[350], 223, 221, 222);
	Face_Set(&map_new_wall->triangles[351], 221, 217, 218);
	Face_Set(&map_new_wall->triangles[352], 219, 217, 221);
	Face_Set(&map_new_wall->triangles[353], 224, 222, 218);
	Face_Set(&map_new_wall->triangles[354], 225, 227, 228);
	Face_Set(&map_new_wall->triangles[355], 227, 231, 232);
	Face_Set(&map_new_wall->triangles[356], 231, 229, 230);
	Face_Set(&map_new_wall->triangles[357], 229, 225, 226);
	Face_Set(&map_new_wall->triangles[358], 227, 225, 229);
	Face_Set(&map_new_wall->triangles[359], 232, 230, 226);
	Face_Set(&map_new_wall->triangles[360], 233, 235, 236);
	Face_Set(&map_new_wall->triangles[361], 235, 239, 240);
	Face_Set(&map_new_wall->triangles[362], 239, 237, 238);
	Face_Set(&map_new_wall->triangles[363], 237, 233, 234);
	Face_Set(&map_new_wall->triangles[364], 235, 233, 237);
	Face_Set(&map_new_wall->triangles[365], 240, 238, 234);
	Face_Set(&map_new_wall->triangles[366], 241, 243, 244);
	Face_Set(&map_new_wall->triangles[367], 243, 247, 248);
	Face_Set(&map_new_wall->triangles[368], 247, 245, 246);
	Face_Set(&map_new_wall->triangles[369], 245, 241, 242);
	Face_Set(&map_new_wall->triangles[370], 243, 241, 245);
	Face_Set(&map_new_wall->triangles[371], 248, 246, 242);
}

struct Mesh* ModelMap_new_Wall_New() {
	struct Mesh *map_new_wall= New_Mesh(372, 248);
	ModelMap_new_Wall_Init(map_new_wall);
	return map_new_wall;
}
