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
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxsum;
    }
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        int sum=root->val+maxgain(root->left)+maxgain(root->right);
        sum=max(max(sum,maxPathSum(root->left)),maxPathSum(root->right));
        if(sum>maxsum) maxsum=sum;
        return sum;
    }
    int maxgain(TreeNode* root) {
        if(root==nullptr) return 0;
        if(gainmp.find(root)!=gainmp.end()) return gainmp[root];
        int gain=root->val+max(maxgain(root->left),maxgain(root->right));
        gain=gain>0?gain:0;
        gainmp[root]=gain;
        return gain;
    }
private:
    int maxsum=INT_MIN;
    unordered_map<TreeNode*,int> gainmp;
};
