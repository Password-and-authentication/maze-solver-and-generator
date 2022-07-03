#ifndef CELL
#define CELL

#include <stddef.h>
#define LEFT 0
#define RIGHT 1
#define TOP 2 
#define BOT 3

typedef struct cellstruct {
    bool bottom_wall: 1;
    bool right_wall: 1;
    bool visited: 1;
} cell;

typedef struct mazestruct {
    size_t width;
    size_t height;
    cell *cells;
} Maze;

#endif