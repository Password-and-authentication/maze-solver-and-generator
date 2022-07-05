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

    point getpoint();
    point s, e;
    while (true) {
        printf("Point format: x,x\n");
        printf("Enter starting point: ");
        s = getpoint();
        printf("Enter ending point: ");
        e = getpoint();
        if (s.x >= colMAX || s.y >= rowMAX || e.x >= colMAX || e.y >= rowMAX || s.x < 0 || s.y < 0 || e.x < 0 || e.y < 0) {
            printf("\nCoordinate to high or low\n\n\n");
            continue;
        }
        break; 
    }
    //solve(&maze, s, e);

    //printmaze(&maze);
    //putchar('\n');
    return 0;
}

point getpoint() {
    char str[10];
    char sx[10];
    char sy[10];

    scanf("%s", str);
    int i, j;
    i = j = 0;
    while ((sx[i] = str[i]) != ',' && ++i);
    sx[i] = '\n';
    ++i;
    while ((sy[j] = str[i]) != '\n' && ++i && ++j);
    sy[j] = '\n';
    point p = {atoi(sx), atoi(sy)};
    return p;
}   

