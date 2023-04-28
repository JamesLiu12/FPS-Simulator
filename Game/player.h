#ifndef FPS_SIMULATOR_PLAYER_H
#define FPS_SIMULATOR_PLAYER_H
#include "weapon.h"

//The character user operates in the game
struct Player{
    //The camera and the screen displayed for the user
    struct Canvas canvas;

    /*
     * maxHealth: the initial HP of player
     * health: the HP of player now
     * moveSpeed: the move speed of player
     * defence: the defence of player for damage got
     */
    double maxHealth, health, moveSpeed, rotationSpeed, defence;
    struct Transform transform;

    //The collideBox for player
    struct CollideBox collideBox;

    //The direction of player facing now
    struct Vector3 facing;

    //The displacement of player in this frame
    struct Vector3 move;

    /*
     * fireCDcounter: the time left for next shoot
     * reloadCDcounter: the time left for finishing reload
     * weapon: the weapon that player has in hand
     * inFireCD: if the player could fire
     * FIREFLAG: if the player fires in this frame
     * inReloadCD: if the player could reload
     * RELOADFLAG: if the player reloads this frame
     * DEADFLAG: if the player has dead
     * WINFLAG: if the player has win
     * QUITFLAG: if the player has quit the game
     */
    double fireCDcounter,reloadCDcounter;
    struct Weapon weapon;
    int inFireCD, FIREFLAG, inReloadCD, RELOADFLAG, DEADFLAG, WINFLAG,QUITFLAG;
};

//Initializer of player
void Player_Init(struct Player *player, enum WeaponName weaponname);

//Newer of Player
struct Player* New_Player(enum WeaponName weaponname);

//Deleter of Player
void Del_Player(struct Player *player);

//Let player displace a vector
void Player_Move(struct Player *player, struct Vector3* move);

//Let player rotate an Euler angle
void Player_Rotate(struct Player *player, struct Vector3* angle);

//What player does each frame
void Player_Update(struct Player *player, double delta_time);

//Displacement operations of player
void Player_MoveForward(struct Player *player, double delta_time);
void Player_MoveBackward(struct Player *player, double delta_time);
void Player_MoveLeft(struct Player *player, double delta_time);
void Player_MoveRight(struct Player *player, double delta_time);

//Rotate operations of player
void Player_RotateUp(struct Player *player, double delta_time);
void Player_RotateDown(struct Player *player, double delta_time);
void Player_RotateLeft(struct Player *player, double delta_time);
void Player_RotateRight(struct Player *player, double delta_time);

//Get user control and update player
void Player_Control(struct Player *player, double delta_time);

//Player pause the game
void Player_Pause(struct Player *player);

//Update data for a shoot
void Player_Shoot(struct Player *player);

//Update data for a reloading
void Player_Reload(struct Player *player);

//Change HP of player
void Player_ChangeHealth(struct Player *player,double deltaHealth);

//Set the position of player
void Player_SetPosition(struct Player *player, double x, double y, double z);
#endif //FPS_SIMULATOR_PLAYER_H
