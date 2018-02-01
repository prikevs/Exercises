#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> st;
        stringstream ss(preorder); 
        string item;
        while(getline(ss, item, ',')) {
            if (!st.empty()) {
                if (item == "#") {
                    while (!st.empty() && st.top() == "#") {
                        st.pop();
                        if (st.empty()) {
                            return false; 
                        }
                        st.pop();
                    }
                }
            }
            st.push(item); 
        }
        if (st.size() == 1 && st.top() == "#") {
            return true; 
        }
        return false;
    }
};

int main() {
    string s("9,3,4,#,#,1,#,#,2,#,6,#,#");
    Solution sol;
    cout << sol.isValidSerialization(s) << endl;
    return 0;
}
