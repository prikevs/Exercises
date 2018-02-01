#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int LEN = 1000010;
const int MOD = 10000;
int ans[LEN];
int sum[LEN];

void init()
{
    memset(ans, 0, sizeof(ans));
    memset(sum, 0, sizeof(sum));
    ans[0] = ans[1] = 1, ans[2] = 2;
    sum[0] = 1, sum[1] = 2, sum[2] = 4;
    for(int i = 3; i < LEN; ++i) {
        ans[i] = (ans[i-1] + ans[i-2] + sum[i-3]*2) % MOD;
        sum[i] = (sum[i-1] + ans[i]) % MOD;
    }
}

int main()
{
    init(); 
    int a;
    while(~scanf("%d", &a)) {
        printf("%d\n", ans[a]);
    }
    return 0;
}
