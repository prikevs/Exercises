#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words; 
        auto p = s.begin();
        auto it = s.begin();
        while(it != s.end()) {
            switch(*it) {
            case ' ': 
                //cout << "length: " << it-p << endl;
                if (it-p != 0)
                    words.push_back(s.substr(p-s.begin(), it-p));
                while(it != s.end() && *it == ' ')
                    ++it;
                p = it;
                break;
            default:
                ++it;
            }
                
        }
        if (it-p != 0)
            words.push_back(s.substr(p-s.begin(), it-p));
        s = "";
        int len = words.size();
        for(int i = len-1; i >= 0; --i) {
            cout << words[i] << endl;
            s += words[i]; 
            if (i != 0)
                s += " ";
        }
    }
};

int main()
{
    Solution sol;
    string str = "the sky is blue";
    str = " ";
    str = " 1";
    sol.reverseWords(str);
    cout << str << endl;
    return 0;
}
