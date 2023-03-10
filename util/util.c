#include <stdlib.h>
#include <memory.h>
#include <math.h>
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

int double_equal(double a, double b){
    return (a > b ? a - b : b - a) <= EPSILON;
}

int double_IsZero(double a){
    return fabs(a) < EPSILON;
}

void Gaussian_Elimination(double **a, int number_row, int number_col){
    for (register int i = 0, j = 0; i < number_row && j < number_col;){

        for (register int k = i; k < number_row; k++){
            if (!double_IsZero(a[k][j])){
                for (register int l = j; l < number_col; l++){
                    swap(&a[k][l], &a[i][l], sizeof(double));
                }
                break;
            }
        }

        if (double_IsZero(a[i][j])){
            j++;
            continue;
        }

        double tmp = a[i][j];
        for (register int l = j; l < number_col; l++) a[i][l] /= tmp;

        for (register int k = 0; k < number_row; k++) {
            if (k != i && !double_IsZero(a[k][j])){
                tmp = a[k][j];
                for (register int l = j; l < number_col; l++){
                    a[k][l] -= a[i][l] * tmp;
                }
            }
        }

        i++;
        j++;
    }
}