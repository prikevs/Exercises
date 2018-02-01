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

const int LEN = 200010;

struct Node
{
    int iscat;
    int edge;
    int last;
    int cnt;
}nodes[LEN];

struct Edge
{
    int to;
    int next;
}edges[LEN];
int cnt = 1;
bool vis[LEN];
int ans;
int n, m;


void init()
{
    memset(nodes, 0, sizeof(nodes));
    memset(edges, 0, sizeof(edges));
    memset(vis, 0, sizeof(vis));
    cnt = 1;
    ans = 0;
}

void addEdge(int a, int b)
{
    if (nodes[a].last == 0) {
        nodes[a].edge = cnt; 
    } 
    else {
        edges[nodes[a].last].next = cnt; 
    }
    nodes[a].last = cnt;
    edges[cnt].to = b;
    ++nodes[a].cnt;
    ++cnt;
}

void dfs(int idx, int con, int isfa)
{
    if (nodes[idx].iscat == 1) {
        if (isfa == 1)
            ++con; 
        else
            con = 1;
        isfa = 1;
    }
    else {
        isfa = 0; 
        con = 0;
    }
//    printf("idx=%d, con=%d, isfa=%d\n", idx, con, isfa);
    if (con > m)
        return;
    if (nodes[idx].cnt == 1 && idx != 1)
        ++ans;
    int temp = nodes[idx].edge;
    while(temp != 0) {
        int to = edges[temp].to;
        if (!vis[to]) {
        //    printf("fa:%d son:%d\n", idx, to);
            vis[to] = true; 
            dfs(to, con, isfa);
        }
        temp = edges[temp].next;
    }
}

int main()
{
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &nodes[i].iscat); 
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b); 
        addEdge(a, b);
        addEdge(b, a);
    }
    vis[1] = true;
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
