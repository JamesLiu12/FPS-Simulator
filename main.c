//#define OP_ENGINE_CHROMATIC
#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>

int main() {
    struct Canvas *canvas = new_Canvas(64, 64);
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0.1, 0, 0);

    struct Mesh *mesh = ModelCube_New();
    struct Object *obj1 = Object_New(mesh, FLOOR), *obj2 = Object_New(mesh, WALL);
    Vector3_Set(&obj1->transform.position, 0, 0, 5);
    Vector3_Set(&obj2->transform.position, 3, 3, 8);
    struct Vector3 rot;
    Vector3_Set(&rot, -1, 0, 0);
    Canvas_CameraRotate(canvas, &rot);


    for (int i = 0; i < 100; i++) {
        Canvas_clear(canvas);
        Object_Show(obj1, canvas);
        Object_Show(obj2, canvas);
        Canvas_CameraRotate(canvas, &rotation);
        Canvas_flush(canvas);
//        getchar();
    }
//    for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);
    printf("\x1b[48;2;%d;%d;%dm", 0, 0, 0);
    del_Canvas(canvas);
    return 0;
}