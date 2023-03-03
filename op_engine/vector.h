struct Vector3 {
    double x = 0, y = 0, z = 0;
};

/*
Basic operations for Vector3
*/

void vector3_add(struct Vector3 *v1, struct Vector3 *v2);
void vector3_subtract(struct Vector3 *v1, struct Vector3 *v2);
void vector3_scale(struct Vector3 *v, double factor);

