#ifndef CELL
#define CELL

#define LEFT 0
#define RIGHT 1
#define TOP 2 
#define BOT 3

typedef struct cellstruct *cellptr;

typedef struct cellstruct {
    cellptr neighbors[4];
    int walls[2];              // [0] = top wall, [1] = right wall

    int x;
    int y;

    int visited;
} cell;

#endif