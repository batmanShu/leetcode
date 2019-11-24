/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> veclist;
        ListNode* temp=head;
        while(temp)
        {
            veclist.push_back(temp->val);
            temp=temp->next;
        }
        if(veclist.size()-n==0) return head->next;
        ListNode* cur=new ListNode(veclist[0]);
        ListNode* ret=cur;
        for(int i=1;i<veclist.size();++i)
        {
            if(i==veclist.size()-n) continue;
            ListNode* temp=new ListNode(veclist[i]);
            cur->next=temp;
            cur=cur->next;
        }
        return ret;
    }
};
// @lc code=end

