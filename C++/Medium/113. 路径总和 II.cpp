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
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        backtrack(root,temp,sum);
        return ans;
    }

    void backtrack(TreeNode* root,vector<int>& cur_path,int cur_sum) {
        if(!root)
            return;
        if(isleaf(root))
        {
            if(cur_sum-root->val==0)
            {
                cur_path.push_back(root->val);
                ans.push_back(cur_path);
                cur_path.pop_back();
            }
        }
        else
        {
            cur_path.push_back(root->val);
            backtrack(root->left,cur_path,cur_sum-root->val);
            backtrack(root->right,cur_path,cur_sum-root->val);
            cur_path.pop_back();
        }
    }

    bool isleaf(TreeNode* root) {
        if(!root->left&&!root->right)
            return true;
        return false;
    }
};
