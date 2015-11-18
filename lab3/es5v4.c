#include <stdio.h>

#define N 5

int main (void) {
    int i, j;
    int found_r, found_c;

    /*
    char m[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento (%d, %d): ", i, j);
            scanf("%c%*c", &m[i][j]);
        }
    }
    */

    char m[N][N] = {
        {'a', 'x', 'x', 'a', 'x'},
        {'x', 'n', 'x', 'n', 'x'},
        {'x', 'x', 's', 's', 'x'},
        {'a', 'n', 's', 'i', 'a'},
        {'x', 'x', 'x', 'a', 'a'}
    };

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("\t%c", m[i][j]);
        }
        printf("\n");
    }

    found_c = found_r = 0;
    for (i = 0; i < N && !(found_r || found_c); i++) {
        found_c = found_r = 1;
        for (j = 0; j < N && (found_r || found_c); j++) {
            if (m[i][j] != m[j][j]) {
                found_r = 0;
            }

            if (m[j][i] != m[j][j]) {
                found_c = 0;
            }
        }

        if (found_r) {
            printf("RIGA %d\n", i);
        } else if (found_c) {
            printf("COLONNA %d\n", i);
        }
    }

    return 0;
}
