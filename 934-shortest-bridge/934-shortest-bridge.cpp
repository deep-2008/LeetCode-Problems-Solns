class Solution {
public:
    void dfs(vector<vector<int>>& grid,queue<pair<int,int>>&q,vector<vector<int>>& vis,int r,int c,int n){
        if(r<0 || c<0 || r==n ||c==n ||grid[r][c]==0 || vis[r][c]==1)
                    return;
        vis[r][c]=1;
        q.push({r,c});
        
        dfs(grid,q,vis,r-1,c,n);
        dfs(grid,q,vis,r,c-1,n);
        dfs(grid,q,vis,r+1,c,n);
        dfs(grid,q,vis,r,c+1,n);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int f=0;
        for(int i=0;i<n && !f;i++){
            for(int j=0;j<n && !f;j++){
                if(grid[i][j]==1){
                   dfs(grid,q,vis,i,j,n);
                    f=1;
                }
            }
        }
        int level=0;
        
        while(!q.empty()){
            int size =q.size();
           
            
            while(size>0){
                int row=q.front().first;
                int col=q.front().second;
              //  vis[row][col]=1;
                
                q.pop();
                
              
                
                 for(int i=0;i<4;i++){
                int r=row+dirs[i][0];
                int c=col+dirs[i][1];
                
                if(r<0 || c<0 || r==n ||c==n || vis[r][c]==1)
                    continue;
                
                  if(grid[r][c]==1)
                    return level;
               vis[r][c]=1;
                q.push({r,c});
            }
                size--;
                
            }
             level++;
        }
        
        
            
           return -1;
        
    }
};