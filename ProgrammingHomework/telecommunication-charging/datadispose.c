#include "telemain.h"
#include "timehold.h"

int Disposedata(User *userroot)     /*数据处理输出话费单*/
{
    Call *ccurrent;
    User *ucurrent = userroot;
    int t;
    while(ucurrent != NULL){    /*遍历用户链表*/
        ucurrent->monthly = monthly_fee;    /*月租费*/
        if (ucurrent->yorn == 'Y')          /*来电显示功能费判断*/
            ucurrent->caller = caller_id;
        else
            ucurrent->caller = 0;
        ucurrent->cityin = 0;       /*初始化市内通话费用*/
        ucurrent->cityout = 0;      /*初始化长途通话费用*/

        ccurrent = ucurrent->root;  /*准备开始遍历该用户的通话记录*/

        while(ccurrent != NULL){
            if (ccurrent->type == CALLOUT){     /*如果是拨出电话则统计*/
                t = timetominutes(&ccurrent->endtime) - timetominutes(&ccurrent->begintime);    /*调用自己编写的函数算出间隔时间（分钟）*/
                if (ccurrent->des >= MOD)   /*MOD用于判断市内电话或者长途电话*/
                    ucurrent->cityout += t * city_out;
                else
                    ucurrent->cityin += t * city_in;    
            }       
            ccurrent = ccurrent->next;
        }
        ucurrent->total = ucurrent->monthly + ucurrent->caller + ucurrent->cityin + ucurrent->cityout;  /*计算该用户电话费总和*/
        printf("%s  \t%lld\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", ucurrent->username, ucurrent->phonenum, \
                ucurrent->monthly, ucurrent->caller, ucurrent->cityin,\
                ucurrent->cityout, ucurrent->total);
        ucurrent = ucurrent->next;  
    }   
    return 0;
}

void Clear(User *userroot)      /*退出时释放内存*/
{
    User *ucurrent, *unow;
    Call *ccurrent, *cnow;
    ucurrent = userroot;
    while(ucurrent != NULL){
        ccurrent = ucurrent->root;
        while(ccurrent != NULL){
            cnow = ccurrent;
            ccurrent = ccurrent->next;
            free(cnow);
        }
        unow = ucurrent;
        ucurrent = ucurrent->next;
        free(unow);
    }
}

int Findbug(User *userroot)     /*找出不合理的记录输出并删除*/
{
    FILE *fp;
    int count = 0;
    int t;
    User *ucurrent;
    Call *ccurrent, *now, *previous;
    ucurrent = userroot;
    fp = fopen(ERROROUT, "w");
    if (fp == NULL){
        perror("ERROROUT");
        return -1;
    }
    while(ucurrent != NULL){
        ccurrent = ucurrent->root;
        previous = NULL;
        while(ccurrent != NULL){
            t = timeminusabs(&ccurrent->begintime, &ccurrent->endtime);
            if (t > Ban){     /*用自己写的timecmp()函数比较时间大小，Ban 是全局变量，是3天，作为判断标准*/
                if (ccurrent->type == CALLOUT){ /*由于错误话单主要影响呼出用户的电话费的计费，所以只删除呼出用户的数据, 下同*/
                    count++;
                    fprintf(fp, "%lld %lld %04d%02d%02d%02d%02d%02d", ucurrent->phonenum, ccurrent->des, \
                            ccurrent->begintime.year, ccurrent->begintime.month, ccurrent->begintime.day,\
                            ccurrent->begintime.hour, ccurrent->begintime.minute, ccurrent->begintime.second);
                }
                if (previous == NULL)
                    ucurrent->root = ccurrent->next;
                else
                    previous->next = ccurrent->next;
                now = ccurrent;
                ccurrent = ccurrent->next;  
                free(now);              /*删除链表中有着错误数据的节点，下同*/
                continue;
            }   
            if (ccurrent->next != NULL && timecmp(&ccurrent->endtime, &ccurrent->next->begintime) > 0){ /*判断通话时间通过三天的情况*/
                if (ccurrent->type == CALLOUT){
                    count++;
                    fprintf(fp, "%lld %lld %04d%02d%02d%02d%02d%02d", ucurrent->phonenum, ccurrent->des, \
                            ccurrent->begintime.year, ccurrent->begintime.month, ccurrent->begintime.day,\
                            ccurrent->begintime.hour, ccurrent->begintime.minute, ccurrent->begintime.second);
                }
                if (previous == NULL)
                    ucurrent->root = ccurrent->next;
                else
                    previous->next = ccurrent->next;
                now = ccurrent;
                ccurrent = ccurrent->next;  
                free(now);
                continue;
            }
            previous = ccurrent;
            ccurrent = ccurrent->next;
        }
        ucurrent = ucurrent->next;
    }
    close(fp);
    return count;
}

int List(User *userroot)    /*显示链表中存储的信息*/
{
    User *ucurrent;
    Call *ccurrent;
    ucurrent = userroot;
    while(ucurrent != NULL){
        ccurrent = ucurrent->root;
        printf("Name:\t%s\n", ucurrent->username);
        printf("Phone:\t%lld\n", ucurrent->phonenum);
        printf("YorN:\t%c\n", ucurrent->yorn);
        printf("Chat to\t begintime\t\t endtime\n");
        while(ccurrent != NULL){
            printf("%lld\t%04d%02d%02d%02d%02d%02d\t\t%04d%02d%02d%02d%02d%02d\n", ccurrent->des, ccurrent->begintime.year,\
                    ccurrent->begintime.month, ccurrent->begintime.day, ccurrent->begintime.hour,\
                    ccurrent->begintime.minute, ccurrent->begintime.second,\
                    ccurrent->endtime.year, ccurrent->endtime.month, ccurrent->endtime.day,\
                    ccurrent->endtime.hour, ccurrent->endtime.minute, ccurrent->endtime.second);    
            ccurrent = ccurrent->next;
        }
        printf("\n");
        ucurrent = ucurrent->next;
    }   
}
