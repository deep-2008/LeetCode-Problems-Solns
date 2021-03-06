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
    void helper(TreeNode* root,TreeNode* parent,TreeNode* grand,int &sum){
        if(root==NULL)
            return ;
        
//         if(root->val%2==0){
            
//             if(root->left){
//             if(root->left->left)
//                 sum+=root->left->left->val;
                        
//             if(root->left->right)
//                 sum+=root->left->right->val;
//             }
            
//             if(root->right){
//             if(root->right->left)
//                 sum+=root->right->left->val;
            
//             if(root->right->right)
//                 sum+=root->right->right->val;
//             }
//         }
        
        if(grand!=NULL && grand->val%2==0)
            sum+=root->val;
        
        helper(root->left,root,parent,sum);
        helper(root->right,root,parent,sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int ans=0;
        
        helper(root,NULL,NULL,ans);
        
        return ans;
    }
};