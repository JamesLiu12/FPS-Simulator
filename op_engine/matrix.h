#ifndef OP_MATRIX

#include "vector.h"

//A 3*3 matrix
struct Matrix3x3 {
    double data[3][3];
};

//The multiplication of two matrix
void Matrix3x3_Multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2);

//Apply a transformation m to v
void Matrix3x3_TransformMatrix(struct Matrix3x3 *m, struct Vector3 *v);

void Matrix3x3_TransformEuler(struct Vector3 *angle, struct Vector3 *v);

#define EULER_ANGLE_REVERSED 1
#define EULER_ANGLE_NORMAL 0

/*
 * Transform the euler angle ea in to the matrix form m
 * if reversed is true, then result is the inverse matrix
 */
void Matrix3x3_FromEulerAngle(struct Matrix3x3 *m, struct Vector3 *ea, char reversed);

void Matrix3x3_ToEuler(struct Matrix3x3 *m, struct Vector3 *v);

void Matrix3x3_Copy(struct Matrix3x3 *from, struct Matrix3x3 *to);

#define OP_MATRIX
#endif
