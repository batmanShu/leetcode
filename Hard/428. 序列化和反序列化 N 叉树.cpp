/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s="";
        if(!root)
            return s;
        s+=to_string(root->val);
        s+="[";
        for(int i=0;i<root->children.size();i++)
        {
            s+=serialize(root->children[i]);
            if(i!=root->children.size()-1)
                s+=" ";
        }
        s+="]";
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size()==0)
            return nullptr;
        int i=0;
        Node* root=new Node(readdata(data,i));
        string temp=data.substr(i+1,data.size()-i-2);
        root->children=getchildren(temp);
        return root;
    }

    vector<Node*> getchildren(string data) {
        vector<Node*> ans;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]>='0'&&data[i]<='9')
            {
                int j=i;
                int left=0,right=0;
                while(j<data.size()&&data[j]!=' '||left!=right)
                {
                    if(data[j]=='[')
                        left++;
                    else if(data[j]==']')
                        right++;
                    j++;
                }
                string temp=data.substr(i,j-i);
                Node* node=deserialize(temp);
                ans.push_back(node);
                i=j;
            }
        }
        return ans;
    }

private:


    int readdata(string s,int& start) {
        int ans=0;
        while(s[start]>='0'&&s[start]<='9')
        {
            ans=ans*10+(s[start]-'0');
            start++;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
