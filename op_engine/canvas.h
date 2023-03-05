#ifndef OP_CANVAS

#include "vector.h"
#include "matrix.h"
#include "triangle.h"

struct ScreenProjection {
    double scale_factor;
    double x_displacement, y_displacement;
};

struct Color {
    unsigned char red, green, blue;
};

//Canvas for displaying
struct Canvas {
    unsigned short height, width;

    unsigned char *vram_red, *vram_green, *vram_blue;
    double *vram_depth;

    struct Vector3 transformation_position;
    struct Vector3 transformation_scale;
    struct EulerAngle transformation_rotation;
    struct Matrix3x3 transformation_rotation_matrix;
    struct Color color;

    double field_of_view;
    struct ScreenProjection screen_projection;
};

//The function for construction of a new canvas
struct Canvas* new_canvas(short height, short width);

//The function for freeing the space of a canvas
void del_canvas(struct Canvas* canvas);

//Displaying the current frame.
void canvas_flush(struct Canvas* canvas);
void canvas_clear(struct Canvas* canvas);

//Clear the terminal
void terminal_clear();

// Move the cursor to the top-left corner
void move_cursor_top_left();

void canvas_draw_point(struct Canvas *canvas, struct Vector3 *point);
void canvas_draw_triangle(struct Canvas *canvas, struct Triangle* triangle);
void canvas_draw_triangle_alternative(struct Canvas *canvas, struct Triangle* triangle);

//Move the position of canvas by adding displacement
void canvas_move(struct Canvas *canvas, struct Vector3* displacement);

//Rotate
void canvas_rotate(struct Canvas *canvas, struct EulerAngle* eulerAngle);
void canvas_stretch(struct Canvas *canvas, struct Vector3* scale);

void canvas_calculate_screen_projection(struct Canvas* canvas);

#define OP_CANVAS
#endif
