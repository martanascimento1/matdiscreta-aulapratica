#include <stdio.h>

void fatores_primos(int n) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n = (n/i);
        }
    }
}

int main() {
    int n;

    printf("Digite um numero inteiro:\n");
    scanf("%d", &n);

    printf("Os fatores primos de %d são: ", n);
    fatores_primos(n);

    return 0;
}
