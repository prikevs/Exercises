#include "maze.h"

/*随机生成出入口*/
Status Inandout()
{
    Status res;
    int inout[MAXLEN * 4][2];
    int p = 0;
    int i, s, e;
    for(i = 1; i <= n; i++){
        if (map[i][1] == '-'){
            inout[p][0] = i;
            inout[p][1] = 1;
            p++;
        }
        if (map[i][m] == '-'){
            inout[p][0] = i;
            inout[p][1] = m;
            p++;
        }
    }
    for(i = 2; i < m; i++){
        if (map[1][i] == '-'){
            inout[p][0] = 1;
            inout[p][1] = i;
            p++;
        }
        if (map[n][i] == '-'){
            inout[p][0] = n;
            inout[p][1] = i;
            p++;
        }
    }
    if (p < 2){
        memset(&res, -1, sizeof(res));
        return res;
    }
    srand(time(NULL));
    s = 0 + rand() % p;
    e = 0 + rand() % p;
    while(e == s) 
        e = 0 + rand() % p;
    res.s.x = inout[s][1];
    res.s.y = inout[s][0];
    res.e.x = inout[e][1];
    res.e.y = inout[e][0];
    return res;
}
