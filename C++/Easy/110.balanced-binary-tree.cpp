/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
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
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        int result=abs(treedepth(root->left)-treedepth(root->right));
        if(result>1) return false;
        else
        {
            return (isBalanced(root->left)&&isBalanced(root->right));
        }
        return true;
    }
    int treedepth(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        int depth=max(treedepth(root->left),treedepth(root->right));
        return ++depth;
    }

};
