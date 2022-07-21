class Solution {
    int dp[5001][2];
    int solve(vector<int>& prices,int n,int ind,int buy){
        if(ind>=n)
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit=0;
        
        if(buy==1){
            profit=max(-prices[ind]+solve(prices,n,ind+1,0),solve(prices,n,ind+1,1));
        }
        
        else{
            profit=max(prices[ind]+solve(prices,n,ind+2,1),solve(prices,n,ind+1,0));
        }
        
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(prices,n,0,1);
    }
};