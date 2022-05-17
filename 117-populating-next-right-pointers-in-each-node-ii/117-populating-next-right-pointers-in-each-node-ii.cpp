/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
     if(root==NULL)return root;
       
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *curr;
            Node *prev=NULL;
            
            int n =q.size();
            for(int i=0;i<n;i++){
                curr=q.front();
                q.pop();
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                if(prev!=NULL)
                    prev->next=curr;
                prev=curr;
            }
            curr->next=NULL;
            
        }
        
        return root;
        
    }
};