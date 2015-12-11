/*
 * Scrivere una funzione f (e main per chiamarla) che riceve due array di 5 interi A e B e inserisce in ogni casella di B la somma degli elementi
 * di A dall’inizio alla posizione corrispondente a quella in cui si sta inserendo.
 * Esempio: A=[2,3,4,6,8]
 * B=[2,2+3,2+3+4,2+3+4+6,2+3+4+6+8]  B=[2,5,9,15,23]
 */

#include <stdio.h>

#define NA 5
#define NB 5

void sum_pos (int* a, int* b, int a_len, int b_len) {
    int i, j, sum = 0;
    int min_len = a_len > b_len ? b_len : a_len;

    for (i = 0; i < min_len; i++) {
        sum += a[i];
        b[i] = sum;
    }

    return;
}

int main (void) {
    int a[NA] = {2, 3, 4, 6, 8}, b[NB], i;

    sum_pos(a, b, NA, NB);

    for (i = 0; i < NA; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < NB; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}
