#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<vector<int>> dp(len, vector<int>(len, 0)); 
        if (len == 1)
            return triangle[0][0];
        for(int i = len-2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]); 
            }
        }
        return triangle[0][0];
    }
};

int main() {
    vector<vector<int>> triangle = {{1}, {2,3}};
    Solution sol;
    cout << sol.minimumTotal(triangle) << endl;
    return 0; 
}
