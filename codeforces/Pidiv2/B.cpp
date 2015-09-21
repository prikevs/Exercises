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

const int LEN = 1000010;
const int SLEN = 10;

bool arr[LEN];
char str[LEN];
bool mark[110];

int main()
{
    memset(arr, 0, sizeof(arr));
    memset(mark, 0, sizeof(mark));
    int n;
    scanf("%d", &n);
    getchar();
    int ans = 0;
    int last = 0;
    int res[110];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < n; i++) {
        gets(str);
        int tmp;
        int now = 0;
        sscanf(str+2, "%d", &tmp);
 //       printf("tmp=%d\n", tmp);
        if (str[0] == '+') {
            if (arr[tmp] == false) {
                res[i+1] = res[i] + 1;
            } 
            arr[tmp] = true;
        }
        else if (str[0] == '-') {
            if (arr[tmp] == false) {
                for(int j = 0; j <= i; j++) {
                    res[j]++; 
                }
                res[i+1] = res[i] - 1;
            } 
            else {
                arr[tmp] = false;
                res[i+1] = res[i]-1;
            }
        }
    }
    for(int i = 0; i <= n; i++ ) {
        if (res[i] > ans)
            ans = res[i];
    }
//    printf("ans=%d, last=%d\n", ans, last);
    printf("%d\n", ans);
    return 0;
}
