/*
Alla fine degli anni ’90 due squattrinati studenti di Stanford (Larry Page e Sergey Brin) vi propongono di investire su una loro idea: un innovativo motore di ricerca per Internet. Voi siete alquanto scettici sulla possibile riuscita del progetto e volete valutare i possibili ritorni economici. Scrivete quindi un programma che riceve in ingresso 3 valori (usare dei float): il capitale investito, una percentuale di interesse ed il numero di anni su cui valutare l’investimento. Per ogni anno aggiornare gli interessi: 
interessi = capitale * percentuale_interessi / 100
ed aggiornare il capitale sommando gli interessi ottenuti:
capitale = capitale + interessi
Stampare a video per ogni anno il valore del capitale aggiornato.
*/

#include <stdio.h>

int main(void) {
    float budget, tax, years, total;
    int i;

    printf("Capitale investito:\n");
    scanf("%f%*c", &budget);
    printf("Tasso di interesse:\n");
    scanf("%f%*c", &tax);
    printf("Anni:\n");
    scanf("%f%*c", &years);

    for(i = 0, total = budget; i < years; i++) {
        total += total * (tax / 100);
        printf("Anno %d: %f$\n", i + 1, total);
    }

    return 0;
}
