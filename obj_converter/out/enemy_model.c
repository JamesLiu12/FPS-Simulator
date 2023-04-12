#include "../mesh.h"

void ModelEnemy_model_Init(struct Mesh *enemy_model) {
	Vector3_Set(&enemy_model->vertices[0], -0.3, 0.0, 0.3);
	Vector3_Set(&enemy_model->vertices[1], -0.3, 0.2, 0.3);
	Vector3_Set(&enemy_model->vertices[2], -0.3, 0.0, -0.3);
	Vector3_Set(&enemy_model->vertices[3], -0.3, 0.2, -0.3);
	Vector3_Set(&enemy_model->vertices[4], 0.3, 0.0, 0.3);
	Vector3_Set(&enemy_model->vertices[5], 0.3, 0.2, 0.3);
	Vector3_Set(&enemy_model->vertices[6], 0.3, 0.0, -0.3);
	Vector3_Set(&enemy_model->vertices[7], 0.3, 0.2, -0.3);
	Vector3_Set(&enemy_model->vertices[8], -0.3, 0.25, 0.3);
	Vector3_Set(&enemy_model->vertices[9], -0.3, 1.25, 0.3);
	Vector3_Set(&enemy_model->vertices[10], -0.3, 0.25, -0.3);
	Vector3_Set(&enemy_model->vertices[11], -0.3, 1.25, -0.3);
	Vector3_Set(&enemy_model->vertices[12], 0.3, 0.25, 0.3);
	Vector3_Set(&enemy_model->vertices[13], 0.3, 1.25, 0.3);
	Vector3_Set(&enemy_model->vertices[14], 0.3, 0.25, -0.3);
	Vector3_Set(&enemy_model->vertices[15], 0.3, 1.25, -0.3);
	Vector3_Set(&enemy_model->vertices[16], -0.3, 1.3, 0.3);
	Vector3_Set(&enemy_model->vertices[17], -0.3, 1.9, 0.3);
	Vector3_Set(&enemy_model->vertices[18], -0.3, 1.3, -0.3);
	Vector3_Set(&enemy_model->vertices[19], -0.3, 1.9, -0.3);
	Vector3_Set(&enemy_model->vertices[20], 0.3, 1.3, 0.3);
	Vector3_Set(&enemy_model->vertices[21], 0.3, 1.9, 0.3);
	Vector3_Set(&enemy_model->vertices[22], 0.3, 1.3, -0.3);
	Vector3_Set(&enemy_model->vertices[23], 0.3, 1.9, -0.3);

	Face_Set(&enemy_model->triangles[0], 1, 2, 4);
	Face_Set(&enemy_model->triangles[1], 3, 4, 8);
	Face_Set(&enemy_model->triangles[2], 7, 8, 6);
	Face_Set(&enemy_model->triangles[3], 5, 6, 2);
	Face_Set(&enemy_model->triangles[4], 3, 7, 5);
	Face_Set(&enemy_model->triangles[5], 8, 4, 2);
	Face_Set(&enemy_model->triangles[6], 9, 10, 12);
	Face_Set(&enemy_model->triangles[7], 11, 12, 16);
	Face_Set(&enemy_model->triangles[8], 15, 16, 14);
	Face_Set(&enemy_model->triangles[9], 13, 14, 10);
	Face_Set(&enemy_model->triangles[10], 11, 15, 13);
	Face_Set(&enemy_model->triangles[11], 16, 12, 10);
	Face_Set(&enemy_model->triangles[12], 17, 18, 20);
	Face_Set(&enemy_model->triangles[13], 19, 20, 24);
	Face_Set(&enemy_model->triangles[14], 23, 24, 22);
	Face_Set(&enemy_model->triangles[15], 21, 22, 18);
	Face_Set(&enemy_model->triangles[16], 19, 23, 21);
	Face_Set(&enemy_model->triangles[17], 24, 20, 18);
	Face_Set(&enemy_model->triangles[18], 1, 3, 4);
	Face_Set(&enemy_model->triangles[19], 3, 7, 8);
	Face_Set(&enemy_model->triangles[20], 7, 5, 6);
	Face_Set(&enemy_model->triangles[21], 5, 1, 2);
	Face_Set(&enemy_model->triangles[22], 3, 1, 5);
	Face_Set(&enemy_model->triangles[23], 8, 6, 2);
	Face_Set(&enemy_model->triangles[24], 9, 11, 12);
	Face_Set(&enemy_model->triangles[25], 11, 15, 16);
	Face_Set(&enemy_model->triangles[26], 15, 13, 14);
	Face_Set(&enemy_model->triangles[27], 13, 9, 10);
	Face_Set(&enemy_model->triangles[28], 11, 9, 13);
	Face_Set(&enemy_model->triangles[29], 16, 14, 10);
	Face_Set(&enemy_model->triangles[30], 17, 19, 20);
	Face_Set(&enemy_model->triangles[31], 19, 23, 24);
	Face_Set(&enemy_model->triangles[32], 23, 21, 22);
	Face_Set(&enemy_model->triangles[33], 21, 17, 18);
	Face_Set(&enemy_model->triangles[34], 19, 17, 21);
	Face_Set(&enemy_model->triangles[35], 24, 22, 18);
}

struct Mesh* ModelEnemy_model_New() {
	struct Mesh *enemy_model= New_Mesh(36, 24);
	ModelEnemy_model_Init(enemy_model);
	return enemy_model;
}
