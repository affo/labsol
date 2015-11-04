/*
Scrivere un programma che chiede due numeri all’utente e ne stampi a video tutti i divisori comuni.
*/

#include <stdio.h>

int main(void) {
    int n1, n2, max, i;

    printf("Primo numero:\n");
    scanf("%d%*c", &n1);
    printf("Secondo numero:\n");
    scanf("%d%*c", &n2);

    max = n1 > n2 ? n2 : n1;

    for(i = 2; i <= max; i++) {
        if(!(n1 % i) && !(n2 % i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
