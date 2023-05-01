#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "canvas.h"
#include "vector.h"
#include <math.h>
#include "transform.h"
#include "segment.h"
#include "../util/util.h"

void Canvas_Init(struct Canvas *canvas, short height, short width){
    canvas->height = height;
    canvas->width = width;
    canvas->field_of_view = M_PI / 2;

    // Using a 1D array instead of 2D to reduce indexing times.

    unsigned int vram_size = height * width * sizeof(unsigned char);
    unsigned int depth_size = height * width * sizeof(double);
    unsigned int tag_size = height * width * sizeof(enum Tag);

//    canvas->vram_red = (unsigned char*)malloc(vram_size);
//    canvas->vram_green = (unsigned char*)malloc(vram_size);
//    canvas->vram_blue = (unsigned char*)malloc(vram_size);
    canvas->vram_depth = (double*)malloc(depth_size);
    canvas->vram_tag = (enum Tag*)malloc(tag_size);

//    canvas->color.red = (char)255;
//    canvas->color.green = (char)255;
//    canvas->color.blue = (char)255;

    Transform_Init(&canvas->camera_transform, NULL);


    Canvas_CalculateScreenProjection(canvas);
    Canvas_InitView(canvas);
    canvas->render_distance = 100;
    Canvas_clear(canvas);
}

struct Canvas* New_Canvas(short height, short width) {
    struct Canvas* canvas = malloc(sizeof(struct Canvas));
    Canvas_Init(canvas, height, width);
    return canvas;
}

