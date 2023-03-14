//#define OP_ENGINE_CHROMATIC
#include <stdio.h>
#include "op_engine/op_engine.h"
#include <math.h>

int main() {
    struct Canvas *canvas = new_Canvas(64, 64);
    struct Vector3 rotation;
    Vector3_Set(&rotation, 0.1, 0, 0);
    struct Vector3 p1, p2, p3;
    Vector3_Set(&p1, 0, 6, 6);
    Vector3_Set(&p2, 0, -9, 5);
    Vector3_Set(&p3, 9, 0, 5);

    struct Triangle triangle;
    triangle.v1 = p1;
    triangle.v2 = p2;
    triangle.v3 = p3;
    for (int i = 0; i < 100; i++) {
        Canvas_clear(canvas);
        Canvas_CameraRotate(canvas, &rotation);
        Canvas_DrawTriangle(canvas, &triangle);
        Canvas_flush(canvas);
//        getchar();
    }
//    for (int i = 0; i < canvas->height; i++){
//        for (int j = 0; j < canvas->width; j++) printf("%f ", canvas->vram_depth[i * canvas->width + j]);
//        puts("");
//    }
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);

    del_Canvas(canvas);
    return 0;
}