class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),bsp=-prices[0],ssp=0,csp=0,profit=0;
        
        if(n==1)
            return 0;
        
      /*  for(int i=1;i<n;i++){
            bsp=max(bsp,csp-prices[i]);
            
            ssp=max(ssp,bsp+prices[i]);
            
            csp=max(csp,ssp);
        }*/
        
        vector<vector<int>> dp(n,vector<int>(3,INT_MIN));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        dp[0][2]=0;
        
        for(int i=1;i<n;i++){
            dp[i][0]= max(dp[i-1][0],dp[i-1][2]-prices[i]); //buy state
            
            dp[i][1]= max(dp[i-1][1],dp[i-1][0]+prices[i]);//sell state
            
            dp[i][2]= max(dp[i-1][2],dp[i-1][1]); // cool down state
        }
        return dp[n-1][1];
    }
};