#ifndef FPS_SIMULATOR_BEHAVIOUR_H
#define FPS_SIMULATOR_BEHAVIOUR_H

#include "../op_engine/op_engine.h"
#include "property.h"

void Enemy_Move(struct Enemy* enemy, struct Vector3 *move); //enemy consists of two objects: face and body
void Enemy_Rotation(struct Enemy* enemy, struct Vector3 *rotation);

#endif //FPS_SIMULATOR_BEHAVIOUR_H
