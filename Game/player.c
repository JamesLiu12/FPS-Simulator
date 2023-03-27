#include "player.h"

void Player_Init(struct Player *player){
    Canvas_Init(&player->canvas, 32, 64);

    player->health = 100;
    player->atk = 1;
    player->movespeed = 1;
    player->rotationspeed=0.1;

    Transform_Init(&player->transform);

    struct Vector3 v1, v2;
    Vector3_Set(&v1, -0.5, -1, -0.5);
    Vector3_Set(&v2, 0.5, 1, 0.5);
    Vector3_Set(&player->facing,0,0,1);
    CollideBox_Set(&player->collideBox, &v1, &v2);
}

void Del_Player(struct Player *Player){
    del_Canvas(&Player->canvas);
    free(Player);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
    Vector3_Copy(&player->transform.position,&player->canvas.camera_transform.position);
}

void Player_Rotate(struct Player *player, struct Vector3* angle){
    Vector3_Add(&player->transform.rotation, angle);
    Transform_RotationMatrixUpdate(&player->transform);
    struct Matrix3x3 Rmatrix;
    Matrix3x3_FromEulerAngle(&Rmatrix,angle,EULER_ANGLE_NORMAL);
    Matrix3x3_Transform(&Rmatrix, &player->facing);
    Vector3_Copy(&player->transform.rotation,&player->canvas.camera_transform.rotation);
}

void Player_Start(struct Player *Player){
    //TODO
}

void Player_Update(struct Player *Player){
    //TODO
}
void Player_Rotate_Left(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0, -player->rotationspeed, 0);
    Player_Rotate(player,&rotation);
}
void Player_Rotate_Right(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0, player->rotationspeed, 0);
    Player_Rotate(player,&rotation);
}
void Player_Rotate_Up(struct Player *player){
    struct Vector3 RotationAxis;
    struct Vector3 RoRight;
    Vector3_Set(&RoRight,0,M_PI_2,0);
    struct Matrix3x3 Right90Matrix;
    Vector3_Copy(&player->facing,&RotationAxis);
    Vector3_Set(&RotationAxis,RotationAxis.x,0,RotationAxis.z);
    
    Matrix3x3_FromEulerAngle(&Right90Matrix,&RoRight,EULER_ANGLE_REVERSED);
    Matrix3x3_Transform(&Right90Matrix,&RotationAxis);
    Vector3_Normalize(&RotationAxis);
    Vector3_EqualRatioScale(&RotationAxis,player->rotationspeed);
    Player_Rotate(player,&RotationAxis);
}
void Player_Rotate_Down(struct Player *player){
    struct Vector3 RotationAxis;
    struct Vector3 RoRight;
    Vector3_Set(&RoRight,0,M_PI_2,0);
    struct Matrix3x3 Right90Matrix;
    Vector3_Copy(&player->facing,&RotationAxis);
    Vector3_Set(&RotationAxis,RotationAxis.x,0,RotationAxis.z);
    
    Matrix3x3_FromEulerAngle(&Right90Matrix,&RoRight,EULER_ANGLE_NORMAL);
    Matrix3x3_Transform(&Right90Matrix,&RotationAxis);
    Vector3_Normalize(&RotationAxis);
    Vector3_EqualRatioScale(&RotationAxis,player->rotationspeed);

    Player_Rotate(player,&RotationAxis);
}
void Player_Move_Forward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,player->facing.x,0,player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_EqualRatioScale(&movement,player->movespeed);
    Player_Move(player,&movement);
}
void Player_Move_Backward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,-player->facing.x,0,-player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_EqualRatioScale(&movement,player->movespeed);
    Player_Move(player,&movement);
}
void Player_Move_Left(struct Player *player){
    struct Vector3 movement;
    struct Vector3 RoRight;
    Vector3_Set(&RoRight,0,M_PI_2,0);
    struct Matrix3x3 Right90Matrix;
    Vector3_Copy(&player->facing,&movement);
    Vector3_Set(&movement,movement.x,0,movement.z);
    
    Matrix3x3_FromEulerAngle(&Right90Matrix,&RoRight,EULER_ANGLE_REVERSED);
    Matrix3x3_Transform(&Right90Matrix,&movement);
    Vector3_Normalize(&movement);
    Vector3_EqualRatioScale(&movement,player->movespeed);

    Player_Move(player,&movement);

}
void Player_Move_Right(struct Player *player){
    struct Vector3 movement;
    struct Vector3 RoRight;
    Vector3_Set(&RoRight,0,M_PI_2,0);
    struct Matrix3x3 Right90Matrix;
    Vector3_Copy(&player->facing,&movement);
    Vector3_Set(&movement,movement.x,0,movement.z);
    
    Matrix3x3_FromEulerAngle(&Right90Matrix,&RoRight,EULER_ANGLE_NORMAL);
    Matrix3x3_Transform(&Right90Matrix,&movement);
    Vector3_Normalize(&movement);
    Vector3_EqualRatioScale(&movement,player->movespeed);

    Player_Move(player,&movement);}