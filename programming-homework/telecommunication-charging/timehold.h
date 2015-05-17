#ifndef TIMEHOLD_H
#define TIMEHOLD_H

#include <stdio.h>
#include <string.h>

typedef struct Time     /*时间存储结构体*/
{
    int year, month, day, hour, minute, second;
}Time;

Time timehold(const char *time);                    /*将字符串时间转化为结构体*/
int timecmp(const Time *a, const Time *b);          /*时间比较大小函数*/
int timeminusabs(const Time *a, const Time *b);    /*时间相减函数*/
int timetominutes(const Time *a);    /*将时间化成分钟*/

#endif
