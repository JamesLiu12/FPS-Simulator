#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "canvas.h"
#include "vector.h"
#include "math.h"
#include "transform.h"
#include "segment.h"
#include "../util/util.h"

struct Canvas* new_Canvas(short height, short width) {
    struct Canvas* canvas = malloc(sizeof(struct Canvas));

    canvas->height = height;
    canvas->width = width;
    canvas->field_of_view = M_PI / 2;

    // Using a 1D array instead of 2D to reduce indexing times.

    int vram_size = height * width * (int)sizeof(unsigned char);
    int depth_size = height * width * (int)sizeof(double);

    canvas->vram_red = malloc(vram_size);
    canvas->vram_green = malloc(vram_size);
    canvas->vram_blue = malloc(vram_size);
    canvas->vram_depth = malloc(depth_size);

    canvas->color.red = (char)255;
    canvas->color.green = (char)255;
    canvas->color.blue = (char)255;

    init_Transform(&canvas->transform);
    init_Transform(&canvas->camera_transform);

    Canvas_init_planes_view(canvas);

    Canvas_CalculateScreenProjection(canvas);
    Canvas_clear(canvas);

    return canvas;
}

void Canvas_init_planes_view(struct Canvas *canvas){
    //The vectors representing a plane
    struct Vector3 position, direction1, direction2;
    Vector3_Set(&position, 0, 0, 0);

    Vector3_Set(&direction1, (double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Vector3_Set(&direction2, (double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Plane_Set(&canvas->view_planes[0], &position, &direction1, &direction2);

    Vector3_Set(&direction1, (double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Vector3_Set(&direction2, -(double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Plane_Set(&canvas->view_planes[1], &position, &direction1, &direction2);

    Vector3_Set(&direction1, -(double)canvas->width / 2, -(double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Vector3_Set(&direction2, -(double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Plane_Set(&canvas->view_planes[2], &position, &direction1, &direction2);

    Vector3_Set(&direction1, -(double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Vector3_Set(&direction2, (double)canvas->width / 2, (double)canvas->height / 2, canvas->screen_projection.scale_factor);
    Plane_Set(&canvas->view_planes[3], &position, &direction1, &direction2);
}

void del_Canvas(struct Canvas* canvas){
    free(canvas->vram_red);
    free(canvas->vram_green);
    free(canvas->vram_blue);
    free(canvas->vram_depth);
    free(canvas);
}

void Canvas_flush(struct Canvas* canvas){
    move_cursor_top_left();

    register int height, width, vram_index;
    int brightness;

    for (height = 0; height < canvas->height; height++) {
        for (width = 0; width < canvas->width; width++) {

            vram_index = height * canvas->width + width;

//            brightness = (int)(
//                    0.2126 * canvas->vram_red[vram_index] +
//                    0.7152 * canvas->vram_green[vram_index] +
//                    0.0722 * canvas->vram_blue[vram_index]);

//#ifdef OP_ENGINE_CHROMATIC
//            printf("\x1b[38;2;%d;%d;%dm",
//                   canvas->vram_red[vram_index],
//                   canvas->vram_green[vram_index],
//                   canvas->vram_blue[vram_index]);
//            putchar(0xe2);
//            putchar(0x96);
//            putchar(0x88);
//            putchar(0xe2);
//            putchar(0x96);
//            putchar(0x88);
//#endif

//#ifndef OP_ENGINE_CHROMATIC
            if (canvas->vram_red[vram_index] == 255) {
                // Blocks of different brightness ░▒▓█ ▖ ▗ ▘ ▙ ▚ ▛ ▜ ▝ ▞ ▟
                //faster version of printf("██");
                putchar(0xe2);
                putchar(0x96);
                putchar(0x88);
                putchar(0xe2);
                putchar(0x96);
                putchar(0x88);
            } else {
                putchar(' ');
                putchar(' ');
            }
//#endif
        }
        putchar('\n');
    }
}

void Canvas_clear(struct Canvas* canvas){
    int vram_size = canvas->height * canvas->width * sizeof(unsigned char);
    int depth_size = canvas->height * canvas->width * sizeof(double);

    memset(canvas->vram_red, 0, vram_size);
    memset(canvas->vram_green, 0, vram_size);
    memset(canvas->vram_blue, 0, vram_size);
    for (int i = 0; i < canvas->height * canvas->width; i++) {
        canvas->vram_depth[i] = INFINITY;
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
    Vector3_Subtract(to, &canvas->camera_transform.position);
    Matrix3x3_Transform(&canvas->camera_transform.rotation_matrix, to);
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

void vram_write(struct Canvas *canvas, int vram_index, double distance2){
    if (canvas->vram_depth[vram_index] < distance2) {
        return;
    }
    canvas->vram_depth[vram_index] = distance2;
    canvas->vram_red[vram_index] = canvas->color.red;
    canvas->vram_green[vram_index] = canvas->color.green;
    canvas->vram_blue[vram_index] = canvas->color.blue;
}

void Canvas_DrawPoint(struct Canvas *canvas, struct Vector3 *point){
    struct Vector3 projected_p;

    Canvas_ProjectFromCameraToScreen(canvas, point, &projected_p);

    int row, column;
    row = (int)round(projected_p.y);
    column = (int)round(projected_p.x);

    if (row < 0 ||
        row >= canvas->height ||
        column < 0 ||
        column >= canvas->width) {
        return;
    }
    int vram_index = row * canvas->width + column;
    double distance2 = Vector3_MagnitudeSq(point);
    vram_write(canvas, vram_index, distance2);
}

double Canvas_GetProjectedDepth(struct Canvas *canvas, struct Vector3 *point){
    struct Vector3 p;
    Vector3_Copy(point, &p);
    int reverse = FALSE;
    if (p.z < 0){
        reverse = TRUE;
        p.x = -p.x;
        p.y = -p.y;
        p.z = -p.z;
    }
    double distance_to_plane = canvas->width / 2 / tan(canvas->field_of_view / 2);
    struct Vector3 plane_normal;
    Vector3_Set(&plane_normal, 0, 0, 1);
    double included_angle = Vector3_IncludedAngle(&plane_normal, &p);
    return (sqrt(Vector3_MagnitudeSq(&p)) - distance_to_plane / cos(included_angle)) * (reverse ? -1 : 1);
}

/*
 * A function return true <=> the camera_point could be view in the camera
 * The camera_point is the one have been transformed already in to camera relative coordinate
 * */
int Canvas_PointInCamera(struct Canvas *canvas, struct Vector3 *camera_point){
    if (camera_point->z <= 0) return FALSE;
    struct Vector3 screen_point;
    Canvas_ProjectFromCameraToScreen(canvas, camera_point, &screen_point);
    return 0 <= screen_point.x && screen_point.x < canvas->width
        && 0 <= screen_point.y && screen_point.y < canvas->height;
}

void Canvas_DrawTriangle(struct Canvas *canvas, struct Triangle* triangle){
    struct Vector3 camera_p1, camera_p2, camera_p3;

    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v1, &camera_p1);
    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v2, &camera_p2);
    Canvas_ProjectFromWorldToCamera(canvas, &triangle->v3, &camera_p3);

    int number_in_view = 0;
    struct Vector3 *points_in_view = malloc(6 * sizeof(struct Vector3));
    double *points_depth = malloc(6 * sizeof(double));

    if (Canvas_PointInCamera(canvas, &camera_p1)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p1, &screen_p);
        Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
        number_in_view++;
    }
    if (Canvas_PointInCamera(canvas, &camera_p2)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p2, &screen_p);
        Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
        number_in_view++;
    }
    if (Canvas_PointInCamera(canvas, &camera_p3)){
        struct Vector3 screen_p;
        Canvas_ProjectFromCameraToScreen(canvas, &camera_p2, &screen_p);
        Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
        number_in_view++;
    }

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

    for (register int i = 0; i < 4; i++){
        struct Vector3 intersection;

        Plane_intersection_Line(&canvas->view_planes[i], &line1, &intersection);
        if (Segment_is_point_inside(&segment1, &intersection) && intersection.z > 0){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
            number_in_view++;
        }

        Plane_intersection_Line(&canvas->view_planes[i], &line2, &intersection);
        if (Segment_is_point_inside(&segment2, &intersection) && intersection.z > 0){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
            number_in_view++;
        }

        Plane_intersection_Line(&canvas->view_planes[i], &line3, &intersection);
        if (Segment_is_point_inside(&segment3, &intersection) && intersection.z > 0){
            struct Vector3 screen_p;
            Canvas_ProjectFromCameraToScreen(canvas, &intersection, &screen_p);
            Vector3_Set(&points_in_view[number_in_view], screen_p.x, screen_p.y, screen_p.z);
            number_in_view++;
        }
    }
    Canvas_Rasterize(canvas, points_in_view, points_depth, number_in_view);

    free(points_in_view);
    free(points_depth);
}

void Canvas_Rasterize(struct Canvas *canvas, struct Vector3* points_in_view, double* points_depth, int size){

}

void Canvas_DrawTriangleFront(struct Canvas *canvas, struct Triangle* triangle) {
    struct Vector3 p1, p2, p3;
    struct Vector3 *projected_low = &p1, *projected_mid = &p2, *projected_top = &p3;
    struct Vector3 *original_low = &triangle->v1, *original_mid = &triangle->v2, *original_top = &triangle->v3;

    Canvas_ProjectFromWorldToScreen(canvas, &triangle->v1, &p1);
    Canvas_ProjectFromWorldToScreen(canvas, &triangle->v2, &p2);
    Canvas_ProjectFromWorldToScreen(canvas, &triangle->v3, &p3);

    // Order the points by their y-axes.
    if (projected_low->y > projected_mid->y) {
        swap(projected_low, projected_mid, sizeof(struct Vector3));
        swap(original_low, original_mid, sizeof(struct Vector3));
    }
    if (projected_mid->y > projected_top->y) {
        swap(projected_mid, projected_top, sizeof(struct Vector3));
        swap(original_mid, original_top, sizeof(struct Vector3));
    }
    if (projected_low->y > projected_mid->y) {
        swap(projected_low, projected_mid, sizeof(struct Vector3));
        swap(original_low, original_mid, sizeof(struct Vector3));
    }

    // Rasterise the triangle with many horizontal lines
    register short x_lower, x_upper, x, y;

    if (projected_top->y - projected_low->y == 0) {
        return;
    }

    // Lower part
    short
        y_start = fmax((short)ceil(projected_low->y), 0),
        y_end = fmin((short)floor(projected_mid->y), canvas->height - 1);

    double
        depth_low_top_step = (projected_top->z - projected_low->z)
                / fmax(1, (floor(projected_top->y) - ceil(projected_low->y))),
        depth_low_top_now = projected_low->z
                            + depth_low_top_step * (y_start - (short)ceil(projected_low->y)),
        depth_low_mid_step = (projected_mid->z - projected_low->z)
                / fmax(1, (floor(projected_mid->y) - ceil(projected_low->y))),
        depth_low_mid_now = projected_low->z
                            + depth_low_mid_step * (y_start - (short)ceil(projected_low->y));

    //if lower_bound > upper_bound, the direction of depth change should be reversed
    if (projected_low->x > projected_mid->x){
        double tmp = depth_low_mid_step;
        depth_low_mid_step = depth_low_top_step;
        depth_low_top_step = tmp;
        tmp = depth_low_mid_now;
        depth_low_mid_now = depth_low_top_now;
        depth_low_top_now = tmp;
    }

    for (y = y_start; y <= y_end; y++,
            depth_low_mid_now += depth_low_mid_step,
            depth_low_top_now += depth_low_top_step) {
        // Calculate the lower and upper bound of this horizontal line
        x_lower = (short)round(linear_interpolate(
                projected_low->x,
                projected_top->x,
                (y - projected_low->y) / (projected_top->y - projected_low->y)));
        if (projected_mid->y - projected_low->y == 0) {
            break;
        }
        x_upper = (short)round(linear_interpolate(
                projected_low->x,
                projected_mid->x,
                (y - projected_low->y) / (projected_mid->y - projected_low->y)));

        // If the middle point is to the left, swap the upper and the lower bound
        if (x_lower > x_upper) {
            register short tmp;
            tmp = x_lower;
            x_lower = x_upper;
            x_upper = tmp;
        }

        // Skip the points out of the bound
        int x_start = fmax(x_lower, 0), x_end = fmin(x_upper, canvas->width - 1);

        //The depth of each pixel
        double
            //x_upper-x_lower may be zero
            depth_step = (depth_low_mid_now - depth_low_top_now) / fmax(1, (x_upper - x_lower)),
            depth_now = depth_low_top_now + depth_step * (x_start - x_lower);

        for (x = x_start; x <= x_end; x++, depth_now += depth_step) {
            if (depth_now < 0) continue;
            vram_write(canvas, canvas->width * y + x, depth_now * depth_now);
        }
    }

    // Upper part (slightly the same as above)
    y_start = fmax((short)ceil(projected_mid->y), 0);
    y_end = fmin((short)floor(projected_top->y), canvas->height - 1);

    depth_low_top_step = (projected_top->z - projected_low->z)
            / fmax(1, (floor(projected_top->y) - ceil(projected_low->y)));
    depth_low_top_now = projected_low->z
                        + depth_low_top_step * (y_start - (short)ceil(projected_low->y));

    double
        depth_mid_top_step = (projected_top->z - projected_mid->z)
                / fmax(1, (floor(projected_top->y) - ceil(projected_mid->y))),
        depth_mid_top_now = projected_mid->z
                            + depth_mid_top_step * (y_start - (short)ceil(projected_mid->y));

    if (projected_low->x > projected_mid->x){
        double tmp = depth_low_top_step;
        depth_low_top_step = depth_mid_top_step;
        depth_mid_top_step = tmp;
        tmp = depth_low_top_now;
        depth_low_top_now = depth_mid_top_now;
        depth_mid_top_now = tmp;
    }

    for (y = y_start; y <= y_end; y++,
            depth_low_top_now += depth_low_top_step,
            depth_mid_top_now += depth_mid_top_step) {

        x_lower = (short)round(linear_interpolate(
                projected_low->x,
                projected_top->x,
                (y - projected_low->y) / (projected_top->y - projected_low->y)));
        if (projected_top->y - projected_mid->y == 0) {
            break;
        }
        x_upper = (short)round(linear_interpolate( // Only here is different
                projected_mid->x,
                projected_top->x,
                (y - projected_mid->y) / (projected_top->y - projected_mid->y)));

        if (x_lower > x_upper) {
            register short tmp;
            tmp = x_lower;
            x_lower = x_upper;
            x_upper = tmp;
        }

        int x_start = fmax(x_lower, 0), x_end = fmin(x_upper, canvas->width - 1);
        double
                depth_step = (depth_mid_top_now - depth_low_top_now) / fmax(1, (x_upper - x_lower)),
                depth_now = depth_low_top_now + depth_step * (x_start - x_lower);

        for (x = x_start; x <= x_end; x++, depth_now += depth_step) {
            if (depth_now < 0) continue;
            vram_write(canvas, canvas->width * y + x, depth_now * depth_now);
        }
    }
}

void Canvas_Move(struct Canvas *canvas, struct Vector3* displacement){
    Vector3_Add(&canvas->transform.position, displacement);
}

void Canvas_Rotation(struct Canvas *canvas, struct Vector3* rotation){
    canvas->transform.rotation.x += rotation->x;
    canvas->transform.rotation.y += rotation->y;
    canvas->transform.rotation.z += rotation->z;

    Transform_rotation_matrix_update(&canvas->transform);
}

void Canvas_Stretch(struct Canvas *canvas, struct Vector3* scale){
    canvas->transform.scale.x *= scale->x;
    canvas->transform.scale.y *= scale->y;
    canvas->transform.scale.z *= scale->z;
}

void Canvas_CameraMove(struct Canvas *canvas, struct Vector3 *displacement) {
    Vector3_Add(&canvas->camera_transform.position, displacement);
}

void Canvas_CameraRotate(struct Canvas *canvas, struct Vector3 *rotation) {
    Vector3_Add(&canvas->camera_transform.rotation, rotation);
    Matrix3x3_FromEulerAngle(
            &canvas->camera_transform.rotation_matrix,
            &canvas->camera_transform.rotation,
            EULER_ANGLE_REVERSED);
}
