/*
 * Scrivere un programma che riceva in ingresso dall'utente una matrice
 * quadrata 5x5 contenente solo caratteri. Il programma dica all'utente se
 * la parola che si trova sulla diagonale principale può essere ritrovata in
 * un qualsiasi altro punto della matrice (in una riga o in una colonna).
 * Venga indicato a video anche la posizione della parola.
 */

#include <stdio.h>
#include <string.h>
#define N 5

int main (void) {
    int i, j, k, found;
    char diag[N + 1], cfr[N + 1];

    /*
    char m[N][N];
    // acquisizione
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento in posizione (%d, %d): ", i, j);
            scanf("%c%*c", &m[i][j]); // mi raccomando, scartiamo \n
            if (i == j) {
                diag[i] = m[i][j];
            }
        }
    }
    diag[N] = '\0';
    */

    // se vogliamo saltiamo l'acquisizione
    // e scriviamo direttamente la matrice.
    // NB: solo ai fini dell'esecuzione del programma!
    // NON è valido ai fini della soluzione dell'esercizio
    char m[N][N] = {
        {'a', 'i', 'o', 'a', 'q'},
        {'h', 'n', 'a', 'n', 's'}, // "ans" alla fine della riga
        {'a', 'n', 's', 's', 'p'}, // "ans" all'inizio
        {'u', 's', 'p', 'i', 'o'},
        {'g', 'e', 'a', 'a', 'a'}
        //               | match
    };
    strcpy(diag, "ansia");

    // prima stampata
    printf("Matrice:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%c", m[i][j]);
        }
        printf("\n");
    }

    // processing per riga
    for (i = 0, found = 0; i < N && !found; i++) {
        // copio la riga nella stringa temporanea
        // di confronto
        for (j = 0; j < N; j++) {
                cfr[j] = m[i][j];
        }
        cfr[j] = '\0';

        if (strcmp(cfr, diag) == 0) {
            found = 1;
            printf("RIGA %d\n", i);
        }
    }

    // processing per colonna
    // NON inizializzo ancora found!
    // Se ho già trovato, non cerco più
    for (j = 0; j < N && !found; j++) {
        // copio la colonna nella stringa temporanea
        // di confronto
        for (i = 0; i < N; i++) {
                cfr[i] = m[i][j];
        }
        cfr[i] = '\0';

        if (strcmp(cfr, diag) == 0) {
            found = 1;
            printf("COLONNA %d\n", j);
        }
    }

    return 0;
}
