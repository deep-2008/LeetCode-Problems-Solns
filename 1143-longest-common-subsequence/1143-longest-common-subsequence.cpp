class Solution {
  //  int dp[10001][10001];
    
public:
   /* int LCS(string X,string Y,int n,int m){
        if(n==0||m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(X[n-1]==Y[m-1])
            return dp[n][m]=1+ LCS(X,Y,n-1,m-1);
        
        else
            return dp[n][m] = max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));*/
    //}
    int longestCommonSubsequence(string text1, string text2) {
        //Bottom Up
        int n=text1.size();
        int m=text2.size();
       // memset(dp,-1,sizeof(dp));
       int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                   dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
        //Recursive + Memoized Approach
         //  return LCS(text1,text2,n,m);      
    }
};