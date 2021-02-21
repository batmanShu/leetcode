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
        vector<vector<int>> res;
        if(!root) return res;
        list<TreeNode*> curnodes;
        curnodes.push_back(root);
        vector<int> temp;
        temp.push_back(root->val);
        while(!curnodes.empty())
        {
            res.push_back(temp);
            temp.clear();
            int l=curnodes.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* node=curnodes.front();
                curnodes.pop_front();
                if(node->left)
                {
                    curnodes.push_back(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right)
                {
                    curnodes.push_back(node->right);
                    temp.push_back(node->right->val);
                }
            }
        }
        return res;
    }
};
