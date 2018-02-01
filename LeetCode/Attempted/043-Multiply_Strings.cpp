#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class Solution {
    string Add(string &a, string &b)
    {
        //cout << "a = " << a << endl;
        //cout << "b = " << b << endl;
        int len1 = a.length();
        int len2 = b.length();
        string ret;
        int i, j;
        i = len1-1, j = len2-1;
        int m, n, last, now;
        last = now = 0;
        while(i+1 || j+1) {
            if (i == -1) {
                m = 0;
            }
            else {
                m = a[i] - '0';
                --i;
            }
            //cout << "m=" << m <<endl;
            if (j == -1) {
                n = 0;
            }
            else {
                n = b[j] - '0';
                --j;
            }
            //cout << "n=" << n <<endl;
            now = m + n + last;
            last = now / 10;
            now = now % 10;
            ret += char(now+'0');
            //cout << now << endl;
        }
        if (last != 0) {
            ret += char(last+'0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string makezero(int n)
    {
        string ret(n, '0');
        //cout << "make zero = " << ret << endl;
        return ret;
    }

public:
    string multiply(string &a, string &b)
    {
        //cout << "m a = " << a << endl;
        //cout << "m b = " << b << endl;
        int len1 = a.length();
        int len2 = b.length();
        int mid1 = len1 >> 1;
        int mid2 = len2 >> 1;
        if (len1 <= 1 && len2 <= 1) {
            stringstream ss;
            string ret;
            int m = atoi(a.c_str()) * atoi(b.c_str());
            ss << m;
            ss >> ret;
            //cout << "ret = " << ret << endl;
            return ret;
        }
        string a1 = a.substr(0, mid1);
        string b1 = a.substr(mid1, len1-mid1);
        string a2 = b.substr(0, mid2);
        string b2 = b.substr(mid2, len2-mid2);
        //cout << "a1 = " << a1 << endl;
        //cout << "b1 = " << b1 << endl;
        //cout << "a2 = " << a2 << endl;
        //cout << "b2 = " << b2 << endl;

        string temp1 = multiply(a1, a2)+makezero((len1+len2)/2);
        //cout << "temp1 = " << temp1 << endl;
        string temp2 = multiply(a1, b2)+makezero(len1/2);
        string temp3 = multiply(a2, b1)+makezero(len2/2);
        string temp4 = multiply(b1, b2);
        string ret1 = Add(temp1, temp2);
        string ret2 = Add(temp3, temp4);
        string temp = Add(ret1, ret2);
        //return temp;
        string::iterator it = temp.begin();
        while(*it == '0' && it != temp.end()) {
            temp.erase(it);
        }
        return temp;
    }
};

int main()
{
    string num1 = "123";
    string num2 = "1";
    Solution sol;
    cout << sol.multiply(num1, num2) << endl;
    return 0;
}
