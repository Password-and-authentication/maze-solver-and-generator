#include <stdio.h>

typedef struct cellstruct *cellptr;

typedef struct neighbor {
    cellptr cell;
    int *wall;
} neighbor;

typedef struct cellstruct {
    neighbor *left;
    neighbor *right;
    neighbor *top;
    neighbor *bot;

    int visited;
} cell;


void initializeMaze(cellptr maze);
void printMaze(cellptr maze);

int main() {

    cell maze[10][10];
    initializeMaze(*maze);
    cellptr c = &maze[9][9];
    c->visited = 1;
    c->left->cell->visited = 1;
    printMaze(*maze);

    

    return 0;
}


void printMaze(cellptr maze) {
    cellptr cptr = maze;
    
    for (int i = 0; i< 100; ++i) {
        //if (cptr->right == NULL) printf("NEW ROW\n");
        printf("%d ", cptr->visited);
        if (*cptr->right->wall == 1) {

        }
        if (cptr++->right->cell == NULL) putchar(10);
    }
}

void initializeMaze(cellptr maze) {
    cell *c, *d;
    int i, j;

    for (i = 0; i < 10; ++i) {
        c = &maze[10 * i];
        d = c;
        for (j = 0; j < 10; ++j) {  
            if (i == 0) {
                d->top->cell = NULL;
            } else d->top->cell = &(c - 10)[j];
            if (i == 9) {
                d->bot->cell = NULL;
            } else d->bot->cell = &(c + 10)[j];
            d->visited = 0;
            if (j == 0) {
                d->left->cell = NULL;
            } else d->left->cell = (d - 1);
            if (j == 9) {
                d->right->cell = NULL;
            } else d->right->cell = (d + 1);
            ++d;     
        }
        
    } 
}
