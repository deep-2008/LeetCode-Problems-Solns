// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
/*int solve(Node* root,int &res){
    if(root==NULL)
    return 0;
    
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    
    int temp=max(l,r)+root->data;
    if(root->left==NULL && root->right==NULL)
    temp=max(temp,root->data);
    
   // int ans=max(ans,l+r+root->data);
   int ans=l+r+root->data;
    res=max(res,ans);
    if(root->left &&root->right)
    return temp;
    
    else if(root->left)
    return l+root->data;
    
    else
    return r+root->data;
}

    int maxPathSum(Node* root)
    {
        // code here
        int res=INT_MIN;
        int c=solve(root,res);
        return res;
    }*/
    int maxsum =INT_MIN;

   int maxPathSumUtil(Node* root)
   {
       if(!root)return 0;
       int l = maxPathSumUtil(root->left);
       int r= maxPathSumUtil(root->right);
       if(root->left && root->right){
       maxsum =max(maxsum,l+r+root->data);
       return root->data+max(l,r);}
       else if(root->left)return root->data+l;
       else return root->data+r;
   }
   int maxPathSum(Node* root){
       int x= maxPathSumUtil(root);
       if(root->left && root->right)return maxsum;
       return max(maxsum,x);
   }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends