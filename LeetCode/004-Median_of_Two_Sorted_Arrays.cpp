#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int binarySearch(vector<int>& arr1, vector<int>& arr2, int target) {
        int left, right;
        left = 0;
        right = arr1.size();
        int ret = -1;
        while(left < right) {
            int mid = (left + right) >> 1; 
            int pos1 = lower_bound(arr2.begin(), arr2.end(), arr1[mid]) - arr2.begin();
            int pos2 = upper_bound(arr2.begin(), arr2.end(), arr1[mid]) - arr2.begin();
            //cout << "left=" << left << " right=" << right << " pos1=" << pos1 << " pos2=" << pos2 << " target=" << target <<endl;
            if (mid + pos1 <= target && mid + pos2 >= target) {
                ret = arr1[mid]; 
                break;
            } 
            if (mid + pos2 < target) {
                if (left == mid)
                    break;
                left = mid; 
                continue;
            }
            if (mid + pos1 > target) {
                right = mid; 
                continue;
            }
        }
        return ret;
    }

    double solve(vector<int>& arr1, vector<int>& arr2, int target) {
        int ret = binarySearch(arr1, arr2, target);
        if (ret == -1) {
            ret = binarySearch(arr2, arr1, target);
        }
        return double(ret);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        double ret;
        if (total & 1) {
            int t = total / 2; 
            ret = solve(nums1, nums2, t);
        }
        else {
            int t1, t2;
            t2 = total >> 1;
            t1 = t2 - 1;
            double res1 = solve(nums1, nums2, t1);
            double res2 = solve(nums1, nums2, t2);
            //cout << "solve1: " << res1 << endl;
            //cout << "solve2: " << res2 << endl;
            ret = (res1 + res2) / 2;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 3};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
