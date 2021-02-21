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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res=false;
        if(s==nullptr||t==nullptr)
            return false;
        if(s->val==t->val)
        {
            res=isSametree(s, t);
            if(res)
                return res;
        }
        if(isSubtree(s->left, t))
            return true;
        else
            return isSubtree(s->right, t);
    }
    bool isSametree(TreeNode* s, TreeNode* t)
    {
        if(s&&t)
        {
            if(s->val!=t->val)
                return false;
            else
                return isSametree(s->left, t->left)&&isSametree(s->right, t->right);
        }
        else if(s==nullptr&&t==nullptr)
            return true;
        else
            return false;
    }
};
