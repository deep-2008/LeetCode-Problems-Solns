#define vii vector<vector<int>>
class Solution {
    int helper(vii &grid,vii &dp,vii &cost,int r,int c,int m,int n){
        if(r==m-1)
            return grid[r][c];
        
        if(dp[r][c]!=0)
            return dp[r][c];
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            int pos=grid[r][c];
            // int going=grid[r+1][i];
            int temp=grid[r][c]+cost[pos][i]+helper(grid,dp,cost,r+1,i,m,n);
            ans=min(temp,ans);
        }
        
        return dp[r][c]=ans;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<grid[0].size();i++){
            helper(grid,dp,moveCost,0,i,m,n);
        }
        
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,dp[0][i]);
        }
        
        return res;
    }
};