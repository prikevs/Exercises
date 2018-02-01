#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    struct Line {
        Line() : x(0), h(0) {}
        int x;
        int h;
    };
    static bool cmp(const Line &a, const Line &b) {
        return a.h < b.h; 
    }
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        vector<Line> lines(len);
        vector<int> mas(len, 0);
        vector<int> mis(len, 0);
        for(int i = 0; i < len; ++i) {
            lines[i].x = i; 
            lines[i].h = height[i];
        }
        sort(lines.begin(), lines.end(), cmp);
        int ma = 0, mi = 0x7FFFFFFF;
        for(int i = len-1; i >= 0; --i) {
            if (lines[i].x > ma) {
                ma = lines[i].x;
            } 
            if (lines[i].x < mi) {
                mi = lines[i].x;
            }
            mas[i] = ma;
            mis[i] = mi;
        } 
        int ret = 0;
        for(int i = 0; i < len-1; ++i) {
            //cout << "i=" << i << " x=" << lines[i].x << " h=" << lines[i].h << " max=" << mas[i+1]<<endl;
            int t = lines[i].h * max(abs(mas[i+1]-lines[i].x), abs(mis[i+1]-lines[i].x));  
            if (t > ret) {
                ret = t; 
            } 
        }
        return ret;
    }
};

int main()
{
    vector<int> test = {10,9,8,7,6,5,4,3,2,1};
    Solution sol;
    cout << sol.maxArea(test) << endl;
    return 0;    
}

