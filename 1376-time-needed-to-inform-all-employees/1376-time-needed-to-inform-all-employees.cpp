class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& it) {
        if(n==1)
            return 0;
        int time=0;
        int c=0;
        queue<int> q;
        
        //for(int i=0;i<manager.size();i++)
        
      //  q.push(headID);
        
       /* while(!q.empty()){
            int size=q.size();
           //  time+= it[q.front()];
            vector<int> temp;
            
            while(size-->0){
            int node=q.front();
            q.pop();
                temp.push_back(it[node]);
                sort(temp.begin(),temp.end());
                
                if(size==0){
                    time+=temp[temp.size()-1];
                }
                
            
           
            
            for(int i=0;i<manager.size();i++){
                if(manager[i]==node){
                    q.push(i);
                }
              }
            }
        }*/
        
       /* vector<int> ans(n,0);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
           if(it[node]==0)
              continue;
            
            for(int i=0;i<manager.size();i++){
                if(manager[i]==node){
                    q.push(i);
                    ans[i] = it[node]+ans[node];
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        
        return ans[ans.size()-1];*/
        
        vector<pair<int,int>> adj[n];
        int source;
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1)
                source=i;
            else
                adj[manager[i]].push_back({i,it[manager[i]]});
        }
        
        vector<int> ans(n,0);
        
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: adj[node]){
                ans[it.first] = it.second + ans[node];
                q.push(it.first);
            }
        }
        
        
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
        
    }
};