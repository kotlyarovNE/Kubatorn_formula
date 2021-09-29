#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "all_functions.h"

int IN_mass_kub_and_point(point *A,  point *B,  point *C, double *w, double ny[][3], int kr_sum){

    //POINT
    A->x = 0.0;
    A->y = 0.5;

    B->x = 2.0;
    B->y = 0.5;

    C->x = 0.0;
    C->y = 1.5;


    //////////////////////////////////

    //Заполнения массивов w, m и первой строчки ню

    for (int i = 0; i < 3; ++i){
        if(i==0)
            w[i] = -0.562500000000000;

        ny[0][i] = 0.333333333333333;
        w[i+1] = 0.520833333333333;
        }
    //Дозаполнение массива ню

    for(int i = 1; i < kr_sum; ++i){
        ny[i][i-1] = 0.6;
        for (int j = 0; j < 3; ++j){
            if(j!=i-1)
                ny[i][j] = 0.2;
        }
    }
return 0;
}


void INPUT_proverka(double *w, double ny[][3]){

    //Вывод матриц всех
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; ++j){
            printf("%lf ", ny[i][j]);
        }
        printf("\n");
    }

    for( int i = 0; i <4; ++i){
        printf("%lf ", w[i]);
    }
    printf("\n");

}

void points_in_mass(double XI[][3][5], double YI[][3][5], double A_x, double A_y, double B_x, double B_y, double C_x, double C_y){

    XI[0][0][0] = A_x;
    XI[0][1][0] = B_x;
    XI[0][2][0] = C_x;

    YI[0][0][0] = A_y;
    YI[0][1][0] = B_y;
    YI[0][2][0] = C_y;

    for( int l = 1; l < 5; ++l){
        for(int k = 0; k < pow(4, l-1); ++k){
            add(XI, l, k);
            add(YI, l, k);
        }
    }

}

void add(double XI[][3][5], int l, int k){
    //4 треугольника вписывает
    double x_1, x_2, x_3, x_4, x_5, x_6;
    x_1 = XI[k][0][l-1];
    x_2 = XI[k][1][l-1];
    x_3 = XI[k][2][l-1];
    x_4 = (XI[k][0][l-1] + XI[k][1][l-1])/2;
    x_5 = (XI[k][1][l-1] + XI[k][2][l-1])/2;
    x_6 = (XI[k][0][l-1] + XI[k][2][l-1])/2;

    XI[4*k][0][l] = x_1;
    XI[4*k][1][l] = x_4;
    XI[4*k][2][l] = x_6;

    XI[4*k + 1][0][l] = x_4;
    XI[4*k + 1][1][l] = x_5;
    XI[4*k + 1][2][l] = x_6;

    XI[4*k + 2][0][l] = x_4;
    XI[4*k + 2][1][l] = x_2;
    XI[4*k + 2][2][l] = x_5;

    XI[4*k + 3][0][l] = x_6;
    XI[4*k + 3][1][l] = x_5;
    XI[4*k + 3][2][l] = x_3;

}


















