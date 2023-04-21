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
    double deltatime;
    Scene_Init(&scene1);
    Player_Setting(&scene1.player,runner);
    //Scene_Load(&scene1,1);这里应该写个scene读取,做几个scene的预制件,多个地图//TODO

    int count;
    struct Vector3 ZeroVector;
    Vector3_Set(&ZeroVector,0,0,0);
    struct Vector3 New_moveX,New_moveZ;
    Vector3_Set(&New_moveX,0,0,0);
    Vector3_Set(&New_moveZ,0,0,0);
    int isBlocked;
    while(1){
        deltatime=ProgramRunTime()-runner->previousFrameTime;
        runner->previousFrameTime=ProgramRunTime();
        count++;
        Vector3_Set(&scene1.player.moveDirection, 0, 0, 0);
        isBlocked=0;
        if(kbhit()){
            Player_Control(&scene1.player,deltatime);
            Player_Move(&scene1.player, &scene1.player.moveDirection);
           /*if(!Vector3_Equal(&ZeroVector,&scene1.player.moveDirection)){
               Vector3_Set(&New_moveX,scene1.player.moveDirection.x,0,0);
               Player_Move(&scene1.player,&New_moveX);
               for(int i=0;i<scene1.list_Object.size;i++){
                   struct Object *object = ((struct Object**)scene1.list_Object.data)[i];
                   if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,object->collideBoxes,&object->transform)){
                   isBlocked=1;if(isBlocked)break;}
               }
               for(int i=0;i<scene1.list_Enemy.size;i++){
                   struct Enemy *enemy = ((struct Enemy**)scene1.list_Enemy.data)[i];
                   if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,enemy->body.collideBoxes,&enemy->transform)){
                   isBlocked=1;if(isBlocked)break;}
               }
               if(isBlocked){Vector3_Set(&New_moveX,-scene1.player.moveDirection.x,0,0);Player_Move(&scene1.player,&New_moveX);}
               isBlocked=0;
               Vector3_Set(&New_moveZ,0,0,scene1.player.moveDirection.z);
               Player_Move(&scene1.player,&New_moveZ);
               for(int i=0;i<scene1.list_Object.size;i++){
                   struct Object *object = ((struct Object**)scene1.list_Object.data)[i];
                   if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,object->collideBoxes,&object->transform)){
                   isBlocked=1;if(isBlocked)break;}
               }
               for(int i=0;i<scene1.list_Enemy.size;i++){
                   struct Enemy *enemy = ((struct Enemy**)scene1.list_Enemy.data)[i];
                   if(CollideBox_IsCollide(&scene1.player.collideBox,&scene1.player.transform,enemy->body.collideBoxes,&enemy->transform)){
                   isBlocked=1;if(isBlocked)break;}
               }
               if(isBlocked){Vector3_Set(&New_moveZ,0,0,-scene1.player.moveDirection.z);Player_Move(&scene1.player, &New_moveZ);}
                      }*/
            if(keydown(ESC)){break;}
            for(int i=0;i<10;i++)kbhit();// to clear input buffer
            if(keydown(SPACE))break;
        }
            if(scene1.player.FIREFLAG==1){
                Scene_PlayerShoot(&scene1);
            }
            Player_Update(&scene1.player, deltatime);
            Clear_Enemy(&scene1);
            Scene_Show(&scene1, &scene1.player.canvas);
            //printf("\ntime: %lf \n",ProgramRunTime());
            //printf("deltatime: %lf\n",deltatime);
            //printf("\nfire:%d, inCD: %d, CDremaining: %lf", scene1.player.FIREFLAG, scene1.player.In_FireCD, scene1.player.fireCDcounter);
            //printf("\nreload:%d, inCD: %d, CDremaining: %lf", scene1.player.RELOADFLAG, scene1.player.In_ReloadCD, scene1.player.reloadCDcounter);
            
            if(scene1.player.DEADFLAG){system("clear");return 0;}
            usleep(1000000/runner->frame_rate+(int)((ProgramRunTime()-runner->previousFrameTime)*1000000));
    }
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
    player->rotationSpeed= 10 * runner->sensitivity / 100;
}