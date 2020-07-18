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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1||!root2)
            return false;
        if(mp.find(make_pair(root1, root2))!=mp.end())
            return mp[make_pair(root1,root2)];
        int sum=root1->val+root2->val;
        bool flag=false;
        if(sum==target)
            flag=true;
        else if(sum<target)
            flag=twoSumBSTs(root1->right, root2, target) || twoSumBSTs(root1, root2->right, target);
        else
            flag=twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1, root2->left, target);
        mp[make_pair(root1,root2)]=flag;
        return flag;
    }
private:
    map<pair<TreeNode*,TreeNode*>,bool> mp;
};
