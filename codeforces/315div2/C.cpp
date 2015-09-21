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


const int maxn=1200000+100;
int prim[maxn];
bool vis[maxn];
int hu[maxn];
bool nn[maxn+100000];

void newjudge()
{
    memset(nn, 0, sizeof(nn));
    for(int i = 1; i <= 9; i++) {
        nn[i] = true;
        nn[i*10 + i] = true;
    }
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            int k = i*100 + j*10 + i; 
            nn[k] = true;
        } 
    }
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            int k = i*1000 + j*100 + j*10 + i; 
            nn[k] = true;
        } 
    }
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                int t = i*10000 + j*1000 + k*100 + j*10 + i; 
                nn[t] = true;
            } 
        } 
    }
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                int t = i*100000 + j*10000 + k*1000 + k*100 + j*10 + i; 
                nn[t] = true;
            } 
        } 
    }
    for(int i = 1; i <= 1; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 9; k++) {
                for(int m = 0; m <= 9; m++) {
                    int t = i*1000000 + j*100000 + k*10000 + m*1000; + k*100 + j*10 + i; 
                    nn[t] = true;
                }
            } 
        } 
    }
}


int main()
{
    memset(vis,false,sizeof(vis));
    vis[0] = vis[1] = true;
    int cou = 0;
    for(int i = 2;i < maxn;i++)
    {
        if(!vis[i])
        {
            cou++;
            for(int j = i+i;j < maxn;j = j+i)
            vis[j] = true;
        }
        prim[i] = cou;
    }
    int couh = 0;
    newjudge();
    for(int i = 1;i < maxn; i++)
    {
        if(nn[i])
        {
            couh++;
        }
        hu[i]=couh;
    }
    int p,q;
    cin >> p >> q;
    int ans = -1;
    for(int i = maxn-1;i > 0;i--)
    {
        if(q * prim[i] <= p*hu[i])
        {
            ans = i;
            break;
        }

    }
    if(ans == -1) {
        printf("Palindromic tree is better than splay tree\n");
    }
    else {
        cout << ans << endl;
    }
    return 0;
}
