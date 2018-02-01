#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    const string fir[10] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
    const string sec[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    const string ten[10] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    const string tho[4] = {"", " Thousand", " Million", " Billion"};
    vector<string> change(string num) {
        vector<string> ret;

        if (num[0] != '0') {
            ret.push_back(fir[num[0]-'0']);
            ret.push_back(string(" Hundred"));
        }
        cout << num << endl;
        if (num[1] == '0') {
            cout << fir[num[2]-'0'] << endl;
            ret.push_back(fir[num[2]-'0']);
        }
        else if (num[1] == '1') {
            ret.push_back(ten[num[2]-'0']);
        }
        else {
            ret.push_back(sec[num[1]-'0']);
            ret.push_back(fir[num[2]-'0']);
        }
        return ret;
    }

public:
    string numberToWords(int num) {
        string now = to_string(num);
        int len = now.length();
        int cnt = 0;
        if (len % 3 != 0) {
            for(int j = 0; j < 3-len%3; ++j) {
                now = string("0") + now;
            }
        }
        len = now.length();
        int start = len - 3;
        string ret;
        while(start >= 0) {
            auto cut = now.substr(start, 3);
            auto temp = change(cut);
            string pre;
            for(auto t: temp) {
                pre += t;
            }
            cout << pre << endl;
            if (cut != "000") {
                ret = pre + tho[cnt] + ret;
            }
            ++cnt;
            start -= 3;
        }
        int cz = 0;
        while(ret[cz] == ' ') {
            cz++;
        }
        return ret.substr(cz);
    }
};

int main()
{
    int num;
    cin >> num;
    Solution sol;
    cout << sol.numberToWords(num) << endl;;
    return 0;
}
