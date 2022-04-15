class Solution {
public:
    int nthUglyNumber(int n) {
       if(n==1)
           return n;
       int dp[n+1];
        dp[1]=1;
        int p2=1,p3=1,p5=1;
        
        for(int i=2;i<n+1;i++){
            int f1=2*dp[p2];
            int f2=3*dp[p3];
            int f3=5*dp[p5];
            
            dp[i] = min(f2,min(f3,f1));
            if(dp[i]==f1)
                p2++;
            if(dp[i]==f2)
                p3++;
            if(dp[i]==f3)
                p5++;
        }
        return dp[n];
        
        
        
    }
};