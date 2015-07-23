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
    int arr[6];
    for(int i = 0; i < 6; i++) {
        scanf("%d", arr+i); 
    }
    int minus = 0;
    for(int i = 0; i < 6; i += 2) {
        minus += arr[i] * arr[i]; 
    }
    int b = arr[1] + arr[0] + arr[2];
    int ans = b * b - minus;
    printf("%d\n", ans);
    return 0;
}
