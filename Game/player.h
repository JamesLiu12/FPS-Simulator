#ifndef FPS_SIMULATOR_PLAYER_H
#define FPS_SIMULATOR_PLAYER_H

#include "../op_engine/op_engine.h"

struct Player{
    struct Canvas canvas;
    double health, atk, speed, defence;
    struct Transform transform;
    struct CollideBox collideBox;
};

//Initializer of player
void Player_Init(struct Player *player);

//Free the memory of player
void Del_Player(struct Player *player);

void Player_Move(struct Player *player, struct Vector3* move);

void Player_Rotate(struct Player *player, struct Vector3* angle);

//What player does when the game begin
void Player_Start(struct Player *player);

//What player does each frame
void Player_Update(struct Player *player);

#endif //FPS_SIMULATOR_PLAYER_H
