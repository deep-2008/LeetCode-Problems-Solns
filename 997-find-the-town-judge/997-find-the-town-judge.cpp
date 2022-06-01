class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1),trans(n+1);
        if(n==1)
            return 1;
        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            
            adj[u].push_back(v);
            trans[v].push_back(u);
        }
        
        vector<int> indeg(n+1,0),outdeg(n+1,0);
        
        for(int i=0;i<n+1;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
            
            for(auto it: trans[i]){
                outdeg[it]++;
            }
        }
        
      //  int judge=0;
        
        for(int i=0;i<n+1;i++){
            if(indeg[i]==n-1 && outdeg[i]==0){
               return i;
            }
        }
        
        
        return -1;
    }
};