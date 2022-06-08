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
    void helper(TreeNode* root,string s,vector<string>& ans){
        if(root==NULL){
            return;
        }
        
        // int a=root->val;
        // if(s.empty())
        //     s=to_string(root->val);
        // else
        s=s+to_string(root->val)+"->";
        
        if(root->left==NULL && root->right==NULL){
            s.erase((s.size()-2));
            ans.push_back(s);
        }
            
        
      //  if(root->left)
        helper(root->left,s,ans);
        
      //  if(root->right)
        helper(root->right,s,ans);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        
        helper(root,s,ans);
        return ans;
    }
};