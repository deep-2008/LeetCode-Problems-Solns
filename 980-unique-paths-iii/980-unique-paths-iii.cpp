class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c,int zero){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==-1 || grid[r][c]==-2)
            return 0;
        
        if(grid[r][c]==2){
            if(zero==-1)
                return 1;
            return 0;
        }
        
        grid[r][c]=-2;
        zero--;
        
        int totalpath = dfs(grid,r-1,c,zero) + dfs(grid,r+1,c,zero) + dfs(grid,r,c-1,zero) + dfs(grid,r,c+1,zero);
        
        grid[r][c]=0;
        zero++;
        
        return totalpath;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0,r,c;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0)
                zero++;
            else if(grid[i][j]==1){
                r=i;c=j;
            }
        }
    }
        
        return dfs(grid,r,c,zero);
    }
};