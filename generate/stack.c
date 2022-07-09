#ifndef S 
#define S
#include "../point.h"

static point *stack;
static int sp;

void push(point p) {
    stack[sp++] = p;   
}

point pop() {
    if (sp > 0) return stack[--sp];
}

#endif

