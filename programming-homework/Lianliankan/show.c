#include "llkan.h"

void Showmap(char **map, int length)       /*打印所有字符*/
{
    int i, j;
    char ch;
    printf("\n%02d   ", 0);
    for(i = 1; i <= length; i++)
        printf("%02d ", i);
    printf("\n\n");
    for(i = 1; i <= length; i++){
        printf("%02d    ", i);
        for(j = 1; j <= length; j++){
            if (map[i][j] == 0)
                ch = ' ';
            else
                ch = map[i][j];
            printf("%c  ", ch);
        }
        printf("\n");
    }
    printf("\n");
}

void Showscore(int score)   /*打印分数*/
{
    int i = 0;
    printf("\nRanklist:\n");
    for(i = 0; i < 5; i++){
        if (i < topfive.n)
            printf("No.%d %s %d\n", i+1, topfive.top[i].name, topfive.top[i].score);
        else
            printf("--- --- ---\n");
    }
    if (score > 0)
        printf("Your score:%d\n", score);
}
