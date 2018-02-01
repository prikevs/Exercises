#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    static bool cmp(const vector<int> a, const vector<int> b) {
        return a[0] < b[0]; 
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp = {target};
        int pos = upper_bound(matrix.begin(), matrix.end(), temp, cmp) - matrix.begin(); 
        if (pos >= matrix.size()) {
            return false;
        }
        int now = lower_bound(matrix[pos].begin(), matrix[pos].end(), target) - matrix[pos].begin();
        if (now >= matrix[pos].size() || matrix[pos][now] != target) {
            return false; 
        }
        return true;
    }
};

int main()
{
    Solution sol;
    return 0;
}
