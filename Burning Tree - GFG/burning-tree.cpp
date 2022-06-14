// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
    Node* helper(Node* root,int target){
        if(root==NULL)
        return NULL;
        
        if(root->data==target){
           return root; 
           
        }
        
        Node* l=helper(root->left,target);
        Node* r=helper(root->right,target);
        
        // if(left==NULL && right==NULL)
        // return NULL;
        
        if(l==NULL)
        return r;
        
       else if(r==NULL)
        return l;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL)
        return 0;
        
        queue<Node*> q;
        unordered_map<Node*,Node*> parent;
        
        q.push(root);
        
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
        
        Node* start= helper(root,target);
       
        
        unordered_map<Node*,int> vis;
        
        q.push(start);
        vis[start]=1;
        int Time=-1;
        
        while(!q.empty()){
            int size=q.size();
            Time++;
            
            while(size-- >0){
                Node* node=q.front();
                q.pop();
                
                if(node->left && vis[node->left]==0){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                
                if(node->right && vis[node->right]==0){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                
                if(parent[node] && vis[parent[node]]==0){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
        }
        
        return Time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends