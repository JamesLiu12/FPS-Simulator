#include "../mesh.h"

void ModelFloor_Init(struct Mesh *floor) {
	Vector3_Set(&floor->vertices[0], -7.5, 0.0, 7.5);
	Vector3_Set(&floor->vertices[1], 7.5, 0.0, 7.5);
	Vector3_Set(&floor->vertices[2], -7.5, 0.0, -7.5);
	Vector3_Set(&floor->vertices[3], 7.5, 0.0, -7.5);

	Face_Set(&floor->triangles[0], 1, 2, 4);
	Face_Set(&floor->triangles[1], 1, 3, 4);
}

struct Mesh* ModelFloor_New() {
	struct Mesh *floor= New_Mesh(2, 4);
	ModelFloor_Init(floor);
	return floor;
}
