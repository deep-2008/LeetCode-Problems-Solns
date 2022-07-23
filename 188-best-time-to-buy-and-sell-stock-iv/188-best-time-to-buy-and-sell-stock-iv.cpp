class Solution {
    int dp[1001][2][101];
    int solve(vector<int>& prices,int n,int k,int ind,int buy,int count){
        if(ind==n || count==k)
            return 0;
        
        if(dp[ind][buy][count]!=0)
            return dp[ind][buy][count];
        
        int profit=0;
        
        if(buy==1)
            profit=max(-prices[ind]+solve(prices,n,k,ind+1,0,count),solve(prices,n,k,ind+1,1,count));
        
        else
            profit=max(prices[ind]+solve(prices,n,k,ind+1,1,count+1),solve(prices,n,k,ind+1,0,count));
        return dp[ind][buy][count]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,0,sizeof(dp));
        
        return solve(prices,n,k,0,1,0);
    }
};