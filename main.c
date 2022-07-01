#include <stdio.h>

typedef struct cellstruct *cellptr;

typedef struct point {
    int x;
    int y;
} point;

typedef struct cellstruct {
    cellptr left;
    cellptr right;
    cellptr top;
    cellptr bot;

    point point;
    int visited;
} cell;


void initializeMaze(cellptr maze);
void printMaze(cellptr maze);

int main() {

    cell maze[10][10];
    initializeMaze(*maze);
    cellptr c = &maze[0][1];
    c->visited = 1;
    if (c->left) c->left->visited = 1;
    printMaze(*maze);

    

    return 0;
}


void printMaze(cellptr maze) {
    cellptr cptr = maze;
    
    for (int i = 0; i< 100; ++i) {
        //if (cptr->right == NULL) printf("NEW ROW\n");
        printf("%d ", cptr->visited);
        if (cptr++->right == NULL) putchar(10);
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
                d->top = NULL;
            } else d->top = &(c - 10)[j];
            if (i == 9) {
                d->bot = NULL;
            } else d->bot = &(c + 10)[j];
            d->visited = 0;
            if (j == 0) {
                d->left = NULL;
            } else d->left = (d - 1);
            if (j == 9) {
                d->right = NULL;
            } else d->right = (d + 1);
            ++d;     
        }
        
    } 
}

void makecell() {

}