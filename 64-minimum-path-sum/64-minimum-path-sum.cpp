class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),0));
        // dp[0][0]=grid[0][0];
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                
                else if(i==0 && j>0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                
                else if(j==0 && i>0)
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                
                else{
                    int right=dp[i][j-1]+grid[i][j];
                    int down=dp[i-1][j]+grid[i][j];
                    
                    dp[i][j]=min(right,down);
                }
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};











// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int dp[m][n];
//         dp[0][0]=grid[0][0];
        
//        for(int i=1;i<n;i++)
//            dp[0][i]=grid[0][i]+dp[0][i-1];
        
//         for(int i=1;i<m;i++)
//             dp[i][0]=grid[i][0]+dp[i-1][0];
        
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
                               
//                 dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i][j];
//             }
//         }
        
//         return dp[m-1][n-1];
//     }
// };