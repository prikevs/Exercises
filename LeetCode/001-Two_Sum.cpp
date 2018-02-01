#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end()); 
        vector<int> ret(2, -1);
        int len = nums.size();
        for (auto num: copy) {
            int val = target - num;
            auto res = lower_bound(copy.begin(), copy.end(), val);
            if (*res != val) {
                continue; 
            }
            for(int i = 0; i < len; ++i) {
                if (ret[0] == -1 && nums[i] == num) {
                    ret[0] = i; 
                    continue;
                } 
                if (ret[1] == -1 && nums[i] == val) {
                    ret[1] = i; 
                }
            } 
            break;
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    vector<int> nums = {150, 24, 79, 50, 88, 345, 3};
    Solution sol;
    auto ret = sol.twoSum(nums, 200);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}
