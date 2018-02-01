#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0}; 
        for(auto& n: nums) {
            ++color[n];
        }
        int cnt = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < color[i]; ++j) {
                nums[cnt++] = i; 
            } 
        }
    }

};

int main()
{}
