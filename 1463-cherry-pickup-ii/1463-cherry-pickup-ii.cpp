class Solution {
    int dfs(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int r,int c1,int c2){
        if(c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size())
            return 0;
        
        if(r==grid.size()-1){
            if(c1==c2)
                return grid[r][c1];
            else
                return grid[r][c1]+grid[r][c2];
        }
        
        if(dp[r][c1][c2]!=0)
            return dp[r][c1][c2];
        
        int ans=0;
        for(int j1=-1;j1<=1;j1++){
            for(int j2=-1;j2<=1;j2++){
                if(c1==c2)
                    ans=max(ans,grid[r][c1]+dfs(grid,dp,r+1,c1+j1,c2+j2));
                
                else
                    ans=max(ans,grid[r][c1]+grid[r][c2]+dfs(grid,dp,r+1,c1+j1,c2+j2));
            }
        }
        
        return dp[r][c1][c2]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
    }
};