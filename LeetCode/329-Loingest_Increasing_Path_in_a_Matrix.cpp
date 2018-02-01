#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int X, Y;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& m, int x, int y) {
        int ret[4] = {0};
        for(int i = 0; i < 4; ++i) {
            int nowx = x + dx[i]; 
            int nowy = y + dy[i];
            if (nowx < 0 || nowx >= X || nowy < 0 || nowy >= Y) {
                ret[i] = 0; 
                continue;
            }
            if (matrix[nowy][nowx] < matrix[y][x]) {
                if (m[nowy][nowx] > 0) {
                    ret[i] = m[nowy][nowx];
                }
                else {
                    //cout << "nowy: " << nowy << " nowx: " << nowx << endl;
                    ret[i] = DFS(matrix, m, nowx, nowy);
                }
            }
        }
        m[y][x] = max(max(ret[0], ret[1]), max(ret[2], ret[3])) + 1;
        return m[y][x];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        Y = matrix.size();
        if (Y == 0) {
            return 0; 
        }
        X = matrix[Y-1].size();
        if (X == 0) {
            return 0; 
        }
        vector<vector<int>> m(Y, vector<int>(X, 0));

        for(int i = 0; i < Y; ++i) {
            for(int j = 0; j < X; ++j) {
                if (m[i][j] > 0) {
                    continue; 
                }                        
                DFS(matrix, m, j, i);
            }  
        }

        int ret = 0;
        for(int i = 0; i < Y; ++i) {
            for(int j = 0; j < X; ++j) {
                if (m[i][j] > ret) {
                    ret = m[i][j];
                }
            } 
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    matrix[0][0] = 9;
    matrix[0][1] = 9;
    matrix[0][2] = 4;
    matrix[1][0] = 6;
    matrix[1][1] = 6;
    matrix[1][2] = 8;
    matrix[2][0] = 2;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    Solution sol;
    cout << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}
