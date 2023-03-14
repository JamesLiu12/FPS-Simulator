#ifndef OP_ENGINE_TRANSFORMATION

#include "vector.h"
#include "matrix.h"

struct Transform {
    struct Vector3 position;
    struct Vector3 rotation;
    struct Vector3 scale;
    struct Matrix3x3 rotation_matrix;
};

void Transform_Init(struct Transform *transform);
void Transform_RotationMatrixUpdate(struct Transform *transform);

#define OP_ENGINE_TRANSFORMATION
#endif
