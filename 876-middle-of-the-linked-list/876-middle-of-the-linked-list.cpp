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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
            return head;
        
       int count=0;
        ListNode* temp=head;
        
        while(temp){
            count++;
            temp=temp->next;
        }
        
        ListNode *dummy=new ListNode(0);
        ListNode *fast=NULL,*slow=NULL;
        
        if(count%2==0){
           
            dummy->next=head;
            fast=dummy;slow=dummy;
        }
        
        else{
            fast=head;slow=head;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(count%2==0)
            return slow->next;
        
        return slow;
    }
};