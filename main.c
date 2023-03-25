//#define OP_ENGINE_CHROMATIC
#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>
#include <termios.h>
#include "op_engine/input.h"
#include "player/player.h"
const double RotationSpeed=0.1;
const double MoveSpeed=1;

int main() {
    init_keyboard();
    struct Canvas *canvas = New_Canvas(64, 64);
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
        Canvas_clear(canvas);
        Object_Show(obj1, canvas);
        Object_Show(obj2, canvas);
        Canvas_CameraRotate(canvas, &rotation);
        Canvas_flush(canvas);
//        getchar();
    }*/
    char input;
    bool isarrow=0;
    while(1){

            input=scan_keyboard();
            //use a & d to turn left/right about y axis
            if(input=='a'){
                //Vector3_Set(&rotation, 0, -RotationSpeed, 0);
                //Canvas_CameraRotate(canvas,&rotation);
                Canvas_CameraRotateLeft(canvas,RotationSpeed);
                }
            if(input=='d'){
                //Vector3_Set(&rotation, 0, RotationSpeed, 0);
                //Canvas_CameraRotate(canvas,&rotation);
                Canvas_CameraRotateRight(canvas,RotationSpeed);
                }
            //use w & s to loop up/down, rotate the camera about right-hand axis
            if(input=='s'){
                //Vector3_Set(&rotation, RotationSpeed,0,0);
                //Canvas_CameraRotate(canvas,&rotation);
                Canvas_CameraRotateDown(canvas,RotationSpeed);
                }
            if(input=='w'){
                //Vector3_Set(&rotation,-RotationSpeed,0,0);
                //Canvas_CameraRotate(canvas,&rotation);
                Canvas_CameraRotateUp(canvas,RotationSpeed);
                }
            if(input==91)isarrow=1;
            if(isarrow){
            if(input==68){
                Vector3_Set(&movement, -MoveSpeed, 0, 0);
                Canvas_CameraMove(canvas,&movement);
                isarrow=0;}
            if(input==67){
                Vector3_Set(&movement, MoveSpeed, 0, 0);
                Canvas_CameraMove(canvas,&movement);
                isarrow=0;}
            if(input==65){
                Vector3_Set(&movement, 0, 0,MoveSpeed);
                Canvas_CameraMove(canvas,&movement);
                isarrow=0;}
            if(input==66){
                Vector3_Set(&movement, 0, 0, -MoveSpeed);
                Canvas_CameraMove(canvas,&movement);
                isarrow=0;}
            }
            
            if(input=='`'){printf("quiting\n");break;}   
            Canvas_clear(canvas);
            Object_Show(obj1, canvas);
            Object_Show(obj2, canvas);
            Object_Show(obj3, canvas);
            Canvas_flush(canvas);
            printf("%lf %lf %lf\n",canvas->camera_transform.position.x,canvas->camera_transform.position.y,canvas->camera_transform.position.z);
            printf("%lf %lf %lf\n",canvas->camera_transform.rotation.x,canvas->camera_transform.rotation.y,canvas->camera_transform.rotation.z);
            printf("%lf %lf %lf\n",canvas->facing.x,canvas->facing.y,canvas->facing.z);
    }
//   for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    del_Canvas(canvas);
    close_keyboard();
    return 0;
}