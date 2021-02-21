/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val==val) return head->next;
        ListNode* prevnode=head;
        ListNode* node=head->next;
        while(node&&node->val!=val)
        {
            prevnode=node;
            node=node->next;
        }
        if(node)
        {
            prevnode->next=node->next;
        }
        return head;
    }
};
