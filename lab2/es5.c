/*
 * Scrivere un programma che riceva in ingresso dall'utente un vettore di
 * 5 caratteri tutti minuscoli. Il programma dica all'utente se le lettere
 * contenute nel vettore sono in ordine alfabetico.
 */

#include <stdio.h>
#define N 5

int main (void) {
    const int MAX_U = 90;
    const int MIN_U = 65;
    const int MAX_L = 122;
    const int MIN_L = 97;
    const int U2L = 32;

    char s[N + 1];
    int i, l, check, is_l, is_invalid;

    for (i = 0; i < N; i++) {
        scanf("%c", &s[i]);

        if (s[i] == '\n') {
            // allow shorter strings
            break;
        }

        is_invalid = (s[i] < MIN_U && s[i] > MAX_U ) || (s[i] < MIN_L && s[i] > MAX_L);
        is_l = s[i] <= MAX_L && s[i] >= MIN_L;

        if (is_invalid) {
            printf("%c non è un simbolo valido\n", s[i]);
            return 1;
        } else if (!is_l) {
            // to lower case
            s[i] += U2L;
        }
    }
    s[i] = '\0';
    l = i; // saving string length

    // skipping stdin flushing

    for (i = 0, check = 1; check && i < l - 1; i++) {
        if (s[i] > s[i + 1]) {
            check = 0;
        }
    }

    printf("\n%s --> ", s);
    if(check) printf("OK\n");
    else printf("KO\n");

    return 0;
}
