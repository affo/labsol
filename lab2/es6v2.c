/*
 * Scrivere un programma che costruisce un array A di 50 interi e un B di 5
 * interi e stampa 1 se esiste in A una sequenza di 5 elementi che sono
 * esattamente gli elementi di B nello stesso ordine.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NA 50
#define NB 3
#define LIMIT 3

int main (void) {
    int a[NA], b[NB], i, j, found;

    srand(time(NULL));
    // gen a and b
    for (i = 0; i < NA; i++) {
        a[i] = rand() % LIMIT;
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < NB; i++) {
        b[i] = rand() % LIMIT;
        printf("%d ", b[i]);
    }
    printf("\n");

    for (i = 0, j = 0, found = 0; i < NA && !found; i++) {
        if (a[i] == b[j]) {
            found = i;
            for (j = 1; j < NB && found; j++) {
                if (i + j >= NA || a[i + j] != b[j]) {
                    found = 0;
                }
            }
            j = 0;
        }
    }

    if (found) {
        for (i = 0; i < found; i++){
            printf("  ");
        }
        printf("|_");
        for (i = 0; i < NB - 2; i++){
            printf("__");
        }
        printf("|");
        printf("\n");
    } else {
        printf("NOT FOUND\n");
    }

    return 0;
}
