#include "timehold.h"

static int Mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static Feb(int year)
{
    return ((year % 100 != 0 && year % 4 == 0 ) || year % 400 == 0) ? 1:0; 
}

Time timehold(const char *time)
{
    Time res;
    sscanf(time, "%4d%2d%2d%2d%2d%2d", &res.year, &res.month, &res.day, &res.hour, &res.minute, &res.second);
    return res;

}
int timecmp(const Time *a, const Time *b)
{
    return (timetominutes(a) - timetominutes(b));
}

int timeminusabs(const Time *a, const Time *b)
{
    return abs(timetominutes(a) - timetominutes(b));
}

int timetominutes(const Time *a)
{
    int days = 0, minutes = 0, i = 0;
    Mon[2] = Feb(a->year) ? 29 : 28; 
    for(i = 1; i < a->year; i++)
        days += (Feb(i) ? 366 : 365);
    for(i = 1; i < a->month; i++)
        days += Mon[i];
    minutes += a->hour * 60 + a->minute;
    minutes += days * 1440;
    return minutes;
}
