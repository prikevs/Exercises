#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
    void DFS(vector<string> &ret, string &now, int n, int left) {
        cout << "n=" << n << " left=" << left << " now=" << now << endl;
        if (n == 0) {
            while(left--) {
                now += ')';
            }
            ret.push_back(now);
            return; 
        } 
        string temp = now + '(';
        DFS(ret, temp, n-1, left+1);
        if (left > 0) {
            temp = now + ')';
            DFS(ret, temp, n, left-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string now;
        DFS(ret, now, n, 0);
        return ret;
    }
};


int main()
{
    Solution sol;
    auto ret = sol.generateParenthesis(3);
    for(auto s: ret) {
        cout << s << endl;
    }
    return 0;
}

