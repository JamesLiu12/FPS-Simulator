#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "canvas.h"
#include "vector.h"
#include "math.h"


/*
 This is the definition of canvas.
 The reason of using 1D array instead of 2D for storing display RAM is to reduce the indexing times.
*/
struct Canvas* new_canvas(short height, short width){
    struct Canvas* canvas = malloc(sizeof(struct Canvas));

    canvas->height = height;
    canvas->width = width;
    canvas->field_of_view = M_PI / 2;

    int vram_size = height * width * (int)sizeof(int);
    int depth_size = height * width * (int)sizeof(double);

    canvas->vram_red = malloc(vram_size);
    canvas->vram_green = malloc(vram_size);
    canvas->vram_blue = malloc(vram_size);
    canvas->vram_depth = malloc(depth_size);

    memset(canvas->vram_red, 0, vram_size);
    memset(canvas->vram_green, 0, vram_size);
    memset(canvas->vram_blue, 0, vram_size);
    memset(canvas->vram_depth, 0, depth_size);

    return canvas;
}

void del_canvas(struct Canvas* canvas){
    free(canvas->vram_red);
    free(canvas->vram_green);
    free(canvas->vram_blue);
    free(canvas);
}

void canvas_flush(struct Canvas* canvas){
    move_cursor_top_left();

    register int height, width, vram_index;

    for (height = 0; height < canvas->height; height++) {
        for (width = 0; width < canvas->width; width++) {
            vram_index = height * canvas->width + width;
            printf("\x1b[38;2;%d;%d;%dm",
                   canvas->vram_red[vram_index],
                   canvas->vram_green[vram_index],
                   canvas->vram_blue[vram_index]);
            printf("██");
        }
        puts("");
    }
}

void clear() {
    printf("\033[2J");
}

void move_cursor_top_left() {
    printf("\033[1;1H");
}

void canvas_draw_triangle(struct Canvas *canvas, struct Triangle* triangle){
    struct Vector3 projected_p1, projected_p2, projected_p3;
    projected_p1.x = triangle->v1.x / triangle->v1.z;
    projected_p1.y = triangle->v1.y / triangle->v1.z;
    projected_p1.z = triangle->v1.z / triangle->v1.z;
    projected_p2.x = triangle->v2.x / triangle->v2.z;
    projected_p2.y = triangle->v2.y / triangle->v2.z;
    projected_p2.z = triangle->v2.z / triangle->v2.z;
    projected_p3.x = triangle->v3.x / triangle->v3.z;
    projected_p3.y = triangle->v3.y / triangle->v3.z;
    projected_p3.z = triangle->v3.z / triangle->v3.z;

    // TODO
}

void canvas_move(struct Canvas *canvas, struct Vector3* displacement){
    vector3_add(&(canvas->transformation_position), displacement);
}

void canvas_rotate(struct Canvas *canvas, struct EulerAngle* eulerAngle){
    canvas->transformation_rotation.yaw += eulerAngle->yaw;
    canvas->transformation_rotation.pinch += eulerAngle->pinch;
    canvas->transformation_rotation.row += eulerAngle->row;
}

void canvas_stretch(struct Canvas *canvas, struct Vector3* scale){
    canvas->transformation_scale.x *= scale->x;
    canvas->transformation_scale.y *= scale->y;
    canvas->transformation_scale.z *= scale->z;
}
