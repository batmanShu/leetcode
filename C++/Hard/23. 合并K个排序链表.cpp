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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            head=merge2Lists(head,lists[i]);
        }
        return head;
    }
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        if(head1->val>head2->val)
        {
            ListNode* node=merge2Lists(head1,head2->next);
            head2->next=node;
            return head2;
        }
        else
        {
            ListNode* node=merge2Lists(head1->next,head2);
            head1->next=node;
            return head1;
        }
    }
};
