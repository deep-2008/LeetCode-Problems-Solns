class Solution {
    void dfs(vector<vector<int>> &graph,int node,vector<vector<int>> &paths,vector<int> &v){
        v.push_back(node);
        if(node==graph.size()-1){
            paths.push_back(v);
            return;
        }
        
        vector<int> nextNodes=graph[node];
        
        for(int next:nextNodes){
            dfs(graph,next,paths,v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if(graph.size()==0)
            return paths;
        
        vector<int> v;
        dfs(graph,0,paths,v);
        return paths;
    }
};

























