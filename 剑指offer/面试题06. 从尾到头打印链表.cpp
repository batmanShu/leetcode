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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        while(head)
        {
            ret.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<ret.size()/2;i++)
        {
            swap(ret[i],ret[ret.size()-1-i]);
        }
        return ret;
    }
};
