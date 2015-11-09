/*
 * Scrivere un programma che acquisisca due sequenze A e B di 5 numeri
 * interi ciascuna, e stampi a video la sequenza “interlacciata” tra A e
 * l'inversa di B: il primo elemento di A, l'ultimo elemento di B, il secondo
 * elemento di A, il penultimo di B etc. Esempio di esecuzione:
 * Dammi i 5 valori di A: > 1 2 3 4 5
 * Dammi i 5 valori di B: > 6 7 8 9 10
 * Uscita: 1 10 2 9 3 8 4 7 5 6
 */

#include <stdio.h>
#define N 5

int main(void) {
    int a[N], b[N], i;
    char c;

    printf("Dammi i %d valori di A: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d%c", &a[i], &c);
    }
    while (c != '\n' && c != EOF) c = getchar(); // discarding chars until EOL

    printf("Dammi i %d valori di B: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d%c", &b[i], &c);
    }
    while (c != '\n' && c != EOF) c = getchar(); // discarding chars until EOL

    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%d %d ", a[i], b[N - i -1]);
    }

    printf("\n");

    return 0;
}
