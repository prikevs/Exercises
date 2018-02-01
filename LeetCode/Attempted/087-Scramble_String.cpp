#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length(); 
        int len2 = s2.length(); 
        if (len1 != len2) {
            return false; 
        }
        if (len1 == 1) {
            return s1 == s2;
        }
        if (s1 == s2) {
            return true; 
        }
        for(int i = 1; i < len1-1; ++i) {
            string s1l = s1.substr(0, i);
            string s1r = s1.substr(i);

            string s2l = s2.substr(0, i);
            string s2r = s2.substr(i);

            if ((isScramble(s1l, s2r) && isScramble(s1r, s2l) || isScramble(s1l, s2l) && isScramble(s1r, s2r)) == true) {
                return true; 
            }

        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s1 = "great";
    string s2 = "rgeat";
    cout << sol.isScramble(s1, s2) << endl;
    return 0;
}
