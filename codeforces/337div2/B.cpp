#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int LEN = 200020;
int arr[LEN];
int mis[LEN];

int main()
{
    int n, mi, cnt;
    mi = 0x7FFFFFFF;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i]; 
        if (arr[i] < mi) {
            mi = arr[i]; 
        }
    }
    cnt = 0;
    for(int i = 0; i < n; ++i) {
        if (arr[i] == mi) {
            mis[cnt++] = i; 
        } 
    }

    int ma = n-1-mis[cnt-1]+mis[0];
    for(int i = 1; i < cnt; ++i) {
        int temp = mis[i] - mis[i-1] - 1;
        if (temp > ma)  {
            ma = temp;
        }
    }
    ll ret = ll(mi) * n + ma;
    cout << ret << endl;
    return 0;
}
