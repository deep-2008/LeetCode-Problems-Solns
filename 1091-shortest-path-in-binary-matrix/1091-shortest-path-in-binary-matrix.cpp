class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        if(n==1)
            return 1;
        
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
        
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        queue<pair<int,int>> q;
        
        q.push({0,0});
        vis[0][0]=1;
        dist[0][0]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i=0;i<8;i++){
                int r= row+dirs[i][0];
                int c = col+dirs[i][1];
                
                if(r<0 || c<0 || r==n || c==n || grid[r][c]==1 )
                    continue;
                
                if(dist[row][col]+1 < dist[r][c]){
                    dist[r][c] = dist[row][col]+1;
                    q.push({r,c});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX)
            return -1;
        return dist[n-1][n-1];
    }
};