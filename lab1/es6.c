/*
Si scriva un programma in grado di decidere se un numero dato dall’utente è primo. Si ricorda che un numero è primo se non è divisibile per nessuno dei valori compresi tra il numero stesso e 1. N.B. Per la verifica della condizione di divisibilità si può utilizzare l’operatore % come nel problema 1.
Estensione:
Aggiungere anche il calcolo del fattoriale del numero inserito.
*/

#include <stdio.h>

int main(void) {
    int n, i, prime, fact;

    printf("Numero:\n");
    scanf("%d%*c", &n);

    for(i = 2, prime = 1; prime && i <= n / 2; i++) {
        prime = n % i;
    }

    for(i = 0, fact = 1; i < n - 1; i++) {
        fact *= n - i;
    }

    if(!prime) {
        printf("Il numero NON è primo\n");
    } else {
        printf("Il numero è primo\n");
    }

    printf("Il suo fattoriale è %d\n", fact);

    return 0;
}
