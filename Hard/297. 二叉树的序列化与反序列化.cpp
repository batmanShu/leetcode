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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p)
            {
                res+=to_string(p->val)+',';
                q.push(p->left);
                q.push(p->right);
            }
            else res+="null,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto vec_s=split(data);
        if(vec_s[0]=="null") return nullptr;
        TreeNode* root=new TreeNode(stoi(vec_s[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty())
        {
            if(vec_s[i]!="null")
            {
                TreeNode* p=new TreeNode(stoi(vec_s[i]));
                q.front()->left=p;
                q.push(p);
            }
            i++;
            if(vec_s[i]!="null")
            {
                TreeNode* p=new TreeNode(stoi(vec_s[i]));
                q.front()->right=p;
                q.push(p);
            }
            i++;
            q.pop();
        }
        return root;
    }

    vector<string> split(string str) {
        int start=0;
        vector<string> res;
        while(1)
        {
            auto end=str.find(',',start);
            if(end==string::npos) break;
            res.push_back(str.substr(start,end-start));
            start=end+1;
        }
        return move(res);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
