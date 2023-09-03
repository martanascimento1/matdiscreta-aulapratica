#include <stdio.h>

int inverso(int a, int b, int a1, int b1, int x, int y, int s, int t, int c) {
    if (s * a + t * b == c) {
        printf("O inverso de %d mod %d é %d\n", a, b, s);
        return 0;
    } else {
        int nS, nT;
        nS = x - (a1 / b1) * s;
        nT = y - (a1 / b1) * t;
        inverso(a, b, b1, a1 % b1, s, t, nS, nT, c);
    }
}

int mdc(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return mdc(b, a % b);
    }
}

int main() {
    int a, b, c;
    int s, t;

    printf("insira o valor de a: ");
    scanf("%d", &a);

    printf("insira o valor de b: ");
    scanf("%d", &b);

    s = 1;
    t = -a / b;

    if (a >= b) {
        c = mdc(a, b);
    } else {
        c = mdc(b, a);
    }

    if (c == 1) {
        inverso(a, b, b, a % b, 0, 1, s, t, c);
    } else {
        printf("O inverso de %d mod %d não existe!\n", a, b);
    }

    return 0;
}