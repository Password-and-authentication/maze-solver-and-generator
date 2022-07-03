#include "struct.h"

static point stack[10000];
static int sp;

void push(point p) {
    stack[sp++] = p;   
}

point pop() {
    if (sp > 0) return stack[--sp];
}

