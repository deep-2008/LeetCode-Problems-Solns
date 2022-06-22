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
//     void helper(TreeNode* root,vector<int>& inorder){
//         if(root==NULL)
//             return;
        
//         helper(root->left,inorder);
//         inorder.push_back(root->val);
//         helper(root->right,inorder);
//     }
    //OPTIMISED
    bool helper(TreeNode* root,long long int mini,long long int maxi){
        if(root==NULL)
            return true;
        
        if(root->val<=mini || root->val>=maxi)
            return false;
        
        return (helper(root->left,mini,root->val) && helper(root->right,root->val,maxi));
        
//        bool l= helper(root->left,mini,root->val);
//         bool r=helper(root->right,root->val,maxi);
        
//         if(l && r)
//             return 1;
//         return 0;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        // cout<<INT_MAX<<" ";
//         vector<int> inorder;
//         helper(root,inorder);
        
//         for(int i=0;i<inorder.size()-1;i++){
//             if(inorder[i]>=inorder[i+1])
//                 return false;
//         }
        
//         return true;
        long long int mini=LONG_MIN;
        long long int maxi=LONG_MAX;
        
        return helper(root,mini,maxi);
    }
};


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
// class Solution {
//    /* vector<int> in;
    
//     void inorder(TreeNode *root){
//         if(root==NULL)
//             return;
//         inorder(root->left);
//         in.push_back(root->val);
//         inorder(root->right);
//     }*/
// public:
//     bool isValidBST(TreeNode* root) {
//        /* inorder(root);
        
//         for(int i=0;i<in.size()-1;i++){
//             if(in[i]>=in[i+1]){
//                 return false;
//                // break;
//             }
//         }
        
//         return true;*/
//         if(root==NULL) //|| (!root->left && !root->right))
//             return false;
//         if(root && (!root->left && !root->right))
//             return true;
//         if(root->left->val >=root->val || root->right->val <= root->val)
//             return false;
        
           
//         isValidBST(root->left);
//         isValidBST(root->right);
        
//         return true;
//     }
// };