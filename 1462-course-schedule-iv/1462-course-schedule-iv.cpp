// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& que) {
//         int n=pre.size();
//         int m=que.size();
        
//         if(n==0){
//             vector<bool> a(m,false);
//             return a;
//         }
        
//         vector<vector<int>> graph(num);
        
//         for(int i=0;i<n;i++){
//             int u=pre[i][0];
//             int v=pre[i][1];
//             graph[u].push_back(v);
//         }
        
//         vector<int> indeg(num,0);
        
//         for(int i=0;i<num;i++){
//             for(auto node:graph[i]){
//                 indeg[node]++;
//             }
//         }
//          // for(auto i:indeg)
//             // cout<<i<<" ";
        
//         queue<pair<int,int>> q;
//         for(int i=0;i<num;i++){
//             if(indeg[i]==0)
//                 q.push({i,0});
//         }
        
//         vector<pair<int,int>> res;
//         while(!q.empty()){
//             int node=q.front().first;
//             int temp=q.front().second;
//             q.pop();
            
//             res.push_back({node,temp});
            
//             for(auto it:graph[node]){
//                 indeg[it]--;
//                 if(indeg[it]==0)
//                     q.push({it,1});
//             }
//         }
        
//          // for(auto i:res)
//             // cout<<i<<" ";
        
//         vector<bool> ans;
//         for(int i=0;i<m;i++){
//             int u=que[i][0];
//             int v=que[i][1];
//             int ind=0,f=0;
            
//             for(ind=0;ind<num;ind++){
//                 if(res[ind].first==u){
//                     break;
//                 }
//             }
            
//             for(int j=ind+1;j<num;j++){
//                 if(res[j].first==v && res[j].second==0){
//                    break;
//                 }
                
//                 else if(res[j].first==v && res[j].second==1){
//                     ans.push_back(1);
//                     f=1;
//                     break;
//                 }
                    
//             }
            
//             if(f==0)
//                 ans.push_back(0);
            
//         }
        
//         return ans;
//     }
// };



























class Solution {
public:
    vector<bool> checkIfPrerequisite(int n , vector<vector<int>> &p , vector<vector<int>>& qr) {
        vector<int> indegree(n , 0) , adj[n];
        for(int i=0 ; i<p.size() ; i++) {
            int u = p[i][0];
            int v = p[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i=0 ; i<n ; i++) {
            if(!indegree[i]) q.push(i);
        }
        vector<vector<bool>> isReachable(n , vector<bool>(n , false));
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                indegree[v]--;
                isReachable[u][v] = true;
                for(int i=0 ; i<n ; i++) {
                    if(isReachable[i][u]) isReachable[i][v] = true;
                }
                if(!indegree[v]) {
                    q.push(v);
                }
            }
        }
        vector<bool> ans((int)qr.size() , false);
        for(int i=0 ; i<qr.size() ; i++) {
            if(isReachable[qr[i][0]][qr[i][1]]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};