void Canvas_InitView(struct Canvas *canvas){
    //The vectors representing a plane
    struct Vector3 position, direction1, direction2;

    //The position vectors of rays and planes are the same
    Vector3_Set(&position, 0, 0, 0);

    //Initialize the rays
    Vector3_Set(&direction1, (double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Line_Set(&canvas->view_rays[0], &position, &direction1);

    Vector3_Set(&direction1, (double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Line_Set(&canvas->view_rays[1], &position, &direction1);

    Vector3_Set(&direction1, -(double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Line_Set(&canvas->view_rays[2], &position, &direction1);

    Vector3_Set(&direction1, -(double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Line_Set(&canvas->view_rays[3], &position, &direction1);

    //Initialize the planes
    Vector3_Copy(&canvas->view_rays[0].direction, &direction1);
    Vector3_Copy(&canvas->view_rays[1].direction, &direction2);
    Plane_Set(&canvas->view_planes[0], &position, &direction1, &direction2);

    Vector3_Copy(&canvas->view_rays[1].direction, &direction1);
    Vector3_Copy(&canvas->view_rays[2].direction, &direction2);
    Plane_Set(&canvas->view_planes[1], &position, &direction1, &direction2);

    Vector3_Copy(&canvas->view_rays[2].direction, &direction1);
    Vector3_Copy(&canvas->view_rays[3].direction, &direction2);
    Plane_Set(&canvas->view_planes[2], &position, &direction1, &direction2);

    Vector3_Copy(&canvas->view_rays[3].direction, &direction1);
    Vector3_Copy(&canvas->view_rays[0].direction, &direction2);
    Plane_Set(&canvas->view_planes[3], &position, &direction1, &direction2);
}

void Del_Canvas(struct Canvas* canvas){
//    free(canvas->vram_red);
//    free(canvas->vram_green);
//    free(canvas->vram_blue);
    free(canvas->vram_depth);
}

int get_brightness(double depth){
    return (int)fmax(255 - 20 * depth, 10);
}

void print_pixel(enum Tag tag, double distance){
    if (tag == EMPTY) printf("  ");
//    else if (tag == WALL) printf("\x1b[38;2;%d;%d;%dm██", brightness, brightness, brightness);
//    else if (tag == FLOOR) printf("\x1b[38;2;%d;%d;%dm░░", brightness, brightness, brightness);
    else if (tag == WALL) {
        if (25 <= distance && distance < 40) printf("▒▒");
        else if (15 <= distance && distance < 25)printf("▓▓");
        else if (0 <= distance && distance< 15) printf("██");
        else printf("▒▒");
    }
    else if (tag == TRUE_END){
        printf("!!");
    }
    else if (tag == FAKE_WALL){
        if (25 <= distance && distance < 40) printf("▒▒");
        else if (15 <= distance && distance < 16)printf("▓▒");
        else if (16 <= distance && distance < 25)printf("▓▓");
        else if (0 <= distance && distance< 15) printf("██");
        else printf("▒▒");
    }
    else if (tag == FLOOR) printf("░░");
    else if (tag == ENEMY_HEAD) printf("▐▐");
    else if (tag == ENEMY_LEG) printf("▌▌");
    else if (tag == ENEMY_BODY) printf("██");
    else if (tag == END) printf("??");
    else if (tag == STAR) printf("\033[31m██\033[0m");
}//░▒▓█
//█▌▐░▒▌▐▒

void Canvas_flush(struct Canvas* canvas){
    move_cursor_top_left();

    int height, width, vram_index;
    int brightness;

    for (height = 0; height < canvas->height; height++) {
        for (width = 0; width < canvas->width; width++) {

            vram_index = height * canvas->width + width;
            print_pixel(canvas->vram_tag[vram_index], canvas->vram_depth[vram_index]);
        }
        putchar('\n');
    }
}

void Canvas_clear(struct Canvas* canvas){
    unsigned int vram_size = canvas->height * canvas->width * sizeof(unsigned char);
    unsigned int depth_size = canvas->height * canvas->width * sizeof(double);

//    memset(canvas->vram_red, 0, vram_size);
//    memset(canvas->vram_green, 0, vram_size);
//    memset(canvas->vram_blue, 0, vram_size);
    for (int i = 0; i < canvas->height * canvas->width; i++) {
        canvas->vram_depth[i] = INFINITY;
        canvas->vram_tag[i] = EMPTY;
    }
}

void terminal_clear() {
    printf("\033[2J");
}

void move_cursor_top_left() {
    printf("\033[1;1H");
}

void Canvas_CalculateScreenProjection(struct Canvas* canvas) {
    double visible_z_plane_half_width = tan(canvas->field_of_view / 2);

    canvas->screen_projection.scale_factor = 1 / visible_z_plane_half_width * canvas->width / 2;

    canvas->screen_projection.x_displacement = (double)canvas->width / 2;
    canvas->screen_projection.y_displacement = (double)canvas->height / 2;
}

void Canvas_ProjectFromWorldToCamera(struct Canvas *canvas, struct Vector3 *from, struct Vector3 *to) {
    Vector3_Copy(from, to);
    Transform_UpdateGlobal(&canvas->camera_transform);
    Vector3_Subtract(to, &canvas->camera_transform.globalPosition);
    Matrix3x3_TransformMatrix(&canvas->camera_transform.globalRotationMatrix, to);
}

void Canvas_ProjectFromCameraToScreen(struct Canvas *canvas, struct Vector3 *from, struct Vector3 *to) {
    to->x = from->x
            * (canvas->screen_projection.scale_factor / from->z)
            + canvas->screen_projection.x_displacement;

    to->y = canvas->height
            - (from->y * (canvas->screen_projection.scale_factor / from->z)
            + canvas->screen_projection.y_displacement);
    // z-axis can hold the distance
    to->z = from->z;
}

void Canvas_ProjectFromWorldToScreen(struct Canvas *canvas, struct Vector3 *from, struct Vector3 *to) {
    struct Vector3 vector_tmp;
    Canvas_ProjectFromWorldToCamera(canvas, from, &vector_tmp);
    Canvas_ProjectFromCameraToScreen(canvas, &vector_tmp, to);
}

void vram_write(struct Canvas *canvas, int vram_index, double distance, enum Tag tag){
    if (canvas->vram_depth[vram_index] < distance) {
        return;
    }
    canvas->vram_depth[vram_index] = distance;
    canvas->vram_tag[vram_index] = tag;
}

/*
 * A function return true <=> the camera_point could be view in the camera
 * The camera_point is the one have been transformed already in to camera relative coordinate
 * */
int Canvas_IsPointInCamera(struct Canvas *canvas, struct Vector3 *camera_point){
    if (camera_point->z <= 0) return FALSE;
    struct Vector3 screen_point;
    Canvas_ProjectFromCameraToScreen(canvas, camera_point, &screen_point);
    return 0 <= screen_point.x + EPSILON && screen_point.x - EPSILON < canvas->width
           && 0 <= screen_point.y + EPSILON && screen_point.y - EPSILON < canvas->height;
}

void Canvas_DrawTriangle(struct Canvas *canvas, struct Triangle* triangle, enum Tag tag){
    //The position of the points respective to camera
    struct Vector3 camera_p1, camera_p2, camera_p3;

    //Calculate the coordinates of the points taking camera as the origin
    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v1, &camera_p1);
    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v2, &camera_p2);
    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v3, &camera_p3);


    //At most 6 points could appear in view
    int number_in_view = 0;
    struct Vector3 *points_in_view = malloc(9 * sizeof(struct Vector3));

    //If the points are in the view, add them into the list
    if (Canvas_IsPointInCamera(canvas, &camera_p1)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p1, &screen_p);
        Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
        number_in_view++;
    }
    if (Canvas_IsPointInCamera(canvas, &camera_p2)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p2, &screen_p);
        Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
        number_in_view++;
    }
    if (Canvas_IsPointInCamera(canvas, &camera_p3)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p3, &screen_p);
        Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
        number_in_view++;
    }

    //Some points may not in view, then calculate the intersection of the sides of triangle and the view plane
    struct Segment segment1, segment2, segment3;

    Segment_Set(&segment1, &camera_p1, &camera_p2),
    Segment_Set(&segment2, &camera_p1, &camera_p3),
    Segment_Set(&segment3, &camera_p2, &camera_p3);

    struct Line line1, line2, line3;
    struct Vector3 vec_tmp;

    Vector3_Copy(&camera_p2, &vec_tmp);
    Vector3_Subtract(&vec_tmp, &camera_p1);
    Line_Set(&line1, &camera_p1, &vec_tmp);

    Vector3_Copy(&camera_p3, &vec_tmp);
    Vector3_Subtract(&vec_tmp, &camera_p1);
    Line_Set(&line2, &camera_p1, &vec_tmp);

    Vector3_Copy(&camera_p3, &vec_tmp);
    Vector3_Subtract(&vec_tmp, &camera_p2);
    Line_Set(&line3, &camera_p2, &vec_tmp);

    for (int i = 0; i < 4; i++){
        struct Vector3 intersection;

        Plane_LineIntersection(&canvas->view_planes[i], &line1, &intersection);

        if (Segment_IsPointOnSegment(&segment1, &intersection)
            && Canvas_IsPointInCamera(canvas, &intersection)
            && !Vector3_Equal(&intersection, &camera_p1) && !Vector3_Equal(&intersection, &camera_p2)){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
            number_in_view++;
        }

        Plane_LineIntersection(&canvas->view_planes[i], &line2, &intersection);
        if (Segment_IsPointOnSegment(&segment2, &intersection)
            && Canvas_IsPointInCamera(canvas, &intersection)
            && !Vector3_Equal(&intersection, &camera_p1) && !Vector3_Equal(&intersection, &camera_p3)){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
            number_in_view++;
        }

        Plane_LineIntersection(&canvas->view_planes[i], &line3, &intersection);
        if (Segment_IsPointOnSegment(&segment3, &intersection)
            && Canvas_IsPointInCamera(canvas, &intersection)
            && !Vector3_Equal(&intersection, &camera_p2) && !Vector3_Equal(&intersection, &camera_p3)){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
            number_in_view++;
        }
    }

    /* Some sides may not have intersection with the plane in range, then calculate the intersection of the face of
       triangle and the ray of the view*/
    struct Plane plane_triangle;
    struct Triangle triangle_camera;
    Plane_Set(&plane_triangle, &camera_p1, &line1.direction, &line2.direction);
    Triangle_Set(&triangle_camera, &camera_p1, &camera_p2, &camera_p3);
    for (int i = 0; i < 4; i++){
        struct Vector3 intersection;
        Plane_LineIntersection(&plane_triangle, &canvas->view_rays[i], &intersection);
        if (Triangle_IsPointInTriangle3D(&triangle_camera, &intersection) && intersection.z >= 0){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Copy(&screen_p, &points_in_view[number_in_view]);
            number_in_view++;
        }
    }

    Canvas_Rasterize(canvas, points_in_view, number_in_view, tag);

    //Free the memory from heap
    free(points_in_view);
}

struct Vector3 first_point_position;
int cmp_SortInCircle(const void *first, const void *second){
    struct Vector3 *a = (struct Vector3 *)first, *b = (struct Vector3 *)second;
    return atan((first_point_position.y - a->y) / (a->x - first_point_position.x))
        < atan((first_point_position.y - b->y) / (b->x - first_point_position.x));
}

void Canvas_Rasterize(struct Canvas *canvas, struct Vector3* points, int size, enum Tag tag){
    //no triangle needs to be rasterized
    if (size == 0) return;

    //The 3 points of triangle
    struct Vector3 p1, p2, p3;
    int p1_index, p2_index, p3_index;

    //Move the left most point to the first
    for (int i = 1; i < size; i++){
        if (points[i].x < points[0].x) swap(&points[i].x, &points[0].x, sizeof(struct Vector3));
    }

    //Sort the points in the order forming a convex polygon
    Vector3_Copy(&points[0], &first_point_position);
    qsort(points + 1, size - 1, sizeof(struct Vector3), cmp_SortInCircle);

    Vector3_Copy(&points[0], &p1);
    Vector3_Copy(&points[1], &p2);
    for (int point_index = 2; point_index < size; point_index++){
        Vector3_Copy(&points[point_index], &p3);
        int min_x, min_y, max_x, max_y;
        min_x = fmax(0, floor(fmin(p1.x, fmin(p2.x, p3.x))));
        max_x = fmin(canvas->width - 1, ceil(fmax(p1.x, fmax(p2.x, p3.x))));
        min_y = fmax(0, floor(fmin(p1.y, fmin(p2.y, p3.y))));
        max_y = fmin(canvas->height - 1, ceil(fmax(p1.y, fmax(p2.y, p3.y))));
        for (int y = min_y; y <= max_y; y++){
            for (int x = min_x; x <= max_x; x++){
                struct Triangle triangle_screen;
                Triangle_Set(&triangle_screen, &p1, &p2, &p3);
                struct Vector3 point_screen;
                Vector3_Set(&point_screen, x + 0.5, y + 0.5, 0);
                if (Triangle_IsPointInTriangle2D(&triangle_screen, &point_screen)){
                    double depth = Triangle_PerspectiveCorrectInterpolation(&triangle_screen, &point_screen);
                    if (depth < 0) continue;
                    vram_write(canvas, canvas->width * y + x, depth, tag);
                }
            }
        }

        Vector3_Copy(&p3, &p2);
    }
}

void Canvas_CameraMove(struct Canvas *canvas, struct Vector3 *displacement) {
    Vector3_Add(&canvas->camera_transform.position, displacement);
}

void Canvas_CameraRotate(struct Canvas *canvas, struct Vector3 *rotation) {
    Vector3_Add(&canvas->camera_transform.rotation, rotation);
    Matrix3x3_FromEulerAngle(
            &canvas->camera_transform.rotationMatrix,
            &canvas->camera_transform.rotation,
            EULER_ANGLE_REVERSED);
}

void Canvas_AddCover(struct Canvas *canvas, int row, int column, enum Tag tag){
    int vram_index = row * canvas->width + column;
    canvas->vram_depth[vram_index] = 0;
    canvas->vram_tag[vram_index] = tag;
}