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

int dp[N][M];
int need[N];
int value[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", need+i, value+i); 
    }
    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if (j < need[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-need[i]] + value[i], dp[i-1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
