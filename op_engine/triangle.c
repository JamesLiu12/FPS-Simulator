#include "triangle.h"
#include "plane.h"
#include <math.h>

void Triangle_Set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3){
    Vector3_Copy(p1, &triangle->v1);
    Vector3_Copy(p2, &triangle->v2);
    Vector3_Copy(p3, &triangle->v3);
}

int Triangle_IsPointInRange(struct Triangle *triangle, struct Vector3 *point){
    return fmin(fmin(triangle->v1.x, triangle->v2.x), triangle->v3.x) <= point->x
        && fmax(fmin(triangle->v1.x, triangle->v2.x), triangle->v3.x) >= point->x
        && fmin(fmin(triangle->v1.y, triangle->v2.y), triangle->v3.y) <= point->y
        && fmax(fmin(triangle->v1.y, triangle->v2.y), triangle->v3.y) >= point->y
        && fmin(fmin(triangle->v1.z, triangle->v2.z), triangle->v3.z) <= point->z
        && fmax(fmin(triangle->v1.z, triangle->v2.z), triangle->v3.z) >= point->z;
}

int Triangle_IsPointInTriangle2D(struct Triangle *triangle, struct Vector3 *point){
    double result1, result2, result3;
    struct Vector3 v1, v2;
    Vector3_Copy(&triangle->v2, &v1);
    Vector3_Copy(point, &v2);
    Vector3_Subtract(&v1, &triangle->v1);
    Vector3_Subtract(&v2, &triangle->v1);
    result1 = Vector3_CrossProduct2D(&v1, &v2);

    Vector3_Copy(&triangle->v3, &v1);
    Vector3_Copy(point, &v2);
    Vector3_Subtract(&v1, &triangle->v2);
    Vector3_Subtract(&v2, &triangle->v2);
    result2 = Vector3_CrossProduct2D(&v1, &v2);

    Vector3_Copy(&triangle->v1, &v1);
    Vector3_Copy(point, &v2);
    Vector3_Subtract(&v1, &triangle->v3);
    Vector3_Subtract(&v2, &triangle->v3);
    result3 = Vector3_CrossProduct2D(&v1, &v2);

    return (result1 >= 0 && result2 >= 0 && result3 >= 0) || (result1 < 0 && result2 < 0 && result3 < 0);
}

int IsOnSameSide(struct Vector3* A, struct Vector3 *B, struct Vector3 *C, struct Vector3 *P){
    struct Vector3 vec_tmp, AB, AC, AP, res1, res2;

    Vector3_Copy(B, &vec_tmp);
    Vector3_Subtract(&vec_tmp, A);
    Vector3_Copy(&vec_tmp, &AB);

    Vector3_Copy(C, &vec_tmp);
    Vector3_Subtract(&vec_tmp, A);
    Vector3_Copy(&vec_tmp, &AC);

    Vector3_Copy(P, &vec_tmp);
    Vector3_Subtract(&vec_tmp, A);
    Vector3_Copy(&vec_tmp, &AP);

    Vector3_CrossProduct3D(&AB, &AC, &res1);
    Vector3_CrossProduct3D(&AB, &AP, &res2);

    return Vector3_DotProduct3D(&res1, &res2) >= 0;
}

int Triangle_IsPointInTriangle3D(struct Triangle *triangle, struct Vector3 *point){
    return IsOnSameSide(&triangle->v1, &triangle->v2, &triangle->v3, point)
        && IsOnSameSide(&triangle->v2, &triangle->v3, &triangle->v1, point)
        && IsOnSameSide(&triangle->v3, &triangle->v1, &triangle->v2, point);
}