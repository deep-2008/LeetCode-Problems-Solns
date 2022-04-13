class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n=obs[0].size();
        int dp[m][n];
        
        if(obs[0][0]==1 || obs[m-1][n-1]==1)
            return 0;
        
        for(int i=0;i<n;i++){
           if(obs[0][i]==1){
               while(i<n){
                   dp[0][i]=0;
                   i++;
               }
           }
            else
                dp[0][i]=1;
        }
        
        for(int i=0;i<m;i++){
           if(obs[i][0]==1){
               while(i<m){
                   dp[i][0]=0;
                   i++;
               }
           }
            else
                dp[i][0]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obs[i-1][j]==1 && obs[i][j-1]==1)
                    dp[i][j]=0;
                
                else if(obs[i][j-1]==1)
                    dp[i][j]=dp[i-1][j];
                
                else if(obs[i-1][j]==1 )
                    dp[i][j]=dp[i][j-1];
                
                else
                    dp[i][j] = dp[i-1][j]+ dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};