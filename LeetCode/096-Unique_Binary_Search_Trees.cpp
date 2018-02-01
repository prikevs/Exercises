#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> arr(n+1, 0); 
        arr[0] = arr[1] = 1;
        arr[2] = 2;
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                arr[i] += arr[j-1] * arr[i-j]; 
            }
        }
        return arr[n];
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << sol.numTrees(n) << endl;
    return 0;
}

