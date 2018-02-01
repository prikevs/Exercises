#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int Y = grid.size(); 
        int X = grid[0].size();
        for(int i = 1; i < X; ++i)
            grid[0][i] += grid[0][i-1];
        for(int i = 1; i < Y; ++i)
            grid[i][0] += grid[i-1][0];
        for(int i = 1; i < Y; ++i) {
            for(int j = 1; j < X; ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]); 
        }
        return grid[Y-1][X-1];
    }
};

int main()
{
    return 0;
}
