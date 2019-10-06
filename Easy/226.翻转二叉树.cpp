/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL||isleafNode(root))//注意||其实是有先后顺序的
        {
            return root;
        }
        if(root->left!=NULL&&root->right!=NULL)
        {
            root->left=invertTree(root->left);
            root->right=invertTree(root->right);
            TreeNode* tempNode=root->left;
            root->left=root->right;
            root->right=tempNode;
        }
        else if(root->left==NULL)
        {
            root->right=invertTree(root->right);
            root->left=root->right;
            root->right=NULL;
        }
        else
        {
            root->left=invertTree(root->left);
            root->right=root->left;
            root->left=NULL;
        }
        
        return root;
    }
    bool isleafNode(TreeNode* root){
        if(root->left==NULL&&root->right==NULL)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

