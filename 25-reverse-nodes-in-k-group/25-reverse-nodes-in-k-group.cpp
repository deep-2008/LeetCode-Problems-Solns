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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        int count=k;
        ListNode *prev=NULL,*curr=head,*next=NULL;
        
        while(curr && count-->0){
            // ListNode *temp=curr;
            // temp=temp->next;
            // curr->next=prev;
            // prev=curr;
            // curr=temp;
            
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        count=0;
        ListNode* temp=next;
        
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count<k){
            head->next=next;
            return prev;
        }
        
        if(next)
        head->next=reverseKGroup(next,k);
        
        return prev;
    }
};