#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include "stack.c"
#include "cell.h"


#define BOT_WALL 0
#define RIGHT_WALL 1

static int rowMAX;
static int colMAX;

void initcells(Maze *maze);
void printmaze(Maze *maze);
void generatemaze(Maze *maze);
int getrand();

int main(int argc, char *argv[]) {
    srand(time(0));

    if (argc == 1) {    
        colMAX = rowMAX = 7; // default 
    } else colMAX = rowMAX = (atoi(argv[1]));

    Maze maze = {colMAX, rowMAX};
    

    initcells(&maze);
    //generatemaze(maze.cells);
    printmaze(&maze);

    putchar('\n');

    
    return 0;
}

/*
void generatemaze(Maze *maze) {
    cell *start = maze->cells;   
    push(start);

    int allVisited(cell *cell);
    int getrand(int min, int max);

    // while stack is not empty
    while (sp > 0) {
        cell *current = pop();

        if (!allVisited(current)) {
            push(current);

            cell *neighbor;
            int dir = 0;

            // get random neighbor that isnt NULL and isnt visited already
            while ((neighbor = current->neighbors[dir = getrand(0, 3)]) == NULL || neighbor->visited == true)
                    ;
            

            // each cell only has a right wall and a bottom wall
            // so to modify for example the left wall of the current cell
            // you would modify the right wall of the cell left to the current cell


            if (dir == LEFT) {
                neighbor->walls[RIGHT_WALL] = false;            // false = remove wall
            }
            if (dir == RIGHT) {
                current->walls[RIGHT_WALL] = false;
            }
            if (dir == BOT) {
                current->walls[BOT_WALL] = false;
            }
            if (dir == TOP) {
                neighbor->walls[BOT_WALL] = false;
            }
        
            neighbor->visited = true;
            push(neighbor);         
        }       
    }
}*/

void printmaze(Maze *maze) {
    cell *cptr = maze->cells;
    size_t i, j;
    for (j = 0; j <= (colMAX * 2); ++j) putchar('_');

    for (i = 0; i < (colMAX * rowMAX); ++i) {
        if (i % colMAX == 0) {
            putchar(10);
            putchar('|');
        }
        if (cptr->bottom_wall) {
            putchar('_');
        }
        if (cptr->right_wall) {
            putchar('|');
        }
       

    }

}


cell* cell_at(Maze *maze, size_t x, size_t y) {
    return &maze->cells[x + y * colMAX];
}

void initcells(Maze *maze) {
    maze->cells = malloc(colMAX * rowMAX);
    cell *cellptr = maze->cells;
    size_t i;
    for (i = 0; i < (rowMAX * colMAX); ++i) {
        cellptr->visited = 0;
        cellptr->bottom_wall = 1;
        cellptr++->right_wall = 1;
    } 
}


/*int isNull(cell *cell) {
    return cell == NULL;  
}

int allVisited(cell *cell) {
    int l, r, t, b;
    l = r = t = b = 1;
    if (!isNull(cell->neighbors[LEFT])) {
        l = cell->neighbors[LEFT]->visited;
    }
    if (!isNull(cell->neighbors[RIGHT])) {
        r = cell->neighbors[RIGHT]->visited;
    }
    if (!isNull(cell->neighbors[TOP])) {
        t = cell->neighbors[TOP]->visited;
    }
    if (!isNull(cell->neighbors[BOT])) {
        b = cell->neighbors[BOT]->visited;
    }
    //printf("%d %d %d %d\n", l, r, t, b);
    return (l && r && t && b);
}

int getrand(int min, int max) {
    return (rand() % (max - min + 1) + min);
}*/