/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyptr=new ListNode(-1);
        if(head==nullptr)
        {
            return nullptr;
        }
        else
        {
            dummyptr->next=head;
        }
        ListNode* curptr=dummyptr;
        while(curptr!=nullptr&&curptr->next!=nullptr)
        {
            if(curptr->next->val==val) 
            {
                curptr->next=curptr->next->next;
            }
            else
            {
                curptr=curptr->next;
            }
        }
        return dummyptr->next;
    }
};

