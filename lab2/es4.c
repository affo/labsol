/*
 * Scrivere un programma che chiede in input una stringa (senza spazi), la
 * memorizza in un array di caratteri e verifica che la stringa sia ben
 * parentesizzata. Una stringa è ben parentesizzata se le parentesi (che
 * possono essere solo tonde) sono chiuse correttamente nell’ordine in cui
 * vengono aperte. Esempi di stringa ben parentesizzata sono:
 * bla
 * (bla)
 * (bla(bla))
 * (bla () (bla) ()
 */

#include <stdio.h>
#define N 10

int main (void) {
    int i, check = 0;
    char s[N + 1];

    printf("Dammi la stringa (verranno usati solo i primi %d caratteri):\n", N);
    fgets(s, N + 1, stdin);

    // dobbiamo controllare che `check` sia >= 0
    // se succede il contrario, vuol dire che abbiamo
    // incontrato una ')' prima di una '('.
    for (i = 0; s[i] != '\0' && check >= 0; i++) {
        if (s[i] == '(') check++;
        else if (s[i] == ')') check--;
    }

    printf("%s --> ", s);
    if (check == 0) printf("OK\n");
    else printf("KO\n");

    return 0;
}
