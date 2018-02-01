#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 1; 
        }
        for(int i = 0; i < size; ++i) {
            while (nums[i] > 0 && nums[i] != i+1 && nums[i] <= size && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]); 
            } 
        } 
        for(int i = 0; i < size; ++i) {
            if (nums[i] != i+1) {
                return i+1; 
            }
        }
        return size+1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1};
    cout << sol.firstMissingPositive(nums) << endl;
    return 0;
}
