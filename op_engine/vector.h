#ifndef OP_VECTOR

//Left hand(x right, y upward, z forward)
struct Vector3 {
    double x, y, z;
};

/*
Basic operations for Vector3
*/

void Vector3_Set(struct Vector3 *v, double x, double y, double z);
void Vector3_Copy(struct Vector3 *from, struct Vector3 *to);
struct Vector3* Vector3_New(double x, double y, double z);

void Vector3_Add(struct Vector3 *v1, struct Vector3 *v2);
void Vector3_Subtract(struct Vector3 *v1, struct Vector3 *v2);
void Vector3_Scale(struct Vector3 *v, double factor);
void vector3_swap(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_MagnitudeSq(struct Vector3 *v);
double Vector3_DistanceSq3D(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_Distance3D(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_IncludedAngle(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_CrossProduct2D(struct Vector3 *v1, struct Vector3 *v2);
void Vector3_CrossProduct3D(struct Vector3 *v1, struct Vector3 *v2, struct Vector3 *result);
double Vector3_DotProduct3D(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_DistanceSq2D(struct Vector3 *v1, struct Vector3 *v2);
double Vector3_Distance2D(struct Vector3 *v1, struct Vector3 *v2);
#define OP_VECTOR
#endif
