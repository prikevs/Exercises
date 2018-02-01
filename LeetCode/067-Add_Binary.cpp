#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        int t = 0;
        string ret;
        while(len1 > -1 || len2 > -1) {
            int m, n;
            if (len1 == -1) {
                m = 0; 
            }
            else {
                m = a[len1] - '0'; 
                --len1;
            }
            if (len2 == -1) {
                n = 0; 
            }
            else {
                n = b[len2] - '0'; 
                --len2;
            }
            t += m + n;
            ret += t%2 + '0';
            t /= 2;
        }
        if (t != 0) {
            ret += '1'; 
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution sol;
    string a, b;
    cin >> a >> b;
    cout << sol.addBinary(a, b) << endl;
    return 0;
}
