#include "vector.h"
#include <stdlib.h>
#include <stdlib.h>
#include "math.h"
#include "../util/util.h"

// copies the data from one vector to another
// input: a pointer to the vector being copied from, a pointer to the vector being copied to
// output: void
void Vector3_Copy(struct Vector3 *from, struct Vector3 *to) {
    to->x = from->x;
    to->y = from->y;
    to->z = from->z;
}

// assigns values to a 3D vector
// input: a pointer to a vector struct, three doubles, x, y, z representing the components of the vector
// output: void
void Vector3_Set(struct Vector3 *v, double x, double y, double z){
    v->x = x;
    v->y = y;
    v->z = z;
}

// creates a new 3D vector
// input: 3 doubles, x, y, z, representing the components of the vecotr
// output: a pointer to a vector struct
struct Vector3* Vector3_New(double x, double y, double z){
    struct Vector3 *vector = malloc(sizeof(struct Vector3));
    Vector3_Set(vector, x, y, z);
    return vector;
}

// computes vector sum of two vectors
// input: two pointers to vector struct
// output: void
void Vector3_Add(struct Vector3 *v1, struct Vector3 *v2){
    v1->x += v2->x;
    v1->y += v2->y;
    v1->z += v2->z;
}

// computes the vector subtraction of two vectors
// input: two pointers to vector struct
// output: void
void Vector3_Subtract(struct Vector3 *v1, struct Vector3 *v2) {
    v1->x -= v2->x;
    v1->y -= v2->y;
    v1->z -= v2->z;
}

// scales the vector
// input: a pointer to a vector struct, a double factor
// output: void
void Vector3_Scale(struct Vector3 *v, double factor){
    v->x *= factor;
    v->y *= factor;
    v->z *= factor;
}

// changes the vector into a unit vector
// input: a pointer to a vector struct
// output: void
void Vector3_Normalize(struct Vector3 *v){
    v->x /= sqrt(Vector3_MagnitudeSq(v));
    v->y /= sqrt(Vector3_MagnitudeSq(v));
    v->z /= sqrt(Vector3_MagnitudeSq(v));
}

// returns the square of the magnitude of a vector
// input: a pointer to a vector
// output: the square of the magniture of the vector as a double 
double Vector3_MagnitudeSq(struct Vector3 *v){
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

// returns the magnitude of a vector
// input: a pointer to a vector
// output: the magniture of the vector as a double
double Vector3_Magnitude(struct Vector3 *v){
    return sqrt(Vector3_MagnitudeSq(v));
}


double Vector3_CrossProduct2D(struct Vector3 *v1, struct Vector3 *v2){
    return v1->x * v2->y - v2->x * v1->y;
}

// returns the square of the magnitude of a vector considering only the x and y components
// input: a pointer to a vector
// output: the square of the magniture of the vector as a double 
double Vector3_DistanceSq2D(struct Vector3 *v1, struct Vector3 *v2){
    return (v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y);
}

// returns the magnitude of a vector considering only the x and y components
// input: a pointer to a vector
// output: the magniture of the vector as a double
double Vector3_Distance2D(struct Vector3 *v1, struct Vector3 *v2){
    return sqrt(Vector3_DistanceSq2D(v1, v2));
}

// computes the cross product of two vectors and assigns it to a vector struct
// input: two pointers to vectors, a pointer to the resultant vector
// output: void
void Vector3_CrossProduct3D(struct Vector3 *v1, struct Vector3 *v2, struct Vector3 *result){
    result->x = v1->y * v2->z - v1->z * v2->y;
    result->y = -(v1->x * v2->z - v1->z * v2->x);
    result->z = v1->x * v2->y - v1->y * v2->x;
}

// computes the dot product of two vectors
// input: two pointers to vectors
// output: the dot product of the two vectors as a double
double Vector3_DotProduct3D(struct Vector3 *v1, struct Vector3 *v2){
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

// returns the squared distance of two vectors
// input: two pointers to vectors
// output: the square of the distance of two vectors vector as a double 
double Vector3_DistanceSq3D(struct Vector3 *v1, struct Vector3 *v2){
    return (v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y) + (v1->z - v2->z) * (v1->z - v2->z);
}

// returns the distance of two vectors
// input: two pointers to vectors
// output: the distance of two vectors vector as a double 
double Vector3_Distance3D(struct Vector3 *v1, struct Vector3 *v2){
    return sqrt(Vector3_DistanceSq3D(v1, v2));
}

// judges whether two vectors are equal
// input: two pointers to vectors
// output: an integer similar to a boolean variable representing whether the vectors are equal
int Vector3_Equal(struct Vector3 *v1, struct Vector3 *v2){
    return double_Equal(v1->x, v2->x)
           && double_Equal(v1->y, v2->y)
           && double_Equal(v1->z, v2->z);
}

// multiplies two vectors by components
// input: one vector pointer that is multiplied, another vector pointer used to multiply with the first one
// output: void
void Vector3_Multiply(struct Vector3 *v1, struct Vector3 *v2){
    v1->x *= v2->x;
    v1->y *= v2->y;
    v1->z *= v2->z;
}