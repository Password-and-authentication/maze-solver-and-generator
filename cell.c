#ifndef C
#define C
#include "struct.h"
#include <stdbool.h>

cell *cell_at(Maze *maze, size_t x, size_t y) {
    return &maze->cells[x + y * maze->width];
}

bool is_visited(Maze *maze, size_t x, size_t y) {
    return (*cell_at(maze, x, y)).visited;
}

#endif