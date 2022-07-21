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
    void solve(TreeNode* root,vector<vector<int>>& ans,vector<int> temp,int target,int sum){
        if(root==NULL)
            return;
        
        sum+=root->val;
        temp.push_back(root->val);
        
         // if(sum>target)
         //    return;
        
        if(!root->left && !root->right && sum==target){
            ans.push_back(temp);
            return ;
        }
        
        solve(root->left,ans,temp,target,sum);
        // temp.pop_back();
        
        solve(root->right,ans,temp,target,sum);
        // temp.pop_back();       
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        
        if(root==NULL)
            return ans;
        
        solve(root,ans,temp,targetSum,sum);
        return ans;
    }
};