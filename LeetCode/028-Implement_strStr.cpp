#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    void kmp(vector<int> &next, string &needle) {
        int len = needle.length();
        int q = 0;
        for(int i = 1; i < len; ++i) {
            while(needle[i] != needle[q] && q != 0) {
                q = next[q-1];
                //cout << "q=" << q << endl;
            } 
            if (needle[i] == needle[q]) {
                ++q;
            }
            next[i] = q; 
        }
    }

    int match(vector<int> &next, string &haystack, string &needle) {
        int len1 = haystack.length(); 
        int len2 = needle.length();
        int q = 0;
        for(int i = 0; i < len1; ++i) {
            while(needle[q] != haystack[i] && q != 0) {
                //cout << "q=" << q << endl;
                q = next[q-1]; 
            } 
            if (needle[q] == haystack[i]) {
                ++q; 
                if (q == len2) {
                    return i+1 - q; 
                }
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        if (len == 0)
            return 0;
        vector<int> next(len, 0); 
        kmp(next, needle);
        return match(next, haystack, needle);
    }
};

int main()
{
    Solution sol;
    string a= "babbaa";
    string b = "bbb";
    cout << sol.strStr(a, b) << endl;
    return 0;
}
