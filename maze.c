#ifndef M 
#define M
#include "struct.h"
#include <stdio.h>

int colMAX, rowMAX;

void printmaze(Maze *maze) {
    cell *cptr = maze->cells;
    size_t i, j;
    for (j = 0; j <= (colMAX * 2); ++j) putchar('_');
    for (i = 0; i < (colMAX * rowMAX); ++i) {
        if (i % colMAX == 0) {
            putchar('\n');
            putchar('|');
        }
        if (cptr->bottom_wall) {    
            putchar('_');
        } else if (cptr->path) {
            putchar('x');
        } else putchar(' ');
        if (cptr->right_wall) {
            putchar('|');
        } else if (cptr->path) {
            putchar('x');
        } else putchar(' ');
        cptr++;
    }
}


#endif