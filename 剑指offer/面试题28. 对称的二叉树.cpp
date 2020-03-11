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
        if(!root) return true;
        if(!root->left&&!root->right) return true;
        bool is_symmetric=true;
        isSymmetricCore(root->left,root->right,is_symmetric);
        return is_symmetric;
    }
    void isSymmetricCore(TreeNode* a, TreeNode* b, bool& is_symmetric){
        if(!a&&!b) return;
        if(!a||!b) 
        {
            is_symmetric=false;
            return;
        }
        if(a->val!=b->val) is_symmetric=false;
        else
        {
            isSymmetricCore(a->left, b->right, is_symmetric);
            isSymmetricCore(a->right, b->left, is_symmetric);
        }
    }

};
