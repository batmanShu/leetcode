/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mp;
        Node* node=head;
        while(node)
        {
            mp[node]=node->random;
            node=node->next;
        }
        Node* copynodehead=new Node(head->val);
        Node* copynode=copynodehead;
        while(head)
        {
            copynode->random=mp[head];
            mp[head]=copynode;
            if(head->next)
            {
                Node* nextcopynode=new Node(head->next->val);
                copynode->next=nextcopynode;
                copynode=copynode->next;
            }
            else
            {
                copynode->next=nullptr;
            }
            head=head->next;            
        }
        copynode=copynodehead;
        while(copynode)
        {
            copynode->random=mp[copynode->random];
            copynode=copynode->next;
        }
        return copynodehead;
    }
};
