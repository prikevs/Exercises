#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    struct Hash {
        int x;
        bool v;
        Hash() : x(0), v(false) {}
    };
    static const int LEN = 100010;
    static const int MOD = LEN - 13;
    Hash table[LEN];

    bool insert(int n) {
        int addr = n % MOD;
        while(table[addr].v != false) {
            if (table[addr].x == n) {
                return true; 
            }
            ++addr;
        }
        table[addr].v = true;
        table[addr].x = n;
        return false;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        for(auto n: nums) {
            if (insert(n)) {
                return true; 
            } 
        } 
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {1,2,3,4,2};
    cout << sol.containsDuplicate(test) << endl;
    return 0;
}
