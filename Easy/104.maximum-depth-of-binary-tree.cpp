/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        int leftDepth=0;
        int rightDepth=0;
        if (root==nullptr) return 0;
        if (root->left==nullptr&&root->right==nullptr) return 1;
        else
        {
            if(root->left!=nullptr)
            {
                leftDepth=maxDepth(root->left);
            }
            else
            {
                leftDepth=0;
            }
            
            if(root->right!=nullptr)
            {
                rightDepth=maxDepth(root->right);
            }
            else
            {
                rightDepth=0;
            }
            
            return ++(leftDepth>=rightDepth?leftDepth:rightDepth);
        }
        
    }
};

