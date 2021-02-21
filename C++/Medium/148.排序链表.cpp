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
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* node)
    {
        if(!node || !node->next) return node;
        ListNode *fast=node;//快指针走两步
        ListNode *slow=node;//慢指针走一步
        ListNode *brek=node;//断点
        while(fast && fast->next)
        {
            fast=fast->next->next;
            brek=slow;
            slow=slow->next;
        }
        brek->next=nullptr;
        ListNode *l1=mergesort(node);
        ListNode *l2=mergesort(slow);
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        if(l1->val < l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l2->next,l1);
            return l2;
        }
    }
};
