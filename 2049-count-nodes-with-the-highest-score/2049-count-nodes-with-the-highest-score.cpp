// class Solution {
//     int dfs(vector<int>& parents,unordered_map<long long int,int>& mp,unordered_map<int,int>& node,int ind,int n,int m){
        
//         if(node.find(ind)==node.end()){
//             mp[m]++;
//             return 1;
//         }
//        long long int l=0,r=0,count=0;
//         long long int res=0;
        
//         for(int i=1;i<n;i++){
//             if(count==2)break;
            
//            if(parents[i]==ind){
//                count++;
//                if(count==1)
//                l=dfs(parents,mp,node,i,n,m);
               
//                if(count==2)
//                    r=dfs(parents,mp,node,i,n,m);
//            } 
//         }
//         if(l==0 && r==0)
//             res=m;
//         else if(l==0){
//             if(l+r==m)
//                 res=r;
//             else
//             res=(m-(l+r))*r;
//         }
        
//         else if(r==0){
//             if(l+r==m)
//                 res=l;
//             else
//             res=(m-(l+r))*l;
//             }
        
//         else{
//             if(l+r==m)
//                 res=l*r;
//             else
//             res=(m-(l+r))*l*r;
//         }
        
//         mp[res]++;
//         return l+r+1;
//     }
// public:
//     int countHighestScoreNodes(vector<int>& parents) {
//      // return 0;
//         int n=parents.size();
//         int m=n-1;
//         unordered_map<long long int,int> mp;
//          unordered_map<int,int> node;
//         for(auto i:parents)
//             node[i]++;
        
//         dfs(parents,mp,node,0,n,m);
        
//         int ans=0,temp=INT_MIN;        
//         for(auto it:mp){
//             // cout<<it.first<<" -> "<<it.second<<endl;
//             if(it.first>temp){
//                 temp=it.first;
//             ans=it.second;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
     int helper(int src,vector<vector<int>>& g,vector<int>& size){
         int ans = 1;
         
         for(auto child:g[src]){
             ans += helper(child,g,size);
         }
         
         return size[src] = ans; 
     }
    
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        
        vector<int> size(n,0); 
        vector<vector<int>> g(n); 
        
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        
        helper(0,g,size);  
        
        long long cnt = 0, maxi = 0;
        
        for(int i=0;i<n;i++){
            long long pro = 1; 
            pro = max(pro,(long long)n - size[i]); 
        
            for(auto node:g[i]){
                pro = pro * size[node]; 
            }
            
            if(pro > maxi){
                maxi = pro;
                cnt = 1;
            }
            
            else if(pro == maxi){
                cnt++;
            }
        }
        
        return cnt;
    }
};