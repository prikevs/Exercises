#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        if (len < 3) {
            return ret; 
        }
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < len; ++i) {
            if (nums[i] > 0 || (i > 0 && nums[i] == nums[i-1])) {
                continue; 
            }
            for(int j = i+1; j < len; ++j) {
                if (nums[i] + nums[j] + nums[j] > 0 || (j > i+1 && nums[j] == nums[j-1])) {
                    continue; 
                }
                int pos = lower_bound(nums.begin()+j+1, nums.end(), -(nums[i]+nums[j])) - nums.begin();
                if (pos < len && nums[pos] + nums[i] + nums[j] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[pos]}; 
                    ret.push_back(temp); 
                }
            } 
        } 
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {1, 0, -4};
    auto ret = sol.threeSum(test);
    for(auto r : ret) {
        for(auto s : r) {
            cout << s << " "; 
        } 
        cout << endl;
    }
    return 0;
}
