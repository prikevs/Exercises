#include "quesbank.h"

/*添加操作*/
int Add(Ques **rootp)
{
    Ques *current, *previous, *new;
    char op[4];
    /*申请新节点*/
    new = (Ques *)malloc(sizeof(Ques));
    if (new == NULL){
        perror("Add");
        return -1;
    }    
    /*录入新试题信息*/
    printf("Chapter:");
    scanf("%d%*c", &new->chapter);

    printf("Tip:");
    fgets(new->tip, MAXLEN-1, stdin);
    new->tip[strlen(new->tip) - 1] = 0;

    printf("Difficulty:");
    scanf("%d%*c", &new->difficulty);

    printf("Description:");
    fgets(new->description, MAXLEN-1, stdin);
    new->description[strlen(new->description) - 1] = 0;

    printf("Options:");
    fgets(new->option, MAXLEN-1, stdin);
    new->option[strlen(new->option) - 1] = 0;

    printf("Answer:");
    fgets(op, 3, stdin);
    new->ans = op[0];
    new->num = 0x7fffffff;

    new->papern = 0;

    /*注意next值的初始化*/
    new->next = NULL;

    /*遍历链表寻找适当位置插入节点*/
    /*注意处理num值*/
    current = *rootp;
    previous = NULL;
    while(current != NULL && (new->chapter > current->chapter ||\
            (new->chapter == current->chapter &&\
             new->num > current->num))){
        previous = current;
        current = current->next;
    }
    if (previous == NULL){
        *rootp = new;
        new->num = 1;
    }
    else{
        previous->next = new;
        new->num = previous->num + 1;
    }
    new->next = current;
        
    return 0;
}

/*修改操作*/
int Modify(Ques *rootp)
{
    char buffer[MAXLEN];
    char yn[4], op[4];
    int ch, num;
    Ques *current;

    /*输入试题ID*/
    printf("Please input the ID of the problem that you want to MODIFY.\n");    
    fgets(buffer, MAXLEN-1, stdin);
    sscanf(buffer, "%2d%3d", &ch, &num);
    
    /*遍历链表寻找相应试题*/
    current = rootp;
    while(current != NULL && (ch != current->chapter || num != current->num))
        current = current->next;
    if (current == NULL){
        printf("This problem does NOT exist.\n");
        return -1;
    }

    /*对于每项内容询问是否进行修改*/
    printf("Modify TIP?(y or n):"); 
    fgets(yn, 3, stdin);
    if (yn[0] == 'y'){
        printf("New TIP:");
        fgets(current->tip, MAXLEN-1, stdin);
        current->tip[strlen(current->tip) - 1] = 0;
    }

    printf("Modify DIFFICULTY?(y or n):"); 
    fgets(yn, 3, stdin);
    if (yn[0] == 'y'){
        printf("New DIFFICULTY:");
        scanf("%d%*c", &current->difficulty);
    }

    printf("Modify DESCRIPTION?(y or n):"); 
    fgets(yn, 3, stdin);
    if (yn[0] == 'y'){
        printf("New DESCRIPTION:");
        fgets(current->description, MAXLEN-1, stdin);
        current->description[strlen(current->description) - 1] = 0;
    }

    printf("Modify OPTION?(y or n):"); 
    fgets(yn, 3, stdin);
    if (yn[0] == 'y'){
        printf("New OPTION:");
        fgets(current->option, MAXLEN-1, stdin);
        current->option[strlen(current->option) - 1] = 0;
    }

    printf("Modify ANSWER?(y or n):");
    fgets(yn, 3, stdin);
    if (yn[0] == 'y'){
        printf("New ANSWER:");
        fgets(op, 3, stdin);
        current->ans = op[0];
    }
    return 0;
}

/*删除操作*/
int Delete(Ques **rootp)
{
    char buffer[MAXLEN];
    int ch, num;
    int temp;
    Ques *current, *previous, *now;

    /*输入试题ID*/
    printf("Please input the ID of the problem that you want to MODIFY.\n");    
    fgets(buffer, MAXLEN-1, stdin);
    sscanf(buffer, "%2d%3d%*c", &ch, &num);
    
    /*遍历链表寻找相应试题*/
    current = *rootp;
    previous = NULL;
    
    while(current != NULL && (ch != current->chapter || num != current->num)){
        previous = current;
        current = current->next;
    }
    if (current == NULL){
        printf("This problem does NOT exist.\n");
        return -1;
    }
    if (previous == NULL){
        *rootp = current->next;
    }
    else
        previous->next = current->next;
    now = current;

    temp = current->chapter; 
    /*注意previous为空指针的情况（删除头节点时）*/
    if (previous != NULL){
        current = previous->next;
    }
    else{
        current = *rootp;
    }
    while(current != NULL && current->chapter == temp){
        current->num--;
        current = current->next;
    }
    free(now);
}
