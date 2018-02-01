#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        int ma = sqrt(n) + 1;
        int ret = n-2;
        for(int i = 2; i < ma; i++) {
            if (prime[i]) {
                for(int j = i*i; j < n; j+=i) {
                    if (prime[j]) {
                        --ret; 
                        prime[j] = false; 
                    }
                } 
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << sol.countPrimes(n) << endl;
    return 0;
}
