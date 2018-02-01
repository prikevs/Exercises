#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 != 0 || n < 6) {
        cout << 0 << endl; 
        return 0;
    }
    n /= 2;
    if (n % 2 == 0) {
        n -= 1; 
    }
    cout << n / 2 << endl;
    return 0;
}
