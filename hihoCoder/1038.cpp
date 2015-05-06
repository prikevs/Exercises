#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int N = 510;
const int M = 100010;

int dp[M];
int need[N];
int value[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", need+i, value+i); 
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= need[i]; j--) {
            dp[j] = max(dp[j], dp[j-need[i]]+value[i]);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
