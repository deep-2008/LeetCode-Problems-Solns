class Solution {
    int dp[30001][2];
    int solve(vector<int>& nums,int ind,int buy){
        if(ind==nums.size())
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit=0;
        if(buy==1){
            profit=max(-nums[ind]+solve(nums,ind+1,0),solve(nums,ind+1,1));
        }
        
        else{
            profit=max(nums[ind]+solve(nums,ind+1,1),solve(nums,ind+1,0));
        }
        
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size(),profit=0;
        
        // for(int i=1;i<n;i++){
        //     if(nums[i]>nums[i-1])
        //        profit+=(nums[i]-nums[i-1]);          
        //  }
        
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,1);
        
    }
};

