#include "../mesh.h"

void ModelEnemy_Head_Init(struct Mesh *enemy_head) {
	Vector3_Set(&enemy_head->vertices[0], -0.35, 1.4, 0.35);
	Vector3_Set(&enemy_head->vertices[1], -0.35, 2.1, 0.35);
	Vector3_Set(&enemy_head->vertices[2], -0.35, 1.4, -0.35);
	Vector3_Set(&enemy_head->vertices[3], -0.35, 2.1, -0.35);
	Vector3_Set(&enemy_head->vertices[4], 0.35, 1.4, 0.35);
	Vector3_Set(&enemy_head->vertices[5], 0.35, 2.1, 0.35);
	Vector3_Set(&enemy_head->vertices[6], 0.35, 1.4, -0.35);
	Vector3_Set(&enemy_head->vertices[7], 0.35, 2.1, -0.35);

	Face_Set(&enemy_head->triangles[0], 1, 2, 4);
	Face_Set(&enemy_head->triangles[1], 3, 4, 8);
	Face_Set(&enemy_head->triangles[2], 7, 8, 6);
	Face_Set(&enemy_head->triangles[3], 5, 6, 2);
	Face_Set(&enemy_head->triangles[4], 3, 7, 5);
	Face_Set(&enemy_head->triangles[5], 8, 4, 2);
	Face_Set(&enemy_head->triangles[6], 1, 3, 4);
	Face_Set(&enemy_head->triangles[7], 3, 7, 8);
	Face_Set(&enemy_head->triangles[8], 7, 5, 6);
	Face_Set(&enemy_head->triangles[9], 5, 1, 2);
	Face_Set(&enemy_head->triangles[10], 3, 1, 5);
	Face_Set(&enemy_head->triangles[11], 8, 6, 2);
}

struct Mesh* ModelEnemy_Head_New() {
	struct Mesh *enemy_head= New_Mesh(12, 8);
	ModelEnemy_Head_Init(enemy_head);
	return enemy_head;
}
