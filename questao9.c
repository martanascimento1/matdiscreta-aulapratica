#include <stdio.h>

int encontrarSolucao(int valorX, int valorM)
{
    if (valorX >= 0 && valorX < valorM)
    {
        return valorX;
    }
    else if (valorX < 0)
    {
        valorX = valorX + valorM;

        encontrarSolucao(valorX, valorM);
    }
    else
    {
        valorX = valorX - valorM;

        encontrarSolucao(valorX, valorM);
    }
}

int calcularCoeficientes(int a, int m, int a1, int m1, int valX, int valY, int valS, int valT, int valC)
{
    if (valS * a + valT * m == valC)
    {
        return valS;
    }
    else
    {
        int novoS, novoT;

        novoS = valX - (a1 / m1) * valS;
        novoT = valY - (a1 / m1) * valT;

        calcularCoeficientes(a, m, m1, a1 % m1, valS, valT, novoS, novoT, valC);
    }
}

int calcularMDC(int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return num2;
    }
    else
    {
        calcularMDC(num2, num1 % num2);
    }
}

int main()
{
    int valorR1, valorM1;

    printf("Primeira Congruência:\n");

    printf("Digite o valor de b: ");
    scanf("%d", &valorR1);

    printf("Digite o valor de m: ");
    scanf("%d", &valorM1);

    int valorR2, valorM2;

    printf("Segunda Congruência:\n");

    printf("Digite o valor de r: ");
    scanf("%d", &valorR2);

    printf("Digite o valor de m: ");
    scanf("%d", &valorM2);

    int valorR3, valorM3;

    printf("Terceira Congruência:\n");

    printf("Digite o valor de r: ");
    scanf("%d", &valorR3);

    printf("Digite o valor de m: ");
    scanf("%d", &valorM3);

    int valorM1Novo, valorM2Novo, valorM3Novo;

    valorM1Novo = valorM2 * valorM3;
    valorM2Novo = valorM1 * valorM3;
    valorM3Novo = valorM1 * valorM2;

    int valorC1, valorC2, valorC3;

    if (valorM1Novo >= valorM1)
    {
        valorC1 = calcularMDC(valorM1Novo, valorM1);
    }
    else
    {
        valorC1 = calcularMDC(valorM1, valorM1Novo);
    }

    if (valorC1 != 1)
    {
        printf("O sistema não possui solução!\n");
    }
    else
    {
        if (valorM2Novo >= valorM2)
        {
            valorC2 = calcularMDC(valorM2Novo, valorM2);
        }
        else
        {
            valorC2 = calcularMDC(valorM2, valorM2Novo);
        }

        if (valorC2 != 1)
        {
            printf("O sistema não possui solução!\n");
        }
        else
        {
            valorC3 = 1;

            int valorS1, valorT1;

            valorS1 = 1;
            valorT1 = -valorM1Novo / valorM1;

            int valorX1;
            valorX1 = valorR1 * valorM1Novo * calcularCoeficientes(valorM1Novo, valorM1, valorM1, valorM1Novo % valorM1, 0, 1, valorS1, valorT1, valorC1);

            int valorS2 = 1;
           int valorT2 = -valorM2Novo / valorM2;

            int valorX2 = valorR2 * valorM2Novo * calcularCoeficientes(valorM2Novo, valorM2, valorM2, valorM2Novo % valorM2, 0, 1, valorS2, valorT2, valorC2);


            int valorS3 = 1;
            int valorT3 = -valorM3Novo / valorM3;

            int valorX3;
            valorX3 = valorR3 * valorM3Novo * calcularCoeficientes(valorM3Novo, valorM3, valorM3, valorM3Novo % valorM3);
            
            return 0;
            } }
}