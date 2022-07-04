#include <stdio.h>
#include "generate/generate.c"
#include "solve/solve.c"
#include "maze.c"

int main(int argc, char *argv[]) {
    srand(time(0));

    if (argc == 1) {    
        colMAX = rowMAX = 7; // default 
    } else colMAX = rowMAX = (atoi(argv[2]));
    stack = malloc((rowMAX * colMAX) * sizeof(point));
    Maze maze = {colMAX, rowMAX, malloc(rowMAX * colMAX)};

    initcells(&maze);
    point p = {0, 0};
    push(p);
    while (sp > 0) {
        generatemaze(&maze);
    }
    printmaze(&maze);
    putchar('\n');
    
    cell* cellptr = maze.cells;
    for (int i = 0; i < (rowMAX * colMAX); ++i) {
        cellptr->path = false;                          // reset
        cellptr++->visited = false;    
    }

    point s = {0, 0};               // custom starting / end point not yet implemented
    point e = {6, 6};
    solve(&maze, s, e);

    printmaze(&maze);
    return 0;
}

