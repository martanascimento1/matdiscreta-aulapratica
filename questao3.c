#include <stdio.h>

void decompor(int n) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n = (n/i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printf("Fatores primos de %d: ", n);
    decompor(n);

    return 0;
}
