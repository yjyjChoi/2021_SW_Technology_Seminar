/* Rect.h */

#ifndef RECT_H
#define RECT_H

typedef struct point {
    int x, y;
} POINT;

typedef struct rect {
    int left, top, right, bottom;
} RECT;

void PrintRect(const RECT* rt);
int Width(const RECT* rt);
int Height(const RECT* rt);

#endif