#include "quesbank.h"
#include "exfile.h"
#include "operate.h"
#include "paper.h"
#include "query.h"

static void Menu();

/*主函数*/
int main()
{
    char filename[MAXLEN];
    Ques *rootp = NULL;
    Ques *paper = NULL;
    int choice = 0;
    int res = 0;
    printf("Please input the filename:");
    scanf("%s", filename);
    if (Readfromfile(filename, &rootp) < 0){
        printf("Failed to read from file.\n");
        return 0;
    }    
    /*主界面循环*/
    while(choice != 6){
        Menu();
        scanf("%d%*c", &choice);
        switch(choice){
        case 1: Query(rootp);
                break;
        case 2: res = Add(&rootp);
                if (res < 0)
                    printf("Failed to add a problem.\n");
                break;
        case 3: res = Modify(rootp);
                if (res < 0)
                    printf("Failed to modify a problem.\n");
                break;
        case 4: res = Delete(&rootp);
                if (res < 0)
                    printf("Failed to delete a problem.\n");
                break;
        case 5: res = Makepaper(rootp, &paper);
                if (res < 0)
                    printf("Failed to make a paper.\n");
                break;
        case 6: break;
        default: 
                continue;
        }
    }
    /*退出时将内存信息写入文件并释放内存*/
    Writetofile(filename, rootp);
    Destroy(rootp);
    return 0;
}

/*打印菜单*/
static void Menu()
{
    printf("1.Query\n");
    printf("2.Add a problem\n");
    printf("3.Modify a problem\n");
    printf("4.Delete a problem\n");
    printf("5.Make paper\n");
    printf("6.Exit\n");
    printf("Your choice:");
}
