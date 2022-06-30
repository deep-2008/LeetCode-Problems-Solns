class Solution {
    // int dp[50005][4];
    int solve(vector<int>& nums,int ind,int n,int &ans,int pos_frog,vector<vector<int>>& dp){
        if(ind==n-1)
            return dp[ind][pos_frog]=0;
        
        if(dp[ind][pos_frog]!=-1)
            return dp[ind][pos_frog];
        
        
        if(nums[ind+1]==pos_frog){
        int l1=0,l2=0;
        if(pos_frog==1){
            l1=2;l2=3;
        }
        
        else if(pos_frog==2){
            l1=1;
            l2=3;
        }
        
        else if(pos_frog==3){
            l1=1;l2=2;
        }
        
        if(nums[ind]==l1)
            return dp[ind][pos_frog]=1+solve(nums,ind,n,ans,l2,dp);
        
        else if(nums[ind]==l2)
            return dp[ind][pos_frog]=1+solve(nums,ind,n,ans,l1,dp);
        
        else
            return dp[ind][pos_frog]=1+ min(solve(nums,ind,n,ans,l1,dp),solve(nums,ind,n,ans,l2,dp));
    }
        
        if(nums[ind+1]!=pos_frog)
            return dp[ind][pos_frog]=solve(nums,ind+1,n,ans,pos_frog,dp);
        
        return dp[ind][pos_frog]=0;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        int ans=0;
        // memset(dp,-1,sizeof(dp));
        
        vector<vector<int>> dp(n+1,vector<int> (4,-1));
        
        return solve(obstacles,0,n,ans,2,dp);
    }
};