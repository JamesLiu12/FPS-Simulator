#include "triangle.h"
#include "plane.h"
#include <math.h>

void Triangle_Set(struct Triangle *triangle, struct Vector3 *p1, struct Vector3 *p2, struct Vector3 *p3){
    Vector3_Copy(p1, &triangle->v1);
    Vector3_Copy(p2, &triangle->v2);
    Vector3_Copy(p3, &triangle->v3);
}

int Triangle_IsPointInTriangle2D(struct Triangle *triangle, struct Vector3 *point){
    //The point is inside the triangle if for each side of triangle, the point is on the same side of another vertex
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


/*
 * A private function that checks the vectors AC and AP is on the same side about AB
 */
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
    //The point is inside the triangle if for each side of triangle, the point is on the same side of another vertex
    return IsOnSameSide(&triangle->v1, &triangle->v2, &triangle->v3, point)
        && IsOnSameSide(&triangle->v2, &triangle->v3, &triangle->v1, point)
        && IsOnSameSide(&triangle->v3, &triangle->v1, &triangle->v2, point);
}

double Triangle_PerspectiveCorrectInterpolation(struct Triangle *triangle, struct Vector3 *point){
    struct Vector3 *A, *B, *C, *P;
    A = &triangle->v1;
    B = &triangle->v2;
    C = &triangle->v3;
    P = point;

    /*
     * The three coefficient of interpolation of the triangle on the screen
     * A point on triangle can be expressed as "alpha * A + beta * B + gama * C", where "alpha + beta + gama = 1"
    */
    double
        beta = ((P->y - A->y) * (C->x - A->x) - (P->x - A->x) * (C->y - A->y))
                / ((B->y - A->y) * (C->x - A->x) - (B->x - A->x) * (C->y - A->y)),
        gama = ((P->y - A->y) * (B->x - A->x) - (P->x - A->x) * (B->y - A->y))
                / ((C->y - A->y) * (B->x - A->x) - (C->x - A->x) * (B->y - A->y)),
        alpha = 1 - beta - gama;

    //The perspective correction
    return 1 / (alpha / A->z + beta / B->z + gama / C->z);
}