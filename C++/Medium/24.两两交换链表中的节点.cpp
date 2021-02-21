/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* firstNode=new ListNode(-1);//虚拟头结点
        firstNode->next=head;
        ListNode* cur=firstNode;
        while(cur->next)
        {
            if(cur->next->next)
            {
                ListNode* temp=cur->next->next;
                cur->next->next=cur->next->next->next;
                temp->next=cur->next;
                cur->next=temp;
                cur=temp->next;
            }
            else
            {
                cur=cur->next;
            }
        }
        return firstNode->next;
    }
};
// @lc code=end

