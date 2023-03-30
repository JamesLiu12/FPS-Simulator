#include "collide_box.h"
#include "plane.h"
#include "triangle.h"
#include <math.h>

void CollideBox_Set(struct CollideBox *box, struct Vector3 *minVertex, struct Vector3 *maxVertex){
    box->minVertex = *minVertex;
    box->maxVertex = *maxVertex;
}

double CollideBox_RayDistance(struct CollideBox *box, struct Transform *transform, struct Line *ray){

    struct Vector3 vertices[8];
    Vector3_Set(&vertices[0], box->minVertex.x, box->minVertex.y, box->minVertex.z);
    Vector3_Set(&vertices[1], box->maxVertex.x, box->minVertex.y, box->minVertex.z);
    Vector3_Set(&vertices[2], box->maxVertex.x, box->minVertex.y, box->maxVertex.z);
    Vector3_Set(&vertices[3], box->minVertex.x, box->minVertex.y, box->maxVertex.z);
    Vector3_Set(&vertices[4], box->minVertex.x, box->maxVertex.y, box->minVertex.z);
    Vector3_Set(&vertices[5], box->maxVertex.x, box->maxVertex.y, box->minVertex.z);
    Vector3_Set(&vertices[6], box->maxVertex.x, box->maxVertex.y, box->maxVertex.z);
    Vector3_Set(&vertices[7], box->minVertex.x, box->maxVertex.y, box->maxVertex.z);

    Transform_UpdateGlobal(transform);
    for (int i = 0; i < 8; i++){
        Transform_ToGlobal(transform, &vertices[i]);
    }

    struct Triangle triangles[12];
    struct Plane planes[6];
    struct Vector3 d1, d2;

    //front surface
    Triangle_Set(&triangles[0], &vertices[0], &vertices[1], &vertices[5]);
    Triangle_Set(&triangles[1], &vertices[0], &vertices[4], &vertices[5]);
    d1 = vertices[1];
    d2 = vertices[4];
    Vector3_Subtract(&d1, &vertices[0]);
    Vector3_Subtract(&d2, &vertices[0]);
    Plane_Set(&planes[0], &vertices[0], &d1, &d2);

    //bottom surface
    Triangle_Set(&triangles[2], &vertices[0], &vertices[1], &vertices[2]);
    Triangle_Set(&triangles[3], &vertices[0], &vertices[3], &vertices[2]);
    d1 = vertices[1];
    d2 = vertices[3];
    Vector3_Subtract(&d1, &vertices[0]);
    Vector3_Subtract(&d2, &vertices[0]);
    Plane_Set(&planes[1], &vertices[0], &d1, &d2);

    //left surface
    Triangle_Set(&triangles[4], &vertices[0], &vertices[4], &vertices[7]);
    Triangle_Set(&triangles[5], &vertices[0], &vertices[3], &vertices[7]);
    d1 = vertices[4];
    d2 = vertices[3];
    Vector3_Subtract(&d1, &vertices[0]);
    Vector3_Subtract(&d2, &vertices[0]);
    Plane_Set(&planes[2], &vertices[0], &d1, &d2);

    //right surface
    Triangle_Set(&triangles[6], &vertices[6], &vertices[2], &vertices[1]);
    Triangle_Set(&triangles[7], &vertices[6], &vertices[5], &vertices[1]);
    d1 = vertices[2];
    d2 = vertices[5];
    Vector3_Subtract(&d1, &vertices[6]);
    Vector3_Subtract(&d2, &vertices[6]);
    Plane_Set(&planes[3], &vertices[0], &d1, &d2);

    //back surface
    Triangle_Set(&triangles[8], &vertices[6], &vertices[2], &vertices[3]);
    Triangle_Set(&triangles[9], &vertices[6], &vertices[7], &vertices[3]);
    d1 = vertices[2];
    d2 = vertices[7];
    Vector3_Subtract(&d1, &vertices[6]);
    Vector3_Subtract(&d2, &vertices[6]);
    Plane_Set(&planes[4], &vertices[0], &d1, &d2);

    //up surface
    Triangle_Set(&triangles[10], &vertices[6], &vertices[5], &vertices[4]);
    Triangle_Set(&triangles[11], &vertices[6], &vertices[7], &vertices[4]);
    d1 = vertices[5];
    d2 = vertices[7];
    Vector3_Subtract(&d1, &vertices[6]);
    Vector3_Subtract(&d2, &vertices[6]);
    Plane_Set(&planes[5], &vertices[0], &d1, &d2);

    double result = INFINITY;

    for (int i = 0; i < 6; i++){
        struct Vector3 intersection;
        Plane_LineIntersection(&planes[i], ray, &intersection);
        if (double_IsSameSign(intersection.x - ray->position.x, ray->direction.x)
        && (Triangle_IsPointInTriangle3D(&triangles[i * 2], &intersection)
        || Triangle_IsPointInTriangle3D(&triangles[i * 2 + 1], &intersection))){
            double distance = Vector3_Distance3D(&ray->position, &intersection);
            if (distance < result) result = distance;
        }
    }
    return result;
}

double CollideBox_IsCollide(struct CollideBox *b1, struct Transform *t1, struct CollideBox *b2, struct Transform *t2){
    Transform_UpdateGlobal(t1);
    Transform_UpdateGlobal(t2);

    struct Vector3 b1_minV = b1->minVertex;
    struct Vector3 b1_maxV = b1->maxVertex;
    struct Vector3 b2_minV = b2->minVertex;
    struct Vector3 b2_maxV = b2->maxVertex;

    Transform_ToGlobal(t1, &b1_minV);
    Transform_ToGlobal(t1, &b1_maxV);
    Transform_ToGlobal(t2, &b2_minV);
    Transform_ToGlobal(t2, &b2_maxV);

    return (b1_minV.x >= b2_maxV.x || b2_minV.x >= b1_maxV.x)
        && (b1_minV.y >= b2_maxV.y || b2_minV.y >= b1_maxV.y)
        && (b1_minV.z >= b2_maxV.z || b2_minV.z >= b1_maxV.z);
}