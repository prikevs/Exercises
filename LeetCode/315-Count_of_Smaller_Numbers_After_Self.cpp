#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val, idx, big; 
    Node() : val(0), idx(0), big(0) {}
    Node(int v) : val(v) {}
};

class Solution {
    const int _MAX = 0x7FFFFFFF;
    static bool cmp(Node a, Node b) {
        return a.idx < b.idx; 
    }

    void merge_sort(int l, int r, vector<Node>& nodes, vector<int>& ret) {
        //cout << "l=" << l << " r=" << r << endl;
        if (l == r-1) {
            return; 
        } 
        int mid = (l + r) >> 1;
        merge_sort(l, mid, nodes, ret);
        merge_sort(mid, r, nodes, ret);
        int len1 = mid - l;
        int len2 = r - mid;
        Node *arr1 = new Node[len1+1]; 
        Node *arr2 = new Node[len2+1]; 
        for(int i = 0; i < len1; ++i) {
            arr1[i] = nodes[i+l]; 
            //cout << arr1[i]<< " ";
        }
        //cout << endl;
        arr1[len1] = Node(_MAX);
        for(int i = 0; i < len2; ++i) {
            arr2[i] = nodes[i+mid]; 
            //cout << arr2[i]<< " ";
        }
        //cout << endl;
        arr2[len2] = Node(_MAX);
        int i, j, k;
        i = j = 0;
        k = l;
        int temp = 0;
        while(i < len1 || j < len2) {
            if (arr1[i].val <= arr2[j].val) {
                ret[arr1[i].idx] += temp;
                nodes[k++] = arr1[i];         
                ++i;
            }
            else {
                if (arr1[i].val != _MAX) {
                    ++temp;
                }
                nodes[k++] = arr2[j];         
                ++j;
            }
        }
        //seg.Push(l, r);
        delete []arr1;
        delete []arr2;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return nums;
        }
        vector<Node> nodes(size);
        for (int i = 0; i < size; ++i) {
            nodes[i].val = nums[i]; 
            nodes[i].idx = i;
        }
        vector<int> ret(size, 0);
        merge_sort(0, size, nodes, ret);
        //cout << "nodes: ";
        //for(int i = 0; i < size; ++i) {
        //    cout << nodes[i].val << " ";
        //}
        //cout << endl;
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {26,78,27,100,33,67,90};
    auto ret = sol.countSmaller(test);
    for(auto r : ret) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
