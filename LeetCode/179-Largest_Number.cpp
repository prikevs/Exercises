#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    static bool cmp(string &a, string &b) {
        return a+b>b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        vector<string> strs(len, string());
        for(int i = 0; i < len; ++i) {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), cmp);
        string ret = strs[0];
        for(int i = 1; i < len; ++i) {
            ret += strs[i];
        }
        auto it = ret.begin();
        for(; it != ret.end()-1; ++it) {
            if (*it != '0')
                break;
        }

        return ret.substr(it-ret.begin());
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(arr) << endl;
    return 0;
}
