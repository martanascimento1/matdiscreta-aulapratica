#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int main() {
    int a, b;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d%d", &a, &b);

    printf("O MDC de %d e %d eh %d\n", a, b, mdc(a, b));
    printf("O MMC de %d e %d eh %d\n", a, b, mmc(a, b));

    return 0;
}