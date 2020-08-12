/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        Node* root=new Node(node->val,node->neighbors);
        mp[root->val]=root;
        deque<Node*> dq;
        dq.push_back(root);
        while(!dq.empty())
        {
            Node* curnode=dq.front();
            dq.pop_front();
            for(int i=0;i<curnode->neighbors.size();i++)
            {
                Node* oldnode=curnode->neighbors[i];
                if(mp.find(oldnode->val)==mp.end())
                {
                    Node* newnode=new Node(oldnode->val,oldnode->neighbors);
                    curnode->neighbors[i]=newnode;
                    dq.push_back(newnode);
                    mp[newnode->val]=newnode;
                }
                else
                {
                    curnode->neighbors[i]=mp[oldnode->val];
                }
            }
        }
        return root;
    }
private:
    unordered_map<int,Node*> mp;
};
