#ifndef Game_UI_StartMenu
#include "ui_settingmenu.h"
struct UI_StartMenu {
    int pointer;
    char menu[4][8];
    struct UI_SettingMenu settingui;

};
struct UI_StartMenu* New_UI_StartMenu();
void UI_StartMenu_Init(struct UI_StartMenu *Smenu);
void Show_StartMenu(struct UI_StartMenu *Smenu);
int Fetch_Operation();
void Launch_StartMenu(struct UI_StartMenu *startui);
#define Game_UI_StartMenu
#endif
