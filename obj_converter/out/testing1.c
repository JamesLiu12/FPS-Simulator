#include "../mesh.h"

void ModelTesting1_Init(struct Mesh *testing1) {
	Vector3_Set(&testing1->vertices[0], -25.0, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[1], 25.0, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[2], -25.0, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[3], 25.0, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[4], 24.5, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[5], 24.5, 10.0, -25.0);
	Vector3_Set(&testing1->vertices[6], 24.5, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[7], 24.5, 10.0, 25.0);
	Vector3_Set(&testing1->vertices[8], 25.5, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[9], 25.5, 10.0, -25.0);
	Vector3_Set(&testing1->vertices[10], 25.5, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[11], 25.5, 10.0, 25.0);
	Vector3_Set(&testing1->vertices[12], -25.5, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[13], -25.5, 10.0, -25.0);
	Vector3_Set(&testing1->vertices[14], -25.5, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[15], -25.5, 10.0, 25.0);
	Vector3_Set(&testing1->vertices[16], -24.5, 0.0, -25.0);
	Vector3_Set(&testing1->vertices[17], -24.5, 10.0, -25.0);
	Vector3_Set(&testing1->vertices[18], -24.5, 0.0, 25.0);
	Vector3_Set(&testing1->vertices[19], -24.5, 10.0, 25.0);
	Vector3_Set(&testing1->vertices[20], 25.0, 0.0, -25.499998);
	Vector3_Set(&testing1->vertices[21], 25.0, 10.0, -25.499998);
	Vector3_Set(&testing1->vertices[22], -25.0, 0.0, -25.500002);
	Vector3_Set(&testing1->vertices[23], -25.0, 10.0, -25.500002);
	Vector3_Set(&testing1->vertices[24], 25.0, 0.0, -24.499998);
	Vector3_Set(&testing1->vertices[25], 25.0, 10.0, -24.499998);
	Vector3_Set(&testing1->vertices[26], -25.0, 0.0, -24.500002);
	Vector3_Set(&testing1->vertices[27], -25.0, 10.0, -24.500002);
	Vector3_Set(&testing1->vertices[28], 25.0, 0.0, 24.500002);
	Vector3_Set(&testing1->vertices[29], 25.0, 10.0, 24.500002);
	Vector3_Set(&testing1->vertices[30], -25.0, 0.0, 24.499998);
	Vector3_Set(&testing1->vertices[31], -25.0, 10.0, 24.499998);
	Vector3_Set(&testing1->vertices[32], 25.0, 0.0, 25