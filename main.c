#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.c"
#include "cell.h"


#define NEWLINE 10
#define SPACE 32
#define true 1
#define false 0

#define TOP_ROW 0
#define BOT_ROW (rowMAX - 1)
#define FAR_LEFT 0
#define FAR_RIGHT (colMAX - 1)

#define BOT_WALL 0
#define RIGHT_WALL 1

static int rowMAX;
static int colMAX;

void initcells(cellptr maze);
void printmaze(cellptr maze);
void generatemaze(cellptr maze);
int getrand();

int main(int argc, char *argv[]) {
    srand(time(0));

    if (argc == 1) {    
        colMAX = rowMAX = 7; // default 
    } else colMAX = rowMAX = (atoi(argv[1]));


    cell maze[rowMAX][colMAX];

    initcells(*maze);
    generatemaze(*maze);
    printmaze(*maze);

    putchar(NEWLINE);

    
    return 0;
}


void generatemaze(cellptr maze) {
    cellptr start = maze;   
    push(start);

    int allVisited(cellptr cell);
    int getrand(int min, int max);

    // while stack is not empty
    while (sp > 0) {
        cellptr current = pop();

        if (!allVisited(current)) {
            push(current);

            cellptr neighbor;
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
}

void printmaze(cellptr maze) {
    cellptr cptr = maze;

    // print the top part for whole maze:
    for (int i = 0; i < (colMAX * 2); ++i) putchar('_');
    putchar(NEWLINE);

    for (int i = 0; i < (colMAX * rowMAX); ++i) {

        // print left wall for whole maze
        if (cptr->neighbors[LEFT] == NULL) putchar('|');

        // bottom wall
        if (cptr->walls[BOT_WALL] != false) {
            putchar('_');
        } else putchar(SPACE);

        // right wall
        if (cptr->walls[RIGHT_WALL] != false) {
            putchar('|');
        } else putchar(SPACE);
        

        // new row
        if (cptr->neighbors[RIGHT] == NULL) {
            putchar(NEWLINE);
        }
        cptr++; 
    }
}


void initcells(cellptr maze) {
    cellptr rowptr, colptr;
    int row, col;

    for (row = 0; row < rowMAX; ++row) {
        rowptr = &maze[rowMAX * row];
        colptr = rowptr;

        for (col = 0; col < rowMAX; ++col) {  
            if (row == TOP_ROW) {

                // top row has no cells above them
                colptr->neighbors[TOP] = NULL;                          
            } else colptr->neighbors[TOP] = &(rowptr - rowMAX)[col];

            if (row == BOT_ROW) {

                // bottom row has no cells below them
                colptr->neighbors[BOT] = NULL;
            } else colptr->neighbors[BOT] = &(rowptr + rowMAX)[col];

            if (col == FAR_LEFT) {

                // left column has no cells left to them
                colptr->neighbors[LEFT] = NULL;
            } else colptr->neighbors[LEFT] = (colptr - 1);

            if (col == FAR_RIGHT) {

                // right column has no cells right to the,
                colptr->neighbors[RIGHT] = NULL;
            } else colptr->neighbors[RIGHT] = (colptr + 1);
            
            // set all walls to true at the start
            colptr->walls[BOT_WALL] = true;                 
            colptr->walls[RIGHT_WALL] = true;

            colptr++->visited = false;   
        }  
    } 
}


int isNull(cellptr cell) {
    return cell == NULL;  
}

int allVisited(cellptr cell) {
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
}