#include "matrix.h"
#include <memory.h>
#include <math.h>

void Matrix3x3_Multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2){
    double results[3] = {0, 0, 0};
    register int row, col, pt;

    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            for (pt = 0; pt < 3; pt++){
                results[col] += m1->data[row][pt] * m2->data[col][pt];
            }
        }
        for (col = 0; col < 3; col++) m1->data[row][col] = results[col];
        memset(results, 0, sizeof results);
    }

}

void Matrix3x3_Transform(struct Matrix3x3 *m, struct Vector3 *v) {
    double result_x = 0, result_y = 0, result_z = 0;
    register int col;

    result_x += m->data[0][0] * v->x;
    result_y += m->data[1][0] * v->x;
    result_z += m->data[2][0] * v->x;

    result_x += m->data[0][1] * v->y;
    result_y += m->data[1][1] * v->y;
    result_z += m->data[2][1] * v->y;

    result_x += m->data[0][2] * v->z;
    result_y += m->data[1][2] * v->z;
    result_z += m->data[2][2] * v->z;

    v->x = result_x;
    v->y = result_y;
    v->z = result_z;
}

void Matrix3x3_FromEulerAngle(struct Matrix3x3 *m, struct Vector3 *ea, char reversed) {
    double yaw, pinch, row;

    if (reversed) {
        yaw = -ea->y;
        pinch = -ea->x;
        row = -ea->z;
    } else {
        yaw = ea->y;
        pinch = ea->x;
        row = ea->z;
    }

    m->data[0][0] = cos(yaw) * cos(row) + sin(yaw) * sin(pinch) * sin(row);
    m->data[0][1] = sin(yaw) * sin(pinch) * cos(row) - cos(yaw) * sin(row);
    m->data[0][2] = sin(yaw) * cos(pinch);
    m->data[1][0] = cos(pinch) * sin(row);
    m->data[1][1] = cos(pinch) * cos(row);
    m->data[1][2] = -sin(pinch);
    m->data[2][0] = cos(yaw) * sin(pinch) * sin(row) - sin(yaw) * cos(row);
    m->data[2][1] = cos(yaw) * sin(pinch) * cos(row) + sin(yaw) * sin(row);
    m->data[2][2] = cos(yaw) * cos(pinch);
}

