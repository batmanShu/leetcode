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
    struct status{
        int a;
        int b;
        int c;
    };

    status dfs(TreeNode* root){
        if(!root)
            return {INT_MAX/2,0,0};
        auto [la,lb,lc]=dfs(root->left);
        auto [ra,rb,rc]=dfs(root->right);
        int a=1+lc+rc;
        int b = min(a,min(la+rb, ra+lb));
        int c=min(a,lb+rb);
        return {a,b,c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a,b,c]=dfs(root);
        return b;
    }
};
