/*
 * Per il testo completo, si veda LAB5.pdf
 */
#include <stdio.h>
#define N 10

typedef struct { int x, y; } Posizione;

typedef struct c {
    Posizione appezzamento;
    float peso;
    int valido;
} Cesta;

typedef Cesta Coda[N];

/*
 * se la capacità della smallatrice non è ancora
 * saturata aggiunge alla coda la cesta descritta dai parametri
 */
void accoda (Posizione p, float peso, Coda c) {
    Cesta bucket;
    bucket.appezzamento = p;
    bucket.peso = peso;
    bucket.valido = 1;

    int i, inserted = 0;

    for (i = 0; i < N && !inserted; i++) {
        if (c[i].valido == 0) {
            c[i] = bucket;
            inserted = 1;
        }
    }

    return ;
}


typedef float Mappa[N][N];

/*
 * - preleva una cesta dalla coda,
 * - ne dispone la lavorazione invocando la funzione int start(Cesta cs, int numCeste)
 *   che restituisce il numero di pistacchi smallati,
 * - calcola il calibro medio,
 * - aggiorna la mappa, e infine
 * - restituisce la coda modificata.
 * La funzione start() è da considerarsi già implementata. Si badi a gestire il prelievo
 * in modo che la coda si comporti effettivamente come una coda.
 */
int start (Cesta cs, int numCeste) { return 42; }

void smalla (Coda c, Mappa m) {
    int i;

    Cesta cs = c[0];
    int no_pist = start(cs, 1);
    float avg_cal = cs.peso / no_pist;
    m[cs.appezzamento.x][cs.appezzamento.y] = avg_cal;

    // rimuovi il primo elemento
    // e applica left shift
    for (i = 1; i < N; i++) {
        c[i - 1] = c[i];
    }

    // il fatto di aver smallato una cesta
    // porta sempre al fatto che l'ultimo elemento
    // della coda sarà ora vuoto
    c[N - 1].valido = 0;

    return ;
}

/*
 * restituisce 1 se i k valori più elevati in m stanno in un quadrato di lato k,
 * 0 altrimenti
 */
typedef struct {
    Posizione pos;
    float val;
    int valid;
} Max;

typedef Max Maximums[N * N];

void max_insert(float val, int x, int y, Maximums m) {
    int i, j;

    for (i = 0; i < N * N; i++) {
        if (m[i].valid = 0 || m[i].val > val) {
            break;
        }
    }

    // right shift
    for (j = i; j < N * N - 1; j++) {
        if (!m[j].valid) break;
        m[j + 1] = m[j];
    }

    // insert
    Posizione pos;
    pos.x = x; pos.y = y;
    Max max;
    max.pos = pos;
    max.val = val;
    max.valid = 1;
    m[i] = max;

    return ;
}

int concentrati (Mappa m, int k) {
    int i, j, res;
    Maximums maxs;

    // riempiamo l'array di massimi
    // con elementi vuoti
    for (i = 0; i < N * N; i++) {
        Max max;
        max.valid = 0;
        maxs[i] = max;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            max_insert(m[i][j], i, j, maxs);
        }
    }

    // ora l'inserimento in ordine è completo.
    // posso estrarre i primi k massimi
    // ed usarli per identificare un angolo del
    // mio quadrato di lato k
    Posizione top_left;
    top_left.x = N;
    top_left.y = N;

    for (i = 0; i < k; i++) {
        if (maxs[i].pos.x < top_left.x) {
            top_left.x = maxs[i].pos.x;
        }

        if (maxs[i].pos.y < top_left.y) {
            top_left.y = maxs[i].pos.y;
        }
    }

    // ok, ora posso capire su qualcuno dei primi
    // k massimi è fuori da quel quadrato di lato k
    int top = top_left.x;
    int bottom = top_left.x + k;
    int left = top_left.y;
    int right = top_left.y + k;
    int x, y;
    for (i = 0, res = 1; i < k && res; i++) {
        x = maxs[i].pos.x;
        y = maxs[i].pos.y;
        if (x < top || x > bottom || \
                y < left || y > right) {
            res = 0;
        }
    }

    return res;
}
