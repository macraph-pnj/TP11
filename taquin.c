#include "taquin.h"
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

void initialisationPlateau(Plateau* p) {
    int i, j;
    for(i = 0; i < NB_LIG; i++) {
        for(j = 0; j < NB_COL; j++) {
            p->bloc[i][j].lig = i;
            p->bloc[i][j].col = j;
        }
    }
    p->empty_x = NB_COL - 1;
    p->empty_y = NB_LIG - 1;
}

void swap(Carre* a, Carre* b) {
    Carre temp = *a;
    *a = *b;
    *b = temp;
}

int is_valid_move(Plateau *p, int x, int y) {
    if(x == p->empty_x && abs(y - p->empty_y) == 1)
        return 1;
    if(y == p->empty_y && abs(x - p->empty_x) == 1)
        return 1;
    return 0;
}

void move_tile(Plateau *p, int x, int y) {
    if(is_valid_move(p, x, y)) {
        swap(&p->bloc[y][x], &p->bloc[p->empty_y][p->empty_x]);
        p->empty_x = x;
        p->empty_y = y;
    }
}

void shuffle_plateau(Plateau *p, int moves) {
    int i;
    for(i = 0; i < moves; i++){
        int possible_moves[4][2];
        int count = 0;
        int ex = p->empty_x, ey = p->empty_y;
        if(ex > 0) {
            possible_moves[count][0] = ex - 1;
            possible_moves[count][1] = ey;
            count++;
        }
        if(ex < NB_COL - 1) {
            possible_moves[count][0] = ex + 1;
            possible_moves[count][1] = ey;
            count++;
        }
        if(ey > 0) {
            possible_moves[count][0] = ex;
            possible_moves[count][1] = ey - 1;
            count++;
        }
        if(ey < NB_LIG - 1) {
            possible_moves[count][0] = ex;
            possible_moves[count][1] = ey + 1;
            count++;
        }
        int r = MLV_get_random_integer(0, count - 1);
        int nx = possible_moves[r][0];
        int ny = possible_moves[r][1];
        move_tile(p, nx, ny);
    }
}

int is_solved(Plateau *p) {
    int i, j;
    for(i = 0; i < NB_LIG; i++){
        for(j = 0; j < NB_COL; j++){
            if(p->bloc[i][j].lig != i || p->bloc[i][j].col != j)
                return 0;
        }
    }
    return 1;
}
