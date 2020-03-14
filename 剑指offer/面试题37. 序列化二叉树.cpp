/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
            ostringstream out;  //字符串输出流
            queue<TreeNode *> treeq;
            treeq.push(root);
            out<<"[";
            while(!treeq.empty())
            {
                TreeNode *frontNode = treeq.front();
                treeq.pop();  //出队
                if(frontNode)
                {
                    out<<frontNode->val<<",";  //这里会直接将整数val变成字符串
                    treeq.push(frontNode->left);
                    treeq.push(frontNode->right);
                }
                else
                {
                    out<<"null"<<",";
                }
            }
            string s=out.str();
            int i;
            for(i=s.size()-1;i>=0;i--)
            {
                if(s[i]>='0'&&s[i]<='9') break;
            }
            s.erase(i+1);
            s=s+"]";
            cout<<s<<endl;
            return s;  //务必注意要返回string
        }

    // Encodes a tree to a single string.
    /*string serialize(TreeNode* root) {
        if(!root) return "[]";
        string s="[";
        s=s+to_string(root->val)+",";
        layerorder(s,root);
        int i;
        for(i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='0'&&s[i]<='9') break;
        }
        s.erase(i+1);
        s=s+"]";
        return s;
    }*/

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()<=2) return nullptr;
        vector<TreeNode*> s;
        for(int i=1;i<=data.size()-2;)
        {
            int j;
            for(j=i+1;j<=data.size()-2;j++)
            {
                if(data[j]==',') break;
            }
            string temp=data.substr(i,j-i);
            if(temp=="null") s.push_back(NULL);
            else
            {
                TreeNode* node=new TreeNode(atoi(temp.c_str()));
                s.push_back(node);
            }
            i=j+1;
        }
        TreeNode* head=s[0];
        int i=0,j=1;
        for(;j<s.size();i++)
        {
            if(s[i]==NULL) continue;
            if(j<s.size()) s[i]->left=s[j++];
            if(j<s.size()) s[i]->right=s[j++];
        }
        return head;
    }

    /*void layerorder(string& s, TreeNode* root) {
        list<TreeNode*> nodes;
        nodes.push_back(root);
        while(!nodes.empty())
        {
            TreeNode* node=nodes.front();
            nodes.pop_front();
            if(node->left)
            {
                nodes.push_back(node->left);
                s=s+to_string(node->left->val)+",";
            }
            else
            {
                s=s+"null,";
            }
            if(node->right)
            {
                nodes.push_back(node->right);
                s=s+to_string(node->right->val)+",";
            }
            else{
                s=s+"null,";
            }
        }
    }*/
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
