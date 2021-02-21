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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        preorder(root);
        return res;
    }
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        {
            mp[root]=0;
            return;
        }
        if(root==p||root==q) mp[root]=1;
        else mp[root]=0;
        dfs(root->left,p,q);
        dfs(root->right,p,q);
        mp[root]=mp[root]+mp[root->left]+mp[root->right];
    } 
    void preorder(TreeNode* root) {
        if(!root) return;
        if(mp[root]==2)
        {
            if(mp[root->left]!=2&&mp[root->right]!=2) res=root;
        }
        preorder(root->left);
        preorder(root->right);
    }
    unordered_map<TreeNode* , int> mp;
    TreeNode* res;
};
