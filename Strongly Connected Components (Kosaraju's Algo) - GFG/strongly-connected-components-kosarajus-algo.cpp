// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfsTopoSort(int node,vector<int> &vis,stack<int>& st, vector<int> adj[]){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it])
	        dfsTopoSort(it,vis,st,adj);
	    }
	    st.push(node);
	}
	
	void dfsTranspose(int node,vector<int>& vis, vector<int> transpose[]){
	    vis[node]=1;
	    
	    for(auto it:transpose[node]){
	        if(!vis[it])
	        dfsTranspose(it,vis,transpose);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        vector<int> transpose[V];
        int ans=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfsTopoSort(i,vis,st,adj);
        }
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i])
            transpose[it].push_back(i);
        }
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
        
                if(!vis[node]){
                    ans++;
                    dfsTranspose(node,vis,transpose);
                    
                
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends