#include <stdlib.h>
#include <memory.h>

void int_swap(int *a, int *b){
    int *tmp = a;
    a = b;
    b = tmp;
}

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

