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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root)
            return nullptr;
        if(!root->left)
            return root;
        TreeNode* new_root=upsideDownBinaryTree(root->left);
        TreeNode* new_left=upsideDownBinaryTree(root->right);
        TreeNode* new_right=new TreeNode(root->val);
        TreeNode* res=new_root;
        while(new_root->right)
        {
            new_root=new_root->right;
        }
        new_root->right=new_right;
        new_root->left=new_left;
        return res;
    }
};
