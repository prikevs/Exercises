#include <string>
#include <iostream>
using namespace std;

class Solution {
    bool judge(char a, char b) {
        int t = ((a-'0') * 10 + (b-'0'));
        return a != '0' && t > 0 && t <= 26;

    }
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) {
            return 0; 
        }
        vector<int> dp(len, 0);    
        if (s[0] == '0') {
            return 0; 
        }
        dp[0] = 1;
        if (len == 1) {
            return 1; 
        }
        dp[1] = !(s[1]=='0');
        if (judge(s[0], s[1])) {
            ++dp[1];
        }
        for(int i = 2; i < len; ++i) {
            if (s[i] == '0' && !judge(s[i-1], s[i]))
                return 0;
            if (s[i] != '0') {
                dp[i] = dp[i-1]; 
            }
            if (judge(s[i-1], s[i])) {
                dp[i] += dp[i-2]; 
            }
        }
        return dp[len-1];
    }
};

int main()
{
    reutnr 0;
}
