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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> lefttree;
        vector<int> righttree;
        if(root==NULL) return lefttree;
        else
        {
            if(!root->left&&!root->right)
            {
                lefttree.push_back(root->val);
                return lefttree;
            }
        } 
        lefttree=inorderTraversal(root->left);
        righttree=inorderTraversal(root->right);
        lefttree.push_back(root->val);
        lefttree.insert(lefttree.end(),righttree.begin(),righttree.end());
        return lefttree;
    }
};
