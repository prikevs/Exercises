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

const int LEN = 200020;

int arr[LEN];
int query[LEN];

int main()
{
    int n, k, a;
    scanf("%d %d %d", &n, &k, &a);
    int m;
    scanf("%d", &m);
    int ans = -1;

    for(int i = 0; i < m; i++) {
        scanf("%d", query+i); 
        if (ans != -1) {
            break; 
        }
    }
    printf("%d\n", ans);
    return 0;
}
