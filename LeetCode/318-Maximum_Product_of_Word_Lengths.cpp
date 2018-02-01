#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> iden(size, 0);
        for(int i = 0; i < size; ++i) {
            int len = words[i].length();
            for(int j = 0; j < len; ++j) {
                iden[i] |= 1<<(words[i][j]-'a');
            }
        }
        int ret = 0;
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if ((iden[i] & iden[j]) != 0) {
                    continue; 
                }  
                int t = words[i].length() * words[j].length();
                if (t > ret)
                    ret = t;
            } 
        }
        return ret;
    }
};

int main()
{
    return 0;
}
