/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        deque<Node*> dq;
        dq.push_back(root);
        Node* nextnode=root;
        Node* curnode=nullptr;
        while(!dq.empty())
        {
            int l=dq.size();
            for(int i=0;i<l;i++)
            {
                curnode=dq.front();
                dq.pop_front();
                if(!dq.empty())
                    nextnode=dq.front();
                else
                    nextnode=nullptr;
                if(i==l-1)
                {
                    curnode->next=nullptr;
                }
                else
                {
                    curnode->next=nextnode;
                }
                if(curnode->left)
                    dq.push_back(curnode->left);
                if(curnode->right)
                    dq.push_back(curnode->right);
            }
        }
        return root;
    }
};
