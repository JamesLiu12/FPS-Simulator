#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "ui_defeatmenu.h"
#include "ui_instruction.h"
void UI_DefeatMenu_Init(struct UI_DefeatMenu *defeatui){
    defeatui->pointer=0;
    strcpy(defeatui->menu[0], "  New Game  ");
    strcpy(defeatui->menu[1], "Back to Menu");
    strcpy(defeatui->menu[2], "    Exit    ");

}
void Show_DefeatMenu(struct UI_DefeatMenu *defeatui){
    screenclean();
    printf(R"(██████╗ ██╗███████╗ ██████╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗
██╔══██╗██║██╔════╝██╔════╝██╔═══██╗████╗  ██║████╗  ██║██╔════╝██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║
██║--██║██║███████╗██║-_-- ██║--_██║██╔██╗-██║██╔██╗_██║█████╗__██║__--____██║ __██║██║___██║██╔██╗ ██║
██║| ██║██║╚════██║██║  |  ██║/  ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║  /-__  ██║   ██║██║   ██║██║╚██╗██║
██████╔╝██║███████║╚██████╗╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║
╚═════╝ ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝)");
    printf("\n");
    for(int i=0;i<3;i++){
        if(defeatui->pointer!=i){
            for(int j=0;j<44;j++)printf(" ");
            printf("/--------------\\\n");
            for(int j=0;j<44;j++)printf(" ");
            printf("| ");
            for(int j=0;j<12;j++)printf("%c",defeatui->menu[i][j]);
            printf(" |\n");
            for(int j=0;j<44;j++)printf(" ");
            printf("\\--------------/\n");
        }
        else{
            for(int j=0;j<44;j++)printf(" ");
            printf("\033[3;47;35m/--------------\\\n\033[0m");
            for(int j=0;j<40;j++)printf(" ");
            printf("\033[1;37m►\033[0m");
            for(int j=0;j<3;j++)printf(" ");
            printf("\033[3;47;35m| \033[0m");
            for(int j=0;j<12;j++)printf("\033[3;47;35m%c\033[0m",defeatui->menu[i][j]);
            printf("\033[3;47;35m |\n\033[0m");
            for(int j=0;j<44;j++)printf(" ");
            printf("\033[3;47;35m\\--------------/\n\033[0m");
            }
        printf("\n");}
}
int Launch_DefeatMenu(struct UI_DefeatMenu *defeatui){
    int operation;
    operation=0;
    while(operation!=3){
        screenclean();
        Show_DefeatMenu(defeatui);
        operation=Fetch_Operation(); 
        if(operation==1){
            defeatui->pointer++;
            if(defeatui->pointer==3)defeatui->pointer=0;
        }
        if(operation==2){
            defeatui->pointer--;
            if(defeatui->pointer==-1)defeatui->pointer=2;
        }
    }
    return defeatui->pointer;
}