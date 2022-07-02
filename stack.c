#include "cell.h"

static cellptr cellstack[100];
static int sp;

void push(cellptr cell) {
    cellstack[sp++] = cell;   
}

cellptr pop() {
    return (sp > 0) ? cellstack[--sp] : NULL;
}