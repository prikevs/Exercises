#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool alpha[26] = {false};
        for(auto a: s) {
            alpha[a-'a']  = true;
        }
        string ret = "";
        for(int i = 0; i < 26; ++i) {
            if (alpha[i]) {
                ret += 'a'+i; 
            } 
        }
        return ret;
    }
};

int main()
{
    return 0;
}
