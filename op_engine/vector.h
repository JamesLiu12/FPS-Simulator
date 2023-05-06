#ifndef OP_VECTOR

/*
    Defines the data and basic operations on a 3D vector
*/

//Left hand(x right, y upward, z forward)
struct Vector3 {
    double x, y, z;
};

/*
Basic operations for Vector3
*/

// assigns values to a 3D vector
// input: a pointer to a vector struct, three doubles, x, y, z representing the components of the vector
// output: void
void Vector3_Set(struct Vector3 *v, double x, double y, double z);

//Copy the value in "from" to "to"
// input: a pointer to the vector being copied from, a pointer to the vector being copied to
// output: void
void Vector3_Copy(struct Vector3 *from, struct Vector3 *to);

// creates a new 3D vector
// input: 3 doubles, x, y, z, representing the components of the vecotr
// output: a pointer to a vector struct
struct Vector3* Vector3_New(double x, double y, double z);

//The basic operations for Vector3

// computes vector sum of two vectors
// input: two pointers to vector struct
// output: void
void Vector3_Add(struct Vector3 *v1, struct Vector3 *v2);

// computes the vector subtraction of two vectors
// input: two pointers to vector struct
// output: void
void Vector3_Subtract(struct Vector3 *v1, struct Vector3 *v2);

// scales the vector
// input: a pointer to a vector struct, a double factor
// output: void
void Vector3_Scale(struct Vector3 *v, double factor);

// changes the vector into a unit vector
// input: a pointer to a vector struct
// output: void
void Vector3_Normalize(struct Vector3 *v);

//Return the square of module length of v
// input: a pointer to a vector
// output: the square of the magniture of the vector as a double 
double Vector3_MagnitudeSq(struct Vector3 *v);

//Return the module length of v
// input: a pointer to a vector
// output: the magniture of the vector as a double
double Vector3_Magnitude(struct Vector3 *v);

//Return the square of distance between v1 and v2
// input: two pointers to vectors
// output: the square of the distance of two vectors vector as a double 
double Vector3_DistanceSq3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the distance between v1 and v2
// input: two pointers to vectors
// output: the distance of two vectors vector as a double 
double Vector3_Distance3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the result of cross product of v1 and v2, only considering the x and y
double Vector3_CrossProduct2D(struct Vector3 *v1, struct Vector3 *v2);

//Cross product of v1 and v2
void Vector3_CrossProduct3D(struct Vector3 *v1, struct Vector3 *v2, struct Vector3 *result);

//Return the result of dot product of v1 and v2
// input: two pointers to vectors
// output: the dot product of the two vectors as a double
double Vector3_DotProduct3D(struct Vector3 *v1, struct Vector3 *v2);

//Return the result of dot product of v1 and v2, only considering the x and y
// input: two pointers to a vector
// output: the square of the magniture of the vector as a double 
double Vector3_DistanceSq2D(struct Vector3 *v1, struct Vector3 *v2);

//Return the distance between v1 and v2, only considering the x and y
// input: two pointers to a vector
// output: the magniture of the vector as a double
double Vector3_Distance2D(struct Vector3 *v1, struct Vector3 *v2);

//Return True <=> the value of v1 equal to that of v2
// input: two pointers to vectors
// output: an integer similar to a boolean variable representing whether the vectors are equal
int Vector3_Equal(struct Vector3 *v1, struct Vector3 *v2);

//Multiply the value of each x, y, z
// input: one vector pointer that is multiplied, another vector pointer used to multiply with the first one
// output: void
void Vector3_Multiply(struct Vector3 *v1, struct Vector3 *v2);

#define OP_VECTOR
#endif