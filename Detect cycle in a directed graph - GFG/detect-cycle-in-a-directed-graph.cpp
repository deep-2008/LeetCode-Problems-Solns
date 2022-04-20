// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  bool check(int start,vector<int> &vis,vector<int> adj[],vector<int> &dfsvis){
      vis[start]=1;
      dfsvis[start]=1;
      
      for(auto it:adj[start]){
          if(!vis[it]){
             
            if(check(it,vis,adj,dfsvis))
            return true;
          }
          
          else if(vis[it]==1 && dfsvis[it]==1)
          return true;
          
      }
          dfsvis[start]=0;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(check(i,vis,adj,dfsvis))
                return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends