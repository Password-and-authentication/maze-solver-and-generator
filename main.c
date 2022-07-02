#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.c"
#include "cell.h"


#define TOP_ROW 0
#define BOT_ROW 9
#define FAR_LEFT 0
#define FAR_RIGHT 9

#define BOT_WALL 0
#define RIGHT_WALL 1

#define NEWLINE 10
#define SPACE 32

#define true 1
#define false 0


void initcells(cellptr maze);
void printmaze(cellptr maze);
void generatemaze(cellptr maze);
int getrand();

int main() {

    cell maze[10][10];


    initcells(*maze);
    printmaze(*maze);
    srand(time(0));
    //printf("%d\n", getrand());
    generatemaze(*maze);
    printmaze(*maze);

    

    return 0;
}

int getrand() {
    return (rand() % (3 - 0 + 1) + 0);
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


void generatemaze(cellptr maze) {
    cellptr init = maze;    
    

    push(init);
    while (sp > 0) {
        cellptr current = pop();
        //printf("%d\n", sp);
        printf("%d %d\t", current->x, current->y);
        printf("%d\n", allVisited(current));
        if (!allVisited(current)) {
            push(current);
            cellptr neighbor;
            int dir = 0;
            while (true) {
                if ((neighbor = current->neighbors[dir = getrand()]) != NULL && neighbor->visited != true)
                        break;
            }

                    
            //printf("%d %d\t", current->x, current->y);
            //printf("%d %d\n", neighbor->x, neighbor->y);
            

            if (dir == LEFT) {
                neighbor->walls[RIGHT_WALL] = 0;
            }
            if (dir == RIGHT) {
                current->walls[RIGHT_WALL] = 0;
            }
            if (dir == BOT) {
                current->walls[BOT_WALL] = 0;
            }
            if (dir == TOP) {
                neighbor->walls[BOT_WALL] = 0;
            }
        
            neighbor->visited = true;
            push(neighbor);  
            
        }
        
    }
}


void printmaze(cellptr maze) {
    cellptr cptr = maze;
    
    for (int i = 0; i< 100; ++i) {
        //if (cptr->right == NULL) printf("NEW ROW\n");
        if (cptr->walls[RIGHT_WALL] != 0) {
            putchar('|');
        } else putchar(SPACE);
        if (cptr->walls[BOT_WALL] != 0) {
            putchar('_');
        } else putchar(SPACE);

        if (cptr++->neighbors[RIGHT] == NULL) {
            putchar('|');
            putchar(NEWLINE);
        }
        /*printf("%d ", cptr->visited);
        if (cptr->neighbors[RIGHT] == NULL) {
            putchar(10);
        }
        ++cptr;*/
        
    }
}


void initcells(cellptr maze) {
    cellptr rowptr, colptr;
    int row, col;

    for (row = 0; row < 10; ++row) {
        rowptr = &maze[10 * row];
        colptr = rowptr;
        for (col = 0; col < 10; ++col) {  
            if (row == TOP_ROW) {
                printf("%d\n", row);
                colptr->neighbors[TOP] = NULL;
            } else colptr->neighbors[TOP] = &(rowptr - 10)[col];
            if (row == BOT_ROW) {
                colptr->neighbors[BOT] = NULL;
            } else colptr->neighbors[BOT] = &(rowptr + 10)[col];
            if (col == FAR_LEFT) {
                colptr->neighbors[LEFT] = NULL;
            } else colptr->neighbors[LEFT] = (colptr - 1);
            if (col == FAR_RIGHT) {
                colptr->neighbors[RIGHT] = NULL;
            } else colptr->neighbors[RIGHT] = (colptr + 1);
            
            colptr->y = row;
            colptr->x = col;
            colptr->visited = 0;
            colptr->walls[BOT_WALL] = 1;
            colptr->walls[RIGHT_WALL] = 1;
            ++colptr;     
        }
        
    } 
}
