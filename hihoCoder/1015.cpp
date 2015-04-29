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

const int LEN1 = 1e6+10;
const int LEN2 = 1e4+10;
char str[LEN1];
int nxt[LEN1];
char s[LEN2];

void getnext()
{
    int len = strlen(str);
    nxt[0] = 0;
    for(int i = 1, q = 0; i < len; i++) {
        while(q > 0 && str[i] != str[q])
            q = nxt[q-1];
        if (str[i] == str[q])
            q++;
        nxt[i] = q;
    }
    for(int i = 0; i < len; i++)
        printf("%d ", nxt[i]);
    printf("\n");
}

int getans()
{
    int ans = 0;
    int lens = strlen(str);
    int lenp = strlen(s);
    for(int i = 0, j = 0; i < lens; i++) {
        while(j > 0 && str[i] != s[j])
            j = nxt[j-1];
        if (str[i] == s[j])
            j++;
        if (j == lenp) {
            ans++;
            j = nxt[j-1]; 
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);    
        scanf("%s", str);    
        getnext();
        printf("%d\n", getans());
    }
    return 0;
}
