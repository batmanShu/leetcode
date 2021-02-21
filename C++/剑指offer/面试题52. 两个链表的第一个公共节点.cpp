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
        if(!headA||!headB) return nullptr;
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        int flag=2;
        while(nodeA&&nodeB)
        {
            if(nodeA==nodeB) return nodeA;
            if(!nodeA->next&&flag>0) 
            {
                flag--;
                nodeA=headB;
            }
            else
            {
                nodeA=nodeA->next;
            }
            if(!nodeB->next&&flag>0)
            {
                flag--;
                nodeB=headA;
            }
            else
            {
                nodeB=nodeB->next;
            }
        }
        return nullptr;
    }
};
