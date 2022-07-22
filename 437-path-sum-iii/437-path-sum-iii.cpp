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
    unordered_map<long long,long long> mp;
    void solve(TreeNode* root,int target,vector<int> temp,int& ans,long long sum){
        if(root==NULL)
            return;
        
        sum+=root->val;
        
        
        if(sum==target)
            ans++;
        
        if(mp.find(sum-target)!=mp.end())
            ans+=mp[sum-target];
        
        mp[sum]++;
        
        // temp.push_back(sum);
        // cout<<temp.size()<<" ";
        
        solve(root->left,target,temp,ans,sum);
        solve(root->right,target,temp,ans,sum);
        
        // if(sum==target)
        //     ans++;
        mp[sum]--;
        
//         for(int i=0;i<temp.size();i++){
//             int tempSum=sum;
//             tempSum-=temp[i];
            
//             if(tempSum==target)
//                 ans++;
            
//             // if(tempSum<target)
//         }
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right){
            if(root->val==targetSum)
                return 1;
            return 0;
        }
        
        int ans=0;
        long long sum=0;
        vector<int> temp;
        // temp.push_back(0);
        
        solve(root,targetSum,temp,ans,sum);
        return ans;
    }
};