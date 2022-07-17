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
    ListNode *detectCycle(ListNode *head) {
       ListNode* dummy=new ListNode(0);
        dummy->next=head;
        auto prev=head,fast=head,slow=head,temp=head;
        // int count=0,n=0;
        
//         while(temp){
//             temp=temp->next;
//             n++;
//         }
        
        while(fast && fast->next){
            // prev=prev->next;
            slow=slow->next;
            fast=fast->next->next;
            // n++;
            
            if(slow==fast)
                break;
        }
        
        if(!fast || !fast->next)
            return NULL;
        
        // slow=slow->next;
        
        while(slow!=temp){
            slow=slow->next;
            temp=temp->next;
            // count++;
        }
        
        // count=n-count;
        // while(count-->0){
            // prev=prev->next;
        // }
        return temp;
        
    }
};