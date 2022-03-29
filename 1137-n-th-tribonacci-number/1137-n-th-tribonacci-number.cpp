class Solution {
public:
    int series(int n,vector<int> &dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        
        else{
            return (dp[n]=series(n-1,dp)+series(n-2,dp)+series(n-3,dp));
        }
    }
    int tribonacci(int n) {
       vector<int> dp(n+4,-1);
       /* dp[0]=0;
        dp[1]=1;
        dp[2]=1;*/
        
       /* for(int i=3;i<=n;i++){
            dp[i]=dp[i-3]+dp[i-1]+dp[i-2];
        }*/
        
        return series(n,dp);
    }
};