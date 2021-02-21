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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> roots;
        roots.push_back(root);
        vector<vector<int>> res;
        helper(roots,res);
        return res;
    }
    void helper(vector<TreeNode*> roots,vector<vector<int>> &res)
    {
        vector<TreeNode*> nextroots;
        vector<int> temp;
        for(auto a:roots)
        {
            if(a==NULL) continue;
            temp.push_back(a->val);
            nextroots.push_back(a->left);
            nextroots.push_back(a->right);
        }
        if(nextroots.size()==0) return;
        res.push_back(temp);
        helper(nextroots,res);
    }
};
