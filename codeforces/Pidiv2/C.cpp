#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>

#define ABS(a) (a<0?(-(a)):(a))
using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int LEN = 200020;
const int MOD = 1000007;
const int MAX = 0x7fffffff;

int arr[LEN];
struct Hash{
    int n;
    int v;
};

struct Hash hashtable1[MOD+3];
struct Hash hashtable2[MOD+3];
ll before[LEN];
ll after[LEN];

void hash_insert(struct Hash hashtable[], int v)
{
    int addr = ABS(v) % MOD;
    while(hashtable[addr].v != v && hashtable[addr].n != 0) {
        addr++;
    }
    hashtable[addr].v = v;
    hashtable[addr].n++;
}

int hash_find(struct Hash hashtable[], int v)
{
    int addr = ABS(v) % MOD;
    while(hashtable[addr].v != v && hashtable[addr].n != 0) {
        addr++;
    }
    return hashtable[addr].n;
}

int main()
{
    int n, k;
    memset(hashtable1, 0, sizeof(hashtable1));
    memset(hashtable2, 0, sizeof(hashtable2));
    memset(before, 0, sizeof(before));
    memset(after, 0, sizeof(after));
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr+i); 
    }
    if (n < 3) {
        printf("0\n");
        return 0;
    }
    for(int i = 1; i < n; i++) {
        hash_insert(hashtable1, arr[i-1]);
        int mid = arr[i]; 
        if (mid % k == 0) {
            before[i] = hash_find(hashtable1, mid/k);
        }
    }
    for(int i = n-2; i > 0; i--) {
        hash_insert(hashtable2, arr[i+1]); 
        int mid = arr[i];
        if (MAX/k < ABS(mid))
            continue;
        after[i] = hash_find(hashtable2, mid*k);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << " "  << before[i] << " " << after[i] << endl; 
        ans += before[i] * after[i];    
    }
    cout << ans << endl;
    return 0;
}
