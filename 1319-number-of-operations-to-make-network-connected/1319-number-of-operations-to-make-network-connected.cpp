class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int node){
        if(vis[node])
            return;
        
        vis[node]=1;
        
        for(auto it: adj[node]){
          //  if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n,0);
        int count=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                    count++;
            }
        }
        
        return count-1;
    }
};