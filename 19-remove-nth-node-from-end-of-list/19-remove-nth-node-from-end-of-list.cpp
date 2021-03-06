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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        auto prev=dummy,curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }curr=head;
        
        count=count-n;
        
        while(count-->0){
            prev=curr;
            curr=curr->next;
        }prev->next=curr->next;
        
        return dummy->next;
    }
};