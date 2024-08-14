#include <stdio.h>
#include <TXLib.h>

double power(double n, int p);


int main(void) {
    double x, xpow;
    int exp;

    printf("\tВозводит числа в целые степени!\n");
    printf("Введите число и целую степень в которую хотите возвести число, для завершения нажмите q.\n");
    while(scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g в степени %d равно %.5g\n", x, exp, xpow);
        printf("Введите следующую пару чисел.");
    }
    printf("Ready");


    return 0;
}
    double power(double n, int p){
        double pow = 1;
        int i;
        for (i = 1; i <= p; i++)
            pow *= n;
        return pow;

    }
