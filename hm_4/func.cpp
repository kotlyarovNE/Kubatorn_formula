#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int factorial(int n){
    if(n == 0)
        return 1;
    else
        return(factorial(n-1) * n);
}

double f(int a_1, int a_2, int a_3){
    double rez;
    rez = (double)(factorial(a_1) * factorial(a_2) * factorial(a_3)) / (double)factorial(a_1 + a_2 + a_3 + 2);

    return rez;
}


double C_3(int a_1, int a_2, int a_3){
    double rez;
    rez = (double)factorial(a_1 + a_2 + a_3) / (double)(factorial(a_1) * factorial(a_2) * factorial(a_3));

    return rez;
}



double det(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y){
    double rez = 0.0;
    rez = A_x*(B_y - C_y) - B_x*(A_y - C_y) + C_x * (A_y - B_y);

return rez;
}


double S(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y){
    return fabs(0.5*((A_x-C_x)*(B_y-C_y)-(B_x-C_x)*(A_y-C_y)));
}



double bar_form(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y, int r, int s){
    double rez = 0.0;
    int k_1, k_2, k_3;
    int l_1, l_2, l_3;

    for(int i_1 = 0; i_1 <= r; ++i_1){
        for(int i_2 = 0; i_2 <= r - i_1; ++i_2){
            for(int j_1 = 0; j_1 <= s; ++j_1){
                for(int j_2 = 0; j_2 <= s - j_1; ++j_2){
                    k_1 = i_1;
                    k_2 = i_2;
                    k_3 = r - (i_1 + i_2);
                    l_1 = j_1;
                    l_2 = j_2;
                    l_3 = s - (j_1 + j_2);

                    rez += f(k_1 + l_1, k_2 + l_2, k_3 + l_3) * (pow(A_x, k_1)*pow(B_x, k_2)*pow(C_x, k_3)) * (pow(A_y, l_1)*pow(B_y, l_2)*pow(C_y, l_3)) * C_3(k_1, k_2, k_3) * C_3(l_1, l_2, l_3);
                }
            }
        }
    }

    return(rez * fabs(det(A_x, A_y, B_x, B_y, C_x, C_y)));
}


double KUB(double A_x, double A_y, double B_x, double B_y, double C_x, double C_y, int r, int s, double *w, double ny[][3], int kr_sum){
    double rez = 0.0;
    double x, y;
    double PX, PY;

    for(int i = 0; i < kr_sum; ++i){
        x = A_x * ny[i][0] + B_x * ny[i][1] + C_x * ny[i][2];
        y = A_y * ny[i][0] + B_y * ny[i][1] + C_y * ny[i][2];
        PX = pow(x, r);
        PY = pow(y, s);
        rez += PX * PY * w[i];
    }

return (rez * S(A_x, A_y, B_x, B_y, C_x, C_y) );
}



double DELTA(double XI[][3][5], double YI[][3][5], double *w, double ny[][3], int kr_sum){
    int l = 4;
    double rez_kub = 0.0, rez_bar;
    double rez;

    for(int k = 0; k < pow(4, l); ++k){
        rez_kub += KUB(XI[k][0][l], YI[k][0][l], XI[k][1][l], YI[k][1][l], XI[k][2][l], YI[k][2][l], 2, 2, w, ny, kr_sum);
    }

    rez_bar = bar_form(XI[0][0][0], YI[0][0][0], XI[0][1][0], YI[0][1][0], XI[0][2][0], YI[0][2][0], 2, 2);

    rez = fabs(rez_kub - rez_bar) / rez_bar;

return rez;
}
