#include "vector.h"

#ifndef OP_MATRIX

//A 3*3 matrix
struct Matrix3x3 {
    double data[3][3];
};

struct EulerAngle {
    double yaw, pinch, row;
};

//The operations of matrix
void matrix3x3_multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2);
void matrix3x3_transform(struct Matrix3x3 *m, struct Vector3 *v);
void matrix3x3_from_euler_angle(struct Matrix3x3 *m, struct EulerAngle* ea);

#define OP_MATRIX
#endif
