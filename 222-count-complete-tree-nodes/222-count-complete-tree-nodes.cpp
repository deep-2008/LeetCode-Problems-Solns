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
    int leftHeight(TreeNode* root){
        int height=1;
        while(root!=NULL){
            height++;
            root=root->left;
        }
        return height;
    }
    
     int rightHeight(TreeNode* root){
        int height=1;
        while(root!=NULL){
            height++;
            root=root->right;
        }
         return height;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lh =leftHeight(root->left);
        int rh = rightHeight(root->right);
        
        if(lh == rh)
            return (1<<lh)-1;
        
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};