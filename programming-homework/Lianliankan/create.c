#include "llkan.h"

int Createboard(char ***map, int length) /*动态内存分配，创建二维数组*/
{
    int i = 0, j = 0;
    *map = (char **)malloc(sizeof(char *) * (length+2)); 
    if (*map == NULL){
        perror("map");
        return -1;
    }
    for(i = 0; i <= length+1; i++){
        (*map)[i] = (char *)calloc(length+2, sizeof(char)); /*使用calloc申请动态内存并初始化为0*/
        if ((*map)[i] == NULL){
            perror("map[i]");
            return -1;
        }
    }
    return 0;
}

int Createmap(char **map, int length) /*随机生成字符填充map*/
{
    int num = length * length;      /*确定要生成的字符数目*/
    int i, k, j, t;
    int count = 0, position = 0;
    int tnum = num;
    char ch;
    srand(time(NULL));           /*以时间为seed生成随机数列*/
    for(i = 0; i < num/2; i++){
        ch = rand() % MOD + '0';
        for(t = 0; t < 2; t++){
            position = rand() % tnum--;
            count = -1;
            for(j = 1; j <= length; j++){
                for(k = 1; k <= length; k++){
                    if (map[j][k] == 0){
                        count++;
                    }
                    if (count == position){
                        map[j][k] = ch;
                        goto quit;      /*使用goto 语句跳出多层循环*/
                    }
                }
            } 
quit:;
        }
    } 
}

void Destroy(char **map, int length) /*游戏结束，释放内存*/
{
    int i = 0;
    for(i = 0; i <= length+1; i++)
        free(map[i]);
    free(map);
}
