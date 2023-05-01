#include "ui_instruction.h"
#include "../op_engine/input.h"
#include <stdlib.h>
#include <stdio.h>
int Fetch_Operation(){
    //return 1 is rolling down
    //return 2 is rolling up
    //return 3 is selecting
    //return 4 is increasing
    //return 5 is decreasing
    //return 6 is exiting
    while(1){
        if(kbhit()){
        if(keydown(DOWN)||keydown(S))return 1;
        if(keydown(UP)||keydown(W))return 2;
        if(keydown(ENTER))return 3;
        if(keydown(RIGHT)||keydown(D))return 4;
        if(keydown(LEFT)||keydown(A))return 5;
        if(keydown(ESC))return 6;
    }
    }
    return 0;
}
void screenclean(){
    // printf("\033[1;1H");
    // for(int i=0;i<60;i++){
    //     printf("\r");
    //     for(int j=0;j<150;j++)printf(" ");
    //     printf("\n");
    // }
    // printf("\033[1;1H");
#ifdef __linux
    system("clear");
#endif
#ifdef _WIN32
    system("cls");
#endif

}