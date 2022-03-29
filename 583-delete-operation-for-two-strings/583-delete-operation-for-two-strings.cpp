class Solution {
public:
    int minDistance(string X, string Y) {
        int m=X.size();
	    int n=Y.size();
	    int result = n+m;
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                
                else if(X[i-1]==Y[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
                
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        if(dp[m][n] == n)
        return m-dp[m][n];
        
        else 
        return (result - (2*dp[m][n]));
    }
};