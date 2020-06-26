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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode* prevnode=nullptr;
        ListNode* curnode=head;
        ListNode* nextnode=head->next;
        while(curnode)
        {
            if(mp[curnode->val]==1)
            {
                prevnode->next=nextnode;
                curnode=nextnode;
                if(curnode)
                    nextnode=curnode->next;
                else
                    nextnode=nullptr;
            }
            else
            {
                mp[curnode->val]=1;
                prevnode=curnode;
                curnode=nextnode;
                if(curnode)
                    nextnode=curnode->next;
                else
                    nextnode=nullptr;
            }
                
        }
        return head;
    }
private:
    unordered_map<int, int> mp;
};
