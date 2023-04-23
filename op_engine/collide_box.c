#include "collide_box.h"
#include "plane.h"
#include "triangle.h"
#include <math.h>

void CollideBox_Init(struct CollideBox *box, struct Transform *father , double length, double height, double width){
    Transform_Init(&box->transform, father);
    box->halfSize.x = length / 2;
    box->halfSize.y = height / 2;
    box->halfSize.z = width / 2;
}

void Del_CollideBox(struct CollideBox *box){
    Del_Transform(&box->transform);
}

double CollideBox_RayDistance(struct CollideBox *box, struct Line *ray){
    struct Vector3 vertices[8];
    Vector3_Set(&vertices[0], box->halfSize.x, box->halfSize.y, box->halfSize.z);
    Vector3_Set(&vertices[1], -box->halfSize.x, box->halfSize.y, box->halfSize.z);
    Vector3_Set(&vertices[2], -box->halfSize.x, box->halfSize.y, -box->halfSize.z);
    Vector3_Set(&vertices[3], box->halfSize.x, box->halfSize.y, -box->halfSize.z);
    Vector3_Set(&vertices[4], box->halfSize.x, -box->halfSize.y, box->halfSize.z);
    Vector3_Set(&vertices[5], -box->halfSize.x, -box->halfSize.y, box->halfSize.z);
    Vector3_Set(&vertices[6], -box->halfSize.x, -box->halfSize.y, -box->halfSize.z);
    Vector3_Set(&vertices[7], box->halfSize.x, -box->halfSize.y, -box->halfSize.z);

    Transform_UpdateGlobal(&box->transform);
    for (int i = 0; i < 8; i++){
        Transform_ToGlobal(&box->transform, &vertices[i]);
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
        || Triangle_IsPointInTriangle3D(&triangles[i * 2 + 1], &intersection))
        && !Vector3_Equal(&intersection, &ray->position)){
            double distance = Vector3_Distance3D(&ray->position, &intersection);
            if (distance < result) result = distance;
        }
    }
    return result;
}

struct Axis{
    struct Vector3 X, Y, Z;
};

bool hasSeparatingAxis(struct Vector3 *posDiff, struct Vector3 *axis, struct CollideBox *b1, struct CollideBox *b2,
                        struct Axis *axis_b1, struct Axis *axis_b2){
    double sum = 0;
    struct Vector3 vec;

    vec = axis_b1->X;
    Vector3_Scale(&vec, b1->halfSize.x);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));
    vec = axis_b1->Y;
    Vector3_Scale(&vec, b1->halfSize.y);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));
    vec = axis_b1->Z;
    Vector3_Scale(&vec, b1->halfSize.z);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));
    vec = axis_b2->X;
    Vector3_Scale(&vec, b2->halfSize.x);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));
    vec = axis_b2->Y;
    Vector3_Scale(&vec, b2->halfSize.y);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));
    vec = axis_b2->Z;
    Vector3_Scale(&vec, b2->halfSize.z);
    sum += fabs(Vector3_DotProduct3D(&vec, axis));

    return fabs(Vector3_DotProduct3D(posDiff, axis)) > sum;
}

int CollideBox_IsCollide(struct CollideBox *b1, struct CollideBox *b2){
    Transform_UpdateGlobal(&b1->transform);
    Transform_UpdateGlobal(&b2->transform);

    struct Vector3 posDiff = b2->transform.globalPosition;
    Vector3_Subtract(&posDiff, &b1->transform.globalPosition);

    struct Axis axis_b1, axis_b2;

    Vector3_Set(&axis_b1.X, 1, 0, 0);
    Vector3_Set(&axis_b1.Y, 0, 1, 0);
    Vector3_Set(&axis_b1.Z, 0, 0, 1);
    Matrix3x3_TransformEular(&b1->transform.globalRotation, &axis_b1.X);
    Matrix3x3_TransformEular(&b1->transform.globalRotation, &axis_b1.Y);
    Matrix3x3_TransformEular(&b1->transform.globalRotation, &axis_b1.Z);

    Vector3_Set(&axis_b2.X, 1, 0, 0);
    Vector3_Set(&axis_b2.Y, 0, 1, 0);
    Vector3_Set(&axis_b2.Z, 0, 0, 1);
    Matrix3x3_TransformEular(&b2->transform.globalRotation, &axis_b2.X);
    Matrix3x3_TransformEular(&b2->transform.globalRotation, &axis_b2.Y);
    Matrix3x3_TransformEular(&b2->transform.globalRotation, &axis_b2.Z);

    struct Axis axis_c1, axis_c2, axis_c3;
    axis_c1.X = axis_b1.X;
    axis_c1.Y = axis_b1.X;
    axis_c1.Z = axis_b1.X;
    axis_c2.X = axis_b1.Y;
    axis_c2.Y = axis_b1.Y;
    axis_c2.Z = axis_b1.Y;
    axis_c3.X = axis_b1.Z;
    axis_c3.Y = axis_b1.Z;
    axis_c3.Z = axis_b1.Z;

    Vector3_CrossProduct3D(&axis_b1.X, &axis_b2.X, &axis_c1.X);
    Vector3_CrossProduct3D(&axis_b1.X, &axis_b2.Y, &axis_c1.Y);
    Vector3_CrossProduct3D(&axis_b1.X, &axis_b2.Z, &axis_c1.Z);
    Vector3_CrossProduct3D(&axis_b1.Y, &axis_b2.X, &axis_c2.X);
    Vector3_CrossProduct3D(&axis_b1.Y, &axis_b2.Y, &axis_c2.Y);
    Vector3_CrossProduct3D(&axis_b1.Y, &axis_b2.Z, &axis_c2.Z);
    Vector3_CrossProduct3D(&axis_b1.Z, &axis_b2.X, &axis_c3.X);
    Vector3_CrossProduct3D(&axis_b1.Z, &axis_b2.Y, &axis_c3.Y);
    Vector3_CrossProduct3D(&axis_b1.Z, &axis_b2.Z, &axis_c3.Z);

    return !(
            hasSeparatingAxis(&posDiff, &axis_b1.X, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_b1.Y, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_b1.Z, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_b2.X, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_b2.Y, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_b2.Z, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c1.X, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c1.Y, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c1.Z, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c2.X, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c2.Y, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c2.Z, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c3.X, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c3.Y, b1, b2, &axis_b1, &axis_b2) ||
            hasSeparatingAxis(&posDiff, &axis_c3.Z, b1, b2, &axis_b1, &axis_b2));
}