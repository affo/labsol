/*
 * Scrivere un programma che costruisce un array A di 50 interi e un B di 5
 * interi e stampa 1 se esiste in A una sequenza di 5 elementi che sono
 * esattamente gli elementi di B anche in un ordine differente.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NA 50
#define NB 5
#define LIMIT 5

int main (void) {
    int a[NA], b[NB], temp[NB], i, j, found, no_found;

    srand(time(NULL));
    // gen a and b
    for (i = 0; i < NA; i++) {
        a[i] = rand() % LIMIT;
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < NB; i++) {
        b[i] = rand() % LIMIT;
        temp[i] = b[i];
        printf("%d ", b[i]);
    }
    printf("\n");

    for (i = 0, found = 0, no_found = 0; i < NA && !found; i++) {
        for (j = 0; j < NB && !found; j++) {
            if (a[i] == b[j]) {
                no_found++;
                b[j] = -1; // do not refind it
                found = 1;
            }
        }

        if (!found) {
            // no match found
            i -= no_found;
            no_found = 0;
            // recover b
            for (j = 0; j < NB; j++) {
                b[j] = temp[j];
            }
        }

        if (no_found == NB) {
            found = i;
        } else {
            found = 0;
        }
    }

    if (found) {
        for (i = 0; i < found + 1 - NB; i++){
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
