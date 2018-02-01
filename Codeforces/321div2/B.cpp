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

const int LEN = 100010;

struct Friend {
    int m, s;
}friends[LEN];

ll res[LEN];

bool cmp(struct Friend a, struct Friend b)
{
    return a.m < b.m;
}

bool cmp2(struct Friend a, struct Friend b)
{
    return a.m < b.m;
}

int main()
{
    int n, d;
    memset(friends, 0, sizeof(friends));
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &friends[i].m, &friends[i].s); 
    }
    sort(friends, friends+n, cmp);
    struct Friend temp;
    for(int i = 0; i < n; ++i) {
        temp.m = friends[i].m + d;
        res[i] += friends[i].s;
        int pos = lower_bound(friends, friends+n, temp, cmp2) - friends; 
//        cout << "temp.m=" << temp.m << endl;
//        cout << "pos=" << pos << endl;
        res[pos] -= friends[i].s;
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        res[i] += res[i-1]; 
        if (res[i] > ans)
            ans = res[i];
    }
    if (res[0] > ans)
        ans = res[0];
    cout << ans << endl;
    return 0;
}
