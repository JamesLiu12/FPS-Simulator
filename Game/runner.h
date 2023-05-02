
#ifndef FPS_SIMULATOR_RUNNER_H
#define FPS_SIMULATOR_RUNNER_H
#include "../GameUI/Game_UI.h"
#include "player.h"
#include "weapon.h"

//
struct Runner{
    /*
     * frame_rate: frame rate per second
     * difficulty: could be easy, normal, or hard
     * delta_time: the delta time for this frame
     * previousFrameTime: the time for last frame
     * weaponNumber: the number of weapon
     * list_Weapon: the list for storing weapons
     */
    int frame_rate, difficulty;
    int sensitivity;
    double delta_time, previousFrameTime;
    int weaponNumber;
    enum WeaponName list_Weapon[5];
};

//Run the game
int Runner_Run(struct Runner *runner);//return 0 for losing, 1 for victory

//Initializer of runner
void Runner_Init(struct Runner *runner,struct UI_SettingMenu *settingui);

//Deleter of runner
void Del_Runner(struct Runner *runner);

//Set the rotation speed of player
void Runner_SetPlayerRotationSpeed(struct Player *player, double sensitivity);
#endif //FPS_SIMULATOR_RUNNER_H
