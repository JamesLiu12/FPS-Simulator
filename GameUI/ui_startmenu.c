#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "ui_startmenu.h"
#include "ui_settingmenu.h"
#include "../op_engine/op_engine.h"
#include "../Game/game.h"
struct UI_StartMenu* New_UI_StartMenu() {
    struct UI_StartMenu* startui = malloc(sizeof(struct UI_StartMenu));
    UI_StartMenu_Init(startui);
    return startui;
}
void UI_StartMenu_Init(struct UI_StartMenu *startui){
    startui->pointer=0;
    strcpy(startui->menu[0],"New Game");
    strcpy(startui->menu[1],"  Load  ");
    strcpy(startui->menu[2],"Settings");
    strcpy(startui->menu[3],"  Exit  ");
    UI_SettingMenu_Init(&startui->settingui);
}
void Show_StartMenu(struct UI_StartMenu *startui){
    /*printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");*/
    printf(R"(    ___         __  _ _____ _      _       __   ____      _____ _       _ __       
   /   |  _____/ /_(_) ___/(_)____(_)___ _/ /  /  _/___  / ___/(_)___  (_) /___  __
  / /| | / ___/ __/ / /__ / / ___/ / __ `/ /   / // __ \/ /__ / / __ \/ / __/ / / /
 / ___ |/ /  / /_/ / ___// / /__/ / /_/ / /  _/ // / / / ___// / / / / / /_/ /_/ / 
/_/  |_/_/   \__/_/_/   /_/\___/_/\__,_/_/  /___/_/ /_/_/   /_/_/ /_/_/\__/\__, /  
                                                                          /____/   )");
    printf("\n");
    for(int i=0;i<4;i++){
        if(startui->pointer!=i){
            for(int j=0;j<36;j++)printf(" ");
            printf("/----------\\\n");
            for(int j=0;j<36;j++)printf(" ");
            printf("| ");
            for(int j=0;j<8;j++)printf("%c",startui->menu[i][j]);
            printf(" |\n");
            for(int j=0;j<36;j++)printf(" ");
            printf("\\----------/\n");
        }
        else{
            for(int j=0;j<36;j++)printf(" ");
            printf("\033[3;47;35m/----------\\\n\033[0m");
            for(int j=0;j<32;j++)printf(" ");
            printf("\033[1;37m►\033[0m");
            for(int j=0;j<3;j++)printf(" ");
            printf("\033[3;47;35m| \033[0m");
            for(int j=0;j<8;j++)printf("\033[3;47;35m%c\033[0m",startui->menu[i][j]);
            printf("\033[3;47;35m |\n\033[0m");
            for(int j=0;j<36;j++)printf(" ");
            printf("\033[3;47;35m\\----------/\n\033[0m");
            }
        printf("\n");}
}
int Fetch_Operation(){
    //return 1 is rolling down
    //return 2 is rolling up
    //return 3 is selecting
    //return 4 is increasing
    //return 5 is decreasing
    while(1){
        if(kbhit()){
        if(keydown(DOWN)||keydown(S))return 1;
        if(keydown(UP)||keydown(W))return 2;
        if(keydown(ENTER))return 3;
        if(keydown(RIGHT)||keydown(D))return 4;
        if(keydown(LEFT)||keydown(S))return 5;
    }
    }
    return 0;
}
void Launch_StartMenu(struct UI_StartMenu *startui){
    int operation;
    STARTMENUORIGIN:
    operation=0;
    while(operation!=3){
        system("clear");
        Show_StartMenu(startui);
        operation=Fetch_Operation();
        if(operation==1){
            startui->pointer++;
            if(startui->pointer==4)startui->pointer=0;
        }
        if(operation==2){
            startui->pointer--;
            if(startui->pointer==-1)startui->pointer=3;
        }
    }
    if(startui->pointer<0||startui->pointer>=4){
        printf("Pointer Error");
        sleep(5);
        return;
    }
    switch(startui->pointer){
        case 0:
            struct Runner runner;
            Runner_Init(&runner);
            Runner_Run(&runner);
            //TODO
            //Del_Runner(&runner);
            break;
        case 1:
            //Load_Runner();
            //TODO
            break;
        case 2:
            Launch_SettingMenu(&startui->settingui);
            goto STARTMENUORIGIN;
            //TODO
            break;
        case 3:
        printf("\nGoodbye\n");
            break;
        default:
        break;
    }
    //sleep(3);
    return;
}