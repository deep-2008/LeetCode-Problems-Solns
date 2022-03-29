class Solution {
public:
    int solve(int dp[],int n){
        if(n==1)
            return 1;
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);
    }
    int fib(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solve(dp,n);
    }
};