#include <stddef.h>
typedef int bool;

void swap(void *a, void *b, size_t size);
double linear_interpolate(double from, double to, double proportion);
int double_Equal(double a, double b);
int double_IsZero(double a);
bool double_IsSameSign(double a, double b);

/*
 * Guassian_Elimination would give the solution of a group of functions, given the
 * number_row: the number of functions
 * number_col: the number of unknown number plus one
 */
void Gaussian_Elimination(double **a, int number_row, int number_col);
#define TRUE 1
#define FALSE 0
#define EPSILON 1e-6
#define DEPTH_LIMIT 0.05
