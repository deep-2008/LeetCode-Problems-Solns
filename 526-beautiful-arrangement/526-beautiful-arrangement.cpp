class Solution {
    int dp[16];
    int ans=0;
    void solve(vector<int>& ds,vector<int>& vis,int n,int ind){
        if(ind>=n+1){
            ans++;
            // return ;
        }
        
        // if(dp[ind]!=0)
            // return dp[ind];
        
        // vis[ind]=1;
        int temp=0;
        
        for(int i=1;i<n+1;i++){
            if(!vis[i] && (ind%i==0 || i%ind==0)){
                vis[i]=1;
                // temp+= 
                solve(ds,vis,n,ind+1);
                vis[i]=0;
            }
        }
        // vis[ind]=0;
        
        // return dp[ind]=temp;
    }
public:
    int countArrangement(int n) {
       // return 0;
        vector<int> ds;
        vector<int> vis(n+1,0);
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++)
            ds.push_back(i);
        
        // return
        solve(ds,vis,n,1);
        return ans;
    }
};