#include <stdio.h>
#define N 5

int main (void) {
    int i, j, found;

    /*
    char m[N][N];
    for (i = 0; i< N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento (%d, %d): ", i, j);
            scanf("%c%*c", &m[i][j]);
        }
    }
    */

    char m[N][N] = {
        {'a', 'i', 'o', 'a', 'q'},
        {'h', 'n', 'a', 'n', 's'}, // "ans" alla fine della riga
        {'a', 'n', 's', 's', 'p'}, // "ans" all'inizio
        {'u', 's', 'p', 'i', 'o'},
        {'g', 'e', 'a', 'a', 'a'}
        //               | match
    };

    for (i = 0; i< N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%c", m[i][j]);
        }
        printf("\n");
    }

    // confronto righe
    for (i = 0, found = 0; i < N && !found; i++) {
        for (j = 0, found = 1; j < N && found; j++) {
            if(m[i][j] != m[j][j]) {
                found = 0;
            }
        }

        if (found) {
            printf("RIGA %d\n", i);
        }
    }


    // confronto colonne
    for (j = 0; j < N && !found; j++) {
        for (i = 0, found = 1; i < N && found; i++) {
            if(m[i][j] != m[i][i]) {
                found = 0;
            }
        }

        if (found) {
            printf("COLONNA %d\n", j);
        }
    }

    return 0;
}
