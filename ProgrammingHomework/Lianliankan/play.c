#include "llkan.h"
#include "show.h"
#include "judge.h"

static void restart(char **map, int length)     /*实现restart功能，重新排序*/
{
    char now, end, tmp;
    int first = 1;
    int x, y;
    int i, j;
    for(i = 1; i <= length; i++){
        for(j = 1; j <= length; j++){
            if (map[i][j] > 0){
                if (first){
                    first = 0;
                    x = i, y = j;
                    now = map[i][j];
                    continue;
                } 
                tmp = map[i][j];
                map[i][j] = now;
                now = tmp;
            } 
        }
    }
    map[x][y] = now;
}

int Startgame(char **map, int length)   /*启动游戏*/
{
    Pos a, b;
    int score = 0;
    int count = 0;      /*用于统计已经消去的数目*/
    clock_t s, e;
    while(1){
        if (count == length * length){  /*如果全部消去则游戏结束*/
            printf("Success!\n");
            break;
        }
        Showscore(score);   /*打印分数和排名信息*/
        Showmap(map, length);   /*打印界面*/
        s = clock();
        printf("Choose two points (one point is described as row and column)\n");
        printf("Use space to split:\n");
        printf("use -1 -1 -1 -1 to exit\n");
        printf("use 0 0 0 0 to restart\n"); /*说明，输入两个点的坐标，行、列，以空格隔开。如果输入-1 -1 -1 -1则退出游戏，如果输入0 0 0 0调用restart函数重新排序*/
        scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y); 
        e = clock();
        if ((e - s) > TIMELIMIT){
            printf("Time out.\n");
            break;
        }
        if (a.x == -1 && a.y == -1 && b.x == -1 && b.y == -1)
            break;
        else if (a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0){
            restart(map, length);
            continue;
        }
        if (a.x < 1 || a.x > length || b.x < 1 || b.x > length){/*防止输入不合法的情况*/
            printf("invalid input.\n");
            continue;
        }
        a.pic = map[a.x][a.y], b.pic = map[b.x][b.y];
        if (Judge(map, length, a, b)){  /*调用判断函数判断这两点能不能消去*/
            count += 2; /*消去个数统计*/
            e = clock();
            score += (TIMELIMIT - (e - s)); /*分数统计*/
            printf("yes\n");
            map[a.x][a.y] = map[b.x][b.y] = 0; /*消去后位置清零*/
            continue;   /*重新开始循环*/
        }
        printf("no\n"); /*不能消去输出no*/
    } 
    return score;
}
