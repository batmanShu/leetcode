/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        if(root==NULL)
        {
            return output;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            string s=to_string(root->val);
            output.push_back(s);
            return output;
        }
        if(root->left!=NULL&&root->right==NULL)
        {
            vector<string> leftoutput=binaryTreePaths(root->left);
            for(auto itr=leftoutput.begin();itr!=leftoutput.end();itr++)
            {
                string s=to_string(root->val)+"->";
                *itr=s+*itr;
            }
            return leftoutput;
        }
        if(root->left==NULL&&root->right!=NULL)
        {
            vector<string> rightoutput=binaryTreePaths(root->right);
            for(auto itr=rightoutput.begin();itr!=rightoutput.end();itr++)
            {
                string s=to_string(root->val)+"->";
                *itr=s+*itr;
            }
            return rightoutput;
        }
        vector<string> leftoutput=binaryTreePaths(root->left);
        vector<string> rightoutput=binaryTreePaths(root->right);
        for(auto itr=leftoutput.begin();itr!=leftoutput.end();itr++)
        {
            string s=to_string(root->val)+"->";
            *itr=s+*itr;
        }
        for(auto itr=rightoutput.begin();itr!=rightoutput.end();itr++)
        {
            string s=to_string(root->val)+"->";
            *itr=s+*itr;
        }
        leftoutput.insert(leftoutput.end(),rightoutput.begin(),rightoutput.end());
        return leftoutput;
    }
};
// @lc code=end

