// class Solution {
//     int dp[2002];
//     bool solver(vector<int>& stones,int ind,int k,int n,int target){
//         if(k<=0)
//             return false;
        
//         if(ind==n-1){
//             if(target==stones[n-1])
//                 return true;
//             return false;
//         }
        
//         if(target>stones[n-1])
//             return false;
        
//         if(dp[target]!=0)
//             return dp[target];
        
//          target=stones[ind]+k;
//         dp[target]=1;
        
//         // bool a=false,b=false,c=false;
        
//         for(int i=ind;i<n;i++){
//             if(stones[i]==target){
//                 if(k-1>0){
//              return  dp[target]=(solver(stones,i,k,n,target)||solver(stones,i,k+1,n,target) || solver(stones,i,k-1,n,target));}
                
//                 return  dp[target]=(solver(stones,i,k,n,target)||solver(stones,i,k+1,n,target));
                
//             }
            
//         }
        
//         return dp[target]=0;
//     }
// public:
//     bool canCross(vector<int>& stones) {
//         int n=stones.size();
//         // target=0;
//         memset(dp,0,sizeof(dp));
//         return solver(stones,0,1,n,0);
//     }
// };


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recur(stones, mp, 0, 0, dp);
    }
    
    bool recur(vector<int>& stones, map<int, int> &mp, int i, int k, vector<vector<int>>& dp){
        if(i == stones.size()-1) return dp[i][k] = 1;
        if(dp[i][k] != -1) return dp[i][k];
        for(int t=k-1; t<=k+1; t++){
            if(t > 0 && mp.find(stones[i]+t) != mp.end()){
                int ind = mp[stones[i]+t];
                if(recur(stones, mp, ind, t, dp)) return dp[i][k] = 1;
            }
        }
        return dp[i][k] = 0;
    }
};