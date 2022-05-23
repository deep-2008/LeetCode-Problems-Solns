class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==0 || q.size()==(n*n))
            return -1;
        
        int level=0;
        
        while(!q.empty()){
            level++;
            int size =q.size();
            
            while(size>0){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int rowdash =r + dirs[i][0];
                    int coldash = c+dirs[i][1];
                    
                    if(rowdash<0 || rowdash==n || coldash<0 || coldash==n || grid[rowdash][coldash]==1)
                        continue;
                    
                    q.push({rowdash,coldash});
                    grid[rowdash][coldash]=1;
                }
                size--;
            }
        }
        
        return level-1;
    }
};