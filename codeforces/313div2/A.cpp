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
int arr[LEN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr+i); 
    }
    sort(arr, arr+n);
    if (arr[0] > 1) {
        printf("1\n"); 
        return 0;
    }
    if (arr[0] == 1) {
        printf("-1\n"); 
        return 0;
    }
    return 0;
}
