#define vii vector<vector<int>>
// class Solution {
//     int helper(vii &grid,vii &dp,vii &cost,int r,int c,int m,int n){
//         if(r==m-1)
//             return grid[r][c];
        
//         if(dp[r][c]!=0)
//             return dp[r][c];
        
//         int ans=INT_MAX;
        
//         for(int i=0;i<n;i++){
//             int pos=grid[r][c];
//             // int going=grid[r+1][i];
//             int temp=grid[r][c]+cost[pos][i]+helper(grid,dp,cost,r+1,i,m,n);
//             ans=min(temp,ans);
//         }
        
//         return dp[r][c]=ans;
//     }
// public:
//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//         int m=grid.size();
//         int n=grid[0].size();
        
//         vector<vector<int>> dp(m,vector<int> (n,0));
        
//         for(int i=0;i<grid[0].size();i++){
//             helper(grid,dp,moveCost,0,i,m,n);
//         }
        
//         int res=INT_MAX;
//         for(int i=0;i<n;i++){
//             res=min(res,dp[0][i]);
//         }
        
//         return res;
//     }
// };


int dp[2][50] = {};
class Solution {
public:
int minPathCost(vector<vector<int>>& g, vector<vector<int>>& moveCost) {
    int m = g.size(), n = g[0].size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (i == 0)
                dp[0][j] = g[0][j];
            else
                for (int k = 0; k < n; ++k)
                    dp[i % 2][k] = min(j == 0 ? INT_MAX : dp[i % 2][k], g[i][k] + dp[(i - 1) % 2][j] + moveCost[g[i - 1][j]][k]);
    return *min_element(begin(dp[(m - 1) % 2]), begin(dp[(m - 1) % 2]) + n);
}};