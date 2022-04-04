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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int n=0;
        ListNode* temp=head;
        
        while(temp != NULL){
            n++;
            temp=temp->next;
        }
         temp=head;
        
        if(n==1)
            return head;
        
        if(n==2){
            swap(temp->val,temp->next->val);
            return head;
        }
       int a=k-1;
        while(a>0){
            temp=temp->next;
            a--;}
       // int x=temp->val;
        //temp=head;
        
        ListNode* temp2=head;
        int b=n-k;
        while(b>0){
            temp2=temp2->next;
            b--;}
       // int y=temp->val;
        //temp=head;
        swap(temp->val,temp2->val);
        return head;
        
       /* while(temp!=NULL){
            if(temp->val==x)
                temp->val=y;
            
            if(temp->val=y)
                temp->val=x;
            
            temp=temp->next;
        }
        return head;*/
    }
};