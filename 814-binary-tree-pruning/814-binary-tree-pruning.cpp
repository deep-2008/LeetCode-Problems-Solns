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
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        if(left==0){
            if(root->left)
                root->left=NULL;
        }
        
        if(right==0){
            if(root->right)
                root->right=NULL;
        }
        
        int ans=max(root->val,max(left,right));
        return ans;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        solve(root);
        
          if(root->val==0 && !root->left && !root->right)
            return NULL;
        
        return root;
    }
};