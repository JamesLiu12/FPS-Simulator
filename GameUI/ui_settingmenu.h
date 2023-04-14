#ifndef Game_UI_SettingMenu
struct UI_SettingMenu {
    int pointer;
    char menu[4][12],difficultylevel[3][7];
    int framerate,difficulty;
    int sensitivity;
};
void UI_SettingMenu_Init(struct UI_SettingMenu *settingui);
void Write_Setting(struct UI_SettingMenu *settingui);
void SettingMenu_Show(struct UI_SettingMenu *settingui);
void Launch_SettingMenu(struct UI_SettingMenu *settingui);
#define Game_UI_SettingMenu
#endif
