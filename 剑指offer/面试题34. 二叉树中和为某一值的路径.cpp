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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> path;
        pathSumCore(root,sum,res,path);
        return res;
    }
    void pathSumCore(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path){
        if(!root) return;
        path.push_back(root->val);
        int result=sum-root->val;
        if(!root->left&&!root->right&&result==0) res.push_back(path);
        pathSumCore(root->left,result,res,path);
        pathSumCore(root->right,result,res,path);
        path.erase(path.end()-1);
    }
};
