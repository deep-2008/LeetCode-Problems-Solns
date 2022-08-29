class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>grid.size()-1 || j> grid[0].size()-1 || grid[i][j]=='0')
            return;
        
           
        
        grid[i][j]='0';
        
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        
        int c=0;
        int m=grid.size();
        int n=grid[0].size();
        
      
        
        
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]=='1'){
                   c++;
                   dfs(i,j,grid);
               }
           }
       }
        
        return c;
    }
};
























