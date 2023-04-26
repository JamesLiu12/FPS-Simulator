#include <stddef.h>
typedef int bool;
void swap(void *a, void *b, size_t size);
double linear_interpolate(double from, double to, double proportion);
int double_Equal(double a, double b);
int double_IsZero(double a);
bool double_IsSameSign(double a, double b);
double ProgramRunTime();

/*
 * Guassian_Elimination would give the solution of a group of functions, given the
 * number_row: the number of functions
 * number_col: the number of unknown number plus one
 */
void Gaussian_Elimination(double **a, int number_row, int number_col);

//move the cursor to the position (row, col)
void move_cursor_to(int row, int col);

//Get the current position of the cursor
void get_cursor_position(int *row, int *col);

#define TRUE 1
#define FALSE 0
#define EPSILON 1e-6
#define DEPTH_LIMIT 0.05
#define DEBUG 0