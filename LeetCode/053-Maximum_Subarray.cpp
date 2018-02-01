#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma = 0; 
        int size = nums.size();
        if (size == 0) {
            return 0; 
        }
        int total = 0;
        int ret = nums[0];
        int i;
        for(i = 0; i < size; ++i) {
            if (nums[i] > 0)
                break;
            if (nums[i] > ret) {
                ret = nums[i]; 
            } 
        }
        if (i == size) {
            return ret; 
        }
        for(int i = 0; i < size; ++i) {
            if (total + nums[i] < 0) {
                total = 0;
            } 
            else {
                total += nums[i]; 
            }
            if (ret < total) {
                ret = total; 
            } 
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    //vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> test = {-2,-3,-1};
    cout << sol.maxSubArray(test) << endl;
    return 0;
}
