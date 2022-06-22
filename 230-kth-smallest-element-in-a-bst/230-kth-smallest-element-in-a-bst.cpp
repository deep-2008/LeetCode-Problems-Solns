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
    void helper(TreeNode* root,int k,priority_queue<int>& maxh){
        if(root==NULL)
            return ;
        
        maxh.push(root->val);
        
        if(maxh.size()>k)
            maxh.pop();
        
        helper(root->left,k,maxh);
        helper(root->right,k,maxh);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        
        priority_queue<int> maxh;
        
        helper(root,k,maxh);
        
        return maxh.top();
    }
};