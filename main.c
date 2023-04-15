//#define OP_ENGINE_CHROMATIC
#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "Game/player.h"
#include "GameUI/ui_startmenu.h"
static sig_atomic_t end = 0;
static void sighandler(int signo)
{
    end = 1;
    //printf("good beye!\n");
}
int main() {
    term_setup(sighandler);
    system("clear");    

    struct UI_StartMenu *startui=New_UI_StartMenu();
    UI_StartMenu_Init(startui);
    Launch_StartMenu(startui);
    term_restore();
	sleep(1);
    return 0;
}