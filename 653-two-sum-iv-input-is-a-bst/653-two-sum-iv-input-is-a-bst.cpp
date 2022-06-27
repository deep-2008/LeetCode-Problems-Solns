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
class BSTIterator {
    
    stack<TreeNode*> st;
    bool reverse=true;
    
    //reverse=true--> before;
    //reverse=false-->next;
    
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            
            if(reverse==true)
                root=root->right;
            
            else
                 root=root->left;
        }
    }
    public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        
        if(reverse==false)
            pushAll(temp->right);
        
        else
            pushAll(temp->left);
        
        return temp->val;
    }
};


class Solution {
    
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
       int i=l.next();
        int j=r.next();
        
        while(i<j){
            if(i+j==k)
                return true;
            
            else if(i+j <k)
              i=l.next();
            
            else
                j=r.next();
        }
        
        return false;
        
    }
};


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
// class Solution {
//     bool helper(TreeNode* root,int k,unordered_map<int,int>& mp){
//         if(root==NULL)
//             return false;
        
//         if(mp.find(k-root->val)!=mp.end())
//             return true;
        
//         mp[root->val]=1;
        
//         return (helper(root->left,k,mp) || helper(root->right,k,mp));
//     }
// public:
//     bool findTarget(TreeNode* root, int k) {
//         unordered_map<int,int> mp;
        
//         if(root==NULL)
//             return false;
        
//         return helper(root,k,mp);
//     }
// };