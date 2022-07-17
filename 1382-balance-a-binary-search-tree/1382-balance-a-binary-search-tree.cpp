/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL)
            return;
        
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    
    TreeNode* balance(TreeNode* node,vector<int>& in,int lo,int hi){
        if(lo>hi)return NULL;
        
        int mid=(lo+hi)/2;
        
       TreeNode* root =new TreeNode(in[mid]);
         root->left=balance(node,in,lo,mid-1);
        root->right=balance(node,in,mid+1,hi);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        vector<int> in;
        inorder(root,in);
        
        TreeNode* node=new TreeNode(0);
        return balance(node,in,0,in.size()-1);
        
        // return node;
    }
};