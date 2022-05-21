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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        stack<int> st;
        if(head==NULL)
            return false;
        
        while(head!=NULL && head->next!=NULL){
            st.push(temp->val);
            temp=temp->next;
            head=head->next->next;
        }
        
        if(head!=NULL && head->next==NULL)
            temp=temp->next;
        
        while(!st.empty() && temp!=NULL){
            if(st.top()!=temp->val)
                return false;
            temp=temp->next;
            st.pop();
        }
        
        if(!st.empty() || temp!=NULL)
            return false;
        return true;
       
    }
};