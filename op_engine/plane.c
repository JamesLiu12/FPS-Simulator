#include "plane.h"

void Plane_intersection_Line(struct Plane *plane, struct Line *line, struct Vector3 *result){
    double
        a = -line->position.x,
        b = plane->direction1.x,
        c = plane->direction2.x,
        d = line->position.x - plane->position.x,
        e = -line->position.y,
        f = plane->direction1.y,
        g = plane->direction2.y,
        h = line->position.y - plane->position.y,
        i = -line->position.z,
        j = plane->direction1.z,
        k = plane->direction2.z,
        l = line->position.z - plane->position.z,
        alpha = (d * h - b * f - c * e) / (a * f - b * d + c * d),
        beta = (d * l - a * h - c * g) / (b * f - c * e - a * g),
        gama = (d * h - a * e - f * h) / (c * d - a * g - b * h);
    result->x = line->position.x + alpha * line->direction.x;
    result->y = line->position.y + alpha * line->direction.y;
    result->z = line->position.z + alpha * line->direction.z;
}

void Plane_Set(struct Plane *plane, struct Vector3 *position, struct Vector3 *direction1, struct Vector3 *direction2){
    plane->position.x = position->x;
    plane->position.y = position->y;
    plane->position.z = position->z;
    plane->direction1.x = direction1->x;
    plane->direction1.y = direction1->y;
    plane->direction1.z = direction1->z;
    plane->direction2.x = direction2->x;
    plane->direction2.y = direction2->y;
    plane->direction2.z = direction2->z;
}