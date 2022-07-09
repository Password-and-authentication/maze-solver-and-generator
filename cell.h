#ifndef CELL_H
#define CELL_H
#include <stddef.h>

typedef struct {
    bool bottom_wall: 1;
    bool right_wall: 1;
    bool visited: 1;
    bool path: 1;
} cell;

#endif