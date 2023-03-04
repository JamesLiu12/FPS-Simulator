#include "vector.h"

void vector3_add(struct Vector3 *v1, struct Vector3 *v2){
    v1->x += v2->x;
    v1->y += v2->y;
    v1->z += v2->z;
}

void vector3_subtract(struct Vector3 *v1, struct Vector3 *v2) {
    v1->x -= v2->x;
    v1->y -= v2->y;
    v1->z -= v2->z;
}

void vector3_scale(struct Vector3 *v, double factor){
    v->x *= factor;
    v->y *= factor;
    v->z *= factor;
}
