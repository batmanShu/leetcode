/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
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
        ListNode *ini_headB=headB;
        while(headA!=NULL)
        {
            while(headB!=NULL)
            {
                if(headA==headB)
                {
                    return (headA);
                }
                headB=headB->next;
            }
            headA=headA->next;
            headB=ini_headB;
        }
        return NULL;
    }
};

