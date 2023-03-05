#include <stdio.h>
#include <math.h>
#define OP_ENGINE_CHROMATIC
#include "op_engine/op_engine.h"

int main() {
    struct Canvas *canvas = new_canvas(128, 128);
    struct Vector3 p1, p2, p3;
    p1.x = -1;
    p1.y = -1;
    p1.z = 6;
    p2.x = -1;
    p2.y = 9;
    p2.z = 6;
    p3.x = 6;
    p3.y = -1;
    p3.z = 6;
    struct Triangle triangle;
    triangle.v1 = p1;
    triangle.v2 = p2;
    triangle.v3 = p3;
    canvas_draw_triangle_alternative(canvas, &triangle);
    canvas_flush(canvas);
    del_canvas(canvas);
    printf("\x1b[38;2;%d;%d;%dm", 0xee, 0xee, 0xee);

    return 0;
}