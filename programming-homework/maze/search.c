#include "maze.h"
#include "show.h"

static int vis[BUFSIZE][BUFSIZE];/*visit数组 用于DFS记录已走路径*/
static int ex, ey;               /*终点*/
static int count = 0;            /*记录解数*/

static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void DFS(int x, int y, int step) /*DFS函数，递归求解*/
{
    int tx, ty;
    int i = 0;
    if (x == ex && y == ey){
        count = Printsol(vis, count);
        return;
    }
    for(i = 0; i < 4; i++){
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (tx < 1 || tx > m || ty < 1 || ty > n || vis[ty][tx] \
                || map[ty][tx] == '#')
            continue;
        vis[ty][tx] = step;
        DFS(tx, ty, step+1);
        vis[ty][tx] = 0;
    }
}

int Search(Pos start, Pos end)
{
    count = 0;
    ex = end.x, ey = end.y;
    memset(vis, 0, sizeof(vis));
    vis[start.y][start.x] = 1;
    DFS(start.x, start.y, 2);
    return count;
}
