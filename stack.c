#include "cell.h"

static cell* cellstack[10000];
static int sp;

void push(cell* cell) {
    cellstack[sp++] = cell;   
}

cell* pop() {
    return (sp > 0) ? cellstack[--sp] : NULL;
}