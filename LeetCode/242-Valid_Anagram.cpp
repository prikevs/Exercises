#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2)
            return false;
        vector<int> hash1(26, 0); 
        vector<int> hash2(26, 0); 
        for(int i = 0; i < len1; ++i)
            ++hash1[s[i]-'a']; 
        for(int i = 0; i < len2; ++i)
            ++hash2[t[i]-'a']; 
        for(int i = 0; i < 26; ++i) {
            if (hash1[i] != hash2[i]) 
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}
