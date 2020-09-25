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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root=buildTreeCore(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }

    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& postorder, int l0, int r0, int l1, int r1) {
        if(l0>r0||l1>r1)
            return nullptr;
        int root_val=postorder[r1];
        int inorder_ind;
        for(inorder_ind=l0;inorder_ind<=r0;inorder_ind++)
        {
            if(inorder[inorder_ind]==root_val)
                break;
        }
        int postorder_ind=inorder_ind-l0+l1;
        TreeNode* root=new TreeNode(root_val);
        TreeNode* left=buildTreeCore(inorder,postorder,l0,inorder_ind-1,l1,postorder_ind-1);
        TreeNode* right=buildTreeCore(inorder,postorder,inorder_ind+1,r0,postorder_ind,r1-1);
        root->left=left;
        root->right=right;
        return root;
    }
};
