#include "runner.h"
#include "../op_engine/op_engine.h"
#include "scene.h"
#include "../GameUI/ui_instruction.h"
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
    runner->weaponNumber = settingui->weaponnumber;
    runner->list_Weapon[0]=AK47;
    runner->list_Weapon[1]=P1999;
    runner->list_Weapon[2]=Razor_ELEC;
    runner->list_Weapon[3]=X_114514;
    runner->list_Weapon[4]=MOSS;
    runner->previousFrameTime = ProgramRunTime();
}
int Runner_Run(struct Runner *runner){
    int end=1;
    struct Scene scene;
    Scene_Init(&scene, runner->list_Weapon[runner->weaponNumber], runner->difficulty);
    Runner_SetPlayerRotationSpeed(&scene.player, runner->sensitivity);
    while(1){
        runner->delta_time= ProgramRunTime() - runner->previousFrameTime;
        runner->previousFrameTime = ProgramRunTime();
#ifdef _WIN32
        runner->delta_time *= 0.01;
#endif
        Scene_Update(&scene, runner->delta_time);

        if(scene.player.DEADFLAG || scene.player.QUITFLAG){
            screenclean();
            end=0;
            break;
        }
        if(scene.player.WINFLAG){
            screenclean();
            end=1;
            break;
        }
        if(scene.player.TRUEWINFLAG){
            screenclean();
            end=2;
            break;
        }
        usleep(1000000 / runner->frame_rate);
    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    Del_Scene(&scene);
    #ifdef __linux__
    system("clear");
    #endif
    printf("Goodbye!\n");
    return end;
    //TODO
    //For each frame
}

void Del_Runner(struct Runner *runner){

}
void Runner_SetPlayerRotationSpeed(struct Player *player, double sensitivity){
    player->rotationSpeed= 3 * sensitivity / 100;
}