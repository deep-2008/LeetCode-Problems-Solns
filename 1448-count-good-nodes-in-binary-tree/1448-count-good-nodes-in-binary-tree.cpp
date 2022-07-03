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
    void helper(TreeNode* root,int maxm){
        if(root==NULL)
            return;
        
        if(maxm<=root->val)
            ans++;
        
            maxm=max(maxm,root->val);
        
        helper(root->left,maxm);
        helper(root->right,maxm);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        helper(root,root->val);
        return ans;
    }
};