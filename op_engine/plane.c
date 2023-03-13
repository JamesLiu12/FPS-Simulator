#include "plane.h"
#include<stdlib.h>
#include "../util/util.h"

void Plane_LineIntersection(struct Plane *plane, struct Line *line, struct Vector3 *result){
//    double
//        a = -line->direction.x,
//        b = plane->direction1.x,
//        c = plane->direction2.x,
//        d = line->position.x - plane->position.x,
//        e = -line->direction.y,
//        f = plane->direction1.y,
//        g = plane->direction2.y,
//        h = line->position.y - plane->position.y,
//        i = -line->direction.z,
//        j = plane->direction1.z,
//        k = plane->direction2.z,
//        l = line->position.z - plane->position.z,
//        alpha = (d * h - b * f - c * e) / (a * f - b * d + c * d),
//        beta = (d * l - a * h - c * g) / (b * f - c * e - a * g),
//        gama = (d * h - a * e - f * h) / (c * d - a * g - b * h);
//    result->x = line->position.x + alpha * line->direction.x;
//    result->y = line->position.y + alpha * line->direction.y;
//    result->z = line->position.z + alpha * line->direction.z;

    double **gaussian_form = malloc(3 * sizeof(double*));
    for (register int i = 0; i < 3; i++) gaussian_form[i] = malloc(4 * sizeof(double));

        gaussian_form[0][0] = -line->direction.x,
        gaussian_form[0][1] = plane->direction1.x,
        gaussian_form[0][2] = plane->direction2.x,
        gaussian_form[0][3] = line->position.x - plane->position.x,
        gaussian_form[1][0] = -line->direction.y,
        gaussian_form[1][1] = plane->direction1.y,
        gaussian_form[1][2] = plane->direction2.y,
        gaussian_form[1][3] = line->position.y - plane->position.y,
        gaussian_form[2][0] = -line->direction.z,
        gaussian_form[2][1] = plane->direction1.z,
        gaussian_form[2][2] = plane->direction2.z,
        gaussian_form[2][3] = line->position.z - plane->position.z,

    Gaussian_Elimination(gaussian_form, 3, 4);

    result->x = line->position.x + gaussian_form[0][3] * line->direction.x;
    result->y = line->position.y + gaussian_form[0][3] * line->direction.y;
    result->z = line->position.z + gaussian_form[0][3] * line->direction.z;

    for (register int i = 0; i < 3; i++) free(gaussian_form[i]);
    free(gaussian_form);
}

void Plane_Set(struct Plane *plane, struct Vector3 *position, struct Vector3 *direction1, struct Vector3 *direction2){
    Vector3_Copy(position, &plane->position);
    Vector3_Copy(direction1, &plane->direction1);
    Vector3_Copy(direction2, &plane->direction2);
}

int Plane_isPointOnPlane(struct Plane *plane, struct Vector3 *point){
    double
        a1 = plane->direction1.x,
        b1 = plane->direction2.x,
        c1 = point->x - plane->position.x,
        a2 = plane->direction1.y,
        b2 = plane->direction2.y,
        c2 = point->y - plane->position.y,
        alpha = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1),
        beta = (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1);
    return double_equal(plane->position.z + alpha * plane->direction1.z + beta * plane->direction2.z, point->z);
}