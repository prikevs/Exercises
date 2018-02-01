#include "quesbank.h"

/*从文件中读取内容*/
int Readfromfile(char *filename, Ques **rootp)
{
    FILE *fp;
    int count = 0;
    Ques *current, *previous, *new, *ppre;
    fp = fopen(filename, "r");
    if (fp == NULL){        /*如果文件不存在则返回主函数*/
        perror(filename);
        return 0;
    }

    /*读取文件信息*/
    while(!feof(fp)){
        new = (Ques *)malloc(sizeof(Ques));
        if (new == NULL){
            perror("new");
            return -1;
        }
        new->chapter = new->num = 0;
        fscanf(fp, "%2d%3d%*c", &new->chapter, &new->num);
        if (new->chapter == 0 && new->num == 0)
            break;
        fgets(new->tip, MAXLEN-1, fp);
        new->tip[strlen(new->tip) - 1] = 0;

        fscanf(fp, "%d%*c", &new->difficulty);

        fgets(new->description, MAXLEN-1, fp);
        new->description[strlen(new->description) - 1] = 0;

        fgets(new->option, MAXLEN-1, fp);
        new->option[strlen(new->option) - 1] = 0;

        fscanf(fp, "%c", &new->ans);

        fscanf(fp, "%d%*c", &new->papern);

        new->next = NULL;

        /*根据记录的chapter和num来插入链表*/
        current = *rootp;
        previous = NULL;
//        ppre = NULL;
        while(current != NULL && (new->chapter > current->chapter ||\
                    (new->chapter == current->chapter &&\
                     new->num > current->num))){
//            ppre = previous;
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
            *rootp = new;
        else
            previous->next = new;
        new->next = current;
    }
    fclose(fp);
}

int Writetofile(char *filename, Ques *rootp) /*写入文件*/
{
    FILE *fp;
    Ques *current;
    fp = fopen(filename, "w");
    /*文件打开失败则报错退出*/
    if (fp == NULL){
        perror(filename);        
        return -1;
    }
    /*遍历链表，同时将信息输入文件*/
    current = rootp;
    while(current != NULL){
        fprintf(fp, "%02d%03d\n", current->chapter, current->num);
        fputs(current->tip, fp);
        fputc('\n', fp);
        fprintf(fp, "%d\n", current->difficulty);
        fputs(current->description, fp);
        fputc('\n', fp);
        fputs(current->option, fp);
        fputc('\n', fp);
        fprintf(fp, "%c\n", current->ans);
        fprintf(fp, "%d\n", current->papern);
        
        current = current->next;
    }
    fclose(fp);
}


/*释放内存*/
int Destroy(Ques *rootp)
{
    Ques *current, *now;
    current = rootp;
    while(current != NULL){
        now = current;
        current = current->next;
        free(now);
    }
}

/*将试卷信息同时写进试卷文件和答案文件*/
int Writepaper(char *paperfile, char *ansfile, Ques *rootp)
{
    FILE *pp, *ap;
    Ques *current;
    int index = 1;
    int *paperinfo;
    double dif = 0;
    int total = 0;
    int i = 0;

    paperinfo = (int *)calloc(100, sizeof(int));
    current = rootp; 
    while(current != NULL){
        dif += current->difficulty;
        paperinfo[current->chapter]++;
        total++;
        current = current->next;
    }

    pp = fopen(paperfile, "w"); 
    if (pp == NULL){
        perror("paperfile");
        return -1;
    }
    ap = fopen(ansfile, "w");
    if (ap == NULL){
        perror("ansfile");
        return -1;
    }
    fprintf(ap, "Degree of difficulty: %.2f\n", dif/total);
    fprintf(ap, "Chapter:\t");
    for(i = 0; i < 100; i++){
        if (paperinfo[i])
            fprintf(ap, "%d\t", i);
    }
    fprintf(ap, "\nNumber:\t");
    for(i = 0; i < 100; i++){
        if (paperinfo[i])
            fprintf(ap, "%d\t", paperinfo[i]);
    }
    fprintf(ap, "\n\n");
    /*遍历链表，写入信息*/
    current = rootp;
    while(current != NULL){
        fprintf(pp, "%d.", index);
        fputs(current->description, pp);
        fputc('\n', pp);
        fputs(current->option, pp);
        fputc('\n', pp);

        fprintf(ap, "%d.", index);
        fprintf(ap, "%c\n", current->ans);
        index++;
        current = current->next;
    }
    fclose(pp);
    fclose(ap); 
    free(paperinfo);
}
