#include "maze.h"
#include "init.h"
#include "search.h"
#include "fdispose.h"
#include "show.h"

char map[BUFSIZE][BUFSIZE]; /*地图*/
int m, n; /*n代表行， m代表列*/

int main(void)
{
    char filename[MAXLEN] = "map.txt";
    Status inout;
    printf("Please input the filename:");    
//    scanf("%s", filename);

    /*从文件中读取迷宫*/
    if (Readfromfile(filename) < 0){
        printf("Failed to read from file\n");
        return 0;
    }
    
    /*生成出入口*/
    inout = Inandout();
    if (inout.s.x == -1){
        printf("Invalid map.\n");
        return 0;
    }
    printf("%d %d\n%d %d\n", inout.s.x, inout.s.y, inout.e.x, inout.e.y);
    /*将出入口标示 'S'即start, 'E'即end*/
    map[inout.s.y][inout.s.x] = 'S';
    map[inout.e.y][inout.e.x] = 'E';
    Showmap();

    /*搜寻合法路径*/
    if (Search(inout.s, inout.e) < 1){
        printf("There is no solution.\n");
        return 0;
    }
    return 0;
}
