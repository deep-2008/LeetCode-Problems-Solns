/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
       if(head==NULL)
           return head;
        
        queue<Node*> q;
        Node* temp=head;
        while(temp){
            if(temp->child)
                q.push(temp);
            temp=temp->next;
        }
        
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            
            Node* last=node->child,*temp=node->child;
            Node* curr=node;
            node=node->next;
            
            while(last->next){
                if(last->child)
                    q.push(last);
                last=last->next;
            }
            
            if(last->child)
                q.push(last);
            
            curr->next=temp;
            temp->prev=curr;
            curr->child=NULL;
            
            if(node){
                last->next=node;
                node->prev=last;
            }
        }
        
        return head;
    }
};