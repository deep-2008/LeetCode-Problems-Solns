class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto it: edges)
            adj[it[0]].push_back(it[1]);
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(auto it: adj[i])
                indegree[it]++;
        }
        
        vector<int> result;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                result.push_back(i);
        }
        return result;
    }
};