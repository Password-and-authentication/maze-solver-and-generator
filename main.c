#include <stdio.h>


#define TOP_ROW 1
#define BOT_ROW 9
#define FAR_LEFT 0
#define FAR_RIGHT 9

typedef struct cellstruct *cellptr;


typedef struct cellstruct {
    cellptr left;
    cellptr right;
    cellptr top;
    cellptr bot;
    int *walls[2];              // [0] = top wall, [1] = right wall

    int visited;
} cell;


void initializeMaze(cellptr maze);
void printMaze(cellptr maze);

int main() {

    cell maze[10][10];
    initializeMaze(*maze);
    cellptr c = &maze[9][9];
    c->visited = 1;
    c->left->visited = 1;
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
    cellptr rowptr, colptr;
    int row, col;

    for (row = 0; row < 10; ++row) {
        rowptr = &maze[10 * row];
        colptr = rowptr;
        for (col = 0; col < 10; ++col) {  
            if (row == TOP_ROW) {
                colptr->top = NULL;
            } else {
                colptr->top = &(rowptr - 10)[col];
                

            }
            if (row == BOT_ROW) {
                colptr->bot = NULL;
            } else colptr->bot = &(rowptr + 10)[col];
            if (col == FAR_LEFT) {
                colptr->left = NULL;
            } else colptr->left = (colptr - 1);
            if (col == FAR_RIGHT) {
                colptr->right = NULL;
            } else colptr->right = (colptr + 1);

            colptr->visited = 0;
            ++colptr;     
        }
        
    } 
}
