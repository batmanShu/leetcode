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
        unordered_map<Node*,Node*> copymap;
        Node* copyhead=new Node(head->val);
        Node* copynode=copyhead;
        Node* node=head;
        while(node)
        {
            copymap[node]=copynode;
            copynode->random=node->random;
            if(node->next)
            {
                Node* next_node=new Node(node->next->val);
                copynode->next=next_node;
            }
            node=node->next;
            copynode=copynode->next;
        }
        copynode=copyhead;
        while(copynode)
        {
            copynode->random=copymap[copynode->random];
            copynode=copynode->next;
        }
        return copyhead;
    }
};
