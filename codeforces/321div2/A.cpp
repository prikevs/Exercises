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
int arr[LEN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr+i); 
    }
    int ans = 1;
    for(int i = 0; i < n-1; ++i) {
        if (arr[i+1] >= arr[i]) {
            int temp = 1;
            int j;
            for(j = i+1; j < n; ++j) {
                if (arr[j] >= arr[j-1]) {
                    ++temp; 
                }
                else {
                    break; 
                }
            } 
            i = j - 1;
            if (temp > ans)
                ans = temp;
        } 
    }
    printf("%d\n", ans);
    return 0;
}
