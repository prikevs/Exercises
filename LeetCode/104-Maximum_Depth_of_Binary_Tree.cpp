#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int DFS(TreeNode *p) {
        if (p == NULL) {
            return 0; 
        } 
        return max(DFS(p->left), DFS(p->right)) + 1;
    }
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0; 
        }
        return DFS(root);
    }
};

int main()
{}
