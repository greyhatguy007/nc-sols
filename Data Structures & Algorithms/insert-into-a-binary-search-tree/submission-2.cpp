class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (curr) {
            parent = curr;
            if (curr->val > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (parent->val > val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        
        return root;
    }
};