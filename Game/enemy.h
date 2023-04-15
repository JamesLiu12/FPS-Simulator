#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../op_engine/op_engine.h"

struct Enemy{
    struct Object head, body, leg;
    double health, atk, speed;
    struct Transform transform;
};

void Enemy_Init(struct Enemy *enemy, struct Object *head, struct Object *body, struct Object *leg);
void Del_Enemy(struct Enemy *enemy);

#endif //FPS_SIMULATOR_ENEMY_H
