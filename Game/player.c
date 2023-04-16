#include "player.h"
#include "weapon.h"
#include "../op_engine/op_engine.h"
void Player_Init(struct Player *player){
    Canvas_Init(&player->canvas, 32, 64);

    player->health = 100;
    player->atk = 1;
    player->movespeed = 0.5;
    player->rotationspeed=0.1;
    Vector3_Set(&player->facing,0,0,1);

    Transform_Init(&player->transform, NULL);
    Transform_Init(&player->canvas.camera_transform, &player->transform);

    struct Vector3 v1, v2;
    Vector3_Set(&v1, -0.5, -1, -0.5);
    Vector3_Set(&v2, 0.5, 1, 0.5);
    CollideBox_Set(&player->collideBox, &v1, &v2);

    struct Weapon* weapon = (struct Weapon*)malloc(sizeof (struct Weapon));
    struct ArrayList* weapon_list = (struct ArrayList*)malloc(sizeof (struct ArrayList));
    Weapon_List_Init(weapon_list);
    Weapon_Init(weapon,player,weapon_list);
}

struct Player* New_Player() {
    struct Player* player = malloc(sizeof(struct Player));
    Player_Init(player);
    return player;
}

void Del_Player(struct Player *player){
    Del_Canvas(&player->canvas);
//    free(player);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
//    Canvas_CameraMove(&player->canvas,move);
}

void Player_Rotate(struct Player *player, struct Vector3* angle){
    Vector3_Add(&player->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&player->transform);

    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,angle,EULER_ANGLE_REVERSED);
    Matrix3x3_Transform(&RotationMatrix,&player->facing);
    Vector3_Normalize(&player->facing);

    Canvas_CameraRotate(&player->canvas,angle);
}

void Player_Start(struct Player *player){
    //TODO
}

void Player_Update(struct Player *player){
    //TODO
}

void Player_MoveForward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,player->facing.x,0,player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->movespeed);
    Player_Move(player,&movement);
    
}
void Player_MoveBackward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,-player->facing.x,0,-player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->movespeed);
    Player_Move(player,&movement);
}
void Player_MoveLeft(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,-player->facing.z,0,player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->movespeed);
    Player_Move(player,&movement);
}
void Player_MoveRight(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,player->facing.z,0,-player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->movespeed);
    Player_Move(player,&movement);
}

void Player_RotateUp(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation,player->facing.z,0,-player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation,player->rotationspeed);
    Player_Rotate(player,&rotation);
}
void Player_RotateDown(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation,-player->facing.z,0,player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation,player->rotationspeed);
    Player_Rotate(player,&rotation);
}
void Player_RotateLeft(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation,0,player->rotationspeed,0);
    Player_Rotate(player,&rotation);
}
void Player_RotateRight(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation,0,-player->rotationspeed,0);
    Player_Rotate(player,&rotation);
}

void Player_Control(struct Player *player){
	if(keydown(W))Player_RotateUp(player);
	if(keydown(S))Player_RotateDown(player);
	if(keydown(A))Player_RotateLeft(player);
	if(keydown(D))Player_RotateRight(player);

	if(keydown(UP))Player_MoveForward(player);
	if(keydown(DOWN))Player_MoveBackward(player);
	if(keydown(LEFT))Player_MoveLeft(player);
	if(keydown(RIGHT))Player_MoveRight(player);
}