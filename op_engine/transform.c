#include "transform.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void Transform_Init(struct Transform *transform, struct Transform *father_transform) {
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
            &transform->rotationMatrix, &transform->rotation, EULER_ANGLE_NORMAL);

    transform->father = father_transform;
    if (transform->father != NULL) Transform_AddChild(father_transform, transform);
    Transform_UpdateGlobal(transform);
    transform->childCount = 0;
    ArrayList_Init(&transform->list_child, sizeof(struct Transform*));
}

void Del_Transform(struct Transform *transform){
    Del_ArrayList(&transform->list_child);
//    free(transform);
}

void Transform_RotationMatrixUpdate(struct Transform *transform) {
    Matrix3x3_FromEulerAngle(
            &transform->rotationMatrix, &transform->rotation, EULER_ANGLE_NORMAL);
}

void Transform_UpdateGlobal(struct Transform *transform){
    transform->globalPosition = transform->position;
    transform->globalRotation = transform->rotation;
    transform->globalScale = transform->scale;

    Matrix3x3_FromEulerAngle(
            &transform->globalRotationMatrix, &transform->globalRotation, EULER_ANGLE_NORMAL);

    if (transform->father == NULL) return;
    Transform_UpdateGlobal(transform->father);

    Vector3_Add(&transform->globalRotation, &transform->father->globalRotation);
    Vector3_Multiply(&transform->globalScale, &transform->father->globalScale);

    Matrix3x3_TransformMatrix(&transform->father->globalRotationMatrix, &transform->globalPosition);
    Vector3_Multiply(&transform->globalPosition, &transform->father->globalScale);
    Vector3_Add(&transform->globalPosition, &transform->father->globalPosition);

    Matrix3x3_FromEulerAngle(
            &transform->globalRotationMatrix, &transform->globalRotation, EULER_ANGLE_NORMAL);
}

//void Transform_UpdateGlobal(struct Transform *transform) {
//    // 如果存在父物体，先更新父物体的全局信息
//    if (transform->father != NULL) {
//        Transform_UpdateGlobal(transform->father);
//    }
//
//    // 更新子物体的全局信息
//    transform->globalPosition = transform->position;
//    transform->globalRotation = transform->rotation;
//    transform->globalScale = transform->scale;
//    Matrix3x3_FromEulerAngle(
//            &transform->globalRotationMatrix, &transform->globalRotation, EULER_ANGLE_NORMAL);
//
//    Matrix3x3_FromEulerAngle(
//            &transform->rotationMatrix, &transform->rotation, EULER_ANGLE_NORMAL);
//
//    if (transform->father != NULL) {
//        // 将子物体和父物体的局部欧拉角转换为旋转矩阵
//
//        // 将两个旋转矩阵相乘以获得子物体的全局旋转矩阵
//        Matrix3x3_Copy(&transform->father->globalRotationMatrix, &transform->globalRotationMatrix);
//        Matrix3x3_Multiply(&transform->globalRotationMatrix, &transform->rotationMatrix);
//
//        // 将全局旋转矩阵转换回欧拉角
//        Matrix3x3_ToEuler(&transform->globalRotationMatrix, &transform->globalRotation);
//
//        // 更新子物体的全局缩放
//        Vector3_Multiply(&transform->globalScale, &transform->father->globalScale);
//
//        // 更新子物体的全局位置
//        Matrix3x3_TransformMatrix(&transform->father->globalRotationMatrix, &transform->globalPosition);
//        Vector3_Multiply(&transform->globalPosition, &transform->father->globalScale);
//        Vector3_Add(&transform->globalPosition, &transform->father->globalPosition);
//    }
//
//    // 更新子物体的全局旋转矩阵
//    Matrix3x3_FromEulerAngle(
//            &transform->globalRotationMatrix, &transform->globalRotation, EULER_ANGLE_NORMAL);
//}

void Transform_AddChild(struct Transform *transform, struct Transform *child){
    ArrayList_PushBack(&transform->list_child, child);
    transform->childCount++;
}

void Transform_ToGlobal(struct Transform *transform, struct Vector3 *vector){
//    Matrix3x3_TransformMatrix(&transform->globalRotationMatrix, vector);
    Matrix3x3_TransformEuler(&transform->globalRotation, vector);
    Vector3_Multiply(vector, &transform->globalScale);
    Vector3_Add(vector, &transform->globalPosition);
}

void Transform_AddPosition(struct Transform *transform, struct Vector3 *position){
    Vector3_Add(&transform->position, position);
}

void Transform_AddRotation(struct Transform *transform, struct Vector3 *rotation){
    Vector3_Add(&transform->rotation, rotation);
    Matrix3x3_FromEulerAngle(&transform->rotationMatrix, &transform->rotation, EULER_ANGLE_NORMAL);
}

void Transform_CopyValues(struct Transform *from, struct Transform *to){
    to->position = from->position;
    to->rotation = from->rotation;
    to->scale = from->scale;
    Matrix3x3_FromEulerAngle(
            &to->rotationMatrix, &to->rotation, EULER_ANGLE_NORMAL);
}