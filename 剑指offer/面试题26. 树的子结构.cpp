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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        if(!A) return false;
        if(A->val!=B->val) 
            return isSubStructure(A->left,B)||isSubStructure(A->right,B);
        else
        {
            if(isSameTree(A,B)) return true;
            else return isSubStructure(A->left,B)||isSubStructure(A->right,B);
        }
    }
    bool isSameTree(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A) return false;
        if(A->val==B->val)
            return isSameTree(A->left,B->left)&&isSameTree(A->right,B->right);
        else 
            return false;
    }
};
