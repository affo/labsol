/*
 * Per il testo del problema, si veda LAB4.pdf
 */

#include <stdio.h>
#include <string.h>

#define LENGTH 200
#define N 3

typedef struct _movie {
    char title[LENGTH + 1];
    char type[LENGTH + 1];
    int year;
} movie;


int add(movie f[], int no_f);
void print(movie f[], int no_f);
movie search(movie f[], int no_f, char* title);
int rem(movie f[], int no_f, char* title);

// support functions
void _print_movie(movie m);
void _print_menu() {
    printf("\n");
    printf("Scegli un'opzione:\n");
    printf("\t(1) Aggiungi un film\n");
    printf("\t(2) Stampa la lista dei film\n");
    printf("\t(3) Cerca un film\n");
    printf("\t(4) Rimuovi un film\n");
    printf("\t(5) Esci dal programma\n");
    printf("\n");
}

// tools for string
void _trim_newline(char* s) {
    int l = strlen(s);

    if (s[l - 1] == '\n') {
        s[l - 1] = '\0';
    }

    return;
}
// tools for arrays
void _right_shift(movie a[], int length, int start) {
    int i;

    for (i = length - 1; i >= start + 1; i--) {
            a[i] = a[i - 1];
        }

    return;
}

void _left_shift(movie a[], int length, int end) {
    int i;

    for (i = end; i < length - 1; i++) {
        a[i] = a[i + 1];
    }

    return;
}


int main (void) {
    movie movies[N];
    int no_movies = 0;
    int ans, temp;
    char title[LENGTH + 1];
    movie result;

    do {
        _print_menu();
        scanf("%d%*c", &ans);

        switch (ans) {
            case 1:
                temp = add(movies, no_movies);
                if (temp > no_movies) {
                    printf("Film aggiunto con successo\n");
                } else {
                    printf("Impossibile aggiungere film\n");
                }

                no_movies = temp;
                break;

            case 2:
                print(movies, no_movies);
                break;

            case 3:
                printf("Titolo: ");
                fgets(title, LENGTH + 1, stdin);
                _trim_newline(title);
                result = search(movies, no_movies, title);

                if (strlen(result.title) == 0) {
                    printf("Nessun film trovato che corrisponda a: %s\n", title);
                } else {
                    _print_movie(result);
                }
                break;

            case 4:
                printf("Titolo: ");
                fgets(title, LENGTH + 1, stdin);
                _trim_newline(title);
                temp = rem(movies, no_movies, title);

                if (temp < no_movies) {
                    printf("Film %s cancellato correttamente\n", title);
                } else {
                    printf("Nessun film trovato che corrisponda a: %s\n", title);
                }

                no_movies = temp;
                break;
        }
    } while (ans != 5);

    return 0;
}


int add(movie f[], int no_f){
    int i, inserted;
    movie m;

    if (no_f >= N) {
        return no_f;
    }

    printf("Inserimento nuovo film:\n");
    printf("Titolo: ");
    fgets(m.title, LENGTH + 1, stdin);
    printf("Genere: ");
    fgets(m.type, LENGTH + 1, stdin);
    printf("Anno: ");
    scanf("%d%*c", &m.year);

    _trim_newline(m.title);
    _trim_newline(m.type);

    for (i = 0, inserted = 0; i < no_f && !inserted; i++) {
        if (f[i].year > m.year) {
            _right_shift(f, no_f + 1, i);
            f[i] = m;
            inserted = 1;
        }
    }

    if (!inserted) {
        f[no_f] = m;
    }

    no_f++;
    return no_f;
}

void _print_movie(movie m) {
    printf("{\n");
    printf("\t\"titolo\": \"%s\",\n", m.title);
    printf("\t\"genere\": \"%s\",\n", m.type);
    printf("\t\"anno\": %d\n", m.year);
    printf("}\n");
}

void print(movie f[], int no_f) {
    int i;

    for (i = 0; i < no_f; i++) {
        _print_movie(f[i]);
        printf("\n");
    }

    return;
}

movie search(movie f[], int no_f, char* title) {
    int i;

    movie m;
    strcpy(m.title, "");

    for (i = 0; i < no_f; i++) {
        if (strcmp(f[i].title, title) == 0) {
            m = f[i];
            break;
        }
    }

    return m;
}

int rem(movie f[], int no_f, char* title) {
    int i;

    for (i = 0; i < no_f; i++) {
        if (strcmp(f[i].title, title) == 0) {
            _left_shift(f, no_f, i);
            no_f--;
            break;
        }
    }

    return no_f;
};
