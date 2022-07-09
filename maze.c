#include "cell.h"
#include "maze.h"
#include <stdbool.h>
#include <stdio.h>

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

cell *cell_at(Maze *maze, size_t x, size_t y) {
    return &maze->cells[x + y * maze->width];
}

bool is_visited(Maze *maze, size_t x, size_t y) {
    return (*cell_at(maze, x, y)).visited;
}

