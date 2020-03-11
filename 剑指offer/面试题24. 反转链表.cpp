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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* prev_node=nullptr;
        ListNode* cur_node=head;
        ListNode* next_node=head->next;
        while(cur_node)
        {
            next_node=cur_node->next;
            cur_node->next=prev_node;
            prev_node=cur_node;
            cur_node=next_node;
        }
        return prev_node;
    }
};
