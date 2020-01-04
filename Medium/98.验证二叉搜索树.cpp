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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sk;
        long temp=LONG_MIN;
        while(root||sk.size())
        {
            while(root)
            {
                sk.push(root);
                root=root->left;
            }
            root=sk.top();
            sk.pop();
            if(temp>=root->val) return false;
            temp=root->val;
            root=root->right;
        }
        return true;
    }
};
