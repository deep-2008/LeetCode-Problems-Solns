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
    int maxSum=INT_MIN;
    
    int sum(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int lval=sum(root->left);
        int rval=sum(root->right);
        
        
        if(lval<0 )
            lval=0;
        
        if(rval<0)
            rval=0;
        
        maxSum = max(maxSum, (lval+rval+root->val));
        
        return root->val+max(lval,rval);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        sum(root);
        
        return maxSum;
        
    }
};