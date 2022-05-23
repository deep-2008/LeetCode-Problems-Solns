// GIVES TLE
#define vi vector<int>
#define vii vector<vector<int>>
class Solution {
public:
     vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    
    void bfs(vii &h,vii &vis, queue<pair<int,int>>& q, vii &temp,vii &ans){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            temp[row][col]++;
            
            if(temp[row][col]==2)
                ans.push_back({row,col});
            
            for(int i=0;i<4;i++){
                int r = row+dirs[i][0];
                int c=col +dirs[i][1];
                
               if(r<0 || c<0||r==h.size()||c==h[0].size()||vis[r][c]||h[r][c]<h[row][col])
                   continue;
                q.push({r,c});
                vis[r][c]=1;
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
       
        int m=h.size();
        
        int n=h[0].size();
        
        vector<vector<int>> vis(m,vector<int> (n,0));
        vii ans;
        vii temp(m,vi (n,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            q.push({i,0});
            vis[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            q.push({0,i});
            vis[0][i] =1;
        }
        
        bfs(h,vis,q,temp,ans);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1)
                    vis[i][j]=0;
            }
        }
        
        for(int i=0;i<n;i++){
            q.push({m-1,i});
            vis[m-1][i]=1;
        }
        
        for(int i=0;i<m-1;i++){
            q.push({i,n-1});
            vis[i][n-1]=1;
        }
        
        bfs(h,vis,q,temp,ans);
        
        return ans;
    }
};



