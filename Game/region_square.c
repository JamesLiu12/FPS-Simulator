#include "region_square.h"
#include <stdlib.h>

void RegionSquare_Init(struct RegionSquare *region2d, double x, double z, double len, double wid, int num){
    region2d->x = x;
    region2d->z = z;
    region2d->length= len;
    region2d->width = wid;
    region2d->number = num;
}

struct RegionSquare* New_RegionSquare(double x, double z, double len, double wid, int num){
    struct RegionSquare *region2d = malloc(sizeof(struct RegionSquare));
    RegionSquare_Init(region2d, x, z, len, wid, num);
    return region2d;
}