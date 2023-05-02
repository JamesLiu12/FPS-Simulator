#ifndef OP_REGION2D

//Left hand(x right, y upward, z forward)
struct Region2D {
    double x,z;
    double length,width;
    int number;
};
void Region2D_Init(struct Region2D *region2d, double x, double z, double len, double wid, int num);
struct Region2D* Region2D_New(double x, double z, double len, double wid, int num);
#define OP_REGION2D
#endif