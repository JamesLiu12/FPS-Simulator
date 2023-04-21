
#include "player.h"
#include "../op_engine/op_engine.h"

#include "runner.h"

void Player_Init(struct Player *player){
    Canvas_Init(&player->canvas, 32, 64);
    player->maxHealth = 100;
    player->health = player->maxHealth;
    player->moveSpeed = 0.1;
    player->rotationSpeed = 0.1;
    player->In_FireCD = 0;
    player->FIREFLAG = 0;
    player->fireCDcounter = 0;
    player->DEADFLAG = 0;
    Vector3_Set(&player->facing,0,0,1);

    Transform_Init(&player->transform, NULL);
    Transform_Init(&player->canvas.camera_transform, &player->transform);
    Vector3_Set(&player->canvas.camera_transform.position, 0, 0.8, 0);

    struct Vector3 v1, v2;
    Vector3_Set(&v1, -0.5, -1, -0.5);
    Vector3_Set(&v2, 0.5, 1, 0.5);
    CollideBox_Init(&player->collideBox, NULL, 0.7, 1.8, 0.7);
    player->collideBox.transform = player->transform;
    player->collideBox.transform.position.y = 0.9;
    Weapon_Init(&player->weapon, P1999);
}

struct Player* New_Player() {
    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    Player_Init(player);
    return player;
}

void Del_Player(struct Player *player){
    Del_Canvas(&player->canvas);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
}

void Player_Rotate(struct Player *player, struct Vector3* angle){
    //Vector3_Add(&player->transform.rotation, angle);
    //Transform_RotationMatrixUpdate(&player->transform);

    Canvas_CameraRotate(&player->canvas,angle);
    struct Vector3 BaseFacing;
    Vector3_Set(&BaseFacing,0,0,1);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,&player->canvas.camera_transform.rotation,EULER_ANGLE_REVERSED);
    Matrix3x3_TransformMatrix(&RotationMatrix, &BaseFacing);
    Vector3_Normalize(&BaseFacing);
    Vector3_Copy(&BaseFacing,&player->facing);

}

void Player_Start(struct Player *player){
    //TODO
    Vector3_Set(&player->transform.position,0,1,0);
}

void Player_Update(struct Player *player, double delta_time){
    if(player->In_FireCD){
        player->FIREFLAG = 0 ;
        //TODO
        player->fireCDcounter -= delta_time;
        if(player->fireCDcounter <= 0) player->In_FireCD = 0;
    }

    if(player->weapon.bullet_number == 0) Player_Reload(player);
    if(player->In_ReloadCD){
        player->RELOADFLAG = 0;
        player->reloadCDcounter -= delta_time;
        if(player->reloadCDcounter <= 0){
            player->In_ReloadCD = 0;
        player->weapon.bullet_number = player->weapon.magazine_size;
        }
    }
    //Player_Control(player);
}

void Player_Control(struct Player *player){
    if(keydown(W)) Player_RotateUp(player);
    if(keydown(S)) Player_RotateDown(player);
    if(keydown(A)) Player_RotateLeft(player);
    if(keydown(D)) Player_RotateRight(player);

    if(keydown(UP)) Player_MoveForward(player);
    if(keydown(DOWN)) Player_MoveBackward(player);
    if(keydown(LEFT)) Player_MoveLeft(player);
    if(keydown(RIGHT)) Player_MoveRight(player);

    if(keydown(H)) Player_ChangeHealth(player,-5);
    if(keydown(K)) Player_ChangeHealth(player,5);

    if(keydown(F)) Player_Shoot(player);
    if(keydown(R)) Player_Reload(player);
}
void Player_Shoot(struct Player *player){
    if(!player->FIREFLAG){
        if(!player->In_FireCD){
            if(player->weapon.bullet_number>0){
            player->FIREFLAG = 1;
            player->In_FireCD = 1;
            player->fireCDcounter = player->weapon.fireCDtime;
            player->weapon.bullet_number -= 1;
            }
        }
    }
}
void Player_Reload(struct Player *player){
    if(!player->RELOADFLAG){
        if(!player->In_ReloadCD){
        player->RELOADFLAG = 1;
        player->In_ReloadCD = 1;
        player->reloadCDcounter = player->weapon.reloadCDtime;
        }
    }
}
void Player_MoveForward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement, player->facing.x, 0, player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed);
    //Player_Move(player,&movement);
    Vector3_Copy(&movement, &player->moveDirection);
}
void Player_MoveBackward(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement, -player->facing.x, 0, -player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed);
    Vector3_Copy(&movement, &player->moveDirection);
    //Player_Move(player, &movement);
}
void Player_MoveLeft(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement,-player->facing.z,0,player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->moveSpeed);
    Vector3_Copy(&movement,&player->moveDirection);
    //Player_Move(player,&movement);
}
void Player_MoveRight(struct Player *player){
    struct Vector3 movement;
    Vector3_Set(&movement, player->facing.z, 0, -player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed);
    Vector3_Copy(&movement, &player->moveDirection);
    //Player_Move(player,&movement);
}

void Player_RotateUp(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation, player->facing.z, 0, -player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation, player->rotationSpeed);
    Player_Rotate(player, &rotation);
}
void Player_RotateDown(struct Player *player){
    struct Vector3 rotation;
    Vector3_Set(&rotation, -player->facing.z, 0, player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation, player->rotationSpeed);
    Player_Rotate(player, &rotation);
}
void Player_RotateLeft(struct Player *player){
    struct Vector3 rotation;
    struct Vector3 current_rotation;

    Vector3_Copy(&player->canvas.camera_transform.rotation,&current_rotation);
    Vector3_Set(&rotation, -current_rotation.x, 0, -current_rotation.z);
    Player_Rotate(player, &rotation);
    Vector3_Set(&rotation, 0, player->rotationSpeed, 0);
    Player_Rotate(player, &rotation);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,&rotation,EULER_ANGLE_REVERSED);
    Vector3_Set(&rotation, current_rotation.x, 0, current_rotation.z);
    Matrix3x3_TransformMatrix(&RotationMatrix, &rotation);
    Player_Rotate(player, &rotation);
}
void Player_RotateRight(struct Player *player){
    struct Vector3 rotation;
    struct Vector3 current_rotation;

    Vector3_Copy(&player->canvas.camera_transform.rotation,&current_rotation);
    Vector3_Set(&rotation, -current_rotation.x, 0, -current_rotation.z);
    Player_Rotate(player, &rotation);
    Vector3_Set(&rotation, 0, -player->rotationSpeed, 0);
    Player_Rotate(player, &rotation);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,&rotation,EULER_ANGLE_REVERSED);
    Vector3_Set(&rotation, current_rotation.x, 0, current_rotation.z);
    Matrix3x3_TransformMatrix(&RotationMatrix, &rotation);
    Player_Rotate(player, &rotation);
}

void Player_ChangeHealth(struct Player *player, double deltaHealth){
    player->health += deltaHealth;
    if(player->health > player->maxHealth) player->health = player->maxHealth;
    if(player->health <= 0){
        player->health = 0;
        player->DEADFLAG = 1;
    }
}
