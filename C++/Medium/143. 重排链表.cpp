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
    void reorderList(ListNode* head) {
        core(head);
    }

    ListNode* core(ListNode* head){
        if(!head)
            return head;
        ListNode* headnext=head->next;
        if(!headnext||!headnext->next)
            return head;
        ListNode* curnode=head;
        ListNode* prevnode=nullptr;
        while(curnode&&curnode->next)
        {
            prevnode=curnode;
            curnode=curnode->next;
        }
        prevnode->next=nullptr;
        head->next=curnode;
        curnode->next=core(headnext);
        return head;
    }
};
