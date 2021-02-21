/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> results;
        if (root==NULL) return false;
        results=subtreesum(root);
        for (auto iter=results.begin();iter!=results.end();iter++)
        {
            if (*iter==sum)  return true;
        }
        return false;
    }
    vector<int> subtreesum(TreeNode* root){
        vector<int> temp;
        if(root->left==NULL)
        {
            if(root->right==NULL)
            {
                temp.push_back(root->val);
                return temp;
            }
            else
            {
                temp=subtreesum(root->right);
                for(auto iter=temp.begin();iter!=temp.end();iter++)
                {
                    *iter=*iter+root->val;
                }
                return temp;
            }
            
        }
        else
        {
            if(root->right==NULL)
            {
                temp=subtreesum(root->left);
                for(auto iter=temp.begin();iter!=temp.end();iter++)
                {
                    *iter=*iter+root->val;
                }
                return temp;
            }
            else
            {
                vector<int> temp1;
                vector<int> temp2;
                temp1=subtreesum(root->left);
                temp2=subtreesum(root->right);
                temp1.insert(temp1.end(),temp2.begin(),temp2.end());
                temp=temp1;
                for(auto iter=temp.begin();iter!=temp.end();iter++)
                {
                    *iter=*iter+root->val;
                }
                return temp;
            }
            
        }
        

    }
};

