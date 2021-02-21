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
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> s;
        int pos=0;
        while(pos<S.size())
        {
            int level=0;
            while(pos<S.size()&&S[pos]=='-')
            {
                level++;
                pos++;
            }
            int value=0;
            while(pos<S.size()&&isdigit(S[pos]))
            {
                value=value*10+S[pos]-'0';
                pos++;
            }
            if(level==s.size())
            {
                TreeNode* node=new TreeNode(value);
                if(s.size()!=0)
                    s.top()->left=node;
                s.push(node);
            }
            else
            {
                while(level!=s.size())
                    s.pop();
                TreeNode* node=new TreeNode(value);
                s.top()->right=node;
                s.push(node);
            }
        }
        while(s.size()>1)
            s.pop();
        return s.top();
    }
};
