#include "matrix.h"
#include <stdlib.h>
#include <memory.h>
#include <math.h>

void matrix3x3_multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2){
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

void matrix3x3_transform(struct Matrix3x3 *m, struct Vector3 *v) {
    double result_x = 0, result_y = 0, result_z = 0;
    register int column;

    for (column = 0; column < 3; column++) {
        result_x += m->data[0][column] * v->x;
        result_y += m->data[1][column] * v->y;
        result_z += m->data[2][column] * v->z;
    }

    v->x = result_x;
    v->y = result_y;
    v->z = result_z;
}

void matrix3x3_from_euler_angle(struct Matrix3x3 *m, struct EulerAngle* ea, char reversed) {
    double yaw, pinch, row;

    if (reversed) {
        yaw = -ea->yaw;
        pinch = -ea->pinch;
        row = -ea->roll;
    } else {
        yaw = ea->yaw;
        pinch = ea->pinch;
        row = ea->roll;
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

