#include "vector.h"
#include <stdlib.h>
#include <stdlib.h>
#include "math.h"
#include "../util/util.h"


void Vector3_Copy(struct Vector3 *from, struct Vector3 *to) {
    to->x = from->x;
    to->y = from->y;
    to->z = from->z;
}


void Vector3_Set(struct Vector3 *v, double x, double y, double z){
    v->x = x;
    v->y = y;
    v->z = z;
}


struct Vector3* Vector3_New(double x, double y, double z){
    struct Vector3 *vector = malloc(sizeof(struct Vector3));
    Vector3_Set(vector, x, y, z);
    return vector;
}


void Vector3_Add(struct Vector3 *v1, struct Vector3 *v2){
    v1->x += v2->x;
    v1->y += v2->y;
    v1->z += v2->z;
}


void Vector3_Subtract(struct Vector3 *v1, struct Vector3 *v2) {
    v1->x -= v2->x;
    v1->y -= v2->y;
    v1->z -= v2->z;
}


void Vector3_Scale(struct Vector3 *v, double factor){
    v->x *= factor;
    v->y *= factor;
    v->z *= factor;
}


void Vector3_Normalize(struct Vector3 *v){
    v->x /= sqrt(Vector3_MagnitudeSq(v));
    v->y /= sqrt(Vector3_MagnitudeSq(v));
    v->z /= sqrt(Vector3_MagnitudeSq(v));
}


double Vector3_MagnitudeSq(struct Vector3 *v){
    return v->x * v->x + v->y * v->y + v->z * v->z;
}


double Vector3_Magnitude(struct Vector3 *v){
    return sqrt(Vector3_MagnitudeSq(v));
}


double Vector3_CrossProduct2D(struct Vector3 *v1, struct Vector3 *v2){
    return v1->x * v2->y - v2->x * v1->y;
}


double Vector3_DistanceSq2D(struct Vector3 *v1, struct Vector3 *v2){
    return (v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y);
}


double Vector3_Distance2D(struct Vector3 *v1, struct Vector3 *v2){
    return sqrt(Vector3_DistanceSq2D(v1, v2));
}


void Vector3_CrossProduct3D(struct Vector3 *v1, struct Vector3 *v2, struct Vector3 *result){
    result->x = v1->y * v2->z - v1->z * v2->y;
    result->y = -(v1->x * v2->z - v1->z * v2->x);
    result->z = v1->x * v2->y - v1->y * v2->x;
}


double Vector3_DotProduct3D(struct Vector3 *v1, struct Vector3 *v2){
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}


double Vector3_DistanceSq3D(struct Vector3 *v1, struct Vector3 *v2){
    return (v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y) + (v1->z - v2->z) * (v1->z - v2->z);
}


double Vector3_Distance3D(struct Vector3 *v1, struct Vector3 *v2){
    return sqrt(Vector3_DistanceSq3D(v1, v2));
}


int Vector3_Equal(struct Vector3 *v1, struct Vector3 *v2){
    return double_Equal(v1->x, v2->x)
           && double_Equal(v1->y, v2->y)
           && double_Equal(v1->z, v2->z);
}


void Vector3_Multiply(struct Vector3 *v1, struct Vector3 *v2){
    v1->x *= v2->x;
    v1->y *= v2->y;
    v1->z *= v2->z;
}