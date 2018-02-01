#include "maze.h"

int Printsol(int vis[][BUFSIZE], int count) /*综合visit数组打印解*/
{
    int i, j;
    printf("Solution %d:\n", ++count);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if (vis[i][j] != 0)
                printf("%3d", vis[i][j]);
            else
                printf("%3c", map[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
    return count;
}

void Showmap() /*打印地图*/
{
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%c", map[i][j]);    
        }
        printf("\n");
    }
    printf("\n");
}
