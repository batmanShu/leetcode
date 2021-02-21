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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        if(k==1)
            return head;
        for(int i=0;i<k;i++)
        {
            if(temp==nullptr)
                return head;
            temp=temp->next;
        }
        ListNode* tailnode=head;
        ListNode* curnode=head;
        ListNode* prevnode=nullptr;
        ListNode* nextnode=head->next;
        for(int i=0;i<k;i++)
        {
            curnode->next=prevnode;
            prevnode=curnode;
            curnode=nextnode;
            if(curnode)
                nextnode=curnode->next;
        }
        tailnode->next=reverseKGroup(curnode,k);
        return prevnode;
    }
};
