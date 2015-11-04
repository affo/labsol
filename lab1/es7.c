/*
Scrivere un programma che chieda un intero positivo n all'utente e in risposta stampi i primi n numeri della serie di Fibonacci. La serie di Fibonacci è definita come segue:

    F(0) = 1        F(1) = 1
    F(n) = F(n-1) + F(n-2)

    Quindi la serie è:
    1 1 2 3 5 8 13
*/

#include <stdio.h>

int main(void) {
    int n, p, pp, i, tmp;
    pp = 0;
    p = 1;

    printf("Numero:\n");
    scanf("%d%*c", &n);

    for(i = 0; i < n; i++) {
        printf("%d ", p);
        tmp = pp;
        pp = p;
        p += tmp;
    }
    printf("\n");

    return 0;
}
