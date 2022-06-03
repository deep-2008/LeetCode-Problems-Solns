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
    
    void dfs(TreeNode* root,int step){
        if(root==NULL)
            return;
        
        ans=max(ans,step);
        
        if(root->left)
            dfs(root->left,step+1);
        
        if(root->right)
            dfs(root->right,step+1);
    }
    
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int step=1;
        dfs(root,step);
        
        return ans;
    }
};