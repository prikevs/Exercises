#include "quesbank.h"
#include "exfile.h"

static int *result;
static int total;
static int maxch;

static int Addpaper(Ques *insert, Ques **paper);
static void Analyze(Ques *rootp);

/*生成试卷*/
int Makepaper(Ques *rootp, Ques **paper)
{
    int num, i;
    Ques *current;
    /*调用分析函数分析试题分布情况*/
    Analyze(rootp);
    printf("Numbers of problems you wanna Make into the paper:");
    scanf("%d", &num);
    while (num > total || num < 1){
        printf("Invalid input, be careful about the range(%d ~ %d)\n", 1, total); 
    }
    current = rootp;
    for(i = 0; i< num; i++){
        Addpaper(current, paper);
        current = current->next;
    }
    /*将试卷写入文件*/
    Writepaper(PAPERFILE, ANSFILE, rootp);
    free(result);
}

/*分析函数*/
static void Analyze(Ques *rootp)
{
    int i = 0;
    Ques *current = rootp;
    total = 0, maxch = 0;
    /*遍历链表，确认试题数目*/
    while(current != NULL){
        printf("total=%d\n", total);
        total++;
        if (current->chapter > maxch)
            maxch = current->chapter;
        current = current->next;
    }
    /*哈希方式存储结果*/
    result = (int *)calloc(maxch+1, sizeof(int));
    current = rootp;
    while(current != NULL){
        result[current->chapter]++;
        current = current->next;
    }
    /*输出分析结果*/
    printf("There are %d problems.\nDetails are as follows:\n", total);
    printf("Chapter |Number  \n");
    printf("--------|--------\n");
    for(i = 0; i <= maxch; i++){
        if (result[i] > 0){
            printf("   %d   |  %d    \n", i, result[i]);
            printf("--------|--------\n");
        }
    }
}

    
/*将题目信息加入paper链表尾部*/
static int Addpaper(Ques *insert, Ques **paper)
{
    Ques *current, *new;
    current = *paper;
    new = (Ques *)malloc(sizeof(Ques));
    if (new == NULL){
        perror("Addpaper");
        return -1;
    }
    *new = *insert;
    new->next = NULL;
    if (current == NULL){
        *paper = new; 
        return 0;
    }
    while(current->next != NULL)
        current = current->next;
    current->next = new;
    return 0;
}
