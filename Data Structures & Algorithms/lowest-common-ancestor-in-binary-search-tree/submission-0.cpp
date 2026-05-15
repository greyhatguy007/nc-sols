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
    void populate(TreeNode* curr, TreeNode* x, deque<TreeNode*> &q){
        if(!x || !curr) return;
        q.push_back(curr);
        if(curr->val==x->val) return;
        if(curr->val>x->val) populate(curr->left,x,q);
        else populate(curr->right,x,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> a;
        deque<TreeNode*> b;
        TreeNode* ans = nullptr;
        populate(root,p,a);
        populate(root,q,b);
        while(!a.empty() && !b.empty() && a.front()->val == b.front()->val){
            ans = a.front();
            a.pop_front();
            b.pop_front();
        }
        return ans;
    }
};
