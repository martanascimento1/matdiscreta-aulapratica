#include <stdio.h>

int congruencia(int valorX, int valorM)
{
    if (valorX >= 0 && valorX < valorM)
    {
        return valorX;
    }
    else if (valorX < 0)
    {
        valorX = valorX + valorM;

       congruencia(valorX, valorM);
    }
    else
    {
        valorX = valorX - valorM;

       congruencia(valorX, valorM);
    }
}

int calcular(int a, int m, int a1, int m1, int x, int y, int s, int t, int c)
{
    if (s * a + t * m == c)
    {
        return s;
    }
    else
    {

       int s2 = x - (a1 / m1) * s;
       int t2 = y - (a1 / m1) * t;

        calcular(a, m, m1, a1 % m1, s, t, s2, t2, c);
    }
}

int mdc(int n1, int n2)
{
    if (n1 % n2 == 0)
    {
        return n2;
    }
    else
    {
        mdc(n2, n1 % n2);
    }
}

     int solucao (int m, int n, int r, int m1)
{
      if (m > n)
       {
        return r;
       }
      else
      {
        int r2, m2;

        printf("Congruência %d:\n", m);

        printf("Digite o valor de r: ");
        scanf("%d", &r2);

        printf("Digite o valor de m: ");
        scanf("%d", &m2);

        int valorC;
        valorC = mdc(m1, m2);

        if (valorC != 1)
        {
            printf("O sistema não possui solução!\n");
        }
        else
        {
            int valorS1, valorT1;

            valorS1 = 1;
            valorT1 = -m2 / m1;

            int valorX1;
            valorX1 = r * m2 * calcular(m2, m1, m1, m2 % m1, 0, 1, valorS1, valorT1, valorC);

            int valorS2, valorT2;

            valorS2 = 1;
            valorT2 = -m1 / m2;

            int valorX2;
            valorX2 = r2 * m1 * calcular(m1, m2, m2, m1 % m2, 0, 1, valorS2, valorT2, valorC);

            int valorX;
            valorX = valorX1 + valorX2;
            valorX = congruencia(valorX, m1 * m2);

         solucao(m + 1, n, valorX, m1 * m2);
        }
    }
}

int main ()
{
    int n;

    printf("Digite o numero de congruências do sistema: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("congruencias insuficientes \n");
    }
    else
    {
        int r, m;

        printf("Congruência 1: \n");

        printf("Digite o valor de b: ");
        scanf("%d", &r);

        printf("Digite o valor de m: ");
        scanf("%d", &m);

        int x = solucao(2, n, r, m);

        printf("A solução do sistema é %d\n", x);
    }
}