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
    vector<int> findMode(TreeNode* root) {
        most=1;
        vector<int> ans;
        inorder(root);
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second==most)
                ans.push_back(itr->first);
        }
        return ans;
    }
private:
    unordered_map<int,int> mp;
    int most;

    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        mp[root->val]++;
        most=max(most,mp[root->val]);
        inorder(root->right);
    }
};
