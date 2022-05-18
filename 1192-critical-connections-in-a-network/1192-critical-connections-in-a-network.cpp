class Solution {
public:
    
    void dfs(int node,int parent,int &timer,vector<vector<int>>& result,vector<vector<int>>& adj,vector<int>& tin, vector<int>& low, vector<int>& vis){
        vis[node]=1;
        low[node]=tin[node]=timer++;
        
        for(auto it: adj[node]){
            if(it==parent)
                continue;
            
            if(!vis[it]){
                dfs(it,node,timer,result,adj,tin,low,vis);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                    result.push_back({node,it});
            }
            
            else
                low[node]=min(low[node],tin[it]);
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        vector<vector<int>> result;
            int timer=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,timer,result,adj,tin,low,vis);
            }
        }
        
        return result;
    }
    
};