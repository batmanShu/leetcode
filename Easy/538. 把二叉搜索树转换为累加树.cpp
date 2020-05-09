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
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
private:
    int cursum=0;
    void inorder(TreeNode* root) {
        if(root==nullptr)
            return;
        inorder(root->right);
        root->val=root->val+cursum;
        cursum=root->val;
        inorder(root->left);
    }
};
