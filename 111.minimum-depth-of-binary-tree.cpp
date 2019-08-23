/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL&&root->right==NULL) return 1;
        if (root->left==NULL||root->right==NULL) 
        {
            return 1+max(minDepth(root->left),minDepth(root->right));
        }
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

