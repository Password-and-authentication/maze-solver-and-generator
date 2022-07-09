#ifndef POINT_H
#define POINT_H

#include <stddef.h>

typedef struct {
    size_t x;
    size_t y;
} point;

extern point getpoint();

#endif