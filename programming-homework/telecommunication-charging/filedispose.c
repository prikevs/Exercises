#include "telemain.h"

int Useradd(User **rootp, char *name, ll phonenum, char yorn)   /*添加用户信息*/
{
    User *current;
    User *new;
    User *previous;
    
    current = *rootp;
    previous = NULL;

    while(current != NULL ){
        previous = current;
        current = current->next;
    }
    new = (User *)malloc(sizeof(User));
    if (new == NULL){
        perror("malloc");
        return -1;
    }
    strncpy(new->username, name, NAMELEN);
    new->phonenum = phonenum;
    new->yorn = yorn;
    new->next = current;
    new->root = NULL;
    if (previous == NULL)
        *rootp = new;
    else
        previous->next = new;       /*链表添加节点操作*/
    return 0;
}

User *finduser(User *root, ll num)  /*遍历用户链表寻找对应用户，返回节点指针*/
{
    User *current = root;
    while(current != NULL){
        if (current->phonenum == num % MOD)
            return current;
        current = current->next;
    }
    return NULL;
}

int Readcall(User *root, ll callout, ll callin, char *begin, char *end) /*读取话单信息并处理存入链表*/
{
    User *now;
    Time begintime = timehold(begin);
    Time endtime = timehold(end);       /*用自己写的timehold()函数将字符串形式的时间转化成结构体存储*/
    if ((now = finduser(root, callout)) == NULL){   /*寻找相关用户，下同*/
        printf("No such user.\n");
        return -1;
    }
    if (Calladd(&now->root, CALLOUT, callin, &begintime, &endtime) < 0){    /*将通话记录加入对应用户衍生出来的第二维链表，下同*/
        printf("Calladd failed.\n");
        return -1;
    }

    if ((now = finduser(root, callin)) == NULL){
        printf("No such user.\n");
        return -1;
    }
    if (Calladd(&now->root, CALLIN, callout, &begintime, &endtime) < 0){
        printf("Calladd failed.\n");
        return -1;
    }
}

int Calladd(Call **rootp, int type, ll des, Time *begintime, Time *endtime) /*第二维链表添加函数*/
{
    Call *current;
    Call *previous;
    Call *new;
    current = *rootp;
    previous = NULL;
    while(current != NULL && timecmp(&current->begintime, begintime) < 0){  /*按从小到大的时间顺序添加链表，方便差错*/
        previous = current;
        current = current->next;
    }
    new = (Call *)malloc(sizeof(Call)); /*链表添加操作*/
    if (new == NULL)
        return -1;
    new->begintime = *begintime;
    new->endtime = *endtime;
    new->type = type;
    new->des = des;
    new->next = current;
    if (previous == NULL)
        *rootp = new;
    else
        previous->next = new;
    return 0;
}

int Readfromfile(User **userroot)   /*从文件中读取数据*/
{
    FILE *ufp, *cfp;
    signed char ch;
    char username[NAMELEN];
    ll phonenum;
    char yorn;

    ll callout, callin;
    char begintime[DATELEN], endtime[DATELEN];

    char all[ALLLEN];

    int i = 0;

    ufp = fopen(USERDATA, "r");     /*user file pointer 读取用户信息文件*/
    if (ufp == NULL){
        perror(USERDATA);
        return -1;
    }
    while(fgets(all, ALLLEN, ufp) != NULL){
//      printf("%s\n", all);
        i = 0;
        while(!isdigit(all[i])){
            username[i] = all[i];
            i++;
        }
        i--;
        username[i] = 0;
        sscanf(all + i, "%lld %c", &phonenum, &yorn);
        if (Useradd(userroot, username, phonenum, yorn) < 0){   /*调用函数处理*/
            printf("Failed to add element.\n");
            return -1;
        }

    }
    fclose(ufp);

    cfp = fopen(CALLDATA, "r");     /*call file pointer 读取通话记录文件*/
    if (cfp == NULL){
        perror(CALLDATA);
        return -1;
    }
    while(fgets(all, ALLLEN, cfp) != NULL){
//      printf("%s\n", all);
        sscanf(all, "%lld %lld %s %s", &callout, &callin, begintime, endtime);
        if (Readcall(*userroot, callout, callin, begintime, endtime) < 0){  /*调用函数处理*/
            printf("Failed to add element.\n");
            return -1;
        }   
    }
    fclose(cfp);
}

int Savetofile(User *userroot)  /*将计算得到的结果存入文件*/
{
    FILE *fp;
    User *current = userroot;
    fp = fopen(RESULT, "w");
    if (fp == NULL){
        perror(RESULT);
        return -1;
    }
    while(current != NULL){
        fprintf(fp, "%s\t\t%lld\t\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", current->username, current->phonenum, current->monthly, current->caller, current->cityin, current->cityout, current->total);
        current = current->next;
    }
    close(fp);
    return 0;
}
