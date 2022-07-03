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
    int ans=0;
    
    void helper(TreeNode* root,int lb,int ub){
        if(root==NULL)
            return;
        
        ans=max(ans,max(abs(root->val-lb),abs(root->val-ub)));
        
        ub=max(root->val,ub);
        lb=min(root->val,lb);
        
        helper(root->left,lb,ub);
        helper(root->right,lb,ub);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        helper(root,root->val,root->val);
        return ans;
    }
};