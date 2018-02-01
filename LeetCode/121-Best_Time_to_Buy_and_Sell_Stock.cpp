#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0; 
        }
        int ret = 0;
        int min = prices[0];
        for(auto p: prices) {
            if (p < min) {
                min = p; 
            } 
            else {
                if (p - min > ret) {
                    ret = p - min; 
                } 
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {2,1,5,4,8};
    cout << sol.maxProfit(test) << endl;
    return 0;
}
