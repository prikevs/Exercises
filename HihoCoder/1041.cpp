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

vector <vector<int> > nodes(110);
vector <int> order(110);
bool vis[110];
int n, m;
bool f = 0;

void dfs(int pos, int next)
{
    if (f)
        return;
//    printf("next=%d\n", next);
    if (next == m-1) {
//        printf("x\n");
        f = 1;
        return; 
    }
    for(int i = 0; i < nodes[pos].size(); i++) {
        int p = nodes[pos][i];
        int nn = next;
        if (!vis[p]) {
            if (p == order[next]) {
                nn++; 
            }
            vis[p] = true;
            dfs(p, nn);
            vis[p] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            nodes[i].clear();
        for(int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        order.clear();
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> order[i];
        }
        memset(vis, 0, sizeof(vis));
        f = 0;
        int nn = 0;
        if (1 == order[0])
            nn++;
        vis[1] = true;
        dfs(1, nn);     
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
