/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        ListNode* head=new ListNode(-1);
        head->next=l1;
        ListNode* cur=head;
        while(cur->next&&l2)
        {
            if(cur->next->val>=l2->val)
            {
                ListNode* temp=cur->next;
                if(l2->next)
                {
                    ListNode* l2_next=l2->next;
                    cur->next=l2;
                    cur->next->next=temp;
                    cur=cur->next;
                    l2=l2_next;
                }
                else
                {
                    cur->next=l2;
                    cur->next->next=temp;
                    return head->next;
                }
                
            }
            else
            {
                cur=cur->next;
            }
            if(!cur->next&&l2)
            {
                cur->next=l2;
                return head->next;
            }
        }
        
        return head->next;
    }
};
// @lc code=end

