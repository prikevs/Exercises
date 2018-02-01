#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 1); 
        int idx2, idx3, idx5;
        idx2 = idx3 = idx5 = 0;
        for(int i = 1; i < n; ++i) {
            int mi = min(nums[idx2]*2, min(nums[idx3]*3, nums[idx5]*5));
            if (mi == nums[idx2]*2) {
                ++idx2; 
            }
            if (mi == nums[idx3]*3) {
                ++idx3; 
            }
            if (mi == nums[idx5]*5) {
                ++idx5; 
            }
            nums[i] = mi;
        }
        return nums[n-1];
    }
};

int main()
{
    Solution sol;
    for(int i = 1; i <= 10; ++i) {
        cout << sol.nthUglyNumber(i) << endl;
    }
    return 0;
}
