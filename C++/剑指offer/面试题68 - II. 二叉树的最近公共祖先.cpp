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
        if(!root) return nullptr;
        if(isInTree(p,q)) return p;
        if(isInTree(q,p)) return q;
        if(isInTree(root->left,p))
        {
            if(isInTree(root->right,q)) return root;
            return lowestCommonAncestor(root->left,p,q);
        }
        else
        {
            if(isInTree(root->left,q)) return root;
            return lowestCommonAncestor(root->right,p,q);
        }
    }
    bool isInTree(TreeNode* root, TreeNode* p) {
        if(!root) return false;
        if(root==p) return true;
        return isInTree(root->left,p)||isInTree(root->right,p);
    }
};
