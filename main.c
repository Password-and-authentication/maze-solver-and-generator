#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>
#include "stack.c"
#include "struct.h"


#define BOT_WALL 0
#define RIGHT_WALL 1

static int rowMAX;
static int colMAX;


void initcells(Maze *maze);
void printmaze(Maze *maze);
void generatemaze(Maze *maze);
int getrand();

cell *cell_at(Maze *maze, size_t x, size_t y);

int main(int argc, char *argv[]) {
    srand(time(0));

    if (argc == 1) {    
        colMAX = rowMAX = 7; // default 
    } else colMAX = rowMAX = (atoi(argv[1]));

    Maze maze = {colMAX, rowMAX};
    

    initcells(&maze);
    generatemaze(&maze);
    printmaze(&maze);

    putchar('\n');

    
    return 0;
}

cell *cell_at(Maze *maze, size_t x, size_t y) {
    return &maze->cells[x + y * maze->width];
}

bool is_visited(Maze *maze, size_t x, size_t y) {
    return (*cell_at(maze, x, y)).visited;
}

int getrand(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void generatemaze(Maze *maze) {
    cell *start = maze->cells;
    cell *getneighbor(Maze *maze, point *p, direction *dir);
    bool allVisited(Maze *maze, point* p);

    direction d;
    point p = {0, 0};
    push(p);


    while (sp > 0) {
        p = pop();
        cell* current = cell_at(maze, p.x, p.y);
        if (!allVisited(maze, &p)) {
            printf("%zu %zu\n", p.x, p.y);
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

void printmaze(Maze *maze) {
    cell *cptr = maze->cells;
    size_t i, j;
    for (j = 0; j <= (colMAX * 2); ++j) putchar('_');
    for (i = 0; i < (colMAX * rowMAX); ++i) {
        if (i % colMAX == 0) {
            putchar(10);
            putchar('|');
        }
        if (cptr->bottom_wall) {    
            putchar('_');
        } else putchar(32);
        if (cptr->right_wall) {
            putchar('|');
        } else putchar(32);
        cptr++;
    }
}

void initcells(Maze *maze) {
    maze->cells = malloc(colMAX * rowMAX);
    cell *cellptr = maze->cells;
    size_t i;
    for (i = 0; i < (rowMAX * colMAX); ++i) {
        cellptr->visited = false;
        cellptr->bottom_wall = true;
        cellptr++->right_wall = true;
    } 
}


cell* getneighbor(Maze *maze, point *p, direction *dir) {
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
