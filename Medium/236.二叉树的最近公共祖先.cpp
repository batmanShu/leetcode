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
        if(isNodeinTree(p,q)) return p;
        if(isNodeinTree(q,p)) return q;
        bool flag=isNodeinTree(root->right,q);
        if(isNodeinTree(root->left,p))
        {
            if(flag) return root;
            else return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            if(flag) return lowestCommonAncestor(root->right, p, q);
            else return root;
        }
    }
    bool isNodeinTree(TreeNode* root, TreeNode* node){
        //用来判断节点node是否在以root为根的树中
        if(root==nullptr||node==nullptr) return false;
        if(root==node||root->left==node||root->right==node) return true;
        return isNodeinTree(root->left,node)||isNodeinTree(root->right,node);
    }
};
