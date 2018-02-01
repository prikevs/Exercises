#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool flag;
    int DFS(TreeNode *node) {
        if (node == NULL || !flag) {
            return 1; 
        } 
        int left = DFS(node->left);
        int right = DFS(node->right);
        if (abs(left-right) > 1) {
            flag = false; 
            return 0;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        flag = true; 
        DFS(root);
        return flag;
    }
};

int main()
{}
