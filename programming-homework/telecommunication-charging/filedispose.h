int Useradd(User **rootp, char *name, ll phonenum, char yorn);              /*在链表中添加用户信息*/
int Readcall(User *rootp, ll callout, ll callin, char *begin, char *end);   /*处理话单信息*/
int Calladd(Call **root, int type, ll des, Time *begintime, Time *endtime); /*在链表中添加话单信息*/
int Readfromfile(User **userroot);      /*从文件中读取操作的入口函数*/
User *finduser(User *root, ll num);     /*功能函数，用于遍历用户链表查找用户，并返回指向该节点的指针*/
int Savetofile(User *userroot);         /*将信息存入文件*/
