
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

point getpoint() {
    char str[10];
    char sx[10];
    char sy[10];

    scanf("%s", str);
    int i, j;
    i = j = 0;
    while ((sx[i] = str[i]) != ',' && ++i);
    sx[i] = '\n';
    ++i;
    while ((sy[j] = str[i]) != '\n' && ++i && ++j);
    sy[j] = '\n';
    point p = {atoi(sx), atoi(sy)};
    printf("%zu %zu \n", p.x, p.y);
    return p;
}   