#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXLEN 80

typedef struct Pos
{
    int x, y;
}Pos;

typedef struct Status
{
    Pos s, e;
}Status;

extern char map[BUFSIZE][BUFSIZE];
extern int m, n;

#endif
