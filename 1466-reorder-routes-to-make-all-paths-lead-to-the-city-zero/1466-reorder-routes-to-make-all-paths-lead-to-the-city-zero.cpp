class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> graph[n];
        
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            
            graph[u].push_back({v,0});
            graph[v].push_back({u,1});
        }
        
        vector<int> vis(n,0);
       
       
        int step=0;
        
       /* for(int i=0;i<n;i++){
            queue<int> q;
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                
                for(auto it:graph[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                        step++;
                    }
                }
            }
        }*/
        
        
                dfs(0,graph,vis,step);
        
        
        return step;
    }
    
    void dfs(int node,vector<pair<int,int>> graph[],vector<int>& vis,int &step){
       vis[node]=1;
        
        for(auto it:graph[node]){
            if(vis[it.first])
                continue;
            
            if(it.second==0)
                step++;
            
                dfs(it.first,graph,vis,step);
            }
        }
    
};