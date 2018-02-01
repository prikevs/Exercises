#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows, vector<int>(1, 1));
        for(int i = 1; i < numRows; ++i) {
            for(int j = 1; j < i; ++j) {
                tri[i].push_back(tri[i-1][j] + tri[i-1][j-1]);
            } 
            tri[i].push_back(1);
        }
        return tri;
    }
};

int main()
{
    Solution sol;
    auto ret = sol.generate(10);
    for(auto row: ret) {
        for(auto num: row) {
            cout << num << " "; 
        } 
        cout << endl;
    }
    return 0;
}
