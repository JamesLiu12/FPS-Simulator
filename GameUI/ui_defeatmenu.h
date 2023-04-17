#ifndef Game_UI_DefeatMenu
#include "ui_settingmenu.h"
struct UI_DefeatMenu {
    int pointer;
    char menu[3][12];
};
void UI_DefeatMenu_Init(struct UI_DefeatMenu *defeatui);
void Show_DefeatMenu(struct UI_DefeatMenu *defeatui);
int Launch_DefeatMenu(struct UI_DefeatMenu *defeatui);
#define Game_UI_DefeatMenu
#endif