#include "stack.c"
#include <stdio.h>


void generatemaze(Maze *maze);
void printmaze(Maze *maze);

void step(Maze *maze) {
    
    while (sp > 0) {
        char c = getchar();
        if (c == '\n') {
            generatemaze(maze);
            printmaze(maze);
            
            putchar('\n');
        }  
    }
}

void insta(Maze *maze) {
    while (sp > 0) {     
        generatemaze(maze);
    }
    printmaze(maze);
}