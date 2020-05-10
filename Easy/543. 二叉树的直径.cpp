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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        preorder(root);
        return d-1;
    }
    void preorder(TreeNode* root) {
        if(root==nullptr)
            return;
        d=max(d,depth(root->left)+depth(root->right)+1);
        preorder(root->left);
        preorder(root->right);
    }
    int depth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int l_d=0,r_d=0;
        if(memo.find(root->left)!=memo.end())
            l_d=memo[root->left];
        else
            l_d=depth(root->left);
        if(memo.find(root->right)!=memo.end())
            r_d=memo[root->right];
        else
            r_d=depth(root->right);
        int res=max(l_d,r_d)+1;
        memo[root]=res;
        return res;
    }
private:
    unordered_map<TreeNode*,int> memo;
    int d=0;
};
