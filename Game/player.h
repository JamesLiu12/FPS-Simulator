#ifndef FPS_SIMULATOR_PLAYER_H
#define FPS_SIMULATOR_PLAYER_H

#include "../op_engine/op_engine.h"
struct Player{
    struct Canvas canvas;
    double health, atk, movespeed, rotationspeed;
    struct Transform transform;
    struct CollideBox collideBox;
    struct Vector3 facing;
    struct Vector3 movedirection;
    double fireCDtime,fireCDcounter;
    int In_FireCD,IsFiring;
};

//Initializer of player
void Player_Init(struct Player *player);
struct Player* New_Player();
//Free the memory of player
void Del_Player(struct Player *player);

void Player_Move(struct Player *player, struct Vector3* move);

void Player_Rotate(struct Player *player, struct Vector3* angle);

//What player does when the game begin
void Player_Start(struct Player *player);

//What player does each frame
void Player_Update(struct Player *player);

void Player_Control(struct Player *player);

void Player_MoveForward(struct Player *player);
void Player_MoveBackward(struct Player *player);
void Player_MoveLeft(struct Player *player);
void Player_MoveRight(struct Player *player);

void Player_RotateUp(struct Player *player);
void Player_RotateDown(struct Player *player);
void Player_RotateLeft(struct Player *player);
void Player_RotateRight(struct Player *player);
void Player_Shoot(struct Player *player);
#endif //FPS_SIMULATOR_PLAYER_H
