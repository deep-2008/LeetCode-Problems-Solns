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
    ListNode* partition(ListNode* head, int x) {
       ListNode* dummyMore=new ListNode(0);
       ListNode* dummyLess=new ListNode(0);
       ListNode* less=dummyLess,*more=dummyMore,*curr=head;
        
        while(curr){
            if(curr->val <x){
                less->next=curr;
                less=curr;
            }
            
            else{
                more->next=curr;
                more=curr;
            }
            
            curr=curr->next;
        }
        
        more->next=NULL;        
        less->next=dummyMore->next;
        
        return dummyLess->next;
    }
};