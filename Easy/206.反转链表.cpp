/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* previousNode=NULL;
        ListNode* currentNode=head;
        ListNode* nextNode=head->next;
        while(nextNode!=NULL)
        {
            currentNode->next=previousNode;
            previousNode=currentNode;
            currentNode=nextNode;
            nextNode=currentNode->next;
        }
        currentNode->next=previousNode;
        return currentNode;
    }
};
// @lc code=end

