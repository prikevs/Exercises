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
    int a, b, c, d, l;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for(int l = 0; l <= d; l++) {
        int total = a + b + c + l;
        int mid = total / 2 + 1;
        for(int i = a; i <= total - mid; i++) {
            int left = max(mid, i+b);
            int right = min(total-mid+i, total-c);
            if (left > right)
                continue;
       //     cout << i << " " << left << " " << right << endl;
            ans += right-left+1;
        }
    }
    cout << ans << endl;
    return 0;
}
