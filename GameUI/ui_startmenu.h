#ifndef Game_UI_StartMenu
#include "ui_settingmenu.h"
#include "ui_weaponselectionmenu.h"
struct UI_StartMenu {
    int pointer;
    int tips_number;
    char tips_string[90];
    char menu[4][8];
    struct UI_SettingMenu settingui;
    struct UI_WeaponMenu weaponui;
};
struct UI_StartMenu* New_UI_StartMenu();
void UI_StartMenu_Init(struct UI_StartMenu *Smenu);
void Show_StartMenu(struct UI_StartMenu *Smenu);
void Launch_StartMenu(struct UI_StartMenu *startui);
void printchar(int n, char a);
void printdialog(char a[]);
void Victory();
void True_Victory();
#define Game_UI_StartMenu
#endif