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
    runner->weaponnumber = settingui->weaponnumber;
    runner->weaponlist[0]=P1999;
    runner->weaponlist[1]=AK47;
    runner->weaponlist[2]=Razor_ELEC;
    runner->weaponlist[3]=X_114514;
    runner->weaponlist[4]=MOSS;
    runner->previousFrameTime = ProgramRunTime();
}
int Runner_Run(struct Runner *runner){
    int end=1;
    struct Scene scene;
    double delta_time;
    Scene_Init(&scene, runner->weaponlist[runner->weaponnumber]);
    Runner_SetPlayerRotationSpeed(&scene.player, runner->sensitivity);
    while(1){
        delta_time= ProgramRunTime() - runner->previousFrameTime;
        runner->previousFrameTime = ProgramRunTime();
#ifdef _WIN32
        delta_time *= 0.01;
#endif
        Scene_Update(&scene, delta_time);

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
void Runner_Load(struct Runner *runner){
    //TODO
    Runner_Run(runner);
}
void Del_Runner(struct Runner *runner){
    
    free(runner);
}
void Runner_SetPlayerRotationSpeed(struct Player *player, double sensitivity){
    player->rotationSpeed= 3 * sensitivity / 100;
}