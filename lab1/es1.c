/*
Scrivere un programma per il calcolo delle tabelline. Il programma riceve dall’utente due numeri. Il primo corrisponde al numero di cui è necessario calcolare la tabellina mentre il secondo indica la lunghezza della tabellina richiesta.
Es: 2, 10 produce come risultato: 2 4 6 8 10 12 14 16 18 20
Es: 3, 8 produce come risultato: 3 6 9 12 15 18 21 24
Accettare solamente numeri positivi: se l’utente inserisce un numero negativo mostrare un messaggio di errore e richiede un altro numero.
*/

#include <stdio.h>

int main(void){
    int n, l, i;

    do {
        printf("Numero di cui calcolare la tabellina:\n");
        scanf("%d%*c", &n);
    } while(n <= 0);

    do {
        printf("Lunghezza tabellina:\n");
        scanf("%d%*c", &l);
    } while(l <= 0);

    for(i = 0; i < l; i++) {
        printf("%d ", n * (i + 1));
    }
    printf("\n");

    return 0;
}
