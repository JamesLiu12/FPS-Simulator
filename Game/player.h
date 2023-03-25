#ifndef FPS_SIMULATOR_PLAYER_H
#define FPS_SIMULATOR_PLAYER_H

#include "../op_engine/op_engine.h"

struct Player{
    struct Canvas canvas;
    double health, atk, speed;
    struct Transform transform;
    struct CollideBox collideBox;
};

#endif //FPS_SIMULATOR_PLAYER_H
