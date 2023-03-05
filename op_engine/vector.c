#include "vector.h"
#include <stdlib.h>

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

void vector3_swap(struct Vector3 *v1, struct Vector3 *v2){
    struct Vector3 *tmp = malloc(sizeof (struct Vector3));
    tmp->x = v1->x;
    tmp->y = v1->y;
    tmp->z = v1->z;
    v1->x = v2->x;
    v1->y = v2->y;
    v1->z = v2->z;
    v2->x = tmp->x;
    v2->y = tmp->y;
    v2->z = tmp->z;
    free(tmp);
}
double vector3_length2(struct Vector3 *v){
    return v->x * v->x + v->y * v->y + v->z * v->z;
}