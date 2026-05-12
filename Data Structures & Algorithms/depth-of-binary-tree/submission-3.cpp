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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        if(root) st.push({root, 1});
        int ans = 0;
        pair<TreeNode*,int> temp;
        while(!st.empty()){
            temp = st.top();
            ans = max(ans, temp.second);
            st.pop();
            if(temp.first->left) st.push({temp.first->left,temp.second+1});
            if(temp.first->right) st.push({temp.first->right,temp.second+1});
        }
        return ans;
    }
};
