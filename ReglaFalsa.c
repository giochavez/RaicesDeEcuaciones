#include <stdio.h>
#include <stdlib.h>
#include "utileria.h"
#include "biseccion.h"

int FalsaMenu(){
    double a, b, tol;
    printf ("Intervalo a: ");
    scanf ("%lf",&a);
    printf("Intervalo b: ");
    scanf("%lf", &b);
    if (f(a)*f(b)<=0){
            printf ("Tolerancia: ");
            scanf ("%lf",&tol);
            biseccion(a,b,tol);
    }
    else{
            printf("No converge\n");
    }
    return 0;
}

double falsa (double a, double b, double tol) {
    double c, er;
    int i = 0;

    do {
        c =  b-(f(b)*(b-a))/(f(b)-f(a));
        if (f(a)*f(c) < 0)  b = c;
        else                a = c;
        er = fabs (a - b);
        i++;
    } while (er > tol && f(c) != 0);
    printf ("MB La raiz aprox. = %lf, #iteraciones %d\n",c,i);

    return c;
}
