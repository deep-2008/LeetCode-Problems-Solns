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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};