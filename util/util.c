#include <stdlib.h>
#include <memory.h>
#include "util.h"

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

double linear_interpolate(double from, double to, double proportion) {
    return from + proportion * (to - from);
}

double double_equal(double a, double b){
    return (a > b ? a - b : b - a) <= epsilon;
}