/*          连连看          */       
/*Copyright 2014 by Kevince.*/

#ifndef LLKAN_H
#define LLKAN_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define char signed char /*方便程序的移植*/

#define NAMELEN 20      /*玩家姓名长度*/

#define LEVELONE 8      /*等级一*/
#define LEVELTWO 10     /*等级二*/
#define LEVELTHREE 12   /*等级三*/
#define M 30    /*vis数组最大大小*/ 
#define MOD 20  /*字符的种类数目*/

#define TIMELIMIT 200

#define FILEDATA "data/topfive.data"    /*文件存放位置*/

typedef struct Pos  /*位置结构体，给判断函数传入选择的两个位置以及各自的字符*/
{
    int x, y;
    char pic; 
}Pos;

struct Data     /*玩家信息*/
{
    char name[NAMELEN];
    int score;
};

struct Top      /*最高排名*/
{
    int n;
    struct Data top[6];
};

extern struct Top topfive; /*声明全局变量*/

#endif
