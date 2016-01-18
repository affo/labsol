/*
 * Tribonacci
 * Per il testo completo, si veda LAB5.pdf
 */
#include <stdio.h>

// int tribo (int n);
void tribo (int n);

int main (void) {
    int n;

    scanf("%d%*c", &n);
    tribo(n);

    return 0;
}

// Questa versione della funzione ha una elevata complessità algoritmica
// e arriva alla non terminazione anche con input piccoli (es. 35).
// Inoltre, non permette di stampare la serie di tribonacci "pulita" direttamente
// all'interno della funzione (scopri il perché disegnando l'albero delle chiamate).
// Per stampare la serie è necessario chiamare tribo(k) per ogni k <= n e
// stamparne il risultato.
/*
int tribo (int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
}
*/

// Questa versione è invece "ricorsiva in coda" e ha quindi
// performance migliori. Inoltre permette di stampare la serie direttamente
// all'interno dell'invocazione ricorsiva.
void t_r (int n, int i, int one, int two, int three) {
    printf("%d ", one);

    if (i > n) {
        return;
    }

    t_r(n, i + 1, one + two + three, one, two);
}

void tribo (int n) {
    if (n > 0) {
        t_r(n, 2, 1, 0, 0);
    }
    printf("\n");
    return;
}
