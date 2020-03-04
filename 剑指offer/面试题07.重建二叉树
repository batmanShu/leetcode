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
        return buildTreeCore(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    TreeNode* buildTreeCore(vector<int>::iterator prebegin, vector<int>::iterator preend, vector<int>::iterator inbegin, vector<int>::iterator inend){
        if(inend==inbegin) return nullptr;
        TreeNode* root=new TreeNode(*prebegin);
        auto itr_root=find(inbegin,inend,*prebegin);
        root->left=buildTreeCore(prebegin+1,prebegin+(itr_root-inbegin)+1,inbegin,itr_root);
        root->right=buildTreeCore(prebegin+(itr_root-inbegin)+1,preend,itr_root+1,inend);
        return root;
    }
};
