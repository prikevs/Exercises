/*********************************************
*        电信计费系统 （程序设计实验）       *
*         Copyright 2014 by Kevince          *
*               18 Nov 2014                  *
**********************************************/

/************************************************************************
                            数据存储结构                                *
                             二维链表                                   *
                                                                        *
   *userroot                                                            *
       |                                                                *
----------------  ----------------  ----------------                    *
|用户信息|*root|->|话单信息|*next|->|话单信息|*next|-> ......           *
|姓名号码|     |  ----------------  ----------------                    *
|...     |     |                                                        *
----------------                                                        *
|*next         |                                                        *
----------------                                                        *
       |                                                                *
----------------  ----------------  ----------------                    *
|用户信息|*root|->|话单信息|*next|->|话单信息|*next|-> ......           *
|姓名号码|     |  ----------------  ----------------                    *
|...     |     |                                                        *
----------------                                                        *
|*next         |                                                        *
----------------                                                        *
       |                                                                *
    ......                                                              *
                                                                        *
*************************************************************************/



#ifndef TELE_H
#define TELE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "timehold.h"

#define NAMELEN 30
#define DATELEN 30
#define ALLLEN 110

#define CALLIN 1
#define CALLOUT 0

#define MOD 100000000

#define USERDATA "data.in/user.in"
#define CALLDATA "data.in/call.in"
#define ERROROUT "data.out/bugs.out"
#define RESULT "data.out/result.out"


typedef long long ll;

typedef struct Call     /*话单信息结构体*/
{
    ll des;
    int type;
    Time begintime;
    Time endtime;   
    struct Call *next;
}Call;

typedef struct User     /*用户信息结构体*/
{
    char username[NAMELEN];
    ll phonenum;
    char yorn;  
    struct Call *root;
    struct User *next;
    double monthly;
    double caller;
    double cityin;
    double cityout;
    double total;
}User;

/*声明全局变量*/
extern const double monthly_fee;
extern const double caller_id;
extern const double city_in;
extern const double city_out;
extern const int Ban;


#endif
