#include "behaviour.h"


void Enemy_Move(struct Enemy* enemy, struct Vector3* move){
    Object_Move(enemy->face,move);
    Object_Move(enemy->body,move);
}

void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *rotation){
    Object_Rotation(enemy->face,rotation);
    Object_Rotation(enemy->body,rotation);
}
