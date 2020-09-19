/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        return ans;
    }
private:
    int ans=0;
    void preorder(TreeNode* root) {
        if(!root)
            return;
        if(isleaf(root->left))
            ans+=root->left->val;
        preorder(root->left);
        preorder(root->right);
    }
    bool isleaf(TreeNode* root) {
        if(!root)
            return false;
        if(!root->left&&!root->right)
            return true;
        return false;
    }
};
