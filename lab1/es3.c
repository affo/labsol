/*
Scrivere un programma che permette di effettuare le operazioni di una semplice calcolatrice: Somma, Sottrazione, Divisione, Prodotto. Il programma deve quindi richiedere all’utente la tipologia di operazione da svolgere (es. “premere 1 se si vuole effettuare una somma”) ed in seguito i due operandi necessari. Dopo ogni operazione stampare i risultati ottenuti. NB: Attenzione alla divisione!
Estensione:
Aggiungere anche l’elevamento a potenza (calcolato moltiplicando il numero per sé stesso) come operazione disponibile.
*/

#include <stdio.h>

int main(void) {
    int n1, n2, ans, i, res;

    do {
        printf("Scegli l'operatore\n");
        printf("1) +\n");
        printf("2) -\n");
        printf("3) *\n");
        printf("4) /\n");
        printf("5) **\n");
        scanf("%d%*c", &ans);
    } while (ans < 1 || ans > 5);

    printf("Primo numero:\n");
    scanf("%d%*c", &n1);
    do {
        printf("Secondo numero:\n");
        scanf("%d%*c", &n2);
    } while (ans == 4 && n2 == 0);

    switch(ans) {
        case 2:
            printf("%d\n", n1 - n2);
            break;
        case 3:
            printf("%d\n", n1 * n2);
            break;
        case 4:
            printf("%f\n", (float) n1 / n2);
            break;
        case 5:
            for(i = 0, res = 1; i < n2; i++) {
                res *= n1;
            }
            printf("%d\n", res);
            break;
        default:
            printf("%d\n", n1 + n2);
    }


    return 0;
}
