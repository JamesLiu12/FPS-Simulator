#include "triangle.h"

void Triangle_set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3){
    triangle->v1.x = p1->x;
    triangle->v1.y = p1->y;
    triangle->v1.z = p1->z;
    triangle->v2.x = p2->x;
    triangle->v2.y = p2->y;
    triangle->v2.z = p2->z;
    triangle->v3.x = p3->x;
    triangle->v3.y = p3->y;
    triangle->v3.z = p3->z;
}