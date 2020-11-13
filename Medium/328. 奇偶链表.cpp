/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        ListNode* prev_odd=nullptr;
        ListNode* cur_odd=oddhead;
        ListNode* next_odd=nullptr;
        if(cur_odd&&cur_odd->next)
            next_odd=cur_odd->next->next;
        ListNode* prev_even=nullptr;
        ListNode* cur_even=evenhead;
        ListNode* next_even=nullptr;
        if(cur_even&&cur_even->next)
            next_even=cur_even->next->next;
        while(cur_odd&&cur_even)
        {
            prev_odd=cur_odd;
            prev_even=cur_even;
            cur_odd->next=next_odd;
            cur_even->next=next_even;
            cur_odd=next_odd;
            cur_even=next_even;
            if(cur_odd&&cur_odd->next)
                next_odd=cur_odd->next->next;
            else
                next_odd=nullptr;
            if(cur_even&&cur_even->next)
                next_even=cur_even->next->next;
            else
                next_even=nullptr;
        }
        if(cur_odd)
        {
            prev_odd=cur_odd;
        }
        prev_odd->next=evenhead;
        return oddhead;
    }
};
