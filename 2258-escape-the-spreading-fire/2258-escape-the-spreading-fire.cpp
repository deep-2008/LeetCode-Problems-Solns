class Solution {
    void timeToCatchFire(vector<vector<int>> grid,vector<vector<int>>& timer,int m,int n){
        queue<pair<int,int>> q;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        
        // grid[0][1]=-2;
        // cout<<grid[0][1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    timer[i][j]=0;
                }
            }
        }
        
        int time=0;
        while(!q.empty()){
            int size=q.size();
            time++;
            
            while(size-->0){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int r=row+dirs[i][0];
                    int c=col+dirs[i][1];
                    
                    if(r<0 || c<0 || r==m || c==n || grid[r][c]==2 || grid[r][c]==1 )
                        continue;
                    
                    timer[r][c]=time;
                    grid[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        // cout<<timer[1][0];
    }
    
    void dfs(vector<vector<int>> grid,int r,int c,int m,int n,vector<vector<int>>& man){
     queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int time=0;
         vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!q.empty()){
            time++;
            int size=q.size();
            
            
                int t=q.front().first;
                int col=q.front().second.second;
                int row=q.front().second.first;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int r=row+dirs[i][0];
                    int c=col+dirs[i][1];
                    
                    if(r<0 || c<0 || r==m || c==n || grid[r][c]==2 || grid[r][c]==1 ||man[r][c]<=t+1 )
                        continue;
                    
                    man[r][c]=t+1;
                    // grid[r][c]=1;
                    q.push({t+1,{r,c}});
                }
            
        }
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> timer(m,vector<int> (n,1e9));
        vector<vector<int>> man(m,vector<int> (n,1e9));
        
        timeToCatchFire(grid,timer,m,n);
        // cout<<" "<<grid[0][1];
        
        int mini=1e9;
        dfs(grid,0,0,m,n,man);
        
        int a=timer[m-1][n-1]-man[m-1][n-1];
        int b=timer[m-2][n-1]-man[m-2][n-1];
        int c=timer[m-1][n-2]-man[m-1][n-2];
        
        if(man[m-1][n-1]==mini||(man[m-1][n-1]>timer[m-1][n-1]))return -1;
        
        if(timer[m-1][n-1]==mini)return 1e9;
        
        return a-(max(b,c)>a?0:1);
        
        // return mini;
    }
};