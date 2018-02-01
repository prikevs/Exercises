#include "llkan.h"
#include "create.h"
#include "play.h"
#include "show.h"

void menu();        /*打印菜单*/
int init();         /*初始化*/
int handlescore(int socre);   /*将排名信息存到文件*/

struct Top topfive; /*全局变量 保存名词*/

int main()
{
    char **map;
    int dif = 0;
    int length = 0;
    int score;
    if (init() == 0){
        printf("null");
        memset(&topfive, 0, sizeof(topfive));
    }
    while(1){
        menu();
        scanf("%d", &dif);      /*选择难度*/
        switch(dif){
        case 1: length = LEVELONE; break;
        case 2: length = LEVELTWO; break;
        case 3: length = LEVELTHREE; break;
        case 4: Showscore(0); break;
        case 5: exit(EXIT_SUCCESS); break;
        default: length = LEVELONE;
        }
        if (dif == 4)
            continue;
        if (Createboard(&map, length) < 0){     /*调用函数创建动态二维数组*/
            printf("Failed to create board.\n"); 
            exit(EXIT_FAILURE);
        }
        if (Createmap(map, length) < 0){        /*调用函数随机生成字符*/
            printf("Failed to create map.\n");
            exit(EXIT_FAILURE);
        }
        score = Startgame(map, length);           /*启动游戏*/
        if (score < 0){
            printf("Failed to start game.\n");
            exit(EXIT_FAILURE);
        }
        else if (handlescore(score) < 0){                  /*存储文件*/
            printf("Failed to save to file.\n");
            exit(EXIT_FAILURE);
        }
        Destroy(map, length);                   /*游戏结束释放内存*/
    } 
    exit(EXIT_SUCCESS);
}

void menu()
{
    printf("Difficulty:\n");
    printf("1.Level one\t(%d * %d)\n", LEVELONE, LEVELONE);
    printf("2.Level two\t(%d * %d)\n", LEVELTWO, LEVELTWO);
    printf("3.Level three\t(%d * %d)\n", LEVELTHREE, LEVELTHREE);
    printf("4.Show ranklist\n");
    printf("5.Exit\n");
    printf("Your choice:");
}

int init()
{
    FILE *fp;
    fp = fopen(FILEDATA, "rb");       /*二进制方式以读的方式打开文件*/ 
    if (fp == NULL)
        return 0;
    fread(&topfive, sizeof(topfive), 1, fp);/*将文件信息读入内存*/
    printf("topfive.n=%d\n", topfive.n);
    fclose(fp);
    return 1;
}

static int cmp(const void *a, const void *b)    /*qsort函数需要使用的cmp函数，用于排序最终成绩*/
{
    return (*(struct Data *)b).score - (*(struct Data *)a).score;
}

int handlescore(int score)  /*处理成绩信息并与原来成绩比较*/
{
    FILE *fp;
    printf("You got %d points.\n", score);
    if (score == 0)
        return 0;
    topfive.top[topfive.n].score = score;
    printf("Input your name:");
    scanf("%s", topfive.top[topfive.n].name);
    topfive.n++;
    qsort(topfive.top, topfive.n, sizeof(topfive.top[0]), cmp);     /*qsort包含于stdlib.h函数库中 用来排序*/
    printf("%s %d\n", topfive.top[0].name, topfive.top[0].score);
    if (topfive.n > 5)
        topfive.n = 5;
    fp = fopen(FILEDATA, "wb");     /*二进制方式以写的方式打开文件*/
    if (fp == NULL){
        perror("topfive.data");
        return -1;
    }
    fwrite(&topfive, sizeof(topfive), 1, fp);/*将排名信息写入文件*/
    fclose(fp);
    return 0;
}
