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
        if(root==nullptr)
            return root;
        deque<Node*> dq;
        dq.push_back(root);
        while(!dq.empty())
        {
            int layer_cnt=dq.size();
            Node* prev=nullptr;
            for(int i=0;i<layer_cnt;i++)
            {
                Node* cur=dq.front();
                if(i!=0)
                    prev->next=cur;
                dq.pop_front();
                if(cur->left)
                    dq.push_back(cur->left);
                if(cur->right)
                    dq.push_back(cur->right);
                prev=cur;
            }
        }
        return root;
    }
};
