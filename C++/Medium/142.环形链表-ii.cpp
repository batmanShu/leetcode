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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        ListNode *p1=head;
        ListNode *p2=head;
        ListNode *p3=head->next;
        while(p2!=p3)
        {
            if(!p2||!p3||!p3->next) return NULL;
            p2=p2->next;
            p3=p3->next->next;
        }
        while(p2->next!=p1)
        {
            p2=p2->next;
            if(p2==p3) p1=p1->next;
        }
        return p1;        
    }
};
