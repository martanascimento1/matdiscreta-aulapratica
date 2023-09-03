#include <stdio.h>

int solucao(int x, int m, int m1) {
    if (x >= m) {
        return 0;
    } else {
        if (x >= 0) {
            
            printf("X é %d\n", x);
        }

        int y;
        y = x + m1;

        solucao(y, m, m1);
    }
}

int inverso(int a, int m, int a1, int m1, int x, int y, int s, int t, int c) {
    if (s * a + t * m == c) {
        return s;
    } else {
        int sn, tn;

        sn = x - (a1 / m1) * s;
        tn = y - (a1 / m1) * t;

        inverso(a, m, m1, a1 % m1, s, t, sn, tn, c);
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
    int a, b, m;

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    printf("m: ");
    scanf("%d", &m);

    int s, t;
    s = 1;
    t = -a / m;

    int c;

    if (a >= m) {
        c = mdc(a, m);
    } else {
        c = mdc(m, a);
    }

    int x;

    if (c == 1) {
        x = b * inverso(a, m, m, a % m, 0, 1, s, t, c);

        if (x >= m || x < 0) {
            x = x % m;
        }

        printf("x == %d\n", x);
    } else {
        if (b % c == 0) {
            int a1, b1, m1;
            a1 = a / c;
            b1 = b / c;
            m1 = m / c;

            x = b1 * inverso(a1, m1, m1, a1 % m1, 0, 1, s, t, 1);

            if (x >= m1) {
                x = x % m1;
            }

            solucao(x, m, m1);
        } else {
            printf("essa congruência não tem solução\n");
        }
    }

    return 0;
}