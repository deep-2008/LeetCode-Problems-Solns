class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp[n+1][2];
        memset(dp,INT_MIN,sizeof(dp));
        dp[0][0]=-prices[0]; //buy state profit
        dp[0][1]=0;          //sold state profit   
        
        
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            
            dp[i][1] = max(dp[i-1][1],prices[i]+dp[i-1][0]-fee);
        }
        
        return dp[n-1][1];
    }
};