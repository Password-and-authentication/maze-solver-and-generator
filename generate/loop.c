#include "stack.c"
#include <stdio.h>
#include "../maze.c"


void generatemaze(Maze *maze);

void step(Maze *maze) {
    
    while (sp > 0) {
        char c = getchar();
        if (c == '\n') {
            generatemaze(maze);
            printmaze(maze);
            
            putchar('\n');
        }  
    }
    printf("#");
}

void insta(Maze *maze) {
    while (sp > 0) {     
        generatemaze(maze);
    }
    printmaze(maze);
}