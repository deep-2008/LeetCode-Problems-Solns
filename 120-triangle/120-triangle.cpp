class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
      //  int dp[n][n];
       // dp[0][0]=triangle[0][0];
        if(n==1)
            return triangle[0][0];
        
      /*  for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0)
                    dp[i][j]=triangle[i][j];
                else{
                    int s=triangle[i][j] + dp[i-1][j];
                    int b=triangle[i][j];
                    if(j-1>=0)
                        b+=dp[i-1][j-1];
                    else
                        b=INT_MAX;
                    dp[i][j]= min(s,b);
                }
            }
        }*/
        
        
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=min(triangle[i][j]+dp[j],triangle[i][j]+dp[j+1]);
            }
        }
        
        return dp[0];
        
        /*int c=INT_MAX;
        
        for(int i=0;i<n;i++)
            c=min(c,dp[n-1][i]);
        return c;*/
    }
};