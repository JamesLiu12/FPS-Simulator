#include "behaviour.h"


void Enemy_Move(struct Enemy* enemy, struct Vector3* move){
    Object_Move(&enemy->face,move);
    Object_Move(&enemy->body,move);
	Object_Move(&enemy->leg,move);
	Vector3_Add(&enemy->transform.position, move);
	Transform_UpdateGlobal(&enemy->transform);
}

void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *angle){
    Object_Rotation(&enemy->face,angle);
    Object_Rotation(&enemy->body,angle);
	Vector3_Add(&enemy->transform.rotation, angle);
	Transform_RotationMatrixUpdate(&enemy->transform);
}
