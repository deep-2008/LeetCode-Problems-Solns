class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<int> indeg(n,0);
        vector<vector<int>> graph(n);
        queue<int> q;
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            
            graph[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            for(auto it:graph[i])
                indeg[it]++;
        }
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it:graph[node]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        
        if(ans.size()<n)
            return {};
        
        return ans;
    }
};