#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "ui_startmenu.h"
#include "ui_settingmenu.h"
#include "ui_instruction.h"
#include "../Game/runner.h"
#include "ui_defeatmenu.h"
struct UI_StartMenu* New_UI_StartMenu() {
    struct UI_StartMenu* startui = malloc(sizeof(struct UI_StartMenu));
    UI_StartMenu_Init(startui);
    return startui;
}
void UI_StartMenu_Init(struct UI_StartMenu *startui){
    startui->pointer=0;
    strcpy(startui->menu[0],"New Game");
    strcpy(startui->menu[1]," Weapon ");
    strcpy(startui->menu[2],"Settings");
    strcpy(startui->menu[3],"  Exit  ");
    UI_SettingMenu_Init(&startui->settingui);
    UI_WeaponMenu_Init(&startui->weaponui);
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

void Launch_StartMenu(struct UI_StartMenu *startui){
    int operation;
    int end;
    struct Runner runner;
    STARTMENUORIGIN:
    for(int i=0;i<20;i++)kbhit();
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
    STARTUI_ENTER:
    for(int i=0;i<20;i++)kbhit();
    switch(startui->pointer){
        case 0:
            Runner_Init(&runner,&startui->settingui);
            end=Runner_Run(&runner);
            system("clear");
            //Del_Runner(&runner);
            if(end){
                //TODO
                Victory();
                goto STARTMENUORIGIN;
            }
            else{
                //TODO
                //Defeat();
                struct UI_DefeatMenu defeatui;
                UI_DefeatMenu_Init(&defeatui);
                int endchoice;
                endchoice=Launch_DefeatMenu(&defeatui);
                switch (endchoice){
                    case 0:
                    startui->pointer=0;goto STARTUI_ENTER;
                    case 1:
                    goto STARTMENUORIGIN;
                    case 2:
                    startui->pointer=3;goto STARTUI_ENTER;
                    default:
                    break;
                }

            }
            //TODO
            //Del_Runner(&runner);
            break;
        case 1:
            startui->settingui.weaponnumber = Launch_UI_WeaponMenu(&startui->weaponui);
            goto STARTMENUORIGIN;
            break;
        case 2:
            Launch_SettingMenu(&startui->settingui);
            goto STARTMENUORIGIN;
            //TODO
            break;
        case 3:
            break;
        default:
        break;
    }
    //sleep(3);
    return;
}
void printchar(int n, char a){
    for(int i=0;i<n;i++)printf("%c",a);
}
void printdialog(char a[]){
    printf("\n");
    int linecounter,totalcounter;
        printchar(25,' ');
        printchar(60,'_');
        printf("\n");
        printchar(24,' ');
        printchar(1,'/');
        printchar(60,' ');
        printchar(1,'\\');
        printf("\n");
        totalcounter=0;
        while(1){
            printchar(24,' ');
            printchar(1,'|');
            printchar(2,' ');
            linecounter=0;
            while(linecounter<56){
                if(totalcounter>=strlen(a))break;
                if(a[totalcounter]=='\n'){totalcounter++;break;}
                printf("%c",a[totalcounter]);
                linecounter++;
                totalcounter++;
            }
            printchar(58-linecounter,' ');
            printchar(1,'|');
            printf("\n");
            if(totalcounter>=strlen(a))break;
        }
        printchar(24,' ');
        printchar(1,'\\');
        printchar(60,'_');
        printchar(1,'/');
        printf("\n");
}
int minimum(int a,int b){
    return a<b?a:b;
}
void printeye(){
    printf(R"(------_________________________                                                 _________________________------
      |                     --|                                                |--                     |      
      |                     --|                                                |--                     |      
      |                     --|                       ▒▒                       |--                     |      
      |                     --|                      ▒▒▒▒                      |--                     |      
      |                     --|                     ▒▒▒▒▒▒                     |--                     |      
      |                     --|                    ▒▒▒▒▒▒▒▒                    |--                     |      
      |                     --|                   ▒▒▒▒▒▒▒▒▒▒                   |--                     |      
      |                     --|                  ▒▒▒▒▒▒▒▒▒▒▒▒                  |--                     |      
      |                     --|                 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒                 |--                     |      
      |                     --|                ▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒                |--                     |      
      |                     --|               ▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒               |--                     |      
      |                     --|              ▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒              |--                     |      
      |                     --|             ▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒             |--                     |      
      |                     --|            ▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒            |--                     |      
      |                     --|           ▒▒▒▒▒▒▒▓▓░░░░░░░░▓▓▒▒▒▒▒▒▒           |--                     |      
      |                     --|          ▒▒▒▒▒▒▒▓░░  ████  ░░▓▒▒▒▒▒▒▒          |--                     |      
      |                     --|           ▒▒▒▒▒▓▓▓▓░░░░░░░░▓▓▓▓▒▒▒▒▒           |--                     |      
      |                     --|            ▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒            |--                     |      
      |                     --|             ▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒             |--                     |      
      |                     --|              ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒              |--                     |      
      |                     --|               ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒               |--                     |      
      |                     --|                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                |--                     |      
      |                     --|                 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒                 |--                     |      
      |                     --|                  ▒▒▒▒▒▒▒▒▒▒▒▒                  |--                     |      
      |                     --|                   ▒▒▒▒▒▒▒▒▒▒                   |--                     |      
      |                     --|                    ▒▒▒▒▒▒▒▒                    |--                     |      
      |                     --|                     ▒▒▒▒▒▒                     |--                     |      
      |                     --|                      ▒▒▒▒                      |--                     |      
      |                     --|                       ▒▒                       |--                     |      
      |                     --|                                                |--                     |      )");
    printf("\n------________________________|                                                |________________________------\n");
}
void Victory(){
    int temp;
    char a[200];
    int linecounter,totalcounter;
        strcpy(a,"You: This is the end. Right?\n\n(press E to open the door)");
        system("clear");
        printchar(30,'-');
        printchar(25,'_');
        printf(" ");
        printchar(25,'_');
        printchar(30,'-');
        printf("\n");
        for(int k=0;k<30;k++){
            printchar(30,' ');
            printf("|");
            printchar(21,' ');
            printf("--| ");
            printf("|--");
            printchar(21,' ');
            printf("|");
            printchar(30,' ');
        printf("\n");
        }
        printchar(30,'-');
        printchar(25,'_');
        printf(" ");
        printchar(25,'_');
        printchar(30,'-');
        printf("\n");
        printdialog(a);
        while(1){
            if(kbhit())if(keydown(E))break;
        }

    for(int i=0;i<25;i++){
        system("clear");
        printchar(30-i,'-');
        printchar(25,'_');
        printchar(2*i+1,' ');
        printchar(25,'_');
        printchar(30-i,'-');
        printf("\n");
        for(int k=0;k<30;k++){
            printchar(30-i,' ');
            printf("|");
            printchar(21,' ');
            printf("--|");
            temp=minimum(k,30-k)*2+(i-10)*2-30;
            if(temp>0){
                printchar((i*2+1-temp)/2,' ');
                for(int j=0;j<temp;j++)printf("▒");
                printchar((i*2+1-temp)/2,' ');
            }
            else{
                printchar(2*i,' ');
            }
                //for(int j=0;j<2*i;j++){printf(" ");}
            
            printf("|--");
            for(int j=0;j<21;j++){printf(" ");}
            printf("|");
            for(int j=0;j<30-i;j++){printf(" ");}
        printf("\n");
        }
        for(int j=0;j<30-i;j++){printf("-");}
        for(int j=0;j<24;j++){printf("_");}
        printf("|");
        for(int j=0;j<2*i;j++){printf(" ");}
        printf("|");
        for(int j=0;j<24;j++){printf("_");}
        for(int j=0;j<30-i;j++){printf("-");}
        printf("\n");
        usleep(150000);
    }
    sleep(1);
    system("clear");
    for(int i=0;i<100;i++)kbhit();
    printeye();
    strcpy(a,"You: What ...\n\npress to continue");
    printdialog(a);
    while(1){if(kbhit())break;}

    system("clear");
    printeye();
    strcpy(a,"*mystery voice*: Well done\n\npress to continue");
    printdialog(a);
    while(1){if(kbhit())break;}

    system("clear");
    printeye();
    strcpy(a,"*mystery voice*: See you at the entrance\n\npress to continue");
    printdialog(a);
    while(1){if(kbhit())break;}

    strcpy(a,"Your vision gradually fades");

    for(int i=0;i<20;i++){
    system("clear");
    printeye();
    printdialog(a);
    printf("\033[1;1H");
    for(int j=1;j<=i;j++){
        //printf("\033[0J");
        printf("\033[%d;1H",j);
        printf("\r");
        printchar(120,' ');
        printf("\n");
    }
    usleep(150000);
    }
    
    strcpy(a,"                        Victory");

    for(int i=20;i<27;i++){
    system("clear");
    printeye();
    printdialog(a);
    printf("\033[1;1H");
    for(int j=1;j<=i;j++){
        //printf("\033[0J");
        printf("\033[%d;1H",j);
        printf("\r");
        printchar(120,' ');
        printf("\n");
    }
    usleep(150000);
    }

    strcpy(a,"                        Victory  ?");

    for(int i=27;i<40;i++){
    system("clear");
    printeye();
    printdialog(a);
    printf("\033[1;1H");
    for(int j=1;j<=i;j++){
        //printf("\033[0J");
        printf("\033[%d;1H",j);
        printf("\r");
        printchar(120,' ');
        printf("\n");
    }
    usleep(150000);
    }
    //usleep(200000);

    usleep(1000000);
    printf("\033[1;1H");
}