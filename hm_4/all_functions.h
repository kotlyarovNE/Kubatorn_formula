#include <stdio.h>
#include<math.h>
#include <stdlib.h>


typedef struct{
    double x;
    double y;
} point;


int IN_mass_kub_and_point(point *A,  point *B,  point *C, double *w, double ny[][3], int kr_sum);

void INPUT_proverka(double *w, double ny[][3]);

void points_in_mass(double XI[][3][5], double YI[][3][5], double A_x, double A_y, double B_x, double B_y, double C_x, double C_y);

void add(double XI[][3][5], int l, int k);

double DELTA(double XI[][3][5], double YI[][3][5], double *w, double ny[][3], int kr_sum);


double bar_form(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y, int r, int s);

double KUB(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y, int r, int s, double *w, double ny[][3], int kr_sum);


