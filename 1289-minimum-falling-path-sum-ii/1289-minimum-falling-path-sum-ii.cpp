#define vii vector<vector<int>>
class Solution {
    int helper(vii &grid,vii &dp,int m,int n,int r,int c){
        if(r==m-1)
            return dp[r][c]=grid[r][c];
        
        if(dp[r][c]!=0)
            return dp[r][c];
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(i==c)
                continue;
            int temp=grid[r][c]+helper(grid,dp,m,n,r+1,i);
            ans=min(ans,temp);
        }
        
        return dp[r][c]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
        int n=grid[0].size();
        
        vii dp(m,vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            helper(grid,dp,m,n,0,i);
        }
        
        int res=INT_MAX;
        for(int i=0;i<n;i++)
            res=min(res,dp[0][i]);
        return res;
    }
};