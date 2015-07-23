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

int main()
{
    int a[2], b[2], c[2];
    scanf("%d %d %d %d %d %d", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1]);
    sort(a, a+2);
    sort(b, b+2); 
    sort(c, c+2);
    int t1, t2;
    t1 = b[0] + c[1];
    t2 = max(b[1], c[0]);
    if (max(t1, t2) <= a[1] && min(t1, t2) <= a[0]) {
        printf("YES\n");
        return 0;
    }

    t1 = b[0] + c[0];
    t2 = max(b[1], c[1]);
    if (max(t1, t2) <= a[1] && min(t1, t2) <= a[0]) {
        printf("YES\n");
        return 0;
    }

    t1 = b[1] + c[0];
    t2 = max(b[0], c[1]);
    if (max(t1, t2) <= a[1] && min(t1, t2) <= a[0]) {
        printf("YES\n");
        return 0;
    }

    t1 = b[1] + c[1];
    t2 = max(b[0], c[0]);
    if (max(t1, t2) <= a[1] && min(t1, t2) <= a[0]) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");

    return 0;
}
