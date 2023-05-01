#include "player.h"
#include "../op_engine/op_engine.h"
#include "../GameUI/ui_instruction.h"
#include <stdio.h>
#include <stdlib.h>
void Player_Init(struct Player *player, enum WeaponName weaponname, int difficulty){
    Canvas_Init(&player->canvas, 33, 65);
    player->maxHealth = 100;
    player->health = player->maxHealth;
    player->moveSpeed = 15;
    player->rotationSpeed = 4;
    player->inFireCD = 0;
    player->FIREFLAG = 0;
    player->fireCDcounter = 0;
    player->RELOADFLAG = 0;
    player->reloadCDcounter = 0;
    player->healingCDcounter = 0;
    player->DAMAGEFLAG = 0;
    player->DEADFLAG = 0;
    player->WINFLAG = 0;
    player->TRUEWINFLAG = 0;
    player->QUITFLAG = 0;
    switch (difficulty)
    {
    case 0:
        player->healingCDtime = 7;
        player->heal_per_sec = 4;
        break;
    case 1:
        player->healingCDtime = 9;
        player->heal_per_sec = 1;
        break;
    case 2:
        player->healingCDtime = 1000;
        player->heal_per_sec = 0;
        break;
    default:
        player->healingCDtime = 5;
        player->heal_per_sec = 10;
        break;
    }
    Vector3_Set(&player->facing,0,0,1);

    Transform_Init(&player->transform, NULL);
    Transform_Init(&player->canvas.camera_transform, &player->transform);
    Vector3_Set(&player->canvas.camera_transform.position, 0, 1.8, 0);

    CollideBox_Init(&player->collideBox, &player->transform, 1, 2.1, 1);
    Vector3_Set(&player->collideBox.transform.position, 0, 1.06, 0);
    Vector3_Set(&player->move, 0, 0 , 0);
    Weapon_Init(&player->weapon, weaponname);
}

struct Player* New_Player(enum WeaponName weaponname, int difficulty) {
    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    Player_Init(player, weaponname, difficulty);
    return player;
}

void Del_Player(struct Player *player){
    Del_Canvas(&player->canvas);
}

void Player_Move(struct Player *player, struct Vector3* move){
    Vector3_Add(&player->transform.position, move);
}
void Player_SetPosition(struct Player *player, double x, double y, double z){
    Vector3_Set(&player->transform.position,x,y,z);
}
void Player_Rotate(struct Player *player, struct Vector3* angle){
    //Vector3_Add(&player->transform.rotation, angle);
    //Transform_RotationMatrixUpdate(&player->transform);

    Canvas_CameraRotate(&player->canvas,angle);
    struct Vector3 BaseFacing;
    Vector3_Set(&BaseFacing, 0, 0, 1);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,angle,EULER_ANGLE_REVERSED);
    Matrix3x3_TransformMatrix(&RotationMatrix, &player->facing);
    Vector3_Normalize(&player->facing);
    //Vector3_Copy(&BaseFacing,&player->facing);

}

void Player_Start(struct Player *player){
    //TODO
    Vector3_Set(&player->transform.position,0,1,0);
}

