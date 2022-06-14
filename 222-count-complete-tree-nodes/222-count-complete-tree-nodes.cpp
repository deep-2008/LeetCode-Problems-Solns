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
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int count=0;
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        
        count=l+r+1;
        ans+=count;
        
        return count;
    }
};