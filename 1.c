#include <stdio.h>
#include <TXLib.h>

double power(double n, int p);


int main(void) {
    double x, xpow;
    int exp;

    printf("\t�������� ����� � ����� �������!\n");
    printf("������� ����� � ����� ������� � ������� ������ �������� �����, ��� ���������� ������� q.\n");
    while(scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g � ������� %d ����� %.5g\n", x, exp, xpow);
        printf("������� ��������� ���� �����.");
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
