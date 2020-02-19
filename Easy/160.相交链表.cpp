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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA=headA;
        ListNode *nodeB=headB;
        if(!nodeA||!nodeB) return nullptr;
        while(nodeA->next)
        {
            nodeA=nodeA->next;
        }
        while(nodeB->next)
        {
            nodeB=nodeB->next;
        }
        if(nodeA!=nodeB) return nullptr;
        nodeA=headA;
        nodeB=headB;
        while(nodeA!=nodeB)
        {
            if(nodeA->next==nullptr) nodeA=headB;
            else nodeA=nodeA->next;
            if(nodeB->next==nullptr) nodeB=headA;
            else nodeB=nodeB->next;
        }
        return nodeA;
    }
};
