#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    int X, Y, len;
    struct Node {
        int x, y;
        Node(int y, int x) : x(x), y(y) {}
    };
    const int dir[2][4] = {{0,1,0,-1}, {1,0,-1,0}};
    bool DFS(vector<vector<char>>& board, Node pos, int depth, string &word, vector<vector<bool>> &vis) {
        //cout << "DFS: " << pos.y << " " << pos.x << endl;
        //cout << "depth: " << depth << endl;
        
        if (word[depth] != board[pos.y][pos.x]) {
            return false; 
        }
        if (depth == len-1) {
            return true; 
        }
        for(int i = 0; i < 4; ++i) {
            int nowy = pos.y + dir[0][i];
            int nowx = pos.x + dir[1][i];
            if (nowy < 0 || nowy >= Y || nowx < 0 || nowx >= X || vis[nowy][nowx]) {
                continue; 
            }
            //cout << "now: " << nowy << " " << nowx << endl;
            vis[nowy][nowx] = true;
            Node now(nowy, nowx);
            if (DFS(board, now, depth+1, word, vis)) {
                return true; 
            }
            vis[nowy][nowx] = false;
        }
        return false;
    }

    int getIndex(char ch) {
        if (ch >= 'a') {
            return ch - 'a';
        } 
        return ch - 'A';
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        Y = board.size(); 
        if (Y == 0) {
            return false; 
        }
        X = board[0].size();
        len = word.length();
        if (X * Y < len || len == 0) {
            return false; 
        }
        vector<vector<Node>> alpha(26, vector<Node>());

        for(int i = 0; i < Y; ++i) {
            for(int j = 0; j < X; ++j) {
                int t = getIndex(board[i][j]); 
                alpha[t].push_back(Node(i, j));
            } 
        }
        int target = getIndex(word[0]); 
        if (len == 1 && alpha[target].size() != 0) {
            return true;
        }
        for(auto pos: alpha[target]) {
            //cout << "exist: " << pos.y << " " << pos.x << endl;
            vector<vector<bool>> vis(Y, vector<bool>(X, false));
            vis[pos.y][pos.x] = true;
            if (DFS(board, pos, 0, word, vis)) {
                return true; 
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string word = "cdba";
    vector<vector<char>> board(2, vector<char>(2));
    board[0] = {'a', 'b'};
    board[1] = {'c', 'd'};
    cout << sol.exist(board, word) << endl;
    return 0;
}
