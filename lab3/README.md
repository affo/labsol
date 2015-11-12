Le soluzioni di questo laboratorio verranno pubblicate intorno al __09/12/2015__.

## Esempio sulle Matrici
Questo programma acquisisce una matrice e ne stampa la trasposta:

```
#include <stdio.h>
#define N 3

int main (void) {
    int i, j;

    // salto la fase di acquisizione solo
    // per velocizzare l'esecuzione del programma.
    // NON valido in esame.
    /*
    int m[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento (%d, %d): ", i, j);
            // acquisisce un intero e scarta un carattere
            scanf("%d%*c", &m[i][j]);
        }
    }
    */

    int m[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Stampo la trasposta:

    // Modo 1
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%d", m[j][i]);
        }
        printf("\n");
    }

    printf("\n");

    // Modo 2
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
