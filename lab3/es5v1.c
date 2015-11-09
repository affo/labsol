/*
 * Scrivere un programma che riceva in ingresso dall'utente una matrice
 * quadrata 5x5 contenente solo caratteri. Il programma dica all'utente se
 * la parola che si trova sulla diagonale principale può essere ritrovata in
 * un qualsiasi altro punto della matrice (in una riga o in una colonna).
 * Venga indicato a video anche la posizione della parola.
 */

#include <stdio.h>
#define N 5

int main (void) {
    int i, j, k, found;

    /*
    char m[N][N];
    // acquisizione
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento in posizione (%d, %d): ", i, j);
            scanf("%c%*c", &m[i][j]); // mi raccomando, scartiamo \n
        }
    }
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
        for (j = 0; j < N && !found; j++) {
            if (m[i][j] == m[0][0]) {
                // ok, ho trovato un carattere uguale
                found = 1;

                // scorro le colonne per cercare una differenza
                for (k = 1; k < N && found; k++) {
                    // se trovo una differenza oppure
                    // se la riga è finita prima del tempo
                    // allora non ho trovato un match
                    if (j + k >= N || m[i][j + k] != m[k][k]) {
                        found = 0;
                    }
                }

                if (found) {
                    printf("RIGA: Trovato in posizione (%d, %d)\n", i, j);
                }
            }
        }
    }

    // processing per colonna
    // NON inizializzo ancora found!
    // Se ho già trovato, non cerco più
    for (j = 0; j < N && !found; j++) {
        for (i = 0; i < N && !found; i++) {
            if (m[i][j] == m[0][0]) {
                found = 1;
                for (k = 1; k < N && found; k++) {
                    if (i + k >= N || m[i + k][j] != m[k][k]) {
                        found = 0;
                    }
                }

                if (found) {
                    printf("COLONNA: Trovato in posizione (%d, %d)\n", i, j);
                }
            }
        }
    }

    return 0;
}
