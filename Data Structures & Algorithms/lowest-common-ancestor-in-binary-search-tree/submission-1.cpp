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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* a = root;
        TreeNode* b = root;
        TreeNode* ans = nullptr;
        while(a->val != p->val || b->val != q->val){
            if(a==b) ans = a;
            else break;
            if(a->val > p->val) a = a->left;
            else if(a->val<p->val) a = a->right;
            if(b->val>q->val) b = b->left;
            else if(b->val < q->val) b = b->right;

        }
        return ans;
    }
};
