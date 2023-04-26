#include "matrix.h"
#include <memory.h>
#include <math.h>
#include "../util/util.h"

void Matrix3x3_Multiply(struct Matrix3x3 *m1, struct Matrix3x3 *m2){
    double results[3] = {0, 0, 0};
    int row, col, pt;

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

void Matrix3x3_TransformMatrix(struct Matrix3x3 *m, struct Vector3 *v) {
    double result_x = 0, result_y = 0, result_z = 0;
    int col;

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

void Matrix3x3_TransformEuler(struct Vector3 *angle, struct Vector3 *v){
    struct Matrix3x3 m;
    Matrix3x3_FromEulerAngle(&m, angle, TRUE);
    Matrix3x3_TransformMatrix(&m, v);
}

void Matrix3x3_FromEulerAngle(struct Matrix3x3 *m, struct Vector3 *ea, char reversed) {
    double yaw, pinch, roll;

    if (reversed) {
        yaw = -ea->y;
        pinch = -ea->x;
        roll = -ea->z;
    } else {
        yaw = ea->y;
        pinch = ea->x;
        roll = ea->z;
    }

    m->data[0][0] = cos(yaw) * cos(roll) + sin(yaw) * sin(pinch) * sin(roll);
    m->data[0][1] = sin(yaw) * sin(pinch) * cos(roll) - cos(yaw) * sin(roll);
    m->data[0][2] = sin(yaw) * cos(pinch);
    m->data[1][0] = cos(pinch) * sin(roll);
    m->data[1][1] = cos(pinch) * cos(roll);
    m->data[1][2] = -sin(pinch);
    m->data[2][0] = cos(yaw) * sin(pinch) * sin(roll) - sin(yaw) * cos(roll);
    m->data[2][1] = cos(yaw) * sin(pinch) * cos(roll) + sin(yaw) * sin(roll);
    m->data[2][2] = cos(yaw) * cos(pinch);
}

void Matrix3x3_ToEuler(struct Matrix3x3 *m, struct Vector3 *v) {
    double cos_pitch = sqrt(m->data[0][0] * m->data[0][0] + m->data[1][0] * m->data[1][0]);
    double roll, pitch, yaw;
    if (cos_pitch > 1e-6) {
        pitch = atan2(-m->data[2][0], cos_pitch);
        yaw = atan2(m->data[0][1] / cos_pitch, m->data[1][1] / cos_pitch);
        roll = atan2(m->data[2][1] / cos_pitch, m->data[2][2] / cos_pitch);
    } else {
        pitch = atan2(-m->data[2][0], cos_pitch);
        yaw = atan2(-m->data[1][2], m->data[1][1]);
        roll = 0;
    }
    v->x = roll;
    v->y = pitch;
    v->z = yaw;
}

void Matrix3x3_Copy(struct Matrix3x3 *from, struct Matrix3x3 *to){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            to->data[i][j] = from->data[i][j];
        }
    }
}