#include <stdio.h>

int calcularValores(int x, int y, int m, int n, int p, int q, int r, int s, int t)
{
    if (p * x + q * y == t)
    {
        printf("O valor r é %d\n", p);
        printf("O valor s é %d\n", q);

        return 0;
    }
    else
    {
        int rn, sn;

        rn = m - (n / p) * r;
        sn = y - (n / p) * s;

        calcularValores(x, y, n, m % n, p, q, rn, sn, t);
    }
}

int calcularMDC(int x, int y)
{
    if (x % y == 0)
    {
        return y;
    }
    else
    {
        calcularMDC(y, x % y);
    }
}

int main()
{
    int x, y, t;
    int r, s;

    printf("mdc (x, y) = r*x + s*y\n");

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    r = 1;
    s = -x / y;

    if (x >= y)
    {
        t = calcularMDC(x, y);
    }
    else
    {
       // t =
    }
}