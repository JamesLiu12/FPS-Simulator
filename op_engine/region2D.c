#include "region2D.h"
#include <stdlib.h>
void Region2D_Init(struct Region2D *region2d, double x, double z, double len, double wid, int num){
    region2d->x = x;
    region2d->z = z;
    region2d->length= len;
    region2d->width = wid;
    region2d->number = num;
}
struct Region2D* Region2D_New(double x, double z, double len, double wid, int num){
    struct Region2D *region2d = malloc(sizeof(struct Region2D));
    Region2D_Init(region2d, x, z, len, wid, num);
    return region2d;
}