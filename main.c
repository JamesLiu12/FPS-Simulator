//#define OP_ENGINE_CHROMATIC
#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>
#include <termios.h>
#include "Game/player.h"
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

static sig_atomic_t end = 0;
static void sighandler(int signo)
{
    end = 1;
    printf("good beye!\n");
}
int main() {
    //init_keyboard();
    term_setup(sighandler);
    //struct Canvas canvas = New_canvas(64, 64);
    struct Player *player;
    Player_Init(player);
    struct Vector3 movement;
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0, 0, 0);
    Vector3_Set(&movement, 0, 0, 0);

    struct Mesh *mesh = ModelCube_New();
    struct Object *obj1 = Object_New(mesh, FLOOR), *obj2 = Object_New(mesh, WALL);
    Vector3_Set(&obj1->transform.position, 0, 0, 5);
    Vector3_Set(&obj2->transform.position, 3, 3, 8);
    struct Object *obj3 = Object_New(mesh, FLOOR);
    Vector3_Set(&obj3->transform.position, 4, 0, 0);


    /*for (int i = 0; i < 100; i++) {
        player->canvas_clear(player->canvas);
        Object_Show(obj1, player->canvas);
        Object_Show(obj2, player->canvas);
        player->canvas_CameraRotate(player->canvas, &rotation);
        player->canvas_flush(player->canvas);
//        getchar();
    }*/
    
//   for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
int count=0;
    while(1){
        count++;
            if(kbhit()){
                if(keydown(A))Player_Move_Left(player);
                if(keydown(D))Player_Move_Right(player);
                if(keydown(W))Player_Move_Forward(player);
                if(keydown(S))Player_Move_Backward(player);
                if(keydown(UP))Player_Rotate_Up(player);
                if(keydown(DOWN))Player_Rotate_Down(player);
                if(keydown(LEFT))Player_Rotate_Left(player);
                if(keydown(RIGHT))Player_Rotate_Right(player);
                if(keydown(ESC)){
                    printf("OVER\n");
                    sleep(100);
                    break;}
            }
            Canvas_clear(&player->canvas);
            Object_Show(obj1, &player->canvas);
            Object_Show(obj2, &player->canvas);
            Object_Show(obj3, &player->canvas);
            Canvas_flush(&player->canvas);
            printf("%lf %lf %lf\n",player->transform.position.x,player->transform.position.y,player->transform.position.z);
            printf("%lf %lf %lf\n",player->transform.rotation.x,player->transform.rotation.y,player->transform.rotation.z);
            printf("%lf %lf %lf\n",player->facing.x,player->facing.y,player->facing.z);
            printf("seconds  =  %d",count);
            sleep(50);
    }
//   for (int i = 0; i < player->canvas->height; i++){
//        for (int j = 0; j < player->canvas->width; j++) printf("%f ", player->canvas->vram_depth[i * player->canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);


    Del_Player(player);
    //close_keyboard();
    term_restore();
	sleep(100);

    return 0;
}