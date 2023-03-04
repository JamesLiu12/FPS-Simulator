#pragma once
#include <stdio.h>

#include "op_engine/op_engine.h"

int main() {
    struct Vector3 vec;
    struct Matrix3x3 mat;
    struct EulerAngle ea;

    ea.yaw = 0;
    ea.pinch = 0.3;
    ea.row = 0;
    vec.x = 1;
    vec.y = 1;
    vec.z = 1;
    matrix3x3_from_euler_angle(&mat, &ea);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) printf("%.3f ", mat.data[i][j]);
        puts("");
    }
    matrix3x3_transform(&mat, &vec);
    printf("%.3f %.3f %.3f \n", vec.x, vec.y, vec.z);

    return 0;
}
