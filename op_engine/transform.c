#include "transform.h"
#include "matrix.h"
#include <stdio.h>

void Transform_Init(struct Transform *transform) {
    transform->position.x = 0;
    transform->position.y = 0;
    transform->position.z = 0;

    transform->rotation.x = 0;
    transform->rotation.y = 0;
    transform->rotation.z = 0;

    transform->scale.x = 1;
    transform->scale.y = 1;
    transform->scale.z = 1;

    Matrix3x3_FromEulerAngle(
            &transform->rotation_matrix, &transform->rotation, EULER_ANGLE_NORMAL);
}

void Transform_RotationMatrixUpdate(struct Transform *transform) {
    Matrix3x3_FromEulerAngle(
            &transform->rotation_matrix, &transform->rotation, EULER_ANGLE_NORMAL);
}
