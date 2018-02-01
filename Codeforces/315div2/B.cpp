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
struct A
{
    int a, b;
}arr[LEN];

bool cmp1(struct A m, struct A n)
{
    return m.b < n.b;
}

bool cmp2(struct A m, struct A n)
{
    return m.a < n.a;
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        arr[i].a = i+1;
        scanf("%d", &arr[i].b);
    }
    sort(arr, arr+n, cmp1);
    for(int i = 0; i < n; i++) {
        if (i == 0 || arr[i].b != arr[i-1].b) {
            int j = i; 
            while(j < n && arr[j].a == i+1) {
                if (arr[j].b == arr[j].a) {
                    swap(arr[j], arr[i]);
                    break;
                }
                j++;
            }
        }
        arr[i].b = i+1; 
    }
    sort(arr, arr+n, cmp2);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i].b); 
        if (i != n-1) {
            printf(" "); 
        }
    }
    printf("\n");
    return 0;
}
