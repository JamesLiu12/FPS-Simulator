#ifndef FPS_SIMULATOR_PLAYER_H
#define FPS_SIMULATOR_PLAYER_H
#include "../op_engine/op_engine.h"
#include "weapon.h"

struct Player{
    struct Canvas canvas;
    double maxHealth, health, moveSpeed, rotationSpeed, defence;
    struct Transform transform;
    struct CollideBox collideBox;
    struct Vector3 facing;
    struct Vector3 moveDirection;
    double fireCDcounter,reloadCDcounter;
    struct Weapon weapon;
    int In_FireCD,FIREFLAG;
    int In_ReloadCD,RELOADFLAG;
    int DEADFLAG;
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
void Player_Update(struct Player *player, double delta_time);

void Player_MoveForward(struct Player *player, double delta_time);
void Player_MoveBackward(struct Player *player, double delta_time);
void Player_MoveLeft(struct Player *player, double delta_time);
void Player_MoveRight(struct Player *player, double delta_time);

void Player_RotateUp(struct Player *player, double delta_time);
void Player_RotateDown(struct Player *player, double delta_time);
void Player_RotateLeft(struct Player *player, double delta_time);
void Player_RotateRight(struct Player *player, double delta_time);

void Player_Control(struct Player *player, double delta_time);

void Player_Shoot(struct Player *player);
void Player_Reload(struct Player *player);
void Player_ChangeHealth(struct Player *player,double deltaHealth);
void Player_SetPosition(struct Player *player, double x, double y, double z);
#endif //FPS_SIMULATOR_PLAYER_H
