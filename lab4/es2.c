/*
 * Scrivere una funzione che riceve una matrice M di interi e un intero K e
 * restituisce 1 se la matrice ha una riga i cui valori sono tutti minori di K.
 * Si usi il file lab4ges.c allegato per scrivere e testare la funzione
 */

#include <stdio.h>
#include <stdlib.h>

#define N 8

int f(int M[][N], int k);

int main(){
    char inutile;
    int M1[N][N]={ { 3,  5,  6, 23, 87, 23, 12,  1  },
                   { 11, 14, 76, 87, 92,  0,  0, 3  },
                   { 3,  9, 27, 81,  0, 12, 18, 24  },
                   { 1,  2,  0,  4,  7,  2,  1,  4  },
                   { 87, 34, 29, 98,111, 76,123, 99 },
                   { 16, 14, 76, 89, 92, 16,  0,  3 },
                   { 3, 19, 11, 88, 15,  2, 18, 24  },
                   { 12, 29, 21, 88, 15,  2, 19, 25 } };

    int M2[N][N]={  { 3,  5,  6, 23, 87, 23, 12,  1  },
                    { 11, 14, 76, 87, 92,  0,  0, 3  },
                    { 3,134, 27, 81,  0, 12, 18, 24  },
                    { 1,  2,  0,  4,  7,  2,  1,  4  },
                    { 87,  1, 29, 98, 11, 76,123, 99 },
                    { 16, 14, 76, 89, 92, 16,  0,  3 },
                    { 3, 19, 11, 88, 15,  2, 18,  24 },
                    { 12, 29, 21, 88, 15,  2, 19, 25 }};

    int M3[N][N]={  { 3,  5,  6, 23, 87, 23, 12,   1 },
                    { 11, 14, 76, 87, 92,  0,  0,  3 },
                    { 3,134, 27, 81, 15, 12, 18,  24 },
                    { 1,  2,  0,  2,  2,  2,  1,   0 },
                    { 87,  1, 29, 98,111, 76,123, 99 },
                    { 16, 14, 76, 89, 92, 16,  0,  3 },
                    { 3, 19, 11, 88, 15,  2, 18, 24  },
                    { 12, 29, 21, 88, 15,  2, 19, 25 } };

    if(f(M1,3)==1)
        printf("M1 ok\n");
    else
        printf("M1 non ok\n");

    if(f(M2,3)==1)
        printf("M2 ok\n");
    else
        printf("M2 non ok\n");

    if(f(M3,3)==1)
        printf("M3 ok\n");
    else
        printf("M3 non ok\n");

}

int f(int M[][N], int k){
  int ris = 0;
  int i, j;

  for (i = 0; i < N && !ris; i++) {
      for (j = 0, ris = 1; j < N && ris; j++) {
          if (M[i][j] >= k) {
              ris = 0;
          }
      }
  }

  return ris;
}
