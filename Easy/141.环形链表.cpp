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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode* p=head->next;
        ListNode* q=head->next->next;
        while(p!=q)
        {
            if(!p||!q||!q->next) return false;
            p=p->next;
            q=q->next->next;
        }
        return true;
    }
};
