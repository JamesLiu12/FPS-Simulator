#ifndef FPS_SIMULATOR_RECTANGLE_H
#define FPS_SIMULATOR_RECTANGLE_H

#include "../op_engine.h"

struct Rectangle{
    struct Triangle low_left_triangle, up_right_triangle;
};

struct Rectangle* new_Rectangle(struct Vector3 *low_left_vertex, struct Vector3 *up_right_vertex);
void del_Rectangle(struct Rectangle* rectangle);

#endif //FPS_SIMULATOR_RECTANGLE_H
