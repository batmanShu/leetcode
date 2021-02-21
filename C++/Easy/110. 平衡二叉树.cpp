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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getTreeHeight(root->left)-getTreeHeight(root->right))>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int getTreeHeight(TreeNode* root) {
        if(mp.find(root)!=mp.end()) return mp[root];
        if(!root) return 0;
        int h=1;
        mp[root]=h+max(getTreeHeight(root->left),getTreeHeight(root->right));
        return mp[root];
    }
private:
    unordered_map<TreeNode*,int> mp;
};
