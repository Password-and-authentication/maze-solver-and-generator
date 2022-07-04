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
    if (argc > 1 && strcmp(argv[1], "step") == 0) {
        step(&maze);
    } else {
        insta(&maze);
        putchar('\n');
    }

    printf("\nstarting point:\n");
    int c = getchar();
    point s = {0, 1};
    point e = {6, 0};
    cell* cellptr = maze.cells;

    for (int i = 0; i < (rowMAX * colMAX); ++i) {
        cellptr->path = false;
        cellptr++->visited = false;    
    }
    solve(&maze, s, e, colMAX, rowMAX);

    printmaze(&maze);

    
  
    return 0;
}

