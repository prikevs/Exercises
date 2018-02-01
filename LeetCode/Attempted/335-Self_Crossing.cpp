#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct Point {
        int x, y;
    };
    bool judge(Point a, Point b, Point s) {
        if (a.x == b.x) {
            if (s.x == a.x) {
                return s.x >= min(a.x, b.x) && s.x <= max(a.x, b.x);
            } 
            return false;
        } 
    }
public:
    bool isSelfCrossing(vector<int>& x) {
    
    }
};

int main()
{}

