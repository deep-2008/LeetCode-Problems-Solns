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
    void findPos(TreeNode* root,TreeNode* prev,TreeNode* node){
        if(root==NULL){
            if(prev->val > node->val)
                prev->left=node;
            else
                prev->right=node;
            return;
        }
        
        if(root->val > node->val)
            findPos(root->left,root,node);
        
        else
            findPos(root->right,root,node);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root==NULL)
            return node;
        
//         if(root->val > val){
//             node->right=root;
//             if(root->left->val < node->val){
//             node->left=root->left;
//             root->left=NULL;
//             }
//             else
//                 node->left=NULL;
//         }
        
//          else{
//             node->left=root;
//              if(root->right->val > node->val){
//             node->right=root->right;
//             root->right=NULL;
//              }
//              else
//                  node->right=NULL;
//         }
        
        findPos(root,root,node);
        
        return root;
    }
};