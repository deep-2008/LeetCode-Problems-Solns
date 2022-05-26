class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:rooms[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};



























