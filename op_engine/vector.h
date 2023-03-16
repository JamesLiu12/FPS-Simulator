#ifndef OP_VECTOR

//Left hand(x right, y upward, z forward)
struct Vector3 {
    double x, y, z;
};

/*
Basic operations for Vector3
*/

//The setter for Vector3
void Vector3_Set(struct Vector3 *v, double x, double y, double z);

//Copy the value in "from" to "to"
void Vector3_Copy(struct Vector3 *from, struct Vector3 *to);

//The newer for Vector3
struct Vector3* Vector3_New(double x, double y, double z);

//The basic operations for Vector3
void Vector3_Add(struct Vector3 *v1, struct Vector3 *v2);
void Vector3_Subtract(struct Vector3 *v1, struct Vector3 *v2);
void Vector3_Scale(struct Vector3 *v, double factor);

//Return the square of module length of v
double Vector3_MagnitudeSq(struct Vector3 *v);

//Return the square of distance between v1 and v2
double Vector3_DistanceSq3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the distance between v1 and v2
double Vector3_Distance3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the result of cross product of v1 and v2, only considering the x and y
double Vector3_CrossProduct2D(struct Vector3 *v1, struct Vector3 *v2);

//Cross product of v1 and v2
void Vector3_CrossProduct3D(struct Vector3 *v1, struct Vector3 *v2, struct Vector3 *result);

//Return the result of dot product of v1 and v2
double Vector3_DotProduct3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the result of dot product of v1 and v2, only considering the x and y
double Vector3_DistanceSq2D(struct Vector3 *v1, struct Vector3 *v2);

//Return the distance between v1 and v2, only considering the x and y
double Vector3_Distance2D(struct Vector3 *v1, struct Vector3 *v2);

//Return True <=> the value of v1 equal to that of v2
int Vector3_Equal(struct Vector3 *v1, struct Vector3 *v2);

#define OP_VECTOR
#endif
