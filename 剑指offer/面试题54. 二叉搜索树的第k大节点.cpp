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
    int kthLargest(TreeNode* root, int k) {
        reverseinorder(root,k);
        return res->val;
    }
    void reverseinorder(TreeNode* root, int k) {
        if(!root||count>=k) return;
        reverseinorder(root->right,k);
        count++;
        if(count==k)
        {
            res=root;
            return;
        }
        reverseinorder(root->left,k);
    }
private:
    int count=0;
    TreeNode* res;
};
