#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    struct Node{
        Node* next[26]; 
        Node() {memset(next, 0, sizeof(next));}
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        int total = strs.size();
        if (total == 0) {
            return string("");
        }
        Node *head = new Node;
        Node *p = head;
        for(char ch: strs[0]) {
            int idx = ch - 'a';
            if (p->next[idx] == NULL) {
                p->next[idx] = new Node;
            } 
            p = p->next[idx];
        }
        string ans = strs[0];
        for(int i = 1; i < total; ++i) {
            int now = 0;
            p = head;
            int slen = strs[i].length();
            for(int j = 0; j <= slen; ++j) {
                if (j == slen) {
                    ans = ans.substr(0, now);
                    break;
                }
                int idx = strs[i][j] - 'a';
                if (p->next[idx] != NULL) {
                    ++now; 
                    p = p->next[idx];
                }
                else {
                    ans = ans.substr(0, now);
                    break; 
                }
            } 
        }
        return ans;
    }
};

int main()
{
    vector<string> test = {"a", "ab", "abc"};
    Solution sol;
    cout << sol.longestCommonPrefix(test) << endl;
    return 0;
}
