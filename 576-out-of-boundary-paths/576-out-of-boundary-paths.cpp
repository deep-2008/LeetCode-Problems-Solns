#define mod 1000000007
class Solution {
    int ans=0;
    long long int dp[51][51][51];
    
    long long int dfs(int m,int n,int r,int c,int move,int maxMove){
        if(move==maxMove){
            if(r<0 || c<0 || r==m || c==n )
                return 1;
            else
                return 0;
        }
        
        if(r<0 || c<0 || r==m || c==n )
                return 1;
        
        if(dp[r][c][move]!=-1)
            return dp[r][c][move];
        
       long long int up=dfs(m,n,r-1,c,move+1,maxMove)%mod;
        long long int down=dfs(m,n,r+1,c,move+1,maxMove)%mod;
        long long int left=dfs(m,n,r,c-1,move+1,maxMove)%mod;
        long long int right=dfs(m,n,r,c+1,move+1,maxMove)%mod;
        
        return dp[r][c][move]=((up%mod)+(down%mod)+(left%mod)+(right%mod)%mod)%mod;
        // return ans;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,startRow,startColumn,0,maxMove);
    }
};