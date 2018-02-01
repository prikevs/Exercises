#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

double INF = 0.000001;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

int main()
{
    double t, s, q, now;
    cin >> t >> s >> q;
    now = s;
    double v = (q-1) / q;
    int ans = 0;
    while(now < t - INF) {
        now = now / (1-v); 
        ans++;
    }
    cout << ans << endl;
    return 0;
}
