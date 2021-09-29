#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "all_functions.h"

//Запуск программы - ./a.out r, s
//Входные данные: r,s
//r,s- это степени многочлена, т.е. x^r*y^s

int main(int argc,char *argv[]){

    int r, s;
    double I_rs_bar = 0.0, I_kub = 0.0;
    point A, B, C;

    double *w;       // Точки w_i
    double ny[4][3]; // Узлы
    int kr_sum = 4;  //Сумма всех кратностей

    r = atoi(argv[1]);
    s = atoi(argv[2]);

    if ( argc != 3 )  {
        printf("incorrect data entered\n");
        return -1;}

    w = (double*)malloc(4 * sizeof(double));


    //Всё заполняем:
    IN_mass_kub_and_point(&A, &B, &C, w, ny, kr_sum);

    //Барицентрические - точная формула
    I_rs_bar = bar_form(A.x, A.y, B.x, B.y, C.x, C.y, r, s);
    printf("formula_baricenr = %.03e \n",I_rs_bar);
    //Кубаторная формула:
    I_kub = KUB(A.x, A.y, B.x, B.y, C.x, C.y, r, s, w, ny, kr_sum);
    printf("formula_KUB = %.03e \n",I_kub);

    double POGR = fabs(I_rs_bar - I_kub) / I_rs_bar;
    printf("POGR = %.03e \n",POGR);



    double XI[256][3][5], YI[256][3][5];
    points_in_mass(XI, YI, A.x, A.y, B.x, B.y, C.x, C.y);

    //r + s = 4, возьмём r = 2, s = 2
    double delta_l;
    delta_l = DELTA(XI, YI, w, ny, kr_sum);
    printf("DELTA = %.03e \n", delta_l);


    return 0;
}

