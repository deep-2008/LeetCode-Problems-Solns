class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>> adj(n);
        vector<int> finish;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                finish.push_back(i);
               // continue;
            }
            
            if(i+arr[i]<n)
                adj[i].push_back(i+arr[i]);
            
            if(i-arr[i]>=0)
                adj[i].push_back(i-arr[i]);
        }
        
        queue<int> q;
        vector<int> vis(n,0);
        
        q.push(start);
        vis[start]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                for(int i=0;i<finish.size();i++){
                    if(it==finish[i])
                        return true;
                }
                
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return false;
    }
};