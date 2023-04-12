#include "../mesh.h"

void ModelWall123_Init(struct Mesh *wall123) {
	Vector3_Set(&wall123->vertices[0], 3.1, 0.0, 7.29);
	Vector3_Set(&wall123->vertices[1], 3.1, 2.5, 7.29);
	Vector3_Set(&wall123->vertices[2], 2.9, 0.0, 7.29);
	Vector3_Set(&wall123->vertices[3], 2.9, 2.5, 7.29);
	Vector3_Set(&wall123->vertices[4], 3.1, 0.0, -4.71);
	Vector3_Set(&wall123->vertices[5], 3.1, 2.5, -4.71);
	Vector3_Set(&wall123->vertices[6], 2.9, 0.0, -4.71);
	Vector3_Set(&wall123->vertices[7], 2.9, 2.5, -4.71);
	Vector3_Set(&wall123->vertices[8], -2.9, 0.0, 4.59);
	Vector3_Set(&wall123->vertices[9], -2.9, 2.5, 4.59);
	Vector3_Set(&wall123->vertices[10], -3.1, 0.0, 4.59);
	Vector3_Set(&wall123->vertices[11], -3.1, 2.5, 4.59);
	Vector3_Set(&wall123->vertices[12], -2.9, 0.0, -7.41);
	Vector3_Set(&wall123->vertices[13], -2.9, 2.5, -7.41);
	Vector3_Set(&wall123->vertices[14], -3.1, 0.0, -7.41);
	Vector3_Set(&wall123->vertices[15], -3.1, 2.5, -7.41);

	Face_Set(&wall123->triangles[0], 1, 2, 4);
	Face_Set(&wall123->triangles[1], 3, 4, 8);
	Face_Set(&wall123->triangles[2], 7, 8, 6);
	Face_Set(&wall123->triangles[3], 5, 6, 2);
	Face_Set(&wall123->triangles[4], 3, 7, 5);
	Face_Set(&wall123->triangles[5], 8, 4, 2);
	Face_Set(&wall123->triangles[6], 9, 10, 12);
	Face_Set(&wall123->triangles[7], 11, 12, 16);
	Face_Set(&wall123->triangles[8], 15, 16, 14);
	Face_Set(&wall123->triangles[9], 13, 14, 10);
	Face_Set(&wall123->triangles[10], 11, 15, 13);
	Face_Set(&wall123->triangles[11], 16, 12, 10);
	Face_Set(&wall123->triangles[12], 1, 3, 4);
	Face_Set(&wall123->triangles[13], 3, 7, 8);
	Face_Set(&wall123->triangles[14], 7, 5, 6);
	Face_Set(&wall123->triangles[15], 5, 1, 2);
	Face_Set(&wall123->triangles[16], 3, 1, 5);
	Face_Set(&wall123->triangles[17], 8, 6, 2);
	Face_Set(&wall123->triangles[18], 9, 11, 12);
	Face_Set(&wall123->triangles[19], 11, 15, 16);
	Face_Set(&wall123->triangles[20], 15, 13, 14);
	Face_Set(&wall123->triangles[21], 13, 9, 10);
	Face_Set(&wall123->triangles[22], 11, 9, 13);
	Face_Set(&wall123->triangles[23], 16, 14, 10);
}

struct Mesh* ModelWall123_New() {
	struct Mesh *wall123= New_Mesh(24, 16);
	ModelWall123_Init(wall123);
	return wall123;
}
