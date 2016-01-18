/*
 * Per il testo completo, si veda LAB5.pdf
 */
#include <stdio.h>
#define N 3

typedef char griglia[N][N];
typedef struct mo {
    int r, c;
} Mossa;
typedef Mossa Partita[100];

char ennuplaVert(griglia g);
char ennuplaOriz(griglia g);
char ennuplaDiag(griglia g);

int esito(griglia g);

int gioca(griglia g, Partita p);

void print_griglia (griglia g) {
    int i, j;

    printf("     ");
    for (j = 0; j < N; j++) {
        printf("%d  ", j);
    }
    printf("\n");
    printf("     ");
    for (j = 0; j < N; j++) {
        printf("|  ");
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%d -- ", i);

        for (j = 0; j < N; j++) {
            printf("%c  ", g[i][j]);
        }
        printf("\n");
    }
}

int main (void) {
    int i, j, r, c;
    char player;
    griglia g;
    Partita p;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            g[i][j] = '\0';
        }
    }

    i = 0;

    do {
        if (i % 2 == 0) {
            player = 'X';
        } else {
            player = 'O';
        }

        do {
            print_griglia(g);
            printf("Giocatore %c tocca a te (riga, colonna): ", player);
            scanf("%d%*c%d%*c", &r, &c);
        } while (r < 0 || r >= N || c < 0 || c >= N || \
                g[r][c] != '\0');

        p[i].r = r;
        p[i].c = c;
        g[r][c] = player;

        i++;
    } while (esito(g) == 0);

    p[i].r = N;
    p[i].c = N;

    print_griglia(g);
    printf("\t%d\n", gioca(g, p));

    return 0;
}

// a, b, c
char ennuplaVert (griglia g) {
    int i, j, found;
    char ris = '\0';

    for (j = 0, found = 0; j < N && !found; j++) {
        for (i = 0, found = 1; i < N - 1 && found; i++) {
            if (g[i][j] == '\0' || g[i][j] != g[i + 1][j]) {
                found = 0;
            }
        }

        if (found) {
            ris = g[0][j];
        }
    }

    return ris;
}

char ennuplaOriz (griglia g) {
    int i, j, found;
    char ris = '\0';

    for (i = 0, found = 0; i < N && !found; i++) {
        for (j = 0, found = 1; j < N - 1 && found; j++) {
            if (g[i][j] == '\0' || g[i][j] != g[i][j + 1]) {
                found = 0;
            }
        }

        if (found) {
            ris = g[i][0];
        }
    }

    return ris;
}

char ennuplaDiag (griglia g) {
    int i, found;

    for (i = 0, found = 1; i < N - 1 && found; i++) {
        if (g[i][i] == '\0' || g[i][i] != g[i + 1][i + 1]) {
            found = 0;
        }
    }

    if (found) {
        return g[0][0];
    }

    for (i = 0, found = 1; i < N - 1 && found; i++) {
        if (g[i][N - i - 1] == '\0' || g[i][N - i - 1] != g[i + 1][N - i - 2]) {
            found = 0;
        }
    }

    if (found) {
        return g[0][N - 1];
    }

    return '\0';
}

// d
// restituisce 0 se la partita rappresentata da g
// non è finita, 1 se ha vinto il “giocatore X”, 2 se ha vinto il “giocatore
// O”, 3 se è un pareggio
//
// Funzione di supporto per trovare un buco nella griglia
int hole (griglia g) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (g[i][j] == '\0') {
                return 1;
            }
        }
    }

    return 0;
}

int esito (griglia g) {
    int v = ennuplaVert(g);
    int o = ennuplaOriz(g);
    int d = ennuplaDiag(g);

    if (v == 'X' || o == 'X' || d == 'X') {
        return 1;
    }

    if (v == 'O' || o == 'O' || d == 'O') {
        return 1;
    }

    if (hole(g)) {
        return 0;
    }

    return 3;
}

// e
int gioca(griglia g, Partita p) {
    int i = 0;
    int r, c;

    do {
        r = p[i].r;
        c = p[i].c;

        if (i % 2 == 0) {
            // giocatore X
            g[r][c] = 'X';
        } else {
            g[r][c] = 'O';
        }

        i++;
    } while (r != N || c != N);

    return esito(g);
}
