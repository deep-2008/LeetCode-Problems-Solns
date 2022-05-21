class Solution {
public:
  
    void floodfill(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& vis){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==1 )
            return ;
        
      
        grid[r][c]=1;
        
        
        floodfill(grid,r-1,c,vis);
          floodfill(grid,r,c-1,vis);
          floodfill(grid,r+1,c,vis);
          floodfill(grid,r,c+1,vis);
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==0)
                        floodfill(grid,i,j,vis);
                }
            }
        }
        
        int sum=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 ){
                    sum++;
                    floodfill(grid,i,j,vis);
                }
            }
        }
        
        return sum;
    }
};