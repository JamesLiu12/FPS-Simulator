#ifndef OP_CANVAS

#include "vector.h"
#include "matrix.h"
#include "triangle.h"
#include "transform.h"
#include "plane.h"
#include "tag.h"

struct ScreenProjection {
    double scale_factor;
    double x_displacement, y_displacement;
};

//Canvas for displaying
struct Canvas {
    //The height and width of screen
    unsigned short height, width;

    /*
     * vram_depth: the ram for storing depth of pixels
     * vram_tag: the ram for storing the tag of pixels
     */
    double *vram_depth;
    enum Tag *vram_tag;

    //The transform of camera
    struct Transform camera_transform;

    //The four side planes of the view
    struct Plane view_planes[4];

    //The 4 rays that form the side view_planes
    struct Line view_rays[4];

    //The angle of the view
    double field_of_view;

    //The screen projection information of canvas
    struct ScreenProjection screen_projection;

    //The maximum render distance for an object
    double render_distance;
};

//Initializer of canvas
void Canvas_Init(struct Canvas *canvas, short height, short width);

//The function for construction of a new canvas
struct Canvas* New_Canvas(short height, short width);

//The function for initializing the planes and rays of the view
void Canvas_InitView(struct Canvas *canvas);

//Rasterize a polygon on the screen
void Canvas_Rasterize(struct Canvas *canvas, struct Vector3* points, int size, enum Tag tag);

//The function for freeing the space of a canvas
void Del_Canvas(struct Canvas* canvas);

//Displaying the current frame.
void Canvas_flush(struct Canvas* canvas);
void Canvas_clear(struct Canvas* canvas);

//Clear the terminal
void terminal_clear();

// Move the cursor to the top-left corner
void move_cursor_top_left();

void Canvas_DrawTriangle(struct Canvas *canvas, struct Triangle* triangle, enum Tag tag);


// Move the position of canvas by adding displacement
void Canvas_CameraMove(struct Canvas *canvas, struct Vector3 *displacement);

//Rotate the canvas by an Euler angle
void Canvas_CameraRotate(struct Canvas *canvas, struct Vector3 *rotation);

//Update the projection data in Canvas
void Canvas_CalculateScreenProjection(struct Canvas* canvas);

//Add a cover pixel to canvas
void Canvas_AddCover(struct Canvas *canvas, int row, int column, enum Tag tag);

#define OP_CANVAS
#endif
