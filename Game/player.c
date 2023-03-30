#include "player.h"

void Player_Init(struct Player *player){
    Canvas_Init(&player->canvas, 32, 64);

    player->health = 100;
    player->atk = 1;
    player->movespeed = 0.5;
    player->rotationspeed=0.1;
    Vector3_Set(&player->facing,0,0,1);

    Transform_Init(&player->transform, NULL);

    struct Vector3 v1, v2;
    Vector3_Set(&v1, -0.5, -1, -0.5);
    Vector3_Set(&v2, 0.5, 1, 0.5);
    CollideBox_Set(&player->collideBox, &v1, &v2);
}

struct Player* New_Player() {
    struct Player* player = malloc(sizeof(struct Player));
    Player_Init(player);
    return player;
}

void Del_Player(struct Player *player){
    Del_Canvas(&player->canvas);
    free(player);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
    Canvas_CameraMove(&player->canvas,move);
}

void Player_Rotate(struct Player *player, struct Vector3* angle){
    Vector3_Add(&player->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&player->transform);
    Canvas_CameraRotate(&player->canvas,angle);
}

void Player_Start(struct Player *player){
    //TODO
}

void Player_Update(struct Player *player){
    //TODO
}