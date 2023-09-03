#include <stdio.h>

int encontrarSolucao(int x, int m) {
    if (x >= 0 && x < m) {
        return x;
    } else if (x < 0) {
        x = x + m;
        encontrarSolucao(x, m);
    } else {
        x = x - m;
        encontrarSolucao(x, m);
    }
}

int calcularCoeficientes(int a, int m, int a1, int m1, int x, int y, int s, int t, int c) {
    if (s * a + t * m == c) {
        return s;
    } else {
        int sn, tn;
        sn = x - (a1 / m1) * s;
        tn = y - (a1 / m1) * t;
        calcularCoeficientes(a, m, m1, a1 % m1, s, t, sn, tn, c);
    }
}

int calcularMDC(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        calcularMDC(b, a % b);
    }
}

int main() {
    int r1, m1;

    printf("Primeira Congruência:\n");

    printf("Digite o valor de r: ");
    scanf("%d", &r1);

    printf("Digite o valor de m: ");
    scanf("%d", &m1);

    int r2, m2;

    printf("Segunda Congruência:\n");

    printf("Digite o valor de r: ");
    scanf("%d", &r2);

    printf("Digite o valor de m: ");
    scanf("%d", &m2);

    int r3, m3;

    printf("Terceira Congruência:\n");

    printf("Digite o valor de r: ");
    scanf("%d", &r3);

    printf("Digite o valor de m: ");
    scanf("%d", &m3);

    int M1, M2, M3;

    M1 = m2 * m3;
    M2 = m1 * m3;
    M3 = m1 * m2;

    int c1, c2, c3;

    if (M1 >= m1) {
        c1 = calcularMDC(M1, m1);
    } else {
        c1 = calcularMDC(m1, M1);
    }

    if (c1 != 1) {
        printf("O sistema não possui solução!\n");
    } else {
        if (M2 >= m2) {
            c2 = calcularMDC(M2, m2);
        } else {
            c2 = calcularMDC(m2, M2);
        }

        if (c2 != 1) {
            printf("O sistema não possui solução!\n");
        } else {
            c3 = 1;

            int s1, t1;

            s1 = 1;
            t1 = -M1 / m1;

            int x1;
            x1 = r1 * M1 * calcularCoeficientes(M1, m1, m1, M1 % m1, 0, 1, s1, t1, c1);

            int s2, t2;

            s2 = 1;
            t2 = -M2 / m2;

            int x2;
            x2 = r2 * M2 * calcularCoeficientes(M2, m2, m2, M2 % m2, 0, 1, s2, t2, c2);

            int s3, t3;

            s3 = 1;
            t3 = -M3 / m3;

            int x3;
            x3 = r3 * M3 * calcularCoeficientes(M3, m3, m3, M3 % m3, 0, 1, s3, t3, c3);

            int x;
            x = x1 + x2 + x3;

            x = encontrarSolucao(x, m1 * m2 * m3);

            printf("A solução do sistema é %d\n", x);
        }
     }

    return 0;
}