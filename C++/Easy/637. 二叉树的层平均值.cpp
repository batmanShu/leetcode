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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vec_ans;
        list<TreeNode*> l;
        l.push_back(root);
        while(!l.empty())
        {
            int s=l.size();
            double sum=0;
            for(int i=0;i<s;i++)
            {
                TreeNode* node=l.front();
                l.pop_front();
                sum+=node->val;
                if(node->left)
                    l.push_back(node->left);
                if(node->right)
                    l.push_back(node->right);
            }
            double avg=sum/s;
            vec_ans.push_back(avg);
        }
        return vec_ans;
    }
};
