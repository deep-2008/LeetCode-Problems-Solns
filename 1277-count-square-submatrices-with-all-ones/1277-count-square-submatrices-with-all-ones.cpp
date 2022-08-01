class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sum=0;
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    if(matrix[i][j]==1){
                        dp[i][j]=1;
                        sum++;
                    }
                }
                
                else{
                    if(matrix[i][j]==1 && matrix[i-1][j-1]==1 && matrix[i][j-1]==1 && matrix[i-1][j]==1){
                        dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                        sum+=dp[i][j];
                    }
                    
                    else{
                        if(matrix[i][j]==1){
                            dp[i][j]=1;
                            sum++;
                        }
                    }
                }
            }
        }
        
        
        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         sum+=dp[i][j];
        //     }
        // }
        
        return sum;
    }
};