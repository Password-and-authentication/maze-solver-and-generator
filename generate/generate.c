#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include <string.h>
#include "stack.c"
#include "../struct.h"
#include "../cell.c"
#include "../maze.c"

void initcells(Maze *maze);
void generatemaze(Maze *maze);
int getrand();

void generatemaze(Maze *maze) {
    cell *cell_at(Maze *maze, size_t x, size_t y);
    bool is_visited(Maze *maze, size_t x, size_t y);
    cell *getneighbor(Maze *maze, point *p, direction *dir);
    bool allVisited(Maze *maze, point* p);

    point p;
    direction d;

    p = pop();
    cell* current = cell_at(maze, p.x, p.y);
    if (!allVisited(maze, &p)) {
        push(p);
        cell* n = getneighbor(maze, &p, &d);
            
        switch (d) {
        case LEFT:
            n->right_wall = false;
            break;
        case RIGHT:
            current->right_wall = false;
            break;
        case TOP:
            n->bottom_wall = false; 
            break;
        case BOTTOM:
            current->bottom_wall = false;
            break;
        }
        n->visited = true;
        push(p);
    }      
}

void initcells(Maze *maze) {
    cell *cellptr = maze->cells;
    size_t i;
    for (i = 0; i < (rowMAX * colMAX); ++i) {
        cellptr->visited = false;
        cellptr->bottom_wall = true;
        cellptr++->right_wall = true;
    } 
}

bool allVisited(Maze *maze, point *p) {
    if (p->x > 0 && !is_visited(maze, p->x - 1, p->y)) {
        return false;
    } else if (p->x < (colMAX - 1) && !is_visited(maze, p->x + 1, p->y)) {
        return false;
    } else if (p->y > 0 && !is_visited(maze, p->x, p->y - 1)) {
        return false;
    } else if (p->y < (rowMAX - 1) && !is_visited(maze, p->x, p->y + 1)) {
        return false;
    }
    return true;
}


cell* getneighbor(Maze *maze, point *p, direction *dir) {
    int getrand(int, int);
    *dir = getrand(0, 3);
    switch (*dir) {
    case LEFT:
        if (p->x > 0 && !is_visited(maze, p->x - 1, p->y)){
            p->x--;
            break;
        } 
        return getneighbor(maze, p, dir);
    case RIGHT:
        if (p->x < (colMAX - 1) && !is_visited(maze, p->x + 1, p->y)) {
            p->x++;
            break;
        }
        return getneighbor(maze, p, dir);
    case TOP:
        if (p->y > 0 && !is_visited(maze, p->x, p->y - 1)) {
            p->y--;
            break;
        }
        return getneighbor(maze, p, dir);
    case BOTTOM:
        if (p-> y < (rowMAX - 1) && !is_visited(maze, p->x, p->y + 1)) {
            p->y++;
            break;
        }
        return getneighbor(maze, p, dir);
    }
    return cell_at(maze, p->x, p->y);
}

int getrand(int min, int max) {
    return (rand() % (max - min + 1) + min);
}
