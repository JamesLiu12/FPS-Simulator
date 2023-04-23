#include "../mesh.h"

void ModelMap_new_EndGate_Init(struct Mesh *map_new_endgate) {
	Vector3_Set(&map_new_endgate->vertices[0], 57.484146, 4.8842e-2, -3.600599);
	Vector3_Set(&map_new_endgate->vertices[1], 57.484146, 4.108842, -3.600599);
	Vector3_Set(&map_new_endgate->vertices[2], 57.484146, 4.8842e-2, 3.399401);
	Vector3_Set(&map_new_endgate->vertices[3], 57.484146, 4.108842, 3.399401);
	Vector3_Set(&map_new_endgate->vertices[4], 58.14415, 4.8842e-2, -3.600599);
	Vector3_Set(&map_new_endgate->vertices[5], 58.14415, 4.108842, -3.600599);
	Vector3_Set(&map_new_endgate->vertices[6], 58.14415, 4.8842e-2, 3.399401);
	Vector3_Set(&map_new_endgate->vertices[7], 58.14415, 4.108842, 3.399401);

	Face_Set(&map_new_endgate->triangles[0], 1, 2, 4);
	Face_Set(&map_new_endgate->triangles[1], 3, 4, 8);
	Face_Set(&map_new_endgate->triangles[2], 7, 8, 6);
	Face_Set(&map_new_endgate->triangles[3], 5, 6, 2);
	Face_Set(&map_new_endgate->triangles[4], 3, 7, 5);
	Face_Set(&map_new_endgate->triangles[5], 8, 4, 2);
	Face_Set(&map_new_endgate->triangles[6], 1, 3, 4);
	Face_Set(&map_new_endgate->triangles[7], 3, 7, 8);
	Face_Set(&map_new_endgate->triangles[8], 7, 5, 6);
	Face_Set(&map_new_endgate->triangles[9], 5, 1, 2);
	Face_Set(&map_new_endgate->triangles[10], 3, 1, 5);
	Face_Set(&map_new_endgate->triangles[11], 8, 6, 2);
}

struct Mesh* ModelMap_new_EndGate_New() {
	struct Mesh *map_new_endgate= New_Mesh(12, 8);
	ModelMap_new_EndGate_Init(map_new_endgate);
	return map_new_endgate;
}
