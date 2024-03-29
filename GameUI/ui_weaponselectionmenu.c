#include "ui_weaponselectionmenu.h"
#include <stdio.h>
#include <string.h>
void UI_WeaponMenu_Init(struct UI_WeaponMenu *weaponui, int pointer){
    weaponui->pointer=pointer;
    //weapon name should be 10 charaters
    strcpy(weaponui->Weapon_Name[0],"   AK47   ");
    strcpy(weaponui->Weapon_Name[1],"  P1999   ");
    strcpy(weaponui->Weapon_Name[2],"Razor_ELEC");
    strcpy(weaponui->Weapon_Name[3]," X_114514 ");
    strcpy(weaponui->Weapon_Name[4],"   MOSS   ");
    //descroption as long as you want, no more than 100
    strcpy(weaponui->Description[0],"Old       fashioned,but still powerful.");
    strcpy(weaponui->Description[1],"A light   pistol,   accurate  shooters' favourite.");
    strcpy(weaponui->Description[2],"Shoot out electron  beams,    destroy   enemies   with the  power of  Electro.");
    strcpy(weaponui->Description[3],"Shoots out114514PHz X-ray beamdeveloped by the 24-year-old  scientist from Shimo-Kitazawa.");
    strcpy(weaponui->Description[4],"Magnetic  Oshen     SuperspeedShooter  (MOSS) usesmagnetic  field to O-oooooooooo AAAAE-A-A-I-A-U-O!");
    for(int i = 0; i < 5; i++){
        for(int j = strlen(weaponui->Description[i]); j < 100 ; j++) weaponui->Description[i][j]=' ';
    }
}

void Show_UI_WeaponMenu(struct UI_WeaponMenu *weaponui){
    screenclean();
    for(int k = 0; k < 5; k++){
        if(weaponui->pointer == k){
            for(int i = 0; i < 16 ; i++)printf("\033[3;47;30m-\033[0m");
        }
        else{
            for(int i = 0; i < 16 ; i++)printf("-");
        }
        for(int i = 0; i < 8 ; i++)printf(" ");
    }
    printf("\n");
    
    for(int i = 0; i < 5; i++){
        if(weaponui->pointer == i){
            printf("\033[3;47;30m|  \033[0m");
            for(int j = 0; j < 10 ; j++)printf("\033[3;47;30m%c\033[0m",weaponui->Weapon_Name[i][j]);
            printf("\033[3;47;30m  |\033[0m");
        }
        else{
            printf("|  ");
            for(int j = 0; j < 10 ; j++)printf("%c",weaponui->Weapon_Name[i][j]);
            printf("  |");
        }
        for(int j = 0; j < 8 ; j++)printf(" ");
    }
    printf("\n");
    
    for(int i = 0; i < 5; i++){
        if(weaponui->pointer == i){
            printf("\033[3;47;30m|  \033[0m");
            for(int j = 0; j < 10 ; j++)printf("\033[3;47;30m \033[0m");
            printf("\033[3;47;30m  |\033[0m");
        }
        else{
            printf("|  ");
            for(int j = 0; j < 10 ; j++)printf(" ");
            printf("  |");
        }
        for(int j = 0; j < 8 ; j++)printf(" ");
    }
    printf("\n");
    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 5 ; j++){
            if(weaponui->pointer == j){
                printf("\033[3;47;30m|  \033[0m");
                for(int k = 0; k < 10 ; k++)printf("\033[3;47;30m%c\033[0m",weaponui->Description[j][10*i+k]);
                printf("\033[3;47;30m  |\033[0m");
            }
            else {
                printf("|  ");
                for(int k = 0; k < 10 ; k++)printf("%c",weaponui->Description[j][10*i+k]);
                printf("  |");
            }

            for(int k = 0; k < 8 ; k++)printf(" ");
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++){
        if(weaponui->pointer == i){
            printf("\033[3;47;30m|  \033[0m");
            for(int j = 0; j < 10 ; j++)printf("\033[3;47;30m \033[0m");
            printf("\033[3;47;30m  |\033[0m");
        }
        else{
            printf("|  ");
            for(int j = 0; j < 10 ; j++)printf(" ");
            printf("  |");
        }
        for(int j = 0; j < 8 ; j++)printf(" ");
    }
    printf("\n");
    
    for(int i = 0; i < 5; i++){
        if(weaponui->pointer == i){
            printf("\033[3;47;30m|  \033[0m");
            for(int j = 0; j < 10 ; j++)printf("\033[3;47;30m_\033[0m");
            printf("\033[3;47;30m  |\033[0m");
        }
        else{
            printf("|  ");
            for(int j = 0; j < 10 ; j++)printf("_");
            printf("  |");
        }
        for(int j = 0; j < 8 ; j++)printf(" ");
    }
    printf("\n");
}
int Launch_UI_WeaponMenu(struct UI_WeaponMenu *weaponui){
    int operation;
    operation=0;
    while(operation != 3 && operation != 6){
        screenclean();
        Show_UI_WeaponMenu(weaponui);
        operation=Fetch_Operation(); 
        if(operation==4 || operation == 1){
            weaponui->pointer++;
            if(weaponui->pointer==5)weaponui->pointer=0;
        }
        if(operation==5 || operation == 2){
            weaponui->pointer--;
            if(weaponui->pointer==-1)weaponui->pointer=4;
        }
    }
    return weaponui->pointer;
}