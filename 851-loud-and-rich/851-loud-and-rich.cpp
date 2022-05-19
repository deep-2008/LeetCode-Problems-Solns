class Solution {
public:
    void dfs(int node,vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it,vis,adj,st);
        }
        
        st.push(node);
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        
        for(auto it:richer){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        
        
        
        vector<int> vis(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            dfs(i,vis,adj,st);
        }
        
        vector<int> result(n);
         iota(result.begin(),result.end(),0);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(in[i]==0){
               // result[i]=i;
                q.push(i);
            }
        }
        
     /*   while(!st.empty()){
            pair<int,int> node={quiet[st.top()],st.top()};
           
       
            queue<int> q;
            q.push(st.top());
             st.pop();
            while(!q.empty()){
                int x=q.front();
                q.pop();
            for(auto it: adj[x]){
                if(node.first < quiet[it])
                    result[it]=node.second;
                else
                    result[it]=it;
            }}
        }*/
        
        while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto child:adj[cur])
        {
            in[child]--;
            if(quiet[cur]<quiet[child])
            {
                quiet[child]=quiet[cur];
                result[child]=result[cur];
            }
            if(in[child]==0)
                q.push(child);
        }
    }
        
        return result;
        
    }
};