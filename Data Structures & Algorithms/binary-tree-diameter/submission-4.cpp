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
    int ans=0;
    unordered_map<TreeNode*,int> mp;
    int depth(TreeNode* n){
        if(!n) return 0;
        if(mp.find(n)!=mp.end())return mp[n];
        int l = depth(n->left);
        int r = depth(n->right);
        ans = max(ans, l+r);
        mp[n] = max(l,r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};
