#include "wall.h"

void ModelWall_Init(struct Mesh *wall) {
	Vector3_Set(&wall->vertices[0], 3.1, 0.0, 7.29);
	Vector3_Set(&wall->vertices[1], 3.1, 2.5, 7.29);
	Vector3_Set(&wall->vertices[2], 2.9, 0.0, 7.29);
	Vector3_Set(&wall->vertices[3], 2.9, 2.5, 7.29);
	Vector3_Set(&wall->vertices[4], 3.1, 0.0, -4.71);
	Vector3_Set(&wall->vertices[5], 3.1, 2.5, -4.71);
	Vector3_Set(&wall->vertices[6], 2.9, 0.0, -4.71);
	Vector3_Set(&wall->vertices[7], 2.9, 2.5, -4.71);
	Vector3_Set(&wall->vertices[8], -2.9, 0.0, 4.59);
	Vector3_Set(&wall->vertices[9], -2.9, 2.5, 4.59);
	Vector3_Set(&wall->vertices[10], -3.1, 0.0, 4.59);
	Vector3_Set(&wall->vertices[11], -3.1, 2.5, 4.59);
	Vector3_Set(&wall->vertices[12], -2.9, 0.0, -7.41);
	Vector3_Set(&wall->vertices[13], -2.9, 2.5, -7.41);
	Vector3_Set(&wall->vertices[14], -3.1, 0.0, -7.41);
	Vector3_Set(&wall->vertices[15], -3.1, 2.5, -7.41);

	Face_Set(&wall->triangles[0], 1, 2, 4);
	Face_Set(&wall->triangles[1], 3, 4, 8);
	Face_Set(&wall->triangles[2], 7, 8, 6);
	Face_Set(&wall->triangles[3], 5, 6, 2);
	Face_Set(&wall->triangles[4], 3, 7, 5);
	Face_Set(&wall->triangles[5], 8, 4, 2);
	Face_Set(&wall->triangles[6], 9, 10, 12);
	Face_Set(&wall->triangles[7], 11, 12, 16);
	Face_Set(&wall->triangles[8], 15, 16, 14);
	Face_Set(&wall->triangles[9], 13, 14, 10);
	Face_Set(&wall->triangles[10], 11, 15, 13);
	Face_Set(&wall->triangles[11], 16, 12, 10);
	Face_Set(&wall->triangles[12], 1, 3, 4);
	Face_Set(&wall->triangles[13], 3, 7, 8);
	Face_Set(&wall->triangles[14], 7, 5, 6);
	Face_Set(&wall->triangles[15], 5, 1, 2);
	Face_Set(&wall->triangles[16], 3, 1, 5);
	Face_Set(&wall->triangles[17], 8, 6, 2);
	Face_Set(&wall->triangles[18], 9, 11, 12);
	Face_Set(&wall->triangles[19], 11, 15, 16);
	Face_Set(&wall->triangles[20], 15, 13, 14);
	Face_Set(&wall->triangles[21], 13, 9, 10);
	Face_Set(&wall->triangles[22], 11, 9, 13);
	Face_Set(&wall->triangles[23], 16, 14, 10);
}

struct Mesh* ModelWall_New() {
	struct Mesh *wall= New_Mesh(24, 16);
	ModelWall_Init(wall);
	return wall;
}
