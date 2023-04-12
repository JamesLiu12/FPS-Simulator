#include "ui_settingmenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void UI_SettingMenu_Init(struct UI_SettingMenu *settingui){
    settingui->pointer=0;
    strcpy(settingui->menu[0],"Frame Rate  ");
    strcpy(settingui->menu[1],"Difficulty  ");
    strcpy(settingui->menu[2],"Sensitivity ");
    strcpy(settingui->menu[3],"   Back     ");

    strcpy(settingui->difficultylevel[0],"   Easy   ");
    strcpy(settingui->difficultylevel[1],"  Normal  ");
    strcpy(settingui->difficultylevel[2],"   Hard   ");
    freopen("setting.cfg","r",stdin);
    scanf("%d",&settingui->framerate);
    scanf("%d",&settingui->difficulty);
    scanf("%d",&settingui->sensitivity);
    fclose(stdin);
}
void Write_Setting(struct UI_SettingMenu *settingui){
    freopen("setting.cfg","w",stdout);
    printf("%d\n",settingui->framerate);
    fclose(stdout);
}
void SettingMenu_Show(struct UI_SettingMenu *settingui){
    printf(R"(    ___         __  _ _____ _      _       __   ____      _____ _       _ __       
   /   |  _____/ /_(_) ___/(_)____(_)___ _/ /  /  _/___  / ___/(_)___  (_) /___  __
  / /| | / ___/ __/ / /__ / / ___/ / __ `/ /   / // __ \/ /__ / / __ \/ / __/ / / /
 / ___ |/ /  / /_/ / ___// / /__/ / /_/ / /  _/ // / / / ___// / / / / / /_/ /_/ / 
/_/  |_/_/   \__/_/_/   /_/\___/_/\__,_/_/  /___/_/ /_/_/   /_/_/ /_/_/\__/\__, /  
                                                                          /____/   )");
    printf("\n");
    for(int i=0;i<4;i++){
        printf("\n");
        for(int j=0;j<28;j++)printf(" ");
        printf("%s",settingui->menu[i]);
        for(int j=0;j<8;j++)printf(" ");
        switch(i){
            case 0:
            if(settingui->pointer==i){
                printf("\033[3;47;35m%d\033[0m",settingui->framerate);
            }
            else{
                printf("%d",settingui->framerate);
            }
            break;
            case 1:
            if(settingui->pointer==i){
                printf("\033[3;47;35m%s\033[0m",settingui->difficultylevel[settingui->difficulty]);
            }
            else{
                printf("%s",settingui->difficultylevel[settingui->difficulty]);
            }
            break;
            case 2:
            break;
            case 3:
            break;
            default:
            break;
        }
        if(settingui->pointer==i){

        }
        else{

        }
        printf("\n");
    }
}
void Launch_SettingMenu(struct UI_SettingMenu *settingui){

}