#ifndef REGION_SQUARE

//a square region for spawning enemy
struct RegionSquare {
    double x,z;
    double length,width;
    int number;
};

//Initializer of RegionSquare
void RegionSquare_Init(struct RegionSquare *region2d, double x, double z, double len, double wid, int num);

//Newer of RegionSquare
struct RegionSquare* New_RegionSquare(double x, double z, double len, double wid, int num);
#define REGION_SQUARE
#endif