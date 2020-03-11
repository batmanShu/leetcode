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
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* rightTree=mirrorTree(root->left);
        TreeNode* leftTree=mirrorTree(root->right);
        root->left=leftTree;
        root->right=rightTree;
        return root;
    }
};
