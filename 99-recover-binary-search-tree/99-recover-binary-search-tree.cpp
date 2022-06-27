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
    TreeNode* f=NULL,*s=NULL,*t=NULL,*prev=NULL;
    
    void recover(TreeNode* root){
        if(root==NULL)
            return;
        
        recover(root->left);
        
        if(prev!=NULL && root->val<prev->val){
            if(f==NULL){
                f=prev;
                s=root;
            }
            else
                t=root;
        }
        prev=root;
        
        recover(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        // f=root;
        
        recover(root);
        
        if(t!=NULL)
            swap(t->val,f->val);
        
        else
            swap(f->val,s->val);
    }
};

