#ifndef H
#define H
#include <stddef.h>

typedef struct cellstruct {
    bool bottom_wall: 1;
    bool right_wall: 1;
    bool visited: 1;
    bool path: 1;
} cell;

typedef struct mazestruct {
    size_t width;
    size_t height;
    cell *cells;
} Maze;

typedef struct {
    size_t x;
    size_t y;
} point;

typedef enum {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
} direction;
    
#endif