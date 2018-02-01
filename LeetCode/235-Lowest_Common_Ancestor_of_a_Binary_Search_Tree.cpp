#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *tp, *tq, *ans;
    bool flag;
    bool DFS(TreeNode *node) {
        if (flag) {
            return false; 
        }
        if (node == NULL) {
            return false; 
        } 
        bool now = (node == tp || node == tq);
        bool ret1 = DFS(node->left);
        bool ret2 = DFS(node->right);
        if (ret1 && now || now && ret2 || ret1 && ret2) {
            ans = node;
            flag = true;
        }
        return ret1 || ret2 || now;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        flag = false;
        tp = p;
        tq = q;
        DFS(root); 
        return ans;
    }
};

int main()
{}
