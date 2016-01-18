/*
 * Per il testo completo, si veda LAB5.pdf
 */
#include <stdio.h>

typedef struct f {
    unsigned long int barcode;
    float dosaggio;
    char nome[20], principioattivo[20], produttore[20];
} Farmaco;

typedef struct ep {
    Farmaco farmaco;
    int mutuabileSiNo;
    float prezzo_ufficiale;
    char descrizione_e_indicazioni[250];
} ElementoProntuario;

typedef ElementoProntuario PFN[40000];

/*
 * riceve in input un codice a barre (barcode) e un vettore di tipo PFN e restituisce l’indice
 * dell’elemento del prontuario relativo al farmaco con quel codice,
 * oppure il valore -1 se il codice non è presente nel prontuario
 */
int trova (unsigned long int barcode, PFN pfn) {
    int i = 0, ris = -1;
    unsigned long int cmp_barcode;

    do {
        cmp_barcode = pfn[i].farmaco.barcode;
        if (cmp_barcode == barcode) {
            ris = i;
        }
        i++;
    } while (cmp_barcode != 0 && ris == -1);

    return ris;
}

/*
 * riceve come parametri un codice a barre (barcode) e un vettore di tipo PFN e, usando la
 * funzione trova() per trovare il farmaco corrispondente,
 * restituisce 1 se il farmaco identificato dal codice è mutuabile, 0 altrimenti
 */
int esente (unsigned long int barcode, PFN pfn) {
    int i = trova(barcode, pfn);
    int ris;

    if (i >= 0) {
        ris = pfn[i].mutuabileSiNo;
    } else {
        ris = i;
    }

    return ris;
}

// SECONDA PARTE
#define HEIGHT 10
#define WIDTH 10
#define DEPTH 10

typedef unsigned long int Scaffale[HEIGHT][WIDTH][DEPTH];

typedef struct p { int x, y, z; } Pos;

typedef struct ps {
    Pos pos;
    int valido;
} Posizione;

typedef Posizione Posizioni[1000];

typedef struct itm {
    unsigned long int barcode;
    int qta_disponibile;
    Posizioni pos;
    int valido;
} Item;

typedef Item Registro[1000];

/*
 Aggiunge una confezione del farmaco specificato allo
 scaffale nel primo slot libero trovato e aggiorna il registro,
 inserendo la posizione dello slot occupato all’array delle posizioni e
 incrementando la quantità disponibile.
 Se l’operazione riesce, la funzione restituisce 1,
 se invece lo scaffale è pieno, non aggiorna i dati e
 restituisce 0.
 Si tratti, idealmente e se possibile, anche il caso in cui il farmaco non è ancora presente nel registro.
 */
int carica(unsigned long barcode, Scaffale s, Registro r) {
    int i, j, k, ris = 0, updated;

    // inseriamo nel primo slot libero
    for (i = 0; i < HEIGHT && !ris; i++) {
        for (j = 0; j < WIDTH && !ris; j++) {
            for (k = 0; k < DEPTH && !ris; k++) {
                if (s[i][j][k] == 0) {
                    s[i][j][k] = barcode;
                    ris = 1;
                }
            }
        }
    }

    // se ho inserito,
    // allora aggiorno il registro
    if (ris) {
        updated = 0;
        Posizione p;
        p.pos.x = i;
        p.pos.y = j;
        p.pos.z = k;
        p.valido = 1;

        // suppongo di potermi fermare al primo elemento
        // non valido nel registro.
        // Altrimenti i < 1000.
        for (i = 0; r[i].valido && !updated; i++) {
            if (r[i].barcode == barcode) {
                r[i].qta_disponibile++;

                for (j = 0; r[i].pos[j].valido; j++);
                // j ora è l'indice del primo slot libero
                r[i].pos[j] = p;
                updated = 1;
            }
        }

        // il farmaco non è presente
        // i punta all'ultima posizione vuota
        if (!updated) {
            Item item;
            item.barcode = barcode;
            item.qta_disponibile = 1;
            item.pos[0] = p;
            item.valido = 1;

            r[i] = item;
        }
    }

    return ris;
}
