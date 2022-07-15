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
    ListNode* midNode(ListNode* head,ListNode* tail){
        auto fast=head,slow=head;
        
        while(fast!=tail && fast->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* mergeSorted(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return NULL;
        
        auto dummy=new ListNode(0);
        
        auto l1=list1,l2=list2,prev=dummy;
        
        while(l1 && l2){
            if(l1->val<=l2->val){
                prev->next=l1;
                prev=l1;
                l1=l1->next;
            }
            
            else if(l1->val > l2->val){
                prev->next=l2;
                prev=l2;
                l2=l2->next;
            }
        }
        
        if(l1)
            prev->next=l1;
        
        if(l2)
            prev->next=l2;
        
        return dummy->next;
    }
    
    auto sortedList(ListNode* head,ListNode* tail){
        if(head==tail){
            ListNode* temp=new ListNode(head->val);
            return temp;
        }
        
        auto mid=midNode(head,tail);
        auto fh= sortedList(head,mid);
        auto sh=sortedList(mid->next,tail);
        
        return mergeSorted(fh,sh);
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        
        auto tail=head;
        while(tail->next)
            tail=tail->next;
        
        return sortedList(head,tail);
    }
};