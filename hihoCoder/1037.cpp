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

const int LEN = 110;
int room[LEN][LEN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", room[i] + j); 
        }
    }
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            room[i][j] += max(room[i+1][j], room[i+1][j+1]);
        }
    }
    printf("%d\n", room[0][0]);
    return 0;
}
