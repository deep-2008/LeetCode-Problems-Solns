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
        Node* temp=root;
        queue<Node*> q;
        
        if(root==NULL)
            return NULL;
        
        q.push(temp);
        // root->next=NULL;
        // temp->next=NULL;
        
        while(!q.empty()){
            int size=q.size();
            Node* prev=NULL;
            
            while(size-- > 0){
                Node* node=q.front();
                
                q.pop();
                
                // if(size==0)
                //     node->next=NULL;
                // else
                //     node->next=
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right)
                    q.push(node->right);
                
                if(prev!=NULL)
                    prev->next=node;
                prev=node;
            }
        }
        return root;
    }
};

