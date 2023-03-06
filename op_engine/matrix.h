#ifndef OP_MATRIX

#include "vector.h"

//A 3*3 matrix
struct Matrix3x3 {
    double data[3][3];
};

struct EulerAngle {
    double yaw, pinch, roll;
};

//The operations of matrix
void Matrix3x3_Multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2);
void Matrix3x3_Transform(struct Matrix3x3 *m, struct Vector3 *v);

#define EULER_ANGLE_REVERSED 1
#define EULER_ANGLE_NORMAL 0
void Matrix3x3_FromEulerAngle(struct Matrix3x3 *m, struct Vector3 *ea, char reversed);

#define OP_MATRIX
#endif
