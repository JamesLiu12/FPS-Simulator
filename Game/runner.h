
#ifndef FPS_SIMULATOR_RUNNER_H
#define FPS_SIMULATOR_RUNNER_H
#include "../GameUI/Game_UI.h"
#include "player.h"
struct Runner{
    int frame_rate, difficulty;
    int sensitivity;
    //struct Scene scene;
    double delta_time, previousFrameTime;
};

int Runner_Run(struct Runner *runner);//return 0 for losing, 1 for victory
void Runner_Init(struct Runner *runner,struct UI_SettingMenu *settingui);
void Runner_Load(struct Runner *runner);
void Del_Runner(struct Runner *runner);
void Player_Setting(struct Player *player,struct Runner *runner);
#endif //FPS_SIMULATOR_RUNNER_H
