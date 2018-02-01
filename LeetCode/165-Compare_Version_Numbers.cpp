#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> split(string &version) {
        vector<int> ret;
        int len = version.length();
        int last = 0;
        for(int i = 0; i <= len; ++i) {
            //cout << "i=" << i << endl;
            if (i == len || version[i] == '.') {
                //cout << version.substr(last-version.begin(), it-last) << endl;
                ret.push_back(stoi(version.substr(last, i-last)));
                last = i + 1;
            } 
        }
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        int len1 = v1.size();
        int len2 = v2.size();
        int i, j;
        i = j = 0;
        while(i < len1 || j < len2) {
            int a, b;
            if (i == len1)
                a = 0; 
            else
                a = v1[i++];
            if (j == len2)
                b = 0; 
            else
                b = v2[j++];
            cout << "a=" << a << ",b=" << b << endl;
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    string v1 = "0.1";
    string v2 = "1.0";
    cin >> v1 >> v2;
    cout << sol.compareVersion(v1, v2) << endl;
    return 0;
}
