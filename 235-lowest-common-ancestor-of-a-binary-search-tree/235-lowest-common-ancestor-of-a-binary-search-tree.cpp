/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* r=NULL,*l=NULL;
        
        if(root->val < p->val && root->val <q->val)
         r=lowestCommonAncestor(root->right,p,q);
        
        else if(root->val > p->val && root->val > q->val)
         l =lowestCommonAncestor(root->left,p,q);
        
        else 
            return root;
        
        if(l==NULL)
            return r;
        if(r==NULL)
            return l;
        return root;
    }
};


