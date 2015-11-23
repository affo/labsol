/*
 * Si veda testo in LAB4.pdf.
 */

#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10

typedef enum {R, C, G} cell_type;
const char cell_type_names[] = {'R', 'C', 'X'};

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
        {C, C, C, C, C, C, C, R, C, C},
        {R, R, R, R, R, R, R, R, C, C},
        {C, R, C, C, C, C, C, R, C, C},
        {C, C, R, C, C, C, C, R, C, C},
        {C, C, R, R, R, C, C, R, R, R},
        {R, R, R, R, R, C, C, R, C, C},
        {C, C, R, C, C, R, R, R, C, C},
        {C, C, R, C, C, C, C, R, C, C},
        {C, C, R, C, C, C, C, R, C, C}
    };

    print_env(env);

    mark_godzilla_destroy_area(row, column, env);

    printf("\n");
    print_env(env);

    return 0;
}

void mark_godzilla_destroy_area(int row, int column, cell_type env[][WIDTH]) {
    int left = column - 1;
    int right = column + 1;
    int up = row - 1;
    int down = row + 1;

    if (env[row][column] != C) {
        return;
    }

    env[row][column] = G;

    if (up >= 0 && env[up][column] == C) mark_godzilla_destroy_area(up, column, env);
    if (down < HEIGHT && env[down][column] == C) mark_godzilla_destroy_area(down, column, env);
    if (left >= 0 && env[row][left] == C) mark_godzilla_destroy_area(row, left, env);
    if (right < WIDTH && env[row][right] == C) mark_godzilla_destroy_area(row, right, env);

    return;
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
}
