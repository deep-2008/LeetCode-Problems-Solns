class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dirs={{0,-1},{0,1},{-1,0},{1,0}};
        int time=-1;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        if(q.empty()){
            for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
            return 0;
        }
        
        while(!q.empty()){
            time++;
            int size=q.size();
            
            while(size-->0){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int r=row+dirs[i][0];
                    int c=col+dirs[i][1];
                    
                    if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==0 || grid[r][c]==2)
                        continue;
                    
                    grid[r][c]=2;
                    q.push({r,c});
                }
            }
        }
        
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return time;
    }
};