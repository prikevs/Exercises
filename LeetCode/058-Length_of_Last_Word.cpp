#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int num = 0;
        int ret = 0;
        for(auto it = s.begin(); it != s.end(); ++it) {
            switch(*it) {
            case ' ':
                if (num != 0)
                    ret = num;
                num = 0;
                break;
            default:
                ++num; 
            }
        }
        if (num != 0)
            ret = num;
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World") << endl;
    return 0;
}
