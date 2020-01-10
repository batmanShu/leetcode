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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        TreeNode* head=new TreeNode(preorder[0]);
        if(preorder.size()==1) return head;
        if(preorder.size()==2)
        {
            if(preorder[0]==inorder[0])
            {
                TreeNode* right=new TreeNode(preorder[1]);
                head->right=right;
                return head;
            }
            else
            {
                TreeNode* left=new TreeNode(preorder[1]);
                head->left=left;
                return head;
            }
        }
        auto itr1=find(inorder.begin(),inorder.end(),preorder[0]);
        vector<int> lefttree_inorder(inorder.begin(),itr1);
        itr1++;
        vector<int> righttree_inorder(itr1,inorder.end());
        auto itr2=preorder.begin()+1;
        int lefttree_size=lefttree_inorder.size();
        vector<int> lefttree_preorder(itr2,itr2+lefttree_size);
        vector<int> righttree_preorder(itr2+lefttree_size,preorder.end());
        head->left=buildTree(lefttree_preorder,lefttree_inorder);
        head->right=buildTree(righttree_preorder,righttree_inorder);
        return head;
    }
};
