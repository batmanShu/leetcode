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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        list<TreeNode*> curnodes;
        if(!root) return res;
        res.push_back(root->val);
        curnodes.push_back(root);
        while(!curnodes.empty())
        {
            TreeNode* node=curnodes.front();
            curnodes.pop_front();
            if(node->left)
            {
                res.push_back(node->left->val);
                curnodes.push_back(node->left);
            }
            if(node->right)
            {
                res.push_back(node->right->val);
                curnodes.push_back(node->right);
            }
        }
        return res;
    }
};
