class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int n=nums.size(),ans=0;
        
        unordered_map<int,int> dp;
        
        for(int i=0;i<n;i++){
            if(dp.count(nums[i]-diff) > 0)
                dp[nums[i]]=1+dp[nums[i]-diff];
            
            else
                dp[nums[i]]=1;
            
            ans=max(ans,dp[nums[i]]);
        }
        
        return ans;
    }
};