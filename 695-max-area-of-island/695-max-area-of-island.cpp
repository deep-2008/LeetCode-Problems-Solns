/*class Solution {
public:
    void floodfill(vector<vector<int>>& grid,int row,int col,int &sum,int &ans,vector<vector<int>>& vis){
        
        if(row<0 || col<0 || row==grid.size() || col==grid[0].size() || grid[row][col]==0 || vis[row][col]==1)
            return;
        
        if(grid[row][col]==1)
            sum++;
      ans=max(ans,sum);
        vis[row][col]=1;
        //grid[row][col]=0;
        
        floodfill(grid,row-1,col,sum,ans,vis);
        floodfill(grid,row,col-1,sum,ans,vis);
        floodfill(grid,row+1,col,sum,ans,vis);
        floodfill(grid,row,col+1,sum,ans,vis);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sum=0,ans=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                floodfill(grid,i,j,sum,ans,vis);
               // ans=max(ans,sum);
                sum=0;
            }
        }
        
        return ans;
    }
};*/


//SPACE OPTIMISED

class Solution {
public:
    void floodfill(vector<vector<int>>& grid,int row,int col,int &sum,int &ans){
        
        if(row<0 || col<0 || row==grid.size() || col==grid[0].size() || grid[row][col]==0)
            return;
        
        if(grid[row][col]==1)
            sum++;
      ans=max(ans,sum);
        //vis[row][col]=1;
        grid[row][col]=0;
        
        floodfill(grid,row-1,col,sum,ans);
        floodfill(grid,row,col-1,sum,ans);
        floodfill(grid,row+1,col,sum,ans);
        floodfill(grid,row,col+1,sum,ans);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sum=0,ans=0;
        int m=grid.size();
        int n=grid[0].size();
        
       // vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)
                floodfill(grid,i,j,sum,ans);
               // ans=max(ans,sum);
                sum=0;
            }
        }
        
        return ans;
    }
};