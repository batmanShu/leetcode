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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        ListNode* pfakehead=new ListNode(-1);
        pfakehead->next=head;
        int count=0;
        while(head) 
        {
            count++;
            head=head->next;
        }
        if(count==0) return pfakehead->next;
        while(k>=count) k=k-count; 
        head=pfakehead->next;
        if(k==0) return head;
        ListNode* temp=head;
        for(int i=1;i<count-k;i++)
        {
            head=head->next;
        }
        pfakehead->next=head->next;
        ListNode* temp2=head->next;
        head->next=NULL;
        while(temp2&&temp2->next)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;
        return pfakehead->next;
    }
};
