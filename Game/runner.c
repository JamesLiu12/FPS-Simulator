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
    struct Scene scene;
    double deltatime;
    Scene_Init(&scene);
    Player_Setting(&scene.player,runner);
    //Scene_Load(&scene1,1);这里应该写个scene读取,做几个scene的预制件,多个地图//TODO
    while(1){
        deltatime=ProgramRunTime()-runner->previousFrameTime;
        runner->previousFrameTime=ProgramRunTime();
        if(kbhit()){
            Player_Control(&scene.player,deltatime);
            if(keydown(ESC)){break;}
            //for(int i=0;i<10;i++)kbhit();// to clear input buffer
        }
            Scene_Update(&scene,deltatime);
            // Player_Update(&scene.player, deltatime);
            // Clear_Enemy(&scene);
            //Scene_Show(&scene, &scene.player.canvas);
            //printf("\ntime: %lf \n",ProgramRunTime());
            //printf("deltatime: %lf\n",deltatime);
            //printf("\nfire:%d, inCD: %d, CDremaining: %lf", scene.player.FIREFLAG, scene.player.In_FireCD, scene.player.fireCDcounter);
            //printf("\nreload:%d, inCD: %d, CDremaining: %lf", scene.player.RELOADFLAG, scene.player.In_ReloadCD, scene.player.reloadCDcounter);
            
            if(scene.player.DEADFLAG){system("clear");return 0;}
            usleep(1000000/runner->frame_rate);
    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    Del_Scene(&scene);
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