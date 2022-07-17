//catalan numbers
//f(4)=f(0).f(3)+f(1).f(2)+f(2).f(1)+f(3).f(0)
    
class Solution {
public:
    int numTrees(int n) {
       // return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};