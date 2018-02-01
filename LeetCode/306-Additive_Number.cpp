#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
    string Add(string &a, string &b) {
        int len1 = a.length();
        int len2 = b.length();
        int i = len1-1, j = len2-1;
        int t = 0;
        string ret;
        while(i != -1 || j != -1) {
            int t1, t2;
            if (i == -1) {
                t1 = 0; 
            }
            else {
                t1 = a[i] - '0';
                --i;
            }
            if (j == -1) {
                t2 = 0; 
            }
            else {
                t2 = b[j] - '0';
                --j;
            }
            t += t1 + t2;
            ret += char(t%10 + '0');
            t /= 10;
        }
        if (t != 0) {
            ret += char(t + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }


    bool judge(string fir, string sec, string &num) {
        int s = fir.length();
        while(true) {
            string t = Add(fir, sec); 
            s += sec.length();
            //cout << "fir=" << fir << " sec=" << sec << " t=" << t << endl;
            if (s + t.length() > num.length()) {
                //cout << "break" << endl;
                break; 
            }
            //cout <<"s=" << s << " substr: " << num.substr(s, t.length()) << endl;
            if (t == num.substr(s, t.length())) {
                fir = sec;
                sec = t;
            }
            else {
                return false; 
            }
        } 
        return true;
    }
public:
    bool isAdditiveNumber(string num) {
        string fir, sec;
        int len = num.length();
        for(int i = 1; i <= len-2; ++i) {
            fir = num.substr(0, i);
            for(int j = 1; j <= len-i-1 && (len-i-j)>=i && (len-i-j)>=j; ++j) {
                sec = num.substr(i, j); 
                //cout << fir << " " << sec << endl;
                if (judge(fir, sec, num)) {
                    return true; 
                }
            } 
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAdditiveNumber("199100199") << endl;
    return 0;
}
