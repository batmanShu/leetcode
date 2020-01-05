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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
    bool isMirror(TreeNode* a,TreeNode* b){
        if(a==NULL&&b==NULL) return true;
        if(a==NULL||b==NULL) return false;
        return (a->val==b->val)&&isMirror(a->left,b->right)&&isMirror(a->right,b->left);
    }
};
