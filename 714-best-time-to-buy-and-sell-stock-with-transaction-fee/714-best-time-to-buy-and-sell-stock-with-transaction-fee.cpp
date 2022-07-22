class Solution {
    int dp[50001][2];
    int solve(vector<int>& prices,int fee,int ind,int buy){
        if(ind==prices.size())
            return 0;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        int profit=0;
        
        if(buy==1){
            profit=max(-prices[ind]+solve(prices,fee,ind+1,0),solve(prices,fee,ind+1,1));
        }
        
        else
            profit=max(prices[ind]-fee+solve(prices,fee,ind+1,1),solve(prices,fee,ind+1,0));
        
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(prices,fee,0,1);
    }
};