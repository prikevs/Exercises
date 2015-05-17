#include "quesbank.h"

static void Menu();
static void Chapter();
static void Difficulty();

/*查询主函数*/
void Query(Ques *rootp)
{
    int choice;
    Menu();
    scanf("%d%*c", &choice);
    switch(choice){
    case 1: Chapter(rootp); break;
    case 2: Difficulty(rootp); break;
    default:
            printf("Invalid choice.\n");
            return;
    } 
}

/*打印查询菜单*/
static void Menu()
{
    printf("1.Based on chapter.\n");
    printf("2.Based on difficulty.\n");
    printf("Your choice:");
}

/*根据章节查询*/
static void Chapter(Ques *rootp)
{
    int query;
    int flag = 0;
    Ques *current;
    /*输入查询内容并遍历链表，输出符合项*/
    printf("Which chapter do you want to list?");
    scanf("%d%*c", &query); 
    current = rootp;
    while(current != NULL){
        if (current->chapter == query){
            flag = 1;
            printf("Num:        %02d%03d\n", current->chapter, current->num);
            printf("Tip:        ");
            puts(current->tip);
            printf("Difficulty: %d\n", current->difficulty);
            printf("Description:");
            puts(current->description);
            printf("Option:     ");
            puts(current->option);
            printf("Answer:     %c\n", current->ans);
            printf("Chosen(s):  %d\n", current->papern);
        }
        current = current->next;
    } 
    /*没找到符合条件的题目则输出错误信息*/
    if (!flag)
        printf("Sorry, this chapter does NOT exist.\n");
}

/*根据难度查询*/
static void Difficulty(Ques *rootp)
{
    int query;
    int flag = 0;
    Ques *current;
    /*输入查询内容并遍历链表，输出符合项*/
    printf("Which difficulty do you want to list?");
    scanf("%d%*c", &query); 
    current = rootp;
    while(current != NULL){
        if (current->difficulty == query){
            flag = 1;
            printf("Num:        %02d%03d\n", current->chapter, current->num);
            printf("Tip:        ");
            puts(current->tip);
            printf("Difficulty: %d\n", current->difficulty);
            printf("Description:");
            puts(current->description);
            printf("Option:     ");
            puts(current->option);
            printf("Answer:     %c\n", current->ans);
            printf("Chosen(s):  %d\n", current->papern);
        }
        current = current->next;
    } 
    /*没找到符合条件的题目则输出错误信息*/
    if (!flag)
        printf("Sorry, this difficulty does NOT exist.\n");
}
