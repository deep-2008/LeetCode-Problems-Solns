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
    int checkPalindrome(unordered_map<int,int>& mp){
        int count=0;
        
        for(auto it:mp){
            if(it.second%2 != 0)
                count++;
            if(count>1)
                return 0;
        }
        
        return 1;
    }
    
    void helper(TreeNode* root,unordered_map<int,int>& mp,int &ans){
        if(root==NULL)
            return;
        
        mp[root->val]++;
        
        if( root->left==NULL && root->right==NULL){
            if(checkPalindrome(mp))
                ans++;
            // return;
        }
        
        
        
        
        helper(root->left,mp,ans);
        helper(root->right,mp,ans);
        
        mp[root->val]--;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int ans=0;
        unordered_map<int,int> mp;
        helper(root,mp,ans);
        return ans;
    }
};