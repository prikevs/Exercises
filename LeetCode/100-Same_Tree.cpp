#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int DFS(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true; 
        }
        else if (p == NULL || q == NULL) {
            return false; 
        }
        if (p->val != q->val) {
            return false; 
        }
        return DFS(p->left, q->left) && DFS(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode *p, TreeNode* q) {
        return DFS(p, q);         
    }
};

int main()
{
    return 0;
}
