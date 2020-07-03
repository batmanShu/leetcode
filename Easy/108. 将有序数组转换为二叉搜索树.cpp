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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return nullptr;
        if(len==1)
        {
            TreeNode* root= new TreeNode(nums[0]);
            return root;
        }
        int root_ind=(len%2==0)?len/2-1:len/2;
        TreeNode* root=new TreeNode(nums[root_ind]);
        vector<int> leftnums(nums.begin(),nums.begin()+root_ind);
        vector<int> rightnums(nums.begin()+root_ind+1,nums.end());
        root->left=sortedArrayToBST(leftnums);
        root->right=sortedArrayToBST(rightnums);
        return root;
    }
};
