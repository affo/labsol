/*
 * Scrivere un programma che acquisisca una sequenza di 10 numeri
 * interi ed un indice X tra 0 e 9. Il programma dovrà stampare la somma
 * dei numeri in posizioni minori di X e il prodotto dei numeri in posizioni
 * successive a X.
 */

#include <stdio.h>
#define N 10

int main(void) {
    int a[N], index, i, res;

    for (i = 0; i < N; i++) {
        printf("Numero [%d/%d]:\n", i, N - 1);
        scanf("%d%*c", a + i);
    }

    do {
        printf("Indice (tra 0 e %d):\n", N - 1);
        scanf("%d%*c", &index);
    } while (index < 0 || index >= N);

    for (i = 0, res = 0; i < index; i++) {
        res += a[i];
    }
    printf("Somma = %d\n", res);

    for (i = N - 1, res = 1; i > index; i--) {
        res *= a[i];
    }
    printf("Prodotto = %d\n", res);

    return 0;
}
