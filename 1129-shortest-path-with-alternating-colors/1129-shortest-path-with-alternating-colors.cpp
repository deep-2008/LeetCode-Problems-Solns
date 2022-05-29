class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      
        vector<pair<int,int>> adj[n];
        
        vector<vector<int>> vis(n,vector<int> (2,0));
        
        queue<pair<int,int>> q;
        vector<int> ans(n,-1);
        int dist=0;
        
        for(int i=0;i<redEdges.size();i++){
            int u=redEdges[i][0];
            int v=redEdges[i][1];
            
            adj[u].push_back({v,0});
        }
        
         for(int i=0;i<blueEdges.size();i++){
            int u=blueEdges[i][0];
            int v=blueEdges[i][1];
            
            adj[u].push_back({v,1});
        }
        
        q.push({0,-1});
        vis[0][0]=vis[0][1]=1;
        ans[0]=0;
        
        while(!q.empty()){
            dist++;
            
            int size=q.size();
            
            while(size-->0){
                int node=q.front().first;
                int prev=q.front().second;
                q.pop();
                
                for(auto it:adj[node]){
                    if(vis[it.first][it.second]==1)
                        continue;
                    
                    if(prev!=it.second){
                        q.push({it.first,it.second});
                        vis[it.first][it.second]=1;
                        
                        if(ans[it.first]==-1)
                            ans[it.first]=dist;
                    }
                }
            }
        }
        
        return ans;
    }
};