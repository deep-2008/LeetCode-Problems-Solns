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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> temp;
        
        if(headA==NULL || headB==NULL)
            return NULL;
        
        ListNode* a=headA,*d=headA,*b=headB,*c=headB;
        
//        while(a->next!=NULL)
//            a=a->next;
        
//         while(c->next!=NULL)
//             c=c->next;
        
//         if(a!=c)
//             return NULL;
        
//         a->next=b;
//         c->next=d;
        
//         while(a->next!=NULL && c->next!=NULL){
//             a=a->next;
//             c=c->next;
//         }
        
        while(a!=b){
            if(a==NULL)
                a=headB;
            else
                a=a->next;
            
            if(b==NULL)
                b=headA;
            else
                b=b->next;
        }
        
       return a;
        
        
    }
};