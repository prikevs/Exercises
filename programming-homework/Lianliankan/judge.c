#include "llkan.h"

static int vis[M][M];
static int len;
static char **map;
static int ex, ey;
static const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};/*方向向量*/

static int DFS(int sx, int sy, int pre, int cur) /*深度优先搜索判断能否消去*/
{
    int i, nx, ny;
    if (sx == ex && sy == ey)
        return 1;
    if (3 == cur && sx != ex && sy != ey)
        return 0;
    if (4 == cur)
        return 0;
    for(i = 0; i < 4; i++){
        nx = sx + dir[i][0];
        ny = sy + dir[i][1];
        if (nx < 0 || nx > len+1 || ny < 0 || ny > len+1 || \
                vis[nx][ny] || (map[nx][ny] && (nx != ex || ny != ey)))
            continue;
        vis[nx][ny] = 1;
        if (DFS(nx, ny, i, cur + (pre!=i)))
            return 1;
        vis[nx][ny] = 0;
    }
    return 0;
}

int Judge(char **m, int length, Pos a, Pos b){ /*判断函数调用dfs判断能否消去*/
    int x1 = a.x, y1 = a.y;
    len = length, map = m;
    ex = b.x, ey = b.y;
    memset(vis, 0, sizeof(vis));
    if (!map[x1][y1] || !map[ex][ey] || (x1 == ex && y1 == ey) ||\
            map[x1][y1] != map[ex][ey])
        return 0;
    vis[x1][y1] = 1;
    return DFS(x1, y1, -1, 0);
}
