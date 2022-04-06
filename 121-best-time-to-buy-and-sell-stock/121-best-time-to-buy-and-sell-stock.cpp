class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),buy=INT_MAX,profit=0,op=0;
        if(n==1)
            return 0;
       int dp[n+1];
        dp[0]=0;
        
        for(int i=1;i<n+1;i++){
           buy=min(buy,prices[i-1]);
           /* profit=prices[i]-buy;
            op=max(op,profit);*/
            dp[i]=max(prices[i-1]-buy,dp[i-1]);
        }
        return dp[n];
    }
};