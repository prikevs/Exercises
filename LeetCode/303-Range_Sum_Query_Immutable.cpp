#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class NumArray {
    shared_ptr<vector<int>> sums;   
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return;
        sums = make_shared<vector<int>>(size, 0);
        sums->at(0) = nums[0];
        for(int i = 1; i < size; ++i)
            sums->at(i) = sums->at(i-1) + nums[i]; 
    }
    
    int sumRange(int i, int j) {
        if (i == 0) 
            return sums->at(j);
        return sums->at(j) - sums->at(i-1);
    }
};

int main()
{
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    vector<int> brr = {};
    NumArray num(brr);
    cout << num.sumRange(0, 2) << endl;
    cout << num.sumRange(2, 5) << endl;
    cout << num.sumRange(0, 5) << endl;
    return 0;
}
