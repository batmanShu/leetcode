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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        int flag=1;
        while(!nodes.empty())
        {
            vector<int> temp;
            int l=nodes.size();
            while(l>0)
            {
                l--;
                if(flag==1)
                {
                    TreeNode* node=nodes.front();
                    nodes.pop_front();
                    temp.push_back(node->val);
                    if(node->left) nodes.push_back(node->left);
                    if(node->right) nodes.push_back(node->right);
                }
                else
                {
                    TreeNode* node=nodes.back();
                    nodes.pop_back();
                    temp.push_back(node->val);
                    if(node->right) nodes.push_front(node->right);
                    if(node->left) nodes.push_front(node->left);
                }
            }
            res.push_back(temp);
            flag=-flag; 
        }
        return res;
    }
};
