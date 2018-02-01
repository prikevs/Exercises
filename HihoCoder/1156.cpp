#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int LEN = 100010;

struct Node {
    bool flag;
    int color;
    int sons;
    int last;
}nodes[LEN];

struct Edge {
    int head, tail;
    int next;
}edges[LEN<<1];
int cnt = 1;

struct TreeNode {
    int fa; 
    int sons;
    int next;
    int count;
    int last;
    //bool issame;
}tree[LEN];

bool vis[LEN];

map<int, int> colormap[LEN];

int n;

/*
void print(int idx)
{
    printf("edge=%d, sons:", idx); 
    int temp = nodes[idx].sons; 
    while(temp != 0) {
        printf("%d ", temp); 
        temp = nodes[temp].next;
    }
    printf("\n");
}
*/

void makeNode(int idx, int color)
{
    if (nodes[idx].flag == false) {
        nodes[idx].flag = true; 
        nodes[idx].color = color;
    }
}

void makeEdge(int idx, int head, int tail, int next)
{
    edges[idx].head = head;
    edges[idx].tail = tail;
    edges[idx].next = next;
}

void linkNode(int a, int b)
{
    //printf("a=%d\n", a);
    if (nodes[a].sons == 0) {
        nodes[a].sons = cnt; 
        nodes[a].last = cnt;
        makeEdge(cnt, a, b, 0);
        cnt++;
        return;
    } 
    edges[nodes[a].last].next = cnt;
    nodes[a].last = cnt;
    makeEdge(cnt, a, b, 0);
    cnt++;
}

void linkTree(int fa, int son)
{
    tree[son].fa = fa; 
    ++colormap[fa][nodes[son].color];
    ++tree[fa].count;
#ifdef DBUG
    printf("linkTree: fa=%d, son=%d\n", fa, son);
#endif
    if (tree[fa].sons == 0) {
        tree[fa].sons = son; 
        tree[fa].last = son;
        return;
    }
    tree[tree[fa].last].next = son;
    tree[fa].last = son;
    //printf("fa=%d\n", fa);
//    tree[son].issame = (node[son].color == node[fa].color);
}

void makeTree(int idx)
{
    if (nodes[idx].sons == 0) {
        return; 
    }
    int temp = nodes[idx].sons;
    while(temp != 0) {
#ifdef DBUG
        printf("idx=%d,temp=%d\n", idx, temp);
#endif
        int tail = edges[temp].tail;
        if (!vis[tail]) {
            linkTree(idx, tail);
            vis[tail] = true;
            makeTree(tail);
        }
        temp = edges[temp].next; 
    } 
}

void init()
{
    memset(nodes, 0, sizeof(nodes));
    memset(tree, 0, sizeof(tree));
    memset(vis, 0, sizeof(vis));
    memset(edges, 0, sizeof(edges));
    cnt = 1;
    for(int i = 1; i <= n; ++i) {
        colormap[i].clear(); 
    }
}

int countColor(int x)
{
    int ret = 0;
    int fa = tree[x].fa;
    if (fa != 0 && nodes[fa].color != nodes[x].color)
        ++ret;
#ifdef DBUG
    printf("x=%d, tree.count=%d\n", x, tree[x].count);
    printf("color=%d\n", colormap[x][nodes[x].color]);
#endif
    ret += tree[x].count - colormap[x][nodes[x].color];
    return ret;
}

void changeColor(int x, int y)
{
    int fa = tree[x].fa;
    int color = nodes[x].color;
#ifdef DBUG
    printf("init=%d\n", colormap[fa][color]);
#endif
    --colormap[fa][color]; 
    ++colormap[fa][y];
    nodes[x].color = y;
}



int main()
{
    int T, a, b, q, c, x, y;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);    
        init();
        for(int i = 0; i < n-1; ++i) {
            scanf("%d%d", &a, &b); 
    //        printf("a=%d,b=%d\n", a, b);
            makeNode(a, 0); 
            makeNode(b, 0); 
            linkNode(a, b);
            linkNode(b, a);
        //    print(2);
        }
        vis[1] = true;
        makeTree(1);
        printf("Case #%d:\n", cas);
        scanf("%d", &q);
        int colors = 1;
        while(q--) {
            scanf("%d", &c); 
            if (c == 1) {
                printf("%d\n", colors); 
            }
            else {
                scanf("%d%d", &x, &y); 
                int total1 = countColor(x);
                changeColor(x, y);
                int total2 = countColor(x);
#ifdef DBUG
                printf("total1=%d, total2=%d\n", total1, total2);
#endif
                colors += total2 - total1;
            }

        }
    }
    return 0;
}
