#include "maze.h"

/*从文件中读取迷宫同时判断地图合法性*/
int Readfromfile(char *filename)
{
    FILE *fp;
    char buffer[BUFSIZE];
    memset(map, 0, sizeof(map));
    fp = fopen(filename, "r");
    if (fp == NULL){
        return -1;
    }
    while(fgets(buffer, BUFSIZE-1, fp) != NULL){
        if (strlen(buffer) > MAXLEN)
            return -2;
        if (m != 0 && strlen(buffer) -1 != m)
            return -3;
        m = strlen(buffer) - 1;
        strncpy(map[++n] + 1, buffer, m);
    }
    return 0;
}
