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
    unordered_map<int, TreeNode*> mp;
    bool compare(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(a && b && a->val==b->val) return compare(a->left,b->left) && compare(a->right, b->right);
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root || !subroot) return false;
        mp[root->val] = root;
        if(mp.find(subroot->val)!=mp.end()){
            if(compare(mp[subroot->val], subroot)) return true;
        }    
        return isSubtree(root->left,subroot) || isSubtree(root->right, subroot);
    }
};
