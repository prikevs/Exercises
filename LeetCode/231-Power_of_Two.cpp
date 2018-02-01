#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; 
        }
        int judge = 1<<30; 
        if (judge % n) {
            return false; 
        }
        return true;
    }
};

int main()
{}
