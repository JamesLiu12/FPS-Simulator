#ifndef Game_UI_WeaponSelectionMenu
#include "../Game/weapon.h"
#include "ui_instruction.h"
struct UI_WeaponMenu {
    int pointer;
    char Weapon_Name[5][10];
    char Description[5][100];

};
void UI_WeaponMenu_Init(struct UI_WeaponMenu *weaponui);
void Show_UI_WeaponMenu(struct UI_WeaponMenu *weaponui);
int Launch_UI_WeaponMenu(struct UI_WeaponMenu *weaponui);
#define Game_UI_WeaponSelectionMenu
#endif