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

#define L (rt<<1)
#define R (rt<<1|1)

const int LEN = 1e6+10;

struct Seg {
    int l, r;
    int mi;
}seg[LEN<<2];
int input[LEN];

void pushup(int rt)
{
    seg[rt].mi = min(seg[L].mi, seg[R].mi);
}

void buildt(int left, int right, int rt)
{
    seg[rt].l = left, seg[rt].r = right;
    if (left == right) {
        seg[rt].mi = input[left]; 
        return;
    }
    int mid = (left + right) >> 1;
    buildt(left, mid, L);
    buildt(mid+1, right, R);
    pushup(rt);
}

void update(int node, int rt, int n)
{
    if (seg[rt].l == seg[rt].r) {
        if (seg[rt].l == node) {
            seg[rt].mi = n;
        }
        return;
    }
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (node <= mid) {
        update(node, L, n); 
    }
    else {
        update(node, R, n);
    }
    pushup(rt);
}

int query(int left, int right, int rt)
{
    //printf("ql=%d, qr=%d\n", seg[rt].l, seg[rt].r);
    if (seg[rt].l == left && seg[rt].r == right) {
     //   printf("left=%d,right=%d,mi=%d\n", left, right, seg[rt].mi);
        return seg[rt].mi; 
    }
    //if (seg[rt].l == seg[rt].r)
    //    return 0x7fffffff;
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (right <= mid) {
        return query(left, right, L); 
    }
    else if (left > mid) {
        return query(left, right, R); 
    }
    else {
      //  printf("l=%d, mid=%d, r=%d\n", left, mid, right);
        return min(query(left, mid, L), query(mid+1, right, R)); 
    }
}



int main()
{
    int n;
    memset(seg, 0, sizeof(seg));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", input+i); 
    }
    buildt(1, n, 1);
    int q, a, x, y;
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d %d", &a, &x, &y);
        if (a == 0) {
            printf("%d\n", query(x, y, 1)); 
        }
        else {
            update(x, 1, y);
        }
    }
    return 0;
}
