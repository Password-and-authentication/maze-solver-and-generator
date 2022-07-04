#include "../struct.h"
#include "../cell.c"
#include <stdio.h>
#include <stdlib.h>

bool topwall(Maze *maze, point *p);
bool botwall(Maze *maze, point *p);
bool leftwall(Maze *maze, point *p);
bool rightwall(Maze *maze, point *p);

bool equal(point p, point p2);


void solve(Maze *maze, point p, point e, int colMAX, int rowMAX) {
    static bool found = false;
    if (found) return;

    if (equal(p, e)) {
        found = true;  
    }

    (*cell_at(maze, p.x, p.y)).visited = true;
    point temp;
    if (p.x < (colMAX - 1) && !rightwall(maze, &p) && !is_visited(maze, p.x + 1, p.y)) {
        temp = p;
        temp.x++;
        solve(maze, temp, e, colMAX, rowMAX);
    } 
    if (p.x > 0 && !leftwall(maze, &p) && !is_visited(maze, p.x - 1, p.y)) {
        temp = p;
        temp.x--;
        solve(maze, temp, e, colMAX, rowMAX);
    }
    if (p.y > 0 && !topwall(maze, &p) && !is_visited(maze, p.x, p.y - 1)) {
        temp = p;
        temp.y--;
        solve(maze, temp, e, colMAX, rowMAX);
    }
    if (p.y < (rowMAX - 1) && !botwall(maze, &p) && !is_visited(maze, p.x, p.y + 1)) {
        temp = p;
        temp.y++;
        solve(maze, temp, e, colMAX, rowMAX);
    }

    if (found) {
        (*cell_at(maze, p.x, p.y)).path = true;
    }
    return;
}

bool equal(point p, point p2) {
    return (p.x == p2.x && p.y == p2.y);
}


bool rightwall(Maze *maze, point *p) {
    return (*cell_at(maze, p->x, p->y)).right_wall;
}

bool leftwall(Maze *maze, point *p) {
    return (*cell_at(maze, p->x - 1, p->y)).right_wall;
}

bool botwall(Maze *maze, point *p) {
    return (*cell_at(maze, p->x, p->y)).bottom_wall;
}

bool topwall(Maze *maze, point *p) {
    return (*cell_at(maze, p->x, p->y - 1)).bottom_wall;
}


