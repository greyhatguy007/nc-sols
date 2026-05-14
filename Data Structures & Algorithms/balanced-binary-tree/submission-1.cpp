/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int func(TreeNode* node){
        if(!node)  return 0;  
        int l = func(node->left);
        int r = func(node->right);
        if(abs(l-r)>1) return INT_MIN;
        return 1 + max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        int sol = func(root);
        return sol>=0;
    }
};
