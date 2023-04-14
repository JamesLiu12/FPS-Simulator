
#ifndef FPS_SIMULATOR_RUNNER_H
#define FPS_SIMULATOR_RUNNER_H
#include "../GameUI/Game_UI.h"
#include "player.h"
struct Runner{
    int frame_rate,difficulty;
    int sensitivity;
    //struct Scene scene;
    
};

void Runner_Run(struct Runner *runner);
void Runner_Init(struct Runner *runner,struct UI_SettingMenu *settingui);
void Runner_Load(struct Runner *runner);
void Del_Runner(struct Runner *runner);
void Player_Setting(struct Player *player,struct Runner *runner);
#endif //FPS_SIMULATOR_RUNNER_H
