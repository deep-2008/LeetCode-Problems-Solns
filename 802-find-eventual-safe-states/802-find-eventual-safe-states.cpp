class Solution {
public:
    bool dfs(vector<vector<int>>& transpose,vector<int>& vis,vector<int>& selfvis,vector<int>& cycle,int node){
        vis[node]=1;
        selfvis[node]=1;
        
        for(auto it:transpose[node]){
            if(!vis[it]){
               if(dfs(transpose,vis,selfvis,cycle,it)){
                   cycle[node]=1;
                   return true;
               }
            }
            
            else if(vis[it]==1 && selfvis[it]==1){
                cycle[node]=1;
                return true;
            }
        }
        selfvis[node]=0;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),selfvis(n,0),cycle(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(graph,vis,selfvis,cycle,i);
        }
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!cycle[i])
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};