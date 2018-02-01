#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool match(string &s, string &p, int i, int j) {
        cout << "i=" << i << ",j=" << j << endl;
        bool is = false;
        if (s.length() == i) {
            is = true;
            if (j == p.length() || j == p.length() - 2 && p[p.length()-1] == '*') {
                if (i >= s.length())
                    return true;
                return false;
            }
        }
        else {
            if (i == s.length()) {
                if (j == p.length() || j == p.length() - 2 && p[p.length()-1] == '*') 
                    return true;
                return false;
            }
        }
        if (j+1 < p.length() && p[j+1] == '*') {
            if (!is && (s[i] == p[j] || p[j] == '.'))
                if (match(s, p, i+1, j))
                    return true;
            return match(s, p, i, j+2);
        }
        if (!is && (s[i] == p[j] || p[j] == '.'))
            return match(s, p, i+1, j+1);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0); 
    }
};

int main()
{
    string s = "aabcbcbcaccbcaabc";
    string p = ".*a*aa*.*b*.c*.*a*";
    //cin >> s >> p;
    Solution sol;
    cout << sol.isMatch(s, p) << endl;
    return 0;
}
