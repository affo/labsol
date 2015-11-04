/*
Scrivere un programma che generi un numero intero casuale e chieda all’utente di indovinarlo. Ad ogni tentativo fallito da parte dell’utente di indovinare il numero il programma indica se il numero da indovinare è maggiore o minore rispetto a quello appena inserito. N.B. Per generare un numero casuale è necessario chiamare una volta la funzione srand(time(0)) per inizializzare il generatore di numeri casuali ed in seguito, per ogni numero casuale, la funzione rand() come di seguito. 
Es. r = rand()
N.B. Si noti che la funzione rand() restituisce un numero casuale tra zero e la costante  RAND_MAX (costante molto grande). E’ possibile usare il solito operatore % per limitare questo range (L’uso della funzione time(..) necessita della libreria time.h. Le funzioni srand(..) e rand(..) sono invece parte di stdlib.h).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(void) {
    int guess, ans;

    srand(time(0));
    guess = rand() % MAX;

    do {
        printf("Indovina il numero che ho pensato (tra 0 e %d):\n", MAX - 1);
        scanf("%d%*c", &ans);
        if(ans < guess) {
            printf("Un po' di più\n");
        } else if(ans > guess) {
            printf("Un po' di meno\n");
        }
    } while(ans != guess);

    printf("Ce l'hai fatta!\n");

    return 0;
}
