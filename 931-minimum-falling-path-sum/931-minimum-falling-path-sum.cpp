class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m+1][n+1];
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                    dp[i][j]=matrix[i][j];
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                    dp[i][j]=matrix[i][j];
                else{
                    int s=matrix[i][j]+ dp[i-1][j];
                    int ld=matrix[i][j];
                    if(j-1>=0)
                     ld+=dp[i-1][j-1];
                    else
                        ld=INT_MAX;
                    int rd=matrix[i][j];
                    if(j+1<m)
                     rd+=dp[i-1][j+1];
                    else
                        rd=INT_MAX;
                     dp[i][j] = min(s,min(ld,rd));
                }
            }
        }
        int minm=INT_MAX;
        for(int i=0;i<m;i++)
            minm = min(minm,dp[n-1][i]);
        
        return minm;
    }
};