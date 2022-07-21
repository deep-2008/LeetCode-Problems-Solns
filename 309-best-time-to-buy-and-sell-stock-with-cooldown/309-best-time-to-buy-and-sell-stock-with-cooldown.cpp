class Solution {
    // int dp[5001][2];
//     int solve(vector<int>& prices,int n,int ind,int buy){
//         if(ind>=n)
//             return 0;
        
//         if(dp[ind][buy]!=-1)
//             return dp[ind][buy];
        
//         int profit=0;
        
//         if(buy==1){
//             profit=max(-prices[ind]+solve(prices,n,ind+1,0),solve(prices,n,ind+1,1));
//         }
        
//         else{
//             profit=max(prices[ind]+solve(prices,n,ind+2,1),solve(prices,n,ind+1,0));
//         }
        
//         return dp[ind][buy]=profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
        
                  if(buy==1){
                    profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
            
                    else{
                        int a=0,b=0;
                        // if(ind+2<n)
                    a=prices[ind]+dp[ind+2][1];
                    b=dp[ind+1][0];
                        profit=max(a,b);
                }
        
                      dp[ind][buy]=profit;
                }
            }
        
         // solve(prices,n,0,1);
        return dp[0][1];
    }
};