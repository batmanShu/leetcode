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
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        ans=min(ans,abs(prev-root->val));
        prev=root->val;
        inorder(root->right);
    }

private:
    int ans=INT_MAX;
    int prev=INT_MAX;
};
