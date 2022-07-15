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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *nodeBeforeSublist=dummy;
        int count=1;
        
        while(count<left){
            count++;
            nodeBeforeSublist=nodeBeforeSublist->next;
        }
        
        auto workingPointer=nodeBeforeSublist->next;
        
        while(left<right){
            ListNode* currPointer=workingPointer->next;
            workingPointer->next=currPointer->next;
            currPointer->next=nodeBeforeSublist->next;
            nodeBeforeSublist->next=currPointer;
            left++;
        }
        
        return dummy->next;
    }
};