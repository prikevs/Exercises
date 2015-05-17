#include "telemain.h"
#include "datadispose.h"
#include "filedispose.h"
#include "timehold.h"

const double monthly_fee = 25;  /*月租费*/
const double caller_id = 6;     /*来电显示 功能费*/
const double city_in = 0.1;     /*市内通话费用（元/分钟）*/
const double city_out = 0.7;    /*长途通话费用（元/分钟）*/
const int Ban = 4320;  /*作为3天的比较标准*/

void menu() /*打印菜单*/
{
    printf("0.Compute\n");
    printf("1.List\n");
    printf("2.Look for bugs\n");
    printf("3.Save to File\n");
    printf("4.Exit\n");
    printf("Your choice:");
}

int main()
{
    User *userroot = NULL;
    int res;
    int choice = 0;
    if (Readfromfile(&userroot) < 0){   /*读取文件信息*/
        printf("Failed to read from file.\n");
        exit(EXIT_FAILURE);
    }
    while(choice != 4){
        menu();
        scanf("%d", &choice);
        switch(choice){
        case 0: 
            if (Disposedata(userroot) < 0){     /*数据处理*/
                printf("Dispose data error.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 1: 
            if (List(userroot) < 0){            /*列出数据*/
                printf("List data error.\n");
                exit(EXIT_FAILURE);
            } 
            break;
        case 2:
            res = Findbug(userroot);            /*查找话单错误*/
            if (res < 0){
                printf("Findbug error.\n");
                exit(EXIT_FAILURE);
            }
            else{
                printf("There are %d error(s) occurs in the file\n", res);
            }
            break;
        case 3:
            if (Savetofile(userroot) < 0){      /*存入文件*/
                printf("Save to file error.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 4:
            Clear(userroot);                    /*退出释放内存*/
            break;
        default:
            continue;
        }
    }
    return 0;
}

