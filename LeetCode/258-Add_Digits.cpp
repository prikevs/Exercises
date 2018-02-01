#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string temp = to_string(num); 
        while(temp.length() > 1) {
            int t = 0;
            for(auto a: temp) {
                t += (a-'0'); 
            }
            temp = to_string(t);
        }
        return stoi(temp);
    }
    
};

int main()
{
    Solution sol;
    cout << sol.addDigits(10) << endl;
    return 0;
}
