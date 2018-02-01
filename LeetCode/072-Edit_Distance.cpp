#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(); 
        int len2 = word2.length(); 
        vector<vector<int>> edit(len1+1, vector<int>(len2+1, 0));
        edit[0][0] = 0;
        for(int j = 1; j <= len2; ++j) {
            edit[0][j] = j; 
        }
        for(int i = 1; i <= len1; ++i) {
            edit[i][0] = i;
            for(int j = 1; j <= len2; ++j) {
                int t = 1;
                if (word1[i-1] == word2[j-1]) {
                    t = 0; 
                }
                edit[i][j] = min(edit[i-1][j]+1, min(edit[i][j-1]+1, edit[i-1][j-1]+t));
            } 
        }
        return edit[len1][len2];
    }
};

int main()
{
    Solution sol;
    string b = "ab";
    string a = "a";
    cout << sol.minDistance(a, b) << endl;
    return 0;
}
