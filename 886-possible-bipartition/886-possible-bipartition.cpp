class Solution {
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,int node){
        if(vis[node]==-1)
            vis[node]=1;
        
        for(auto it:adj[node]){
            if(vis[it]==-1){
                vis[it]=1-vis[node];
                if(!dfs(adj,vis,it))
                    return false;
            }
            
            else if(vis[it]==vis[node])
                return false;
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,-1);
        
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n+1;i++){
            if(vis[i]==-1)
                if(!dfs(adj,vis,i))
                    return false;
        }
        
        return true;
    }
};