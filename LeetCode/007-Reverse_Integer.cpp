#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string temp = to_string(x);
        if (temp[0] == '-') {
            std::reverse(temp.begin() + 1, temp.end());    
        }
        else {
            std::reverse(temp.begin(), temp.end());    
        }
        int ret = 0;
        try {
            ret = stoi(temp); 
        }catch(...) {}
        return ret;
    }
};

int main()
{
    Solution sol;
    int t;
    cin >> t;
    cout << sol.reverse(t) << endl;
    return 0;
}
