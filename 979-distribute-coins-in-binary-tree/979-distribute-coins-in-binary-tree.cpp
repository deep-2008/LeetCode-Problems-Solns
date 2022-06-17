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
    void findMoves(TreeNode* root,TreeNode* parent,int &moves){
        if(root==NULL)
            return;
        
        // parent=root;
        
        findMoves(root->left,root,moves);
        findMoves(root->right,root,moves);
        
        if(root->val > 1){
            parent->val = parent->val + (root->val-1);
            moves+=(root->val - 1);
            root->val = 1;
        }
        
        else if(root->val<1){
            
            parent->val= parent->val-(1+abs(root->val));
            moves+= (1+abs(root->val));
            root->val=1;
        }
    }
    
    
public:
    int distributeCoins(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        // TreeNode* parent=NULL;
        int moves=0;
        
        findMoves(root,root,moves);
        
        return moves;
    }
};