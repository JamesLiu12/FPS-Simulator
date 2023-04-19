#include "runner.h"
#include "../op_engine/op_engine.h"
#include "scene.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
void Runner_Init(struct Runner *runner,struct UI_SettingMenu *settingui){
    runner->frame_rate=settingui->framerate;
    runner->difficulty=settingui->difficulty;
    runner->sensitivity=settingui->sensitivity;
    runner->previousFrameTime = ProgramRunTime();
}
int Runner_Run(struct Runner *runner){
    struct Scene scene1;

    Scene_Init(&scene1);
    
    //Scene_Load(&scene1,1);这里应该写个scene读取,做几个scene的预制件,多个地图//TODO

    //Player_Setting(&scene1.player,runner);
    /*
    struct Player *player = New_Player(runner);
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0.1, 0, 0);

    struct Mesh *mesh = ModelCube_New();
    struct Transform transform;
    Transform_Init(&transform, NULL);
    struct Object *obj1 = Object_New(mesh, &transform, FLOOR, NULL, 0),
                  *obj2 = Object_New(mesh, &transform, WALL, NULL, 0);
    Vector3_Set(&obj1->transform.position, 0, 0, 5);
    Vector3_Set(&obj2->transform.position, 3, 3, 8);
    struct Object *obj3 = Object_New(mesh, &transform, FLOOR, NULL, 0);
    Vector3_Set(&obj3->transform.position, 5, 0, 0);
    struct Object *obj4 = Object_New(mesh, &transform, FLOOR, NULL, 0);
    Vector3_Set(&obj4->transform.position, -5, -2, 0);
    //struct Vector3 rot;
    //Vector3_Set(&rot, -1, 0, 0);
    //Canvas_CameraRotate(&player->canvas, &rot);
    //Player_Rotate(player,&rot);


    /*for (int i = 0; i < 50; i++) {
        Canvas_clear(&player->canvas);
        Object_Show(obj1, &player->canvas);
        Object_Show(obj2, &player->canvas);
        Player_Rotate(player, &rotation);
        Canvas_flush(&player->canvas);
        getchar();
    }*/
    int count;
    struct Vector3 ZeroVector;
    Vector3_Set(&ZeroVector,0,0,0);
    struct Vector3 New_moveX,New_moveZ;
    Vector3_Set(&New_moveX,0,0,0);
    Vector3_Set(&New_moveZ,0,0,0);
    int isBlocked;
    while(1){
        count++;
        Vector3_Set(&scene1.player.moveDirection, 0, 0, 0);
        isBlocked=0;
        if(kbhit()){
//            Player_Control(&scene1.player);
//            //Player_Move(&scene1.player, &scene1.player.movedirection);
//            if(!Vector3_Equal(&ZeroVector,&scene1.player.moveDirection)){
//                Vector3_Set(&New_moveX,scene1.player.moveDirection.x,0,0);
//                Player_Move(&scene1.player,&New_moveX);
//                for(int i=0;i<scene1.list_Object.size;i++){
//                    struct Object *object = ((struct Object**)scene1.list_Object.data)[i];
//                    if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,object->collideBoxes,&object->transform)){
//                    isBlocked=1;if(isBlocked)break;}
//                }
//                for(int i=0;i<scene1.list_Enemy.size;i++){
//                    struct Enemy *enemy = ((struct Enemy**)scene1.list_Enemy.data)[i];
//                    if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,enemy->body.collideBoxes,&enemy->transform)){
//                    isBlocked=1;if(isBlocked)break;}
//                }
//                if(isBlocked){Vector3_Set(&New_moveX,-scene1.player.moveDirection.x,0,0);Player_Move(&scene1.player,&New_moveX);}
//                isBlocked=0;
//                Vector3_Set(&New_moveZ,0,0,scene1.player.moveDirection.z);
//                Player_Move(&scene1.player,&New_moveZ);
//                for(int i=0;i<scene1.list_Object.size;i++){
//                    struct Object *object = ((struct Object**)scene1.list_Object.data)[i];
//                    if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,object->collideBoxes,&object->transform)){
//                    isBlocked=1;if(isBlocked)break;}
//                }
//                for(int i=0;i<scene1.list_Enemy.size;i++){
//                    struct Enemy *enemy = ((struct Enemy**)scene1.list_Enemy.data)[i];
//                    if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,enemy->body.collideBoxes,&enemy->transform)){
//                    isBlocked=1;if(isBlocked)break;}
//                }
//                if(isBlocked){Vector3_Set(&New_moveZ,0,0,-scene1.player.moveDirection.z);Player_Move(&scene1.player, &New_moveZ);}
//
//            }
//            if(keydown(ESC))return 1;
//            for(int i=0;i<10;i++)kbhit();
//            //if(keydown(SPACE))break;
            
        }
            Scene_Show(&scene1,&scene1.player.canvas);
            /*Canvas_clear(&player->canvas);
            Object_Show(obj1, &player->canvas);
            Object_Show(obj2, &player->canvas);
            Object_Show(obj3, &player->canvas);
            Object_Show(obj4, &player->canvas);
            Canvas_flush(&player->canvas);*/
            if(scene1.player.DEADFLAG){return 0;}
            usleep(10000000/runner->frame_rate);
        //printf("count:  %d\n",count);
        //usleep(5000);
        //system("clear");
    }
//    for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    Del_Scene(&scene1);
    system("clear");
    printf("Goodbye!\n");
    return 1;
    //TODO
    //For each frame
}
void Runner_Load(struct Runner *runner){
    //TODO
    Runner_Run(runner);
}
void Del_Runner(struct Runner *runner){
    free(runner);
}
void Player_Setting(struct Player *player,struct Runner *runner){
    player->rotationSpeed= 0.1 * runner->sensitivity / 100;
}