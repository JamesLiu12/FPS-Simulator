#ifndef OP_VECTOR

//Left hand(x right, y upward, z forward)
struct Vector3 {
    double x, y, z;
};

/*
Basic operations for Vector3
*/

void vector3_add(struct Vector3 *v1, struct Vector3 *v2);
void vector3_subtract(struct Vector3 *v1, struct Vector3 *v2);
void vector3_scale(struct Vector3 *v, double factor);

#define OP_VECTOR
#endif
