/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return coregenerateTree(1,n);
    }
    vector<TreeNode*> coregenerateTree(int left,int right) {
        vector<TreeNode*> res;
        if(left>right)
            return res;
        if(left==right)
        {
            TreeNode* root=new TreeNode(left);
            res.push_back(root);
            return res;
        }
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*> leftTrees=coregenerateTree(left,i-1);
            vector<TreeNode*> rightTrees=coregenerateTree(i+1,right);
            if(leftTrees.size()==0)
            {
                for(auto rightnode:rightTrees)
                {
                    TreeNode* root=new TreeNode(i);
                    root->right=rightnode;
                    res.push_back(root);
                }
            }
            else if(rightTrees.size()==0)
            {
                for(auto leftnode:leftTrees)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=leftnode;
                    res.push_back(root);
                }
            }
            else
            {
                for(auto leftnode:leftTrees)
                {
                    for(auto rightnode:rightTrees)
                    {
                        TreeNode* root=new TreeNode(i);
                        root->left=leftnode;
                        root->right=rightnode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
