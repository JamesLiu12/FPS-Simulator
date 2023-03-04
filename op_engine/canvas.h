#include "vector.h"
#include "matrix.h"
#include "triangle.h"

#ifndef OP_CANVAS

//Canvas for displaying
struct Canvas {
    short height, width;

    int *vram_red, *vram_green, *vram_blue;
    double *vram_depth;

    struct Vector3 transformation_position;
    struct Vector3 transformation_scale;
    struct EulerAngle transformation_rotation;
    double field_of_view;
};

//The function for construction of a new canvas
struct Canvas* new_canvas(short height, short width);

//The function for freeing the space of a canvas
void del_canvas(struct Canvas* canvas);

//Displaying the current frame.
void canvas_flush(struct Canvas* canvas);

//clear the terminal
void clear();

// Move the cursor to the top-left corner
void move_cursor_top_left();

void canvas_draw_triangle(struct Canvas *canvas, struct Triangle* triangle);

//Move the position of canvas by adding displacement
void canvas_move(struct Canvas *canvas, struct Vector3* displacement);

//Rotate
void canvas_rotate(struct Canvas *canvas, struct EulerAngle* eulerAngle);
void canvas_stretch(struct Canvas *canvas, struct Vector3* scale);

#define OP_CANVAS
#endif
