#include "enemy_body.h"

void ModelEnemy_Body_Init(struct Mesh *enemy_body) {
	Vector3_Set(&enemy_body->vertices[0], -0.15, 0.4, 0.15);
	Vector3_Set(&enemy_body->vertices[1], -0.15, 1.4, 0.15);
	Vector3_Set(&enemy_body->vertices[2], -0.15, 0.4, -0.15);
	Vector3_Set(&enemy_body->vertices[3], -0.15, 1.4, -0.15);
	Vector3_Set(&enemy_body->vertices[4], 0.15, 0.4, 0.15);
	Vector3_Set(&enemy_body->vertices[5], 0.15, 1.4, 0.15);
	Vector3_Set(&enemy_body->vertices[6], 0.15, 0.4, -0.15);
	Vector3_Set(&enemy_body->vertices[7], 0.15, 1.4, -0.15);

	Face_Set(&enemy_body->triangles[0], 1, 2, 4);
	Face_Set(&enemy_body->triangles[1], 3, 4, 8);
	Face_Set(&enemy_body->triangles[2], 7, 8, 6);
	Face_Set(&enemy_body->triangles[3], 5, 6, 2);
	Face_Set(&enemy_body->triangles[4], 3, 7, 5);
	Face_Set(&enemy_body->triangles[5], 8, 4, 2);
	Face_Set(&enemy_body->triangles[6], 1, 3, 4);
	Face_Set(&enemy_body->triangles[7], 3, 7, 8);
	Face_Set(&enemy_body->triangles[8], 7, 5, 6);
	Face_Set(&enemy_body->triangles[9], 5, 1, 2);
	Face_Set(&enemy_body->triangles[10], 3, 1, 5);
	Face_Set(&enemy_body->triangles[11], 8, 6, 2);
}

struct Mesh* ModelEnemy_Body_New() {
	struct Mesh *enemy_body= New_Mesh(12, 8);
	ModelEnemy_Body_Init(enemy_body);
	return enemy_body;
}
