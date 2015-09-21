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
int ans[LEN][2];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr+i); 
    } 
    int first = arr[0];
    int last = arr[n-1];
    ans[0][0] = arr[1] - arr[0];
    ans[0][1] = arr[n-1] - arr[0];
    ans[n-1][0] = arr[n-1] - arr[n-2];
    ans[n-1][1] = arr[n-1] - arr[0];
    for(int i = 1; i < n-1; i++) {
        ans[i][0] = min(arr[i]-arr[i-1], arr[i+1]-arr[i]);
        ans[i][1] = max(arr[i]-first, last-arr[i]);
    } 
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]); 
    }
    return 0;
}