void Player_Update(struct Player *player, double delta_time){
    if(player->DAMAGEFLAG){
        player->healingCDcounter = player-> healingCDtime;
    }
    player->DAMAGEFLAG = 0;
    if(player->healingCDcounter > 0){
        player->healingCDcounter -= delta_time;
    }
    else{
        Player_ChangeHealth(player, player->heal_per_sec * delta_time);
    }
    if(player->inFireCD){
        player->FIREFLAG = 0 ;
        //TODO
        player->fireCDcounter -= delta_time;
        if(player->fireCDcounter <= 0) player->inFireCD = 0;
    }

    if(player->weapon.bullet_number == 0) Player_Reload(player);
    if(player->inReloadCD){
        player->RELOADFLAG = 0;
        player->reloadCDcounter -= delta_time;
        if(player->reloadCDcounter <= 0){
            player->inReloadCD = 0;
        player->weapon.bullet_number = player->weapon.magazine_size;
        }
    }
    Vector3_Set(&player->move, 0, 0, 0);
    Player_Control(player, delta_time);
}
void Player_SetDamageFlag(struct Player *player){
    player->DAMAGEFLAG = 1;
}
void Player_Control(struct Player *player, double delta_time){
    if(kbhit()){
    if(keydown(W)) Player_RotateUp(player, delta_time);
    if(keydown(S)) Player_RotateDown(player, delta_time);
    if(keydown(A)) Player_RotateLeft(player, delta_time);
    if(keydown(D)) Player_RotateRight(player, delta_time);

    if(keydown(UP)) Player_MoveForward(player, delta_time);
    if(keydown(DOWN)) Player_MoveBackward(player, delta_time);
    if(keydown(LEFT)) Player_MoveLeft(player, delta_time);
    if(keydown(RIGHT)) Player_MoveRight(player, delta_time);

    //if(keydown(H)) Player_ChangeHealth(player, -5);
    //if(keydown(K)) Player_ChangeHealth(player, 5);

    if(keydown(F)) Player_Shoot(player);
    if(keydown(R)) Player_Reload(player);
    if(keydown(ESC)) Player_Pause(player);
    }
}
void Player_Shoot(struct Player *player){
    if(!player->FIREFLAG){
        if(!player->inFireCD && !player->inReloadCD){
            if(player->weapon.bullet_number>0){
            player->FIREFLAG = 1;
            player->inFireCD = 1;
            player->fireCDcounter = player->weapon.fireCDtime;
            player->weapon.bullet_number -= 1;
            }
        }
    }
}
void Player_Reload(struct Player *player){
    if(!player->RELOADFLAG){
        if(!player->inReloadCD){
        player->RELOADFLAG = 1;
        player->inReloadCD = 1;
        player->reloadCDcounter = player->weapon.reloadCDtime;
        }
    }
}
void Player_Pause(struct Player *player){
    screenclean();
    printf(R"(                      ______       __    __   __  .___________. ______   
                     /  __  \     |  |  |  | |  | |           ||      \  
                    |  |  |  |    |  |  |  | |  | `---|  |----``----)  | 
                    |  |  |  |    |  |  |  | |  |     |  |         /  /  
                    |  `--'  '--. |  `--'  | |  |     |  |        |__|   
                     \_____\_____\ \______/  |__|     |__|         __    
                                                                  (__)  )");
    printf("\nPress ESC to return to the game\n");
    printf("Press ENTER to quit the game\n");

    while(1){
        if(kbhit()){
            if(keydown(ESC))break;
            if(keydown(ENTER)){player->QUITFLAG=1;break;}
        }
    }
}
void Player_MoveForward(struct Player *player, double delta_time){
    struct Vector3 movement;
    Vector3_Set(&movement, player->facing.x, 0, player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed * delta_time);
    //Player_Move(player,&movement);
    Vector3_Copy(&movement, &player->move);
}
void Player_MoveBackward(struct Player *player, double delta_time){
    struct Vector3 movement;
    Vector3_Set(&movement, -player->facing.x, 0, -player->facing.z);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed * delta_time);
    Vector3_Copy(&movement, &player->move);
    //Player_Move(player, &movement);
    Vector3_Copy(&movement, &player->move);
}
void Player_MoveLeft(struct Player *player, double delta_time){
    struct Vector3 movement;
    Vector3_Set(&movement,-player->facing.z,0,player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement,player->moveSpeed * delta_time);
    Vector3_Copy(&movement,&player->move);
    //Player_Move(player,&movement);
    Vector3_Copy(&movement, &player->move);
}
void Player_MoveRight(struct Player *player, double delta_time){
    struct Vector3 movement;
    Vector3_Set(&movement, player->facing.z, 0, -player->facing.x);
    Vector3_Normalize(&movement);
    Vector3_Scale(&movement, player->moveSpeed * delta_time);
    Vector3_Copy(&movement, &player->move);
    //Player_Move(player,&movement);
    Vector3_Copy(&movement, &player->move);
}

void Player_RotateUp(struct Player *player, double delta_time){
    struct Vector3 rotation;
    Vector3_Set(&rotation, player->facing.z, 0, -player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation, player->rotationSpeed * delta_time * 0.5);
    Player_Rotate(player, &rotation);
}
void Player_RotateDown(struct Player *player, double delta_time){
    struct Vector3 rotation;
    Vector3_Set(&rotation, -player->facing.z, 0, player->facing.x);
    Vector3_Normalize(&rotation);
    Vector3_Scale(&rotation, player->rotationSpeed * delta_time * 0.5);
    Player_Rotate(player, &rotation);
}
void Player_RotateLeft(struct Player *player, double delta_time){
    struct Vector3 rotation;
    struct Vector3 current_rotation;

    Vector3_Copy(&player->canvas.camera_transform.rotation, &current_rotation);
    Vector3_Set(&rotation, -current_rotation.x, 0, -current_rotation.z);
    Player_Rotate(player, &rotation);
    Vector3_Set(&rotation, 0, player->rotationSpeed * delta_time, 0);
    Player_Rotate(player, &rotation);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix,&rotation, EULER_ANGLE_REVERSED);
    Vector3_Set(&rotation, current_rotation.x, 0, current_rotation.z);
    Matrix3x3_TransformMatrix(&RotationMatrix, &rotation);
    Player_Rotate(player, &rotation);
}
void Player_RotateRight(struct Player *player, double delta_time){
    struct Vector3 rotation;
    struct Vector3 current_rotation;

    Vector3_Copy(&player->canvas.camera_transform.rotation,&current_rotation);
    Vector3_Set(&rotation, -current_rotation.x, 0, -current_rotation.z);
    Player_Rotate(player, &rotation);
    Vector3_Set(&rotation, 0, -player->rotationSpeed * delta_time, 0);
    Player_Rotate(player, &rotation);
    struct Matrix3x3 RotationMatrix;
    Matrix3x3_FromEulerAngle(&RotationMatrix, &rotation, EULER_ANGLE_REVERSED);
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
