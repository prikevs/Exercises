#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int LEN = 100010;

int arr[LEN];
bool h[LEN];
queue <int> q;

int main()
{
    int n;
    memset(h, 0, sizeof(h));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    for(int i = 0; i < n; i++) {
        if (arr[i] > n || h[arr[i]] == true) {
            q.push(i); 
        }
        else {
            h[arr[i]] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        if (h[i] == false) {
            int t = q.front();
            q.pop();
            arr[t] = i; 
        } 
    }
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
