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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        l1=reverselist(l1);
        l2=reverselist(l2);
        ListNode* head1=l1;
        int sum=0,c=0;
        while(l1&&l2)
        {
            sum=l1->val+l2->val+c;
            c=sum/10;
            sum=sum%10;
            l1->val=sum;
            if(l1->next==nullptr||l2->next==nullptr) break;
            l1=l1->next;
            l2=l2->next;
        }
        if(!l1->next)
        {
            l1->next=l2->next;
        }
        if(l1->next)
        {
            l1=l1->next;
            while(l1->next)
            {
                l1->val=l1->val+c;
                c=l1->val/10;
                l1->val=l1->val%10;
                l1=l1->next;
            }
            l1->val=l1->val+c;
            c=l1->val/10;
            l1->val=l1->val%10;
        }
        if(c>0)
        {
            ListNode* temp=new ListNode(c);
            l1->next=temp;
        }
        return reverselist(head1);
    }
    ListNode* reverselist(ListNode* head) {
        if(!head) return nullptr;
        ListNode* prev_node=nullptr;
        ListNode* node=head;
        ListNode* next_node=head->next;
        while(next_node)
        {
            node->next=prev_node;
            prev_node=node;
            node=next_node;
            next_node=node->next;
        }
        node->next=prev_node;
        return node;
    }
};
