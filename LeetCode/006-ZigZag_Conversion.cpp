#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s; 
        }
        int len = s.length();      
        int num = len / numRows;
        if (len % numRows != 0) {
            ++num; 
        }
        int per = (numRows - 1) * 2;
        char *ret = new char[len+1];
        ret[len] = 0;
        int cnt = 0;
        for(int j = 0; j < numRows; ++j) {
            for(int i = 0; i < num; ++i) {
                int t = i * per + j;
                if (t < len) {
                    //cout << t << endl;
                    ret[cnt++] = s[t]; 
                }
                if (j != 0 && j != numRows-1) {
                    t = (i+1) * per- j;
                    if (t < len) {
                        //cout << t << endl;
                        ret[cnt++] = s[t]; 
                    }
                }  
            } 
        }
        return string(ret);
    }
};

int main()
{
    Solution sol;
    string test("PAYPALISHIRING");
    cout << sol.convert(test, 2) << endl;
    return 0;
}
