#include "ui_instruction.h"
#include "../op_engine/input.h"
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
        if(keydown(LEFT)||keydown(S))return 5;
        if(keydown(ESC))return 6;
    }
    }
    return 0;
}