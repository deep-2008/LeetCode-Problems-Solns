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
         
  //OPTIMISED
    bool helper(TreeNode* root,long long int mini,long long int maxi){
        if(root==NULL)
            return true;
        
        if(root->val<=mini || root->val>=maxi)
            return false;
        
        return (helper(root->left,mini,root->val) && helper(root->right,root->val,maxi));
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
       
        long long int mini=LONG_MIN;
        long long int maxi=LONG_MAX;
        
        return helper(root,mini,maxi);
    }
};


