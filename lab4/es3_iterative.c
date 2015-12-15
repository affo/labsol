/*
 * Si veda testo in LAB4.pdf.
 */

#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

typedef enum {S, C, G} cell_type;
const char cell_type_names[] = {'S', 'C', 'X'};

void mark_godzilla_destroy_area(int row, int column, cell_type env[][WIDTH]);
void print_env(cell_type env[][WIDTH]);

int main (int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("\t./executable <row> <column>\n");
        return -1;
    }

    int row = atoi(argv[1]);
    int column = atoi(argv[2]);

    cell_type env[HEIGHT][WIDTH] = {
        {C, C, C, C, C, C, C, C, C, C},
        {C, C, C, C, C, C, C, S, C, C},
        {S, S, S, S, S, S, S, S, C, C},
        {C, S, C, C, C, C, C, S, C, C},
        {C, C, S, C, C, C, C, S, C, C},
        {C, C, S, S, S, C, C, S, S, S},
        {S, S, S, S, S, C, C, S, C, C},
        {C, C, S, C, C, S, S, S, C, C},
        {C, C, S, C, C, C, C, S, C, C},
        {C, C, S, C, C, C, C, S, C, C}
    };

    print_env(env);

    mark_godzilla_destroy_area(row, column, env);

    printf("\n");
    print_env(env);

    return 0;
}


/*
 * Utils for positions and directions
 */
typedef enum {L, R, U, D} direction_e;
typedef struct {
    int row, column;
} pos_t;


direction_e clock(direction_e d) {
    switch (d) {
        case L: return U;
        case U: return R;
        case R: return D;
        default: return L;
    }
}


direction_e get_opposite(direction_e d) {
    switch (d) {
        case L: return R;
        case U: return D;
        case R: return L;
        default: return U;
    }
}


pos_t get_pos(pos_t p, direction_e d) {
    pos_t res;

    switch (d) {
        case L:
            res.column = p.column - 1;
            res.row = p.row;
            if (res.column < 0) {
               res.column = 0;
            }
            break;
        case U:
            res.column = p.column;
            res.row = p.row - 1;
            if (res.row < 0) {
                res.row = 0;
            }
            break;
        case R:
            res.column = p.column + 1;
            res.row = p.row;
            if (res.column >= WIDTH) {
                res.column = WIDTH - 1;
            }
            break;
        default:
            res.column = p.column;
            res.row = p.row + 1;
            if (res.row >= HEIGHT) {
                res.row = HEIGHT - 1;
            }
    }

    return res;
}


/*
 * The steps of the main algorithm
 */
pos_t reach_border(pos_t p, cell_type env[][WIDTH]) {
    pos_t border;
    int i, j;

    for (i = p.row; i > 0; i--) {
        if (env[i - 1][p.column] != C) {
            break;
        }
    }
    border.row = i;

    for (j = p.column; j > 0; j--) {
        if (env[i][j - 1] != C) {
            break;
        }
    }
    border.column = j;

    return border;
}


// isolates the path sorrounding the city
void isolate_city(pos_t start, cell_type env[][WIDTH]) {
    pos_t curr;
    direction_e camefrom = L;

    curr.row = start.row;
    curr.column = start.column;
    do {
        env[curr.row][curr.column] = G;

        pos_t check;
        direction_e next_d = camefrom;
        do {
            next_d = clock(next_d);
            check = get_pos(curr, next_d);
        } while (env[check.row][check.column] == S || \
                (check.row == curr.row && check.column == curr.column));

        camefrom = get_opposite(next_d);
        curr = check;
    } while (curr.row != start.row || \
            curr.column != start.column);
}


void destroy_city(cell_type env[][WIDTH]) {
    int i, j;
    int destroy_mode;

    for (i = 0; i < HEIGHT; i++) {
        destroy_mode = 0;

        for (j = 0; j < WIDTH; j++) {
            if (destroy_mode) {

                if (env[i][j] == C) {
                    env[i][j] = G;
                } else {
                    destroy_mode = 0;
                }

            } else if (env[i][j] == G) {
                destroy_mode = 1;
            }
        }
    }

    return;
}


/*
 * Main Functions
 */
// the algorithm
void mark_godzilla_destroy_area(int row, int column, cell_type env[][WIDTH]) {
    pos_t start, p;
    p.row = row;
    p.column = column;

    start = reach_border(p, env);
    isolate_city(start, env);
    destroy_city(env);
}

void print_env(cell_type env[][WIDTH]){
    int i, j;

    printf("     ");
    for (j = 0; j < WIDTH; j++) {
        printf("%d  ", j);
    }
    printf("\n");
    printf("     ");
    for (j = 0; j < WIDTH; j++) {
        printf("|  ");
    }
    printf("\n");

    for (i = 0; i < HEIGHT; i++) {
        printf("%d -- ", i);

        for (j = 0; j < WIDTH; j++) {
            printf("%c  ", cell_type_names[env[i][j]]);
        }
        printf("\n");
    }
     return;
}
