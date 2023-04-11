#include "player.h"

void Weapon_Init(struct Weapon *weapon){
	weapon->speed = 10;
	weapon->damage = 2;
}

void Player_Init(struct Player *player){
    Canvas_Init(&player->canvas, 32, 64);

    player->health = 100;
    player->atk = 1;
    player->speed = 1;
	player->defence = 5;
	Weapon_Init(&player->weapon);

    Transform_Init(&player->transform, NULL);

    struct Vector3 v1, v2;
    Vector3_Set(&v1, -0.5, -1, -0.5);
    Vector3_Set(&v2, 0.5, 1, 0.5);
    CollideBox_Set(&player->collideBox, &v1, &v2);
}

void Del_Player(struct Player *player){
    Del_Canvas(&player->canvas);
    free(player);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
}

void Player_Rotate(struct Player *player, struct Vector3* angle){
    Vector3_Add(&player->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&player->transform);
}

void Player_Start(struct Player *player){
    //TODO
}

void Player_Update(struct Player *player){
    //TODO
}