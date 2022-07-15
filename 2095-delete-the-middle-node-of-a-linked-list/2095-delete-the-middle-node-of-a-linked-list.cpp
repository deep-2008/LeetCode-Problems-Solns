/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        auto slow=head,fast=head,prev=dummy;
        
        while(fast->next && fast->next->next){
            prev=prev->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast->next){
            slow=slow->next;
            prev=prev->next;
        }
        
        prev->next=slow->next;
        
        return dummy->next;
    }
};