#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int size;
    int caculate(vector<int>&nums, int len) {
        int sum = 0;
        for(int i = 0; i < len; ++i) {
            sum += nums[i]; 
        }
        int ret = sum;
        for(int i = len; i < size; ++i) {
            sum -= nums[i-len]; 
            sum += nums[i];
            if (sum >= ret) {
                ret = sum;
            }
        }
        return ret;
    }

public:
    int minSubArrayLen(int s, vector<int>& nums) {
        size = nums.size();
        int left = 0, right = size;
        int last = size;
        int ret = 0;
        while(true) {
            int mid = (left + right) >> 1; 
            if (last == mid) {
                break; 
            }
            last = mid;
            int cac = caculate(nums, mid);
            //cout<<"left=" << left << " right=" << right <<" mid=" << mid << " cac=" << cac << endl;
            if (cac >= s) {
                right = mid; 
                ret = mid;
            } 
            else {
                left = mid+1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    cout << sol.minSubArrayLen(15, nums) << endl;
    return 0;
}
