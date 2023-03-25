#ifndef FPS_SIMULATOR_ENEMY_H
#define FPS_SIMULATOR_ENEMY_H

#include "../op_engine/op_engine.h"

struct Enemy{
    struct Object object;
    double health, atk, speed;
    struct Transform transform;
};

#endif //FPS_SIMULATOR_ENEMY_H
