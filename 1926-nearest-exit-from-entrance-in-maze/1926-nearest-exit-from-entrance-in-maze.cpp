class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int> (n,0));
         vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        
        vector<int> temp;
        int level=0;
        
        while(!q.empty()){
            int size=q.size();
            level++;
            
            while(size>0){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int r=row+dirs[i][0];
                    int c=col+dirs[i][1];
                    
                    if(r<0 || c<0 || r==m || c==n || maze[r][c]=='+' || vis[r][c]==1)
                        continue;
                    
                    if((r==0 || c==0 ||r==m-1 || c==n-1))// && maze[r][c]=='.')
                       return level;// temp.push_back(level);
                    
                    vis[r][c]=1;
                    q.push({r,c});
                }
                size--;
            }
        }
        
       // if(temp.size()==0)
            return -1;
        
      //  sort(temp.begin(),temp.end());
        
      //  return temp[0];
    }
};