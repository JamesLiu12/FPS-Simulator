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

    Scene_Init(&scene);

    while (1){
        runner->delta_time = ProgramRunTime() - runner->previousFrameTime;
        runner->previousFrameTime = ProgramRunTime();
        Scene_Update(&scene, runner->delta_time);
    }
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