#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int current = 0;
        int start = 0;
        vector<int> alpha(130, -1);
        int len = s.length();
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            int h = s[i];
            //cout << "start: " << start << " alpha: " << s[i] << " hash: " << alpha[h] << endl;
            if (alpha[h] < start) {
                current = i - start + 1;
            }
            else {
                current = i - start;
                start = alpha[h] + 1;
            }
            alpha[h] = i;
            if (current > ret) {
                ret = current;
            }
        }
        return ret;
    }
};

int main()
{
    string s("abba");
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
