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
    Transform_UpdateGlobal(transform);
    transform->childCount = 0;
    ArrayList_Init(&transform->list_child, sizeof(struct Transform*));
}

void Del_Transform(struct Transform *transform){
    Del_ArrayList(&transform->list_child);
    free(transform);
}

void Transform_RotationMatrixUpdate(struct Transform *transform) {
    Matrix3x3_FromEulerAngle(
            &transform->rotationMatrix, &transform->rotation, EULER_ANGLE_NORMAL);
}

void Transform_UpdateGlobal(struct Transform *transform){
    transform->globalPosition = transform->position;
    transform->globalRotation = transform->rotation;
    transform->globalScale = transform->scale;

    if (transform->father == NULL) return;
    Transform_UpdateGlobal(transform->father);

    Vector3_Add(&transform->globalPosition, &transform->father->globalPosition);
    Vector3_Add(&transform->globalRotation, &transform->father->globalRotation);
    Vector3_Add(&transform->globalScale, &transform->father->globalScale);

    Matrix3x3_FromEulerAngle(
            &transform->globalRotationMatrix, &transform->globalRotation, EULER_ANGLE_NORMAL);
}

void Transform_addChild(struct Transform *transform, struct Transform *child){
    ArrayList_Append(&transform->list_child, child);
}