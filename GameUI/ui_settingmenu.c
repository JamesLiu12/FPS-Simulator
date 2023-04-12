#include "ui_settingmenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ui_startmenu.h"
void UI_SettingMenu_Init(struct UI_SettingMenu *settingui){
    settingui->pointer=0;
    strcpy(settingui->menu[0],"Frame Rate  ");
    strcpy(settingui->menu[1],"Difficulty  ");
    strcpy(settingui->menu[2],"Sensitivity ");
    strcpy(settingui->menu[3],"            ");

    strcpy(settingui->difficultylevel[0],"Easy   ");
    strcpy(settingui->difficultylevel[1],"Normal ");
    strcpy(settingui->difficultylevel[2],"Hard   ");

    settingui->framerate=60;
    settingui->difficulty=1;
    settingui->sensitivity=100;
    /*FILE *fp=fopen("./setting.cfg","r");
    fscanf(fp,"%d",&settingui->framerate);
    fscanf(fp,"%d",&settingui->difficulty);
    fscanf(fp,"%d",&settingui->sensitivity);
    fclose(fp);*/
}
void Write_Setting(struct UI_SettingMenu *settingui){
    FILE *fp=NULL;
    fp=fopen("setting.cfg","w+");
    fprintf(fp,"%d\n",settingui->framerate);
    fprintf(fp,"%d\n",settingui->difficulty);
    fprintf(fp,"%d",settingui->sensitivity);
    fclose(fp);
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
        if(i!=3){for(int j=0;j<12;j++)printf("%c",settingui->menu[i][j]);
        for(int j=0;j<8;j++)printf(" ");}
        switch(i){
            case 0:
            if(settingui->pointer==i){
                printf("\033[3;47;35m%d \033[0m",settingui->framerate);
            }
            else{
                printf("%d",settingui->framerate);
            }
            break;
            case 1:
            if(settingui->pointer==i){
                for(int j=0;j<7;j++)
                printf("\033[3;47;35m%c\033[0m",settingui->difficultylevel[settingui->difficulty][j]);
            }
            else{
                for(int j=0;j<6;j++)
                printf("%c",settingui->difficultylevel[settingui->difficulty][j]);
            }
            break;
            case 2:
            if(settingui->pointer==i){
                printf("\033[3;47;35m%d%% \033[0m",settingui->sensitivity);
            }
            else{
                printf("%d%%",settingui->sensitivity);
            }
            break;
            case 3:
            if(settingui->pointer==i){
                printf("\033[3;47;35mBack \033[0m");
            }
            else{
                printf("Back");
            }
            break;
            default:
            break;
        }
        printf("\n");
    }
}
void Launch_SettingMenu(struct UI_SettingMenu *settingui){
    int operation=0;
    int RETURNFLAG=0;
    settingui->pointer=0;
    while(operation!=3){
        if(RETURNFLAG==1)break;
        system("clear");
        SettingMenu_Show(settingui);
        operation=Fetch_Operation();
        switch (operation)
        {
        case 1:
            settingui->pointer++;
            if(settingui->pointer==4)settingui->pointer=0;
            break;
        case 2:
            settingui->pointer--;
            if(settingui->pointer==-1)settingui->pointer=3;
            break;
        case 3:
            //printf("BACKBACKBACK");
            if(settingui->pointer==3)RETURNFLAG=1;
            break;
        case 4:
            switch (settingui->pointer)
            {
            case 0:
                settingui->framerate+=5;
                if(settingui->framerate>=120)settingui->framerate=30;
                break;
            case 1:
                settingui->difficulty++;
                if(settingui->difficulty>2)settingui->difficulty=0;
                break;
            case 2:
                if(settingui->sensitivity<=115)settingui->sensitivity+=5;
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (settingui->pointer)
            {
            case 0:
                settingui->framerate-=5;
                if(settingui->framerate>=120)settingui->framerate=30;
                break;
            case 1:
                settingui->difficulty--;
                if(settingui->difficulty<0)settingui->difficulty=0;
                break;
            case 2:
                if(settingui->sensitivity>=45)settingui->sensitivity-=5;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        operation=0;
        
    }
    return;
}