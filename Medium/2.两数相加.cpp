/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret=new ListNode(-1);
        ListNode* result=ret;
        int c=0;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1==NULL)
            {
                int num=c+l2->val;
                c=num/10;
                ret->next=new ListNode(num%10);
                ret=ret->next;
                l2=l2->next;
            }
            else if(l2==NULL)
            {
                int num=c+l1->val;
                c=num/10;
                ret->next=new ListNode(num%10);
                ret=ret->next;
                l1=l1->next;
            }
            else
            {
                int num=l1->val+l2->val+c;
                c=num/10;
                ret->next=new ListNode(num%10);
                ret=ret->next;
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(c!=0) ret->next=new ListNode(c); 
        return result->next;
    }
};
// @lc code=end

