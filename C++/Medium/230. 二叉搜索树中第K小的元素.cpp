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
    int kthSmallest(TreeNode* root, int k) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(1)
        {
            TreeNode* node=dq.front();
            if(node->left!=nullptr)
            {
                dq.push_front(node->left);
                node->left=nullptr;
            }
            else
            {
                dq.pop_front();
                k--;
                if(k==0)
                    return node->val;
                if(node->right!=nullptr)
                    dq.push_front(node->right);
            }
        }
        return -1;
    }
};
