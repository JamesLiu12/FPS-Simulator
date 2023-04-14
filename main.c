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
    //sleep(2);
    /*
    //struct Canvas *canvas = New_Canvas(64, 64);
    struct Player *player = New_Player();
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0.1, 0, 0);

    struct Mesh *mesh = ModelCube_New();
    struct Transform transform;
    Transform_Init(&transform, NULL);
    struct Object *obj1 = Object_New(mesh, &transform, FLOOR), *obj2 = Object_New(mesh, &transform, WALL);
    Vector3_Set(&obj1->transform.position, 0, 0, 5);
    Vector3_Set(&obj2->transform.position, 3, 3, 8);
    struct Object *obj3 = Object_New(mesh, &transform, FLOOR);
    Vector3_Set(&obj3->transform.position, 5, 0, 0);
    struct Object *obj4 = Object_New(mesh, &transform, FLOOR);
    Vector3_Set(&obj4->transform.position, -5, -2, 0);
    //struct Vector3 rot;
    //Vector3_Set(&rot, -1, 0, 0);
    //Canvas_CameraRotate(&player->canvas, &rot);
    //Player_Rotate(player,&rot);
    */

    /*for (int i = 0; i < 50; i++) {
        Canvas_clear(&player->canvas);
        Object_Show(obj1, &player->canvas);
        Object_Show(obj2, &player->canvas);
        Player_Rotate(player, &rotation);
        Canvas_flush(&player->canvas);
        getchar();
    }*/
    /*
    int count;
    while(1){
        count++;
        if(kbhit()){
            Player_Control(player);
            if(keydown(ESC))break;
            //if(keydown(SPACE))break;
            
        }
            Canvas_clear(&player->canvas);
            Object_Show(obj1, &player->canvas);
            Object_Show(obj2, &player->canvas);
            Object_Show(obj3, &player->canvas);
            Object_Show(obj4, &player->canvas);
            Canvas_flush(&player->canvas);
            printf("%lf %lf %lf\n",player->facing.x,player->facing.y,player->facing.z);
            printf("%lf %lf %lf\n",player->transform.position.x,player->transform.position.y,player->transform.position.z);
            usleep(1000000/FPS);
        //printf("count:  %d\n",count);
        //usleep(5000);
        //system("clear");
    }
//    for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    Del_Player(player);
    system("clear");
    printf("Goodbye!\n");*/

    term_restore();
	sleep(1);
    return 0;
}