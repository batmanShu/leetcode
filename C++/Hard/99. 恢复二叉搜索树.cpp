/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* x=nullptr, *y=nullptr, *pred=nullptr, *predecessor=nullptr;
        while(root!=nullptr)
        {
            if(root->left!=nullptr)
            {
                predecessor=root->left;
                while(predecessor->right!=nullptr&&predecessor->right!=root)
                {
                    predecessor=predecessor->right;
                }
                if(predecessor->right==nullptr)
                {
                    predecessor->right=root;
                    root=root->left;
                }
                else
                {
                    if(pred&&pred->val>root->val)
                    {
                        y=root;
                        if(x==nullptr)
                        {
                            x=pred;
                        }
                    }
                    predecessor->right=nullptr;
                    pred=root;
                    root=root->right;
                }
            }
            else
            {
                if(pred&&pred->val>root->val)
                {
                    y=root;
                    if(x==nullptr)
                    {
                        x=pred;
                    }
                }
                pred=root;
                root=root->right;
            }
        }
        swap(x->val,y->val);
    }
};
