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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        return ans;
    }

private:
    int ans=0;
    void dfs(TreeNode* root,int cur){
        cur=cur*10+root->val;
        if(!root->left&&!root->right)
        {
            ans+=cur;
            return;
        }
        if(root->left)
            dfs(root->left,cur);
        if(root->right)
            dfs(root->right,cur); 
    }
};
