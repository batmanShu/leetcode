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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head||k<1) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&k>0)
        {
            fast=fast->next;
            k--;
        }
        while(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
