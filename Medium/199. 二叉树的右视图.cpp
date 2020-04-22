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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> cur_layer;
        deque<TreeNode*> next_layer;
        if(root!=nullptr)
            cur_layer.push_back(root);
        while(!cur_layer.empty())
        {
            int temp=0;
            for(auto itr=cur_layer.begin();itr!=cur_layer.end();itr++)
            {
                temp=(*itr)->val;
                if((*itr)->left!=nullptr)
                    next_layer.push_back((*itr)->left);
                if((*itr)->right!=nullptr)
                    next_layer.push_back((*itr)->right);
            }
            cur_layer=next_layer;
            next_layer.clear();
            res.push_back(temp);
        }
        return res;
    }
};
