class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<n;i++){
            int u=pre[i][1];
            int v=pre[i][0];
            adj[u].push_back(v);
        }
        
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<adj.size();i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int comp=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            comp++;
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(comp==numCourses)
            return true;
        return false;
    }
};