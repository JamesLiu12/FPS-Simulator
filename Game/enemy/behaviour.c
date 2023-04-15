#include "behaviour.h"
#include "property.h"
#include "../../op_engine/object.h"

void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *angle){
    Object_Rotation(&enemy->face,angle);
    Object_Rotation(&enemy->body,angle);
	Vector3_Add(&enemy->transform.rotation, angle);
	Transform_RotationMatrixUpdate(&enemy->transform);
}
