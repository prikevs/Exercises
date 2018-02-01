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

const int LEN = 1e5+10;

struct Seg {
    int l, r, sum;
    int lazy;
}seg[LEN<<2];
int input[LEN];

void pushup(int rt)
{
    seg[rt].sum = seg[L].sum + seg[R].sum;
}

void pushdown(int rt)
{
    if (seg[rt].l == seg[rt].r) {
        seg[rt].sum = seg[rt].lazy;
        seg[rt].lazy = 0;
        return;
    }
    seg[L].lazy = seg[R].lazy = seg[rt].lazy;
    seg[L].sum = seg[L].lazy * (seg[L].r - seg[L].l + 1);
    seg[R].sum = seg[R].lazy * (seg[R].r - seg[R].l + 1);
    seg[rt].lazy = 0;
}

void buildt(int left, int right, int rt)
{
    seg[rt].l = left, seg[rt].r = right;
    if (left == right) {
        seg[rt].sum = input[left]; 
        return;
    }
    int mid = (left + right) >> 1;
    buildt(left, mid, L);
    buildt(mid+1, right, R);
    pushup(rt);
}

void update(int left, int right, int n, int rt)
{
    if (seg[rt].lazy)
        pushdown(rt);
    if (seg[rt].l == left && right == seg[rt].r) {
        seg[rt].lazy = n;
        seg[rt].sum = n * (right - left + 1);
        return;
    }
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (right <= mid) {
        update(left, right, n, L); 
    }
    else if (left > mid) {
        update(left, right, n, R);
    }
    else {
        update(left, mid, n, L);    
        update(mid+1, right, n, R);    
    }
    pushup(rt);
}

int query(int left, int right, int rt)
{
    //printf("ql=%d, qr=%d\n", seg[rt].l, seg[rt].r);
    if (seg[rt].lazy)
        pushdown(rt);
    if (seg[rt].l == left && seg[rt].r == right) {
     //   printf("left=%d,right=%d,mi=%d\n", left, right, seg[rt].mi);
        return seg[rt].sum; 
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
        return query(left, mid, L) + query(mid+1, right, R); 
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
    int q, a, x, y, z;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(x, y, 1)); 
    //        printf("xxx:%d\n", seg[1].sum);
        }
        else {
            scanf("%d %d %d", &x, &y, &z);
            update(x, y, z, 1);
        }
    }
    return 0;
}
