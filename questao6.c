#include <stdio.h>

int combinacao(int a, int b, int a1, int b1, int x, int y, int s, int t, int c) {
    if (s * a + t * b == c) {
        printf("O coeficiente s é %d\n", s);
        printf("O coeficiente t é %d\n", t);

        return 0;
    } else {
        int sn, tn;

        sn = x - (a1 / b1) * s;
        tn = y - (a1 / b1) * t;

        combinacao(a, b, b1, a1 % b1, s, t, sn, tn, c);
    }
}

int mdc(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        mdc(b, a % b);
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

    combinacao(a, b, b, a % b, 0, 1, s, t, c);

    return 0;
}