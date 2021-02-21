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
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while(head!=NULL)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        for(int i=0,j=nums.size()-1;i<=j;i++,j--)
        {
            if(nums[i]==nums[j])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
