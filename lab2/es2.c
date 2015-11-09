/*
 * Scrivere un programma che richiede l'inserimento di voti ottenuti in un
 * certo numero di corsi. Il programma chiede qual è il numero di voti da
 * inserire. Per ciascuno, l'utente deve inserire numero di crediti e voto
 * ottenuto (in 30imi). Il programma infine stampa la media pesata dei corsi
 * e il numero totale dei crediti. Si ricorda che la media pesata, ad esempio
 * su due voti, si calcola come:
 * media = (voto1*crediti1+voto2*crediti2)/(crediti1+crediti2).
 */
#include <stdio.h>

int main (void) {
    int no_marks, cfus, mark, i, tot_cfus;
    float avg;

    do {
        printf("Numero di voti su cui fare la media:\n");
        scanf("%d%*c", &no_marks);
    } while (no_marks <= 0);

    for (i = 0, tot_cfus = 0, avg = 0; i < no_marks; i++) {
        do {
            printf("Voto [%d/%d]:\n", i, no_marks - 1);
            scanf("%d%*c", &mark);
        } while (mark < 18 || mark > 30);

        do {
            printf("CFU [%d/%d]:\n", i, no_marks - 1);
            scanf("%d%*c", &cfus);
        } while (cfus <= 0);

        avg += mark * cfus;
        tot_cfus += cfus;
    }

    printf("Crediti conseguiti: %d\n", tot_cfus);
    printf("Media pesata: %f\n", avg / tot_cfus);

    return 0;
}
