#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size * (1+size) / 2;
        for(auto n: nums) {
            sum -= n; 
        }
        return sum;
    }
};

int main()
{
    return 0;
}
