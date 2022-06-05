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
    ListNode* deleteDuplicates(ListNode* head) {
            int ch = 0;
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return head;
        }
        while(true)
        {
            while(head->next != NULL && head->val == head->next->val)
            {
                head = head->next;
                ch++;
            }
            if(ch != 0)
            {
                head = head->next;
            }
            if(head == NULL)
            {
                return NULL;
            }
            if(head->next == NULL)
            {
                return head;
            }
            if(head->next != NULL && head->val != head->next->val)
            {
                break;
            }
        }
        
        if(head == NULL)
        {
            return head;
        }
        if(head->next == NULL)
        {
            return head;
        }
        ListNode *h1 = head;
        ListNode *trail = head;
        while(h1->next != NULL)
        {
            if(h1->val == h1->next->val)
            {
                h1->next = h1->next->next;
                trail->next = trail->next->next;
            }
            else
            {
                h1 = h1->next;
                if(h1 != NULL && h1->next != NULL)
                {
                    if(h1->val != h1->next->val)
                    {
                        trail = trail->next;
                    }
                }
                
            }
        }
        return head;
    }
